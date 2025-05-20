//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define MAX_GENERATIONS 100

int main()
{
    int **board = NULL;
    int **next_board = NULL;
    int size, generations;

    printf("Enter the size of the board (default is 20): ");
    scanf("%d", &size);

    printf("Enter the number of generations (default is 100): ");
    scanf("%d", &generations);

    board = (int**)malloc(size * sizeof(int*));
    next_board = (int**)malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++)
    {
        board[i] = (int*)malloc(size * sizeof(int));
        next_board[i] = (int*)malloc(size * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = 0;
            next_board[i][j] = 0;
        }
    }

    // Simulate the Game of Life
    for (int g = 0; g < generations; g++)
    {
        // Calculate the next generation
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x == 0 && y == 0) continue;
                        if (board[i + x][j + y] == 1) neighbors++;
                    }
                }

                next_board[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            }
        }

        // Copy the next generation to the board
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                board[i][j] = next_board[i][j];
            }
        }

        // Print the board
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            free(board[i][j]);
            free(next_board[i][j]);
        }
        free(board[i]);
        free(next_board[i]);
    }

    free(board);
    free(next_board);

    return 0;
}