//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows, columns;

    // Allocate memory for the board
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    board = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        board[i] = (int *)malloc(columns * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            board[r][c] = 0;
        }
    }

    // Play the game
    int generation = 0;
    while (1)
    {
        // Print the board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Calculate the next generation
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                int num_alive = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            num_alive++;
                        }
                    }
                }

                if (board[r][c] == 1 && num_alive < 2)
                {
                    board[r][c] = 0;
                }
                else if (board[r][c] == 0 && num_alive == 3)
                {
                    board[r][c] = 1;
                }
            }
        }

        // Increment the generation
        generation++;

        // Check if the game is over
        if (generation == 10)
        {
            break;
        }
    }

    // Free the memory
    for (int r = 0; r < rows; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}