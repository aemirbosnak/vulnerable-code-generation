//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
    int **board = (int **)malloc(WIDTH * sizeof(int *)), i, j;

    for (i = 0; i < WIDTH; i++)
    {
        board[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the board
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Game loop
    while (1)
    {
        // Calculate the next generation
        for (i = 0; i < WIDTH; i++)
        {
            for (j = 0; j < HEIGHT; j++)
            {
                int neighbors = 0;
                if (i > 0) neighbors++;
                if (i < WIDTH - 1) neighbors++;
                if (j > 0) neighbors++;
                if (j < HEIGHT - 1) neighbors++;

                if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
                if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
            }
        }

        // Print the board
        for (i = 0; i < WIDTH; i++)
        {
            for (j = 0; j < HEIGHT; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Pause
        system("pause");
    }

    // Free the memory
    for (i = 0; i < WIDTH; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}