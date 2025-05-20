//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int **board = NULL;
    int x, y;

    printf("Enter the dimensions of the board (e.g. 5 5): ");
    scanf("%d %d", &x, &y);

    board = (int **)malloc(x * sizeof(int *) + y * sizeof(int));
    for (int i = 0; i < x; i++)
    {
        board[i] = (int *)malloc(y * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            board[i][j] = 0;
        }
    }

    // Play the game
    while (1)
    {
        printf("Enter the move (e.g. 1 1): ");
        scanf("%d %d", &x, &y);

        // Check if the move is valid
        if (x < 0 || x >= x || y < 0 || y >= y)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the cell is alive
        if (board[x][y] == 1)
        {
            printf("Cell is already alive.\n");
            continue;
        }

        // Calculate the number of neighbors
        int neighbors = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }

                if (board[x + i][y + j] == 1)
                {
                    neighbors++;
                }
            }
        }

        // Check if the cell should be alive
        if (neighbors == 3)
        {
            board[x][y] = 1;
        }

        // Print the board
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Check if the player wants to continue
        printf("Do you want to continue? (Y/N): ");
        char answer;
        scanf("%c", &answer);

        if (answer == 'N')
        {
            break;
        }
    }

    // Free the board
    for (int i = 0; i < x; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}