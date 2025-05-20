//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main()
{
    int **maze = NULL;
    int **visited = NULL;
    int x, y, dx, dy, i, j, seed, steps = 0;
    char direction = ' ';

    // Allocate memory for the maze and visited cells
    maze = (int**)malloc(MAX * sizeof(int*));
    visited = (int**)malloc(MAX * sizeof(int*));
    for (i = 0; i < MAX; i++)
    {
        maze[i] = (int*)malloc(MAX * sizeof(int));
        visited[i] = (int*)malloc(MAX * sizeof(int));
    }

    // Seed the random number generator
    seed = time(NULL);
    srand(seed);

    // Generate the maze
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }

    // Initialize the visited cells
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            visited[i][j] = 0;
        }
    }

    // Start at the center of the maze
    x = MAX / 2;
    y = MAX / 2;

    // Loop until the exit cell is found or a wall is reached
    while (!visited[x][y] && maze[x][y] != 1)
    {
        // Choose a random direction
        dx = rand() % 4 - 1;
        dy = rand() % 4 - 1;

        // Move in the chosen direction
        x += dx;
        y += dy;

        // Mark the cell as visited
        visited[x][y] = 1;

        // Increment the number of steps
        steps++;

        // Change the direction if necessary
        if (dx == 0)
        {
            direction = 'N';
        }
        else if (dy == 0)
        {
            direction = 'E';
        }
        else if (dx == 1)
        {
            direction = 'S';
        }
        else if (dy == 1)
        {
            direction = 'W';
        }
    }

    // Print the number of steps and the direction taken
    printf("Number of steps: %d\n", steps);
    printf("Direction taken: %c\n", direction);

    // Free the memory allocated for the maze and visited cells
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            free(maze[i][j]);
            free(visited[i][j]);
        }
        free(maze[i]);
        free(visited[i]);
    }

    return 0;
}