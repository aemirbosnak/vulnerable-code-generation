//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    printf("Welcome to the Puzzling Game of Life!\n");
    printf("Please enter the number of generations you want to simulate:");
    scanf("%d", &n);

    printf("Creating the game board...\n");
    int **board = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Initializing the cells...\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    printf("Simulating the game...\n");
    for(k = 0; k < n; k++)
    {
        for(l = 0; l < m; l++)
        {
            int neighbors = 0;
            for(o = -1; o <= 1; o++)
            {
                for(p = -1; p <= 1; p++)
                {
                    if(board[o][p] == 1 && (o != 0 || p != 0))
                    {
                        neighbors++;
                    }
                }
            }

            if(board[l][k] == 1 && neighbors < 2)
            {
                board[l][k] = 0;
            }
            else if(board[l][k] == 0 && neighbors == 2)
            {
                board[l][k] = 1;
            }
        }
    }

    printf("Displaying the final board...\n");
    for(q = 0; q < n; q++)
    {
        for(r = 0; r < m; r++)
        {
            printf("%d ", board[q][r]);
        }
        printf("\n");
    }

    printf("Thank you for playing the Puzzling Game of Life!\n");

    return 0;
}