//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: mathematical
#include <stdlib.h>
#include <time.h>

#define MAX_MAZE_SIZE 10

int main()
{
    int size = rand() % MAX_MAZE_SIZE + 1;
    int **maze = malloc(size * sizeof(int *)), i, j;

    for (i = 0; i < size; i++)
    {
        maze[i] = malloc(size * sizeof(int));
        for (j = 0; j < size; j++)
        {
            maze[i][j] = 0;
        }
    }

    // Generate the maze
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i == 0 || j == 0)
            {
                maze[i][j] = 1;
            }
            else if (rand() % 2 == 0)
            {
                maze[i][j] = 1;
            }
        }
    }

    // Print the maze
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < size; i++)
    {
        free(maze[i]);
    }
    free(maze);

    return 0;
}