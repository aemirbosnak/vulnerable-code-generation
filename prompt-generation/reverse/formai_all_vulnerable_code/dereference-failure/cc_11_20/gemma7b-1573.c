//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, x, y, i, j, k;
    system("clear");
    printf("Welcome to the Morphing Maze!\n");

    // Create a 2D array to store the maze
    int **maze = (int **)malloc(5 * sizeof(int *));
    for (i = 0; i < 5; i++)
    {
        maze[i] = (int *)malloc(5 * sizeof(int));
    }

    // Initialize the maze
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            maze[i][j] = 0;
        }
    }

    // Place the obstacles in the maze
    maze[2][2] = 1;
    maze[3][3] = 1;

    // Get the player's starting position
    printf("Enter your starting position (x, y): ");
    scanf("%d %d", &x, &y);

    // Move the player
    printf("Enter your direction (N, S, E, W): ");
    scanf("%c", &choice);

    // While the player is not in the maze or has not reached the goal, continue
    while (maze[x][y] == 0 && x != 4 && y != 4)
    {
        system("clear");
        printf("You are in the morphing maze.\n");

        // Print the maze
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (maze[i][j] == 1)
                {
                    printf("# ");
                }
                else
                {
                    printf(". ");
                }
            }
            printf("\n");
        }

        // Move the player
        switch (choice)
        {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
        }

        // Get the player's direction
        printf("Enter your direction (N, S, E, W): ");
        scanf("%c", &choice);
    }

    // You have reached the goal!
    system("clear");
    printf("Congratulations! You have completed the morphing maze.");

    return 0;
}