//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int n, m, i, j, x, y, path[MAX][MAX], visited[MAX][MAX], startx, starty, endx, endy;

    printf("Welcome to the Mysterious C Maze Route Finder, Mr. Holmes!\n");

    printf("Please provide the dimensions of the maze:");
    scanf("%d %d", &n, &m);

    printf("Enter the starting position of the detective:");
    scanf("%d %d", &startx, &starty);

    printf("Enter the ending position of the detective:");
    scanf("%d %d", &endx, &endy);

    // Create the maze
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            path[i][j] = -1;
            visited[i][j] = 0;
        }
    }

    // Find the route
    x = startx;
    y = starty;
    path[x][y] = 0;
    visited[x][y] = 1;

    while (path[endx][endy] == -1)
    {
        // Move right
        if (visited[x + 1][y] == 0)
        {
            x++;
            path[x][y] = 0;
            visited[x][y] = 1;
        }
        // Move left
        else if (visited[x - 1][y] == 0)
        {
            x--;
            path[x][y] = 0;
            visited[x][y] = 1;
        }
        // Move up
        else if (visited[x][y + 1] == 0)
        {
            y++;
            path[x][y] = 0;
            visited[x][y] = 1;
        }
        // Move down
        else if (visited[x][y - 1] == 0)
        {
            y--;
            path[x][y] = 0;
            visited[x][y] = 1;
        }
    }

    // Print the route
    printf("The detective's route is:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (path[i][j] == 0)
            {
                printf("(%d, %d) ", i, j);
            }
        }
    }

    printf("\nCongratulations, Mr. Holmes, you have solved the mystery!");

    return 0;
}