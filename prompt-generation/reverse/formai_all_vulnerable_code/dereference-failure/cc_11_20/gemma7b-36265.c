//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Allocate memory for the game board
    int **board = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++)
    {
        board[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initialize the game board
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Game loop
    while (1)
    {
        // Print the game board
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Calculate the number of neighbors for each cell
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                int neighbors = 0;
                // Check the four neighboring cells
                if (board[i - 1][j] == 1) neighbors++;
                if (board[i + 1][j] == 1) neighbors++;
                if (board[i][j - 1] == 1) neighbors++;
                if (board[i][j + 1] == 1) neighbors++;

                // Update the cell's state based on the number of neighbors
                if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
                if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) board[i][j] = 0;
            }
        }

        // Pause the game
        printf("Press any key to continue...");
        getchar();

        // Free the memory allocated for the game board
        for (int i = 0; i < HEIGHT; i++)
        {
            free(board[i]);
        }
        free(board);

        // Check if the player wants to continue
        if (rand() % 2 == 0) break;
    }

    return 0;
}