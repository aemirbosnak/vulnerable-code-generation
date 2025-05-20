//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array to store the maze
    int **maze = NULL;
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    maze = malloc(rows * sizeof(int *) + cols * sizeof(int));
    for (int r = 0; r < rows; r++)
    {
        maze[r] = malloc(cols * sizeof(int));
    }

    // Generate the maze
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            maze[r][c] = rand() % 2;
        }
    }

    // Print the maze
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", maze[r][c]);
        }
        printf("\n");
    }

    // Free the memory allocated for the maze
    for (int r = 0; r < rows; r++)
    {
        free(maze[r]);
    }
    free(maze);

    return 0;
}