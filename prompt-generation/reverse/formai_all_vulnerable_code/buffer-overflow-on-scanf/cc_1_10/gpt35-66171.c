//FormAI DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getX();
int getY();
void displayGameBoard(char gameBoard[3][3]); // function to display game board
char checkWin(char gameBoard[3][3]); // function to check if someone wins
void playerMove(char gameBoard[3][3], char playerSymbol); // function for player's turn
void computerMove(char gameBoard[3][3], char computerSymbol); // function for computer's turn

int main()
{
    char gameBoard[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; // initialize game board with numbers from 1 to 9
    char playerSymbol, computerSymbol;
    char winner = ' ';
    int turn; // 1 for player's turn, 0 for computer's turn
    int x, y; // variables for coordinates of each move

    srand(time(NULL));

    printf("*** Welcome to Tic Tac Toe Game! ***\n");

    // choose player's symbol
    printf("Choose your symbol (X or O): ");
    scanf(" %c", &playerSymbol);
    while (playerSymbol != 'X' && playerSymbol != 'O')
    {
        printf("Invalid input. Choose again (X or O): ");
        scanf(" %c", &playerSymbol);
    }

    // assign computer's symbol
    if (playerSymbol == 'X')
        computerSymbol = 'O';
    else
        computerSymbol = 'X';

    // choose who goes first
    turn = rand() % 2;
    if (turn == 1)
        printf("You go first.\n");
    else
        printf("Computer goes first.\n");

    // start the game
    while (winner == ' ')
    {
        if (turn == 1) // player's turn
        {
            displayGameBoard(gameBoard);
            playerMove(gameBoard, playerSymbol);
            winner = checkWin(gameBoard);
            turn = 0;
        }
        else // computer's turn
        {
            computerMove(gameBoard, computerSymbol);
            winner = checkWin(gameBoard);
            turn = 1;
        }
    }

    // display winner
    displayGameBoard(gameBoard);
    if (winner == playerSymbol) // player wins
        printf("Congratulations! You won the game!\n");
    else if (winner == computerSymbol) // computer wins
        printf("Sorry, you lost the game. Better luck next time.\n");
    else // it's a tie
        printf("It's a tie!\n");

    return 0;
}

int getX()
{
    int x;
    printf("Enter row number (1-3): ");
    scanf("%d", &x);
    while (x < 1 || x > 3)
    {
        printf("Invalid input. Enter row number (1-3): ");
        scanf("%d", &x);
    }
    return x - 1;
}

int getY()
{
    int y;
    printf("Enter column number (1-3): ");
    scanf("%d", &y);
    while (y < 1 || y > 3)
    {
        printf("Invalid input. Enter column number (1-3): ");
        scanf("%d", &y);
    }
    return y - 1;
}

void displayGameBoard(char gameBoard[3][3])
{
    printf("\n\n");
    printf("     Tic Tac Toe\n");
    printf("        |\t|\n");
    printf("     %c  |\t%c\t|\t%c\n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
    printf("  _____|_______|_____\n");
    printf("        |\t|\n");
    printf("     %c  |\t%c\t|\t%c\n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
    printf("  _____|_______|_____\n");
    printf("        |\t|\n");
    printf("     %c  |\t%c\t|\t%c\n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
    printf("        |\t|\n\n");
}

char checkWin(char gameBoard[3][3])
{
    int i, j;
    // check for horizontal win
    for (i = 0; i < 3; i++)
    {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2])
            return gameBoard[i][0];
    }
    // check for vertical win
    for (j = 0; j < 3; j++)
    {
        if (gameBoard[0][j] == gameBoard[1][j] && gameBoard[1][j] == gameBoard[2][j])
            return gameBoard[0][j];
    }
    // check for diagonal win
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
        return gameBoard[0][0];
    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0])
        return gameBoard[0][2];
    // check for tie
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (gameBoard[i][j] != 'X' && gameBoard[i][j] != 'O')
                return ' ';
        }
    }
    return 'T'; // it's a tie
}

void playerMove(char gameBoard[3][3], char playerSymbol)
{
    int x, y;
    printf("Your turn (%c).\n", playerSymbol);
    x = getX();
    y = getY();
    while (gameBoard[x][y] == 'X' || gameBoard[x][y] == 'O')
    {
        printf("That spot is already taken. Choose another spot.\n");
        x = getX();
        y = getY();
    }
    gameBoard[x][y] = playerSymbol;
}

void computerMove(char gameBoard[3][3], char computerSymbol)
{
    int x, y;
    printf("Computer's turn (%c).\n", computerSymbol);
    do
    {
        x = rand() % 3;
        y = rand() % 3;
    } while (gameBoard[x][y] == 'X' || gameBoard[x][y] == 'O');
    gameBoard[x][y] = computerSymbol;
}