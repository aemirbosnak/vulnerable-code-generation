//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows, cols;
    int generation = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    board = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 0;
        }
    }

    // Game loop
    while (1)
    {
        // Print the board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Calculate the next generation
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                if (board[r][c] == 1 && neighbors < 2)
                {
                    board[r][c] = 0;
                }
                else if (board[r][c] == 0 && neighbors == 3)
                {
                    board[r][c] = 1;
                }
            }
        }

        // Increment the generation
        generation++;

        // Check if the player wants to continue
        printf("Do you want to continue? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N')
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