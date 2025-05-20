//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int x, y, i, j, maze[MAX][MAX], visited[MAX][MAX];

    // Initialize the maze and visited cells
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            maze[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    // Create the maze
    maze[0][0] = 1;
    maze[0][1] = 1;
    maze[0][2] = 1;
    maze[1][0] = 1;
    maze[1][1] = 1;
    maze[1][2] = 1;
    maze[2][0] = 1;
    maze[2][1] = 1;
    maze[2][2] = 1;

    // Find the route
    visited[0][0] = 1;
    x = 0;
    y = 0;
    while (!visited[MAX - 1][MAX - 1])
    {
        // Move right
        if (maze[x + 1][y] && !visited[x + 1][y])
        {
            x++;
            visited[x][y] = 1;
        }
        // Move down
        else if (maze[x][y + 1] && !visited[x][y + 1])
        {
            y++;
            visited[x][y] = 1;
        }
        // Move left
        else if (maze[x - 1][y] && !visited[x - 1][y])
        {
            x--;
            visited[x][y] = 1;
        }
        // Move up
        else if (maze[x][y - 1] && !visited[x][y - 1])
        {
            y--;
            visited[x][y] = 1;
        }
    }

    // Print the route
    printf("The route is:");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (visited[i][j] == 1)
            {
                printf("(%d, %d) ", i, j);
            }
        }
    }

    return 0;
}