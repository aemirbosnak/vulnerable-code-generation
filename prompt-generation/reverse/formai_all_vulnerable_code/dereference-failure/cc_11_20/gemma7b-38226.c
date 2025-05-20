//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 21
#define HEIGHT 21

int main()
{
    int x, y, i, j, r, c, b, a, n;
    int **maze = NULL;
    int **visited = NULL;

    n = WIDTH * HEIGHT;
    maze = (int**)malloc(n * sizeof(int*));
    visited = (int**)malloc(n * sizeof(int*));

    for(i = 0; i < n; i++)
    {
        maze[i] = (int*)malloc(WIDTH * sizeof(int));
        visited[i] = (int*)malloc(WIDTH * sizeof(int));
    }

    r = rand() % WIDTH;
    c = rand() % HEIGHT;
    visited[r][c] = 1;

    for(x = 0; x < HEIGHT; x++)
    {
        for(y = 0; y < WIDTH; y++)
        {
            if(visited[x][y] == 0)
            {
                a = rand() % 4;
                switch(a)
                {
                    case 0:
                        maze[x][y] = 1;
                        break;
                    case 1:
                        maze[x][y] = 2;
                        break;
                    case 2:
                        maze[x][y] = 3;
                        break;
                    case 3:
                        maze[x][y] = 4;
                        break;
                }
            }
        }
    }

    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}