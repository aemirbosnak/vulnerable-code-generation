//FormAI DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6 // Size of the game board
#define MAX_MOVES 20 // Maximum moves allowed
#define SEED_NUM 7 // Seed number for srand()

// Function prototypes
void drawboard(int board[][SIZE], int moves);
void playgame(int board[][SIZE], int seed, int max_moves);

// Main function
int main(void)
{
    int board[SIZE][SIZE] = {0}; // Initialize game board with 0's
    int seed, max_moves;

    // Get seed and maximum moves from player
    printf("Enter seed value: ");
    scanf("%d", &seed);
    printf("Enter maximum moves: ");
    scanf("%d", &max_moves);

    // Call playgame function
    playgame(board, seed, max_moves);

    return 0;
}

// Function to draw game board
void drawboard(int board[][SIZE], int moves)
{
    printf("\nMoves: %d\n\n", moves);

    // Draw top row
    printf("    ");
    for (int i = 1; i <= SIZE; i++)
    {
        printf("%d   ", i);
    }
    printf("\n");

    // Draw game board
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d  ", i+1);
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                printf("_   ");
            }
            else
            {
                printf("%d   ", board[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to play the memory game
void playgame(int board[][SIZE], int seed, int max_moves)
{
    int moves = 0, matches = 0, num1, num2, row1, row2, col1, col2, temp;
    srand(seed); // Set seed for random number generation

    // Randomly generate numbers and place on board
    for (int i = 0; i < SIZE*SIZE/2; i++)
    {
        do
        {
            row1 = rand() % SIZE;
            col1 = rand() % SIZE;
        } while (board[row1][col1] != 0);
        do
        {
            row2 = rand() % SIZE;
            col2 = rand() % SIZE;
        } while ((board[row2][col2] != 0) || (row2 == row1 && col2 == col1));

        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;

        board[row1][col1] = num1;
        board[row2][col2] = num2;
    }

    // Play game
    while (moves < max_moves && matches < SIZE*SIZE/2)
    {
        drawboard(board, moves);
        printf("\nEnter first row and column (separated by spaces): ");
        scanf("%d %d", &row1, &col1);
        printf("Enter second row and column (separated by spaces): ");
        scanf("%d %d", &row2, &col2);

        // If numbers match, mark as found
        if (board[row1-1][col1-1] == board[row2-1][col2-1])
        {
            matches++;
            board[row1-1][col1-1] = -1;
            board[row2-1][col2-1] = -1;
        }

        // If numbers do not match, swap positions
        else
        {
            temp = board[row1-1][col1-1];
            board[row1-1][col1-1] = board[row2-1][col2-1];
            board[row2-1][col2-1] = temp;
        }

        moves++;
    }

    // Print end game message
    drawboard(board, moves);
    if (matches == SIZE*SIZE/2)
    {
        printf("\nCongratulations, you won!\n");
    }
    else
    {
        printf("\nSorry, you lost. Better luck next time!\n");
    }
}