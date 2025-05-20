//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void draw_maze(int **maze, int n, int m);
int main()
{
    int n, m, i, j;
    int **maze;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    maze = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        maze[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the maze layout (1 for wall, 0 for path):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }

    draw_maze(maze, n, m);

    return 0;
}

void draw_maze(int **maze, int n, int m)
{
    int i, j;

    printf("Your maze:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (maze[i][j] == 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}