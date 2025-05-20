//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main()
{
    int board[MAX][MAX] = {{0}};
    int x, y, n, i, j;

    printf("Enter the number of generations: ");
    scanf("%d", &n);

    // Initialize the board
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Simulate the game for n generations
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            for (x = 0; x < MAX; x++)
            {
                for (y = 0; y < MAX; y++)
                {
                    int neighbors = 0;
                    if (x - 1 >= 0) neighbors++;
                    if (x + 1 < MAX) neighbors++;
                    if (y - 1 >= 0) neighbors++;
                    if (y + 1 < MAX) neighbors++;

                    if (board[x][y] == 1 && neighbors < 2) board[x][y] = 0;
                    else if (board[x][y] == 0 && neighbors == 3) board[x][y] = 1;
                }
            }
        }

        // Print the board
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}