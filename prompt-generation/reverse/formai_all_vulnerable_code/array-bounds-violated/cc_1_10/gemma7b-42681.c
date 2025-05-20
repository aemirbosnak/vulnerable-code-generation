//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Maze structure
    int maze[5][5] = {
        { 0, 1, 0, 0, 0 },
        { 1, 1, 0, 0, 0 },
        { 0, 1, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0 }
    };

    // Current position of the rover
    int x = 0;
    int y = 0;

    // Direction of the rover
    int dx = 1;
    int dy = 0;

    // Goal position
    int goal_x = 2;
    int goal_y = 2;

    // Loop until the rover reaches the goal
    while (x != goal_x || y != goal_y)
    {
        // Move the rover
        x += dx;
        y += dy;

        // If the rover has reached the goal, break out of the loop
        if (x == goal_x && y == goal_y)
        {
            break;
        }

        // If the rover has reached a wall, change direction
        if (maze[x][y] == 1)
        {
            dx *= -1;
            dy = 0;
        }

        // Print the maze
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%d ", maze[i][j]);
            }
            printf("\n");
        }

        // Print the rover's position
        printf("Rover: (%d, %d)\n", x, y);

        // Pause the program
        system("pause");
    }

    // Print a message when the rover reaches the goal
    printf("Rover has reached the goal!\n");

    return 0;
}