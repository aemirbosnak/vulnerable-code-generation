//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    board = (int**)malloc(rows * sizeof(int*));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int*)malloc(cols * sizeof(int));
    }

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("Enter the initial state of the cell at (%d, %d) (0/1): ", r, c);
            scanf("%d", &board[r][c]);
        }
    }

    // Game loop
    int generation = 0;
    while (1)
    {
        // Calculate the next generation
        int **next_board = (int**)malloc(rows * sizeof(int*));
        for (int r = 0; r < rows; r++)
        {
            next_board[r] = (int*)malloc(cols * sizeof(int));
        }

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

                next_board[r][c] = (neighbors == 2) || (neighbors == 3) ? 1 : 0;
            }
        }

        // Print the next generation
        printf("Generation %d:\n", generation);
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", next_board[r][c]);
            }
            printf("\n");
        }

        // Free the previous generation
        for (int r = 0; r < rows; r++)
        {
            free(board[r]);
        }
        free(board);

        // Check if the player wants to continue
        char continue_or_not;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continue_or_not);

        if (continue_or_not == 'N')
        {
            break;
        }

        // Increment the generation number
        generation++;
    }

    return 0;
}