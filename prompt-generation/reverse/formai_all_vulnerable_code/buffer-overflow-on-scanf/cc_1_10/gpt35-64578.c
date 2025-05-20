//FormAI DATASET v1.0 Category: Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// Function to print the game board
void printBoard(char board[ROW][COL])
{
    printf("\n   1  2  3  4  5  6  7  8  9  10\n");
    for (int i = 0; i < ROW; i++)
    {
        printf("%c ", 'A' + i);
        for (int j = 0; j < COL; j++)
        {
            printf("[");
            if (board[i][j] == 'X')
                printf("X");
            else if (board[i][j] == 'O')
                printf("O");
            else
                printf(" ");

            printf("]");
        }
        printf("\n");
    }
}

// Function to check if the shot is a hit or a miss
int hitOrMiss(char board[ROW][COL], char guess[2])
{
    int row = guess[0] - 'A';
    int col = guess[1] - '0' - 1;

    if (board[row][col] == 'X')
    {
        board[row][col] = 'O';
        printf("HIT!\n");
        return 1;
    }
    else
    {
        board[row][col] = '-';
        printf("MISS!\n");
        return 0;
    }
}

// Main function
int main()
{
    char board[ROW][COL];
    char guess[2];
    int hits = 0;
    int shots = 0;
    bool gameOver = false;

    srand(time(0));

    // Initialize the game board
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            board[i][j] = ' ';
        }
    }

    // Place the battleship on the board
    int row = rand() % 10;
    int col = rand() % 10;
    board[row][col] = 'X';

    printf("**WELCOME TO BATTLESHIP GAME**\n");
    while (!gameOver)
    {
        printf("\nGuess a cell (e.g. A1): ");
        scanf("%s", guess);

        if (hitOrMiss(board, guess))
        {
            hits++;

            if (hits == 1)
                printf("You have destroyed the enemy battleship!\n");
            else
                printf("You have hit the enemy battleship %d times!\n", hits);
        }

        shots++;

        if (hits == 1)
            gameOver = true;

        if (shots == 30)
            gameOver = true;

        printBoard(board);
    }

    if (hits == 1)
        printf("\nCongratulations! You have won the game in %d shots!\n", shots);
    else
        printf("\nSorry, you have lost the game!\n");

    return 0;
}