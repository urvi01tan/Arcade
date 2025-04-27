#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include <fstream>
using namespace std;

class Soduko
{
private:
    int soduko[9][9];

public:
    Soduko()
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                soduko[i][j] = 0;
            }
        }
        soduko[1][4] = 6;
        soduko[1][7] = 1;
        soduko[1][9] = 7;
        soduko[2][1] = 3;
        soduko[2][5] = 1;
        soduko[2][9] = 8;
        soduko[3][2] = 5;
        soduko[3][4] = 2;
        soduko[4][6] = 9;
        soduko[4][9] = 6;
        soduko[5][2] = 4;
        soduko[5][3] = 5;
        soduko[5][5] = 6;
        soduko[5][6] = 8;
        soduko[5][8] = 1;
        soduko[5][9] = 3;
        soduko[6][2] = 6;
        soduko[6][4] = 3;
        soduko[6][6] = 5;
        soduko[7][1] = 8;
        soduko[7][2] = 2;
        soduko[7][3] = 3;
        soduko[7][4] = 5;
        soduko[7][5] = 4;
        soduko[8][3] = 7;
        soduko[8][4] = 1;
        soduko[8][7] = 6;
        soduko[9][1] = 4;
        soduko[9][4] = 8;
        soduko[9][6] = 9;
        soduko[9][7] = 2;
        soduko[9][8] = 3;
        soduko[9][9] = 5;
    }
    void print_grid()
    {
        cout << "-------------------------" << endl;
        for (int i = 1; i <= 9; i++)
        {
            cout << "| ";
            for (int j = 1; j <= 9; j++)
            {
                if (soduko[i][j] != 0)
                {
                    cout << soduko[i][j] << " ";
                }
                else
                {
                    cout << ". ";
                }
                if ((j + 1) % 3 == 1)
                {
                    cout << "| ";
                }
            }
            cout << endl;
            if ((i + 1) % 3 == 1)
            {
                cout << "-------------------------" << endl;
            }
        }
    }

    void is_valid(int row, int col, int num)
    {
        system("cls");
        int count = 0, tot = 0;

        for (int i = 1; i <= 9; i++)
        {
            if (soduko[row][i] == num || soduko[i][col] == num)
            {
                count++;
            }
        }

        int subgrid_row = (row / 3) * 3;
        int subgrid_col = (col / 3) * 3;
        for (int i = subgrid_row; i < subgrid_row + 3; i++)
        {
            for (int j = subgrid_col; j < subgrid_col + 3; j++)
            {
                if (soduko[i][j] == num)
                {
                    count++;
                }
            }
        }
        if (count == 0)
        {
            soduko[row][col] = num;
        }
        else
        {
            cout << "invalid value" << endl;
        }
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                if (soduko[i][j] == 0)
                {
                    tot++;
                }
            }
        }
        if (tot != 0)
        {
            print_grid();
            cout << "enter row , column and number to enter";
            cin >> row >> col >> num;
            is_valid(row, col, num);
        }
        else
        {
            cout << "CONGRATULATIONS ON SUCCESFULLY COMPLETING THE GAME";
        }
    }
};

class rps
{
private:
    int userScore;
    int computerScore;
    int ties;

public:
    rps()
    {
        userScore = 0;
        computerScore = 0;
        ties = 0;
    }

    void play()
    {
        srand(time(nullptr));
        while (true)
        {
            cout << "Enter your move (1: Rock, 2: Paper, 3: Scissors, 4: Quit): ";
            int userMove;
            cin >> userMove;
            if (userMove < 1 || userMove > 4)
            {
                cout << "Invalid move! Please enter a valid move." << endl;
                continue;
            }
            if (userMove == 4)
            {
                break;
            }

            int computerMove = rand() % 3 + 1;

            cout << "You played " << moveToString(userMove) << "." << endl;
            cout << "The computer played " << moveToString(computerMove) << "." << endl;

            int result = getResult(userMove, computerMove);
            if (result == 1)
            {
                cout << "You win!" << endl;
                userScore++;
            }
            else if (result == -1)
            {
                cout << "You lose!" << endl;
                computerScore++;
            }
            else
            {
                cout << "It's a tie!" << endl;
                ties++;
            }

            cout << "Score: You " << userScore << ", Computer " << computerScore << ", Ties " << ties << "." << endl;
        }

        cout << "Final score: You " << userScore << ", Computer " << computerScore << ", Ties " << ties << "." << endl;
    }

private:
    string moveToString(int move)
    {
        switch (move)
        {
        case 1:
            return "Rock";
        case 2:
            return "Paper";
        case 3:
            return "Scissors";
        default:
            return "";
        }
    }

    int getResult(int userMove, int computerMove)
    {
        if (userMove == computerMove)
        {
            return 0;
        }
        else if (userMove == 1 && computerMove == 3)
        {
            return 1;
        }
        else if (userMove == 2 && computerMove == 1)
        {
            return 1;
        }
        else if (userMove == 3 && computerMove == 2)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
};

class casino
{
private:
    int secretNumber;
    int numGuesses;
    int maxGuesses;
    int betAmount;
    int playerBalance;

public:
    casino()
    {
        secretNumber = rand() % 100 + 1;
        numGuesses = 0;
        maxGuesses = 5;
        betAmount = 10;
        playerBalance = 100;
    }

    void play()
    {
        cout << "Welcome to the Casino Number Guessing Game!" << endl;

        while (playerBalance > 0)
        {
            cout << "Your balance: $" << playerBalance << endl;
            cout << "Enter your bet amount (0 to quit): ";
            cin >> betAmount;
            if (betAmount == 0)
            {
                break;
            }
            if (betAmount > playerBalance)
            {
                cout << "You don't have enough balance. Please enter a smaller bet amount." << endl;
                continue;
            }
            numGuesses = 0;
            cout << "I'm thinking of a number between 1 and 100. You have " << maxGuesses << " guesses." << endl;

            while (numGuesses < maxGuesses)
            {
                int guess;
                cout << "Guess #" << numGuesses + 1 << ": ";
                cin >> guess;
                if (guess < 1 || guess > 100)
                {
                    cout << "Invalid guess! Please enter a guess between 1 and 100." << endl;
                    continue;
                }
                numGuesses++;

                if (guess == secretNumber)
                {
                    cout << "Congratulations! You guessed the number in " << numGuesses << " guesses." << endl;
                    int winnings = betAmount * (maxGuesses - numGuesses + 1);
                    playerBalance += winnings;
                    cout << "You won $" << winnings << "." << endl;
                    break;
                }
                else if (guess < secretNumber)
                {
                    cout << "Too low!" << endl;
                }
                else
                {
                    cout << "Too high!" << endl;
                }

                if (numGuesses == maxGuesses)
                {
                    cout << "You didn't guess the number. The number was " << secretNumber << "." << endl;
                    playerBalance -= betAmount;
                }
            }
        }
        cout << "Thanks for playing! Your final balance is $" << playerBalance << "." << endl;
    }
};

class hand_cricket
{
private:
    int playerScore;
    int computerScore;

public:
    hand_cricket()
    {
        playerScore = 0;
        computerScore = 0;
    }

    void play()
    {
        cout << "Welcome to Hand Cricket Game!" << endl;
        srand(time(nullptr));
        int toss = rand() % 2;
        if (toss == 0)
        {
            cout << "You won the toss!" << endl;
            playInnings(true);
            playInnings(false);
        }
        else
        {
            cout << "Computer won the toss!" << endl;
            playInnings(false);
            playInnings(true);
        }

        cout << "Game Over!" << endl;
        cout << "Your Score: " << playerScore << endl;
        cout << "Computer Score: " << computerScore << endl;
        if (playerScore > computerScore)
        {
            cout << "Congratulations! You won the game." << endl;
        }
        else if (playerScore < computerScore)
        {
            cout << "Sorry! You lost the game." << endl;
        }
        else
        {
            cout << "The game is tied." << endl;
        }
    }

    void playInnings(bool isPlayerBatting)
    {
        int score = 0;
        int computerNumber;
        int playerNumber;

        if (isPlayerBatting)
        {
            cout << "You are batting now!" << endl;
            do
            {
                cout << "Enter your number (1 to 6): ";
                cin >> playerNumber;
                computerNumber = rand() % 6 + 1;
                if (playerNumber < 1 || playerNumber > 6)
                {
                    cout << "Invalid number! Please enter a number between 1 and 6." << endl;
                }
                else
                {
                    cout << "Computer's number: " << computerNumber << endl;
                    if (playerNumber == computerNumber)
                    {
                        cout << "Out! Your innings is over." << endl;
                        break;
                    }
                    else
                    {
                        score += playerNumber;
                    }
                }
            } while (true);
        }
        else
        {
            cout << "Computer is batting now!" << endl;
            do
            {
                computerNumber = rand() % 6 + 1;
                cout << "Computer's number: " << computerNumber << endl;
                cout << "Enter your number (1 to 6): ";
                cin >> playerNumber;
                if (playerNumber < 1 || playerNumber > 6)
                {
                    cout << "Invalid number! Please enter a number between 1 and 6." << endl;
                }
                else
                {
                    if (playerNumber == computerNumber)
                    {
                        cout << "Out! Computer's innings is over." << endl;
                        break;
                    }
                    else
                    {
                        score += computerNumber;
                    }
                }
            } while (true);
        }
        if (isPlayerBatting)
        {
            playerScore = score;
            cout << "Your innings is over. Your score: " << playerScore << endl;
        }
        else
        {
            computerScore = score;
            cout << "Computer's innings is over. Computer's score: " << computerScore << endl;
        }
    }
};

class TicTacToe
{
public:
    char board[3][3];
    char currentPlayer;

    TicTacToe()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = '-';
            }
        }
        currentPlayer = 'X';
    }

    void printBoard()
    {
        cout << "   1 2 3" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << "  ";
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool play(int row, int col)
    {
        if (board[row - 1][col - 1] == '-')
        {
            board[row - 1][col - 1] = currentPlayer;
            if (currentPlayer == 'X')
            {
                currentPlayer = 'O';
            }
            else
            {
                currentPlayer = 'X';
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    bool checkWin()
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
            {
                return true;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')
            {
                return true;
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-')
        {
            return true;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')
        {
            return true;
        }
        return false;
    }

    bool checkDraw()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '-')
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int filemanagerofrules()
{
    ofstream file1("arcade_guidelines.txt");

    if (!file1)
    {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    file1 << "Arcade Guidelines Rules\n\n";
    file1 << "1. Respect other players and arcade staff.\n";
    file1 << "2. Do not misuse the arcade equipment.\n";
    file1 << "3. Follow the game rules posted on each machine.\n";
    file1 << "4. Do not bring outside food or drinks into the arcade.\n";
    file1 << "5. Report any issues or malfunctions to the staff.\n";

    file1.close();

    cout << "Arcade guidelines have been written to arcade_guidelines.txt.\n";
}
int rolldice()
{
    return rand() % (6 + 1);
}
void welcome()
{
    Sleep(1000);
    cout << "===================" << endl;
    Sleep(1000);
    cout << "|   Welcome        |" << endl;
    Sleep(1000);
    cout << "|      to          |" << endl;
    Sleep(1000);
    cout << "|  PLAY BOX Arcade  |" << endl;
    Sleep(1000);
    cout << "====================" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "|=============================================|" << endl;
    Sleep(1000);
    cout << "|   MADE BY URVASHI  |" << endl;

    Sleep(1000);
    cout << "|=============================================|" << endl;
}
void passwaordmanager()
{
    char UserName[30], Password[30], ch;
    int i = 0;

    printf("Enter UserName : ");

    cin >> UserName;

    cout << "Enter Password : ";
    while (1)
    {
        ch = getch();
        if (ch == 13)
            break;
        if (ch == 32 || ch == 9)
            continue;
        else
        {
            cout << "*";
            Password[i] = ch;
            i++;
        }
    }
    Password[i] = '\0';
    if (strcmp(UserName, "playbox") == 0 && strcmp(Password, "arcade") == 0)
    {
        cout << "Login Success!!!" << endl;
        Sleep(1000);
        cout << "Will be redirected in 3 Seconds..." << endl;
        Sleep(1000);
        cout << "\b \b2";

        Sleep(1000);
        cout << "\b \b1";

        Sleep(1000);
    }
    else
    {

        cout << "Access Denied!!!" << endl;
        Sleep(1000);

        cout << "Will be redirected in 3 Seconds..." << endl;

        Sleep(1000);

        cout << "\b \b2";

        Sleep(1000);
        cout << "\b \b1";

        Sleep(1000);

        passwaordmanager();
    }
}

int main()
{
    welcome();
    passwaordmanager();
    filemanagerofrules();

    cout << "SELECT GAME YOU WANT TO PLAY" << endl;
    int choice;
    while (choice != 7)
    {
        cout << "WELCOME TO THE ARCADE.....\n";
        cout << "1.ROCK PAPER SCISSOR\n";
        cout << "2.HAND CRICKET\n";
        cout << "3.CASINO NUMBER GUESSING\n";
        cout << "4.SODUKO\n";
        cout << "5.TIC TAC TOE\n";
        cout << "6.HIGH LOW DICE SUM GAME\n";
        cout << "7.TO EXIT ARCADE\n '\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            rps game;
            game.play();
            break;
        }

        case 2:
        {
            hand_cricket game;
            game.play();
            break;
        }
        case 3:
        {
            srand(time(nullptr));
            casino game;
            game.play();
            break;
        }
        case 4:
        {
            int row, col, num;
            Soduko a;
            a.print_grid();
            cout << "enter row , column and number to enter";
            cin >> row >> col >> num;
            a.is_valid(row, col, num);
            break;
        }
        case 5:
        {
            TicTacToe game;
            int row, col;
            bool win = false;
            bool draw = false;

            cout << "Tic Tac Toe" << endl;
            cout << "Player 1: X" << endl;
            cout << "Player 2: O" << endl;
            cout << endl;
            while (!win && !draw)
            {
                game.printBoard();

                int player = (game.currentPlayer == 'X') ? 1 : 2;
                cout << "Player " << player << ", enter row and column (1-3): ";
                cin >> row >> col;

                if (game.play(row, col))
                {
                    win = game.checkWin();
                    draw = game.checkDraw();
                }
                else
                {
                    cout << "Invalid move. Try again." << endl;
                }
            }
            game.printBoard();
            if (win)
            {
                int player = (game.currentPlayer == 'X') ? 2 : 1;
                cout << "Player" << player << " wins!" << endl;
            }
            else
            {
                cout << "It's a draw!" << endl;
            }
            break;
        }
        case 6:
        {
            Sleep(1000);
            cout << "IN THIS GAME USER SUM NUMBER WILL BE ALREADY RANDOMLY PICKED THEN" << endl;
            Sleep(1000);
            cout << "THEN USER AND COMPUTER BOTH WILL PREDICT THE SUM OF DICE ROLLED BY THE COMPUTER" << endl;
            Sleep(1000);
            cout << "BASED ON THE SUM OF BOTH USER AND COMPUTER AND PREDICTION SCORE WILL BE PROVEDED" << endl;
            Sleep(1000);
            cout << "ENJOY THE GAME!!!!!!!!!!" << endl;

            srand(time(nullptr));

            int userScore = 0, computerScore = 0;
            char playAgain;

            cout << "Welcome to the High-Low two Dice Sum Game!" << endl;
            do
            {
                int userSum = rolldice() + rolldice();
                int computerSum = rolldice() + rolldice();

                cout << "Your sum: " << userSum << endl;

                char userChoice;
                cout << "Will the next sum be (h)igher or (l)ower than " << userSum << "? (Enter 'h' or 'l'): ";
                cin >> userChoice;

                if (userChoice != 'h' && userChoice != 'l')
                {
                    cout << "Invalid choice. Please enter 'h' for higher or 'l' for lower." << endl;
                    continue;
                }

                char computerChoice = (rand() % 2 == 0) ? 'h' : 'l';
                cout << "Computer predicts: " << (computerChoice == 'h' ? "Higher" : "Lower") << endl;
                if ((userChoice == 'h' && userSum < computerSum) || (userChoice == 'l' && userSum > computerSum))
                {
                    cout << "Computer's sum" << computerSum << endl;
                    cout << "Computer wins!" << endl;
                    computerScore++;
                }
                else if (userSum == computerSum)
                {
                    cout << "Computer's sum=" << computerSum << endl;
                    cout << "It's a tie! " << endl;
                }
                else
                {
                    cout << "Computer's sum=" << computerSum << endl;
                    cout << "You win!" << endl;
                    userScore++;
                }
                cout << "Current Scores - You: " << userScore << ", Computer: " << computerScore << endl;

                cout << "Play again? (y/n): ";
                cin >> playAgain;
            } while (playAgain == 'y');
            cout << "Final Scores - You: " << userScore << ", Computer: " << computerScore << endl;
            cout << "Thanks for playing!" << endl;
        }
        case 7:
        {
            break;
        }
        default:
        {
            cout << "Invalid choice. Please select again." << endl;
            break;
        }
        }
    }
    cout << "=======================================" << endl;
    Sleep(1000);
    cout << "|    Thank you for participating        |" << endl;
    Sleep(1000);
    cout << "|                                        |" << endl;
    Sleep(1000);
    cout << "=========================================|" << endl;
    return 0;
}
