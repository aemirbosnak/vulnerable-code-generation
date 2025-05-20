//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int n, m, i, j, x, y;
    int maze[MAX][MAX] = {{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                            };

    printf("Enter the starting position (x, y): ");
    scanf("%d %d", &x, &y);

    printf("Enter the target position (x, y): ");
    scanf("%d %d", &i, &j);

    if (maze[x][y] == 1 && maze[i][j] == 1)
    {
        printf("The path is found!\n");

        // Traversal algorithm
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        x = y;
        while (x != i || y != j)
        {
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (maze[nx][ny] == 0 && nx >= 0 && ny >= 0 && nx < m && ny < n)
                {
                    maze[nx][ny] = 2;
                    x = nx;
                    y = ny;
                    break;
                }
            }
        }

        // Print the path
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                printf("%d ", maze[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("No path found.\n");
    }

    return 0;
}