//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int main()
{
    // Create a 2D array to store the game board
    int **board = (int**)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int*)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the game board with random values
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Print the game board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Calculate the next generation of the game board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            int num_alive = 0;
            // Check the neighbors of the current cell
            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    if (r == 0 && c == 0) continue;
                    if (board[i + r][j + c] == 1) num_alive++;
                }
            }

            // Update the cell's status based on the number of alive neighbors
            if (board[i][j] == 1 && num_alive < 2) board[i][j] = 0;
            else if (board[i][j] == 0 && num_alive == 2) board[i][j] = 1;
        }
    }

    // Print the next generation of the game board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}