//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void generateMaze(int **maze, int n, int m)
{
    int i, j, r, c;
    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            maze[i][j] = rand() % MAX;
        }
    }

    r = rand() % n;
    c = rand() % m;

    maze[r][c] = 0;
    maze[r][c - 1] = 0;
    maze[r][c + 1] = 0;
    maze[r - 1][c] = 0;
    maze[r + 1][c] = 0;
}

int main()
{
    int n, m, **maze;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    maze = (int *)malloc(n * m * sizeof(int));

    generateMaze(maze, n, m);

    printf("The maze is:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}