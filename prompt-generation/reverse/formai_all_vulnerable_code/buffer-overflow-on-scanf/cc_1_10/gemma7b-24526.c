//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void draw_maze(int **maze, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == 1)
            {
                printf("%c ", '#');
            }
            else
            {
                printf("%c ", '.');
            }
        }
        printf("\n");
    }
}

int main()
{
    int n, m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int **maze = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        maze[i] = (int *)malloc(m * sizeof(int));
    }

    // Generate the maze
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }

    // Draw the maze
    draw_maze(maze, n, m);

    return 0;
}