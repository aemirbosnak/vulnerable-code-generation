//FormAI DATASET v1.0 Category: Table Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLUMNS 6

int board[ROWS][COLUMNS];

int player1Score = 0;
int player2Score = 0;

int currentPlayer = 1;

void initializeBoard(void);
void printBoard(void);
int getNextMove(void);
void makeMove(int column);
int checkForWinner(void);

int main(void)
{
    int winner = 0;

    srand(time(NULL));

    initializeBoard();

    printf("Welcome to the futuristic C Table Game!\n\n");

    while(!winner)
    {
        printBoard();
        printf("\nPlayer %d, make your move.\n", currentPlayer);
        int column = getNextMove();
        makeMove(column);
        winner = checkForWinner();
        currentPlayer = currentPlayer == 1 ? 2 : 1;
    }

    printf("\nCongratulations Player %d, you win!\n", currentPlayer == 1 ? 2 : 1);
    printf("Final Score:\nPlayer 1: %d\nPlayer 2: %d\n", player1Score, player2Score);

    return 0;
}

void initializeBoard(void)
{
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLUMNS; j++)
            board[i][j] = 0;
}

void printBoard(void)
{
    printf("\n");

    for(int i = ROWS - 1; i >= 0; i--)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            printf("| ");

            if(board[i][j] == 0)
                printf(" ");
            else if(board[i][j] == 1)
                printf("X");
            else if(board[i][j] == 2)
                printf("O");
        }

        printf("|\n");
    }

    printf("- - - - - - -\n");
    printf("  1 2 3 4 5 6\n");
}

int getNextMove(void)
{
    int column;
    do
    {
        printf("Enter a column number (1-6): ");
        scanf("%d", &column);
    } while(column < 1 || column > 6 || board[ROWS - 1][column - 1] != 0);

    return column - 1;
}

void makeMove(int column)
{
    for(int i = 0; i < ROWS; i++)
    {
        if(board[i][column] == 0)
        {
            board[i][column] = currentPlayer;
            break;
        }
    }

    if(currentPlayer == 1)
        player1Score++;
    else
        player2Score++;
}

int checkForWinner(void)
{
    for(int i = 0; i < ROWS; i++)  // check for horizontal win
    {
        for(int j = 0; j < COLUMNS - 3; j++)
        {
            if(board[i][j] == currentPlayer && board[i][j+1] == currentPlayer && board[i][j+2] == currentPlayer && board[i][j+3] == currentPlayer)
                return 1;
        }
    }

    for(int i = 0; i < COLUMNS; i++)  // check for vertical win
    {
        for(int j = 0; j < ROWS - 3; j++)
        {
            if(board[j][i] == currentPlayer && board[j+1][i] == currentPlayer && board[j+2][i] == currentPlayer && board[j+3][i] == currentPlayer)
                return 1;
        }
    }

    for(int i = 0; i < ROWS - 3; i++)  // check for diagonal win (top left to bottom right)
    {
        for(int j = 0; j < COLUMNS - 3; j++)
        {
            if(board[i][j] == currentPlayer && board[i+1][j+1] == currentPlayer && board[i+2][j+2] == currentPlayer && board[i+3][j+3] == currentPlayer)
                return 1;
        }
    }

    for(int i = 0; i < ROWS - 3; i++)  // check for diagonal win (bottom left to top right)
    {
        for(int j = COLUMNS - 1; j >= 3; j--)
        {
            if(board[i][j] == currentPlayer && board[i+1][j-1] == currentPlayer && board[i+2][j-2] == currentPlayer && board[i+3][j-3] == currentPlayer)
                return 1;
        }
    }

    return 0;  // no winner
}