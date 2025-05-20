//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: invasive
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
    int **board = (int **)malloc(WIDTH * sizeof(int *));
    for (int i = 0; i < WIDTH; i++)
    {
        board[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the board
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            board[x][y] = rand() % 2;
        }
    }

    // Game loop
    while (1)
    {
        // Check if any cells need to be flipped
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                int num_neighbors = 0;
                // Check the four neighbors
                if (x > 0) num_neighbors++;
                if (x < WIDTH - 1) num_neighbors++;
                if (y > 0) num_neighbors++;
                if (y < HEIGHT - 1) num_neighbors++;

                // If the cell is alive and has fewer than 2 neighbors, it dies
                if (board[x][y] && num_neighbors < 2) board[x][y] = 0;

                // If the cell is dead and has exactly 2 neighbors, it comes back to life
                if (!board[x][y] && num_neighbors == 2) board[x][y] = 1;
            }
        }

        // Print the board
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                printf("%d ", board[x][y]);
            }
            printf("\n");
        }

        // Pause the game
        system("pause");
    }

    // Free the memory
    for (int i = 0; i < WIDTH; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}