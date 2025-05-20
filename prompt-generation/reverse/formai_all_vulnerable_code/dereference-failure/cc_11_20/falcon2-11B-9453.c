//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int n, m, i, j, k;
    int *board, *neighbors;
    int *visited;
    int *status;
    int *seed;

    srand(time(NULL));

    printf("Enter the size of the board (n): ");
    scanf("%d", &n);
    printf("Enter the number of seeds (m): ");
    scanf("%d", &m);

    board = (int *)malloc(n * sizeof(int));
    neighbors = (int *)malloc(n * sizeof(int));
    visited = (int *)malloc(n * sizeof(int));
    status = (int *)malloc(n * sizeof(int));
    seed = (int *)malloc(m * sizeof(int));

    for (i = 0; i < n; i++)
    {
        board[i] = rand() % 2;
        visited[i] = 0;
        status[i] = 0;
    }

    for (i = 0; i < m; i++)
    {
        seed[i] = rand() % n;
    }

    for (i = 0; i < n; i++)
    {
        neighbors[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                neighbors[i]++;
            }
            else
            {
                neighbors[i] += board[j];
            }
        }
    }

    for (i = 0; i < m; i++)
    {
        status[seed[i]] = 1;
        visited[seed[i]] = 1;
    }

    for (k = 0; k < n; k++)
    {
        if (status[k] == 0 && visited[k] == 0)
        {
            for (j = 0; j < n; j++)
            {
                if (board[k] == board[j] && visited[j] == 0)
                {
                    visited[j] = 1;
                    status[j] = 1;
                    neighbors[j]--;
                }
            }
        }
    }

    printf("Percolation simulation results:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", status[i]);
    }
    printf("\n");

    free(board);
    free(neighbors);
    free(visited);
    free(status);
    free(seed);

    return 0;
}