//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Define variables
    char command = 's';
    int x_pos = 0;
    int y_pos = 0;

    // Generate random obstacles
    srand(time(NULL));
    int num_obstacles = rand() % 5 + 1;
    int obstacles_x[num_obstacles];
    int obstacles_y[num_obstacles];

    // Randomly place obstacles
    for(int i = 0; i < num_obstacles; i++)
    {
        obstacles_x[i] = rand() % 10;
        obstacles_y[i] = rand() % 10;
    }

    // Instructions
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Use the following commands to move your vehicle:\n");
    printf("f - move forward\n");
    printf("b - move backward\n");
    printf("l - turn left\n");
    printf("r - turn right\n");
    printf("s - stop\n");
    printf("q - quit\n");

    // Game loop
    while(command != 'q')
    {
        // Print current location
        printf("Vehicle is currently at position (%d,%d)\n", x_pos, y_pos);

        // Check for obstacles
        for(int i = 0; i < num_obstacles; i++)
        {
            if(x_pos == obstacles_x[i] && y_pos == obstacles_y[i])
            {
                printf("WARNING: Obstacle at position (%d,%d)!\n", x_pos, y_pos);
            }
        }

        // Get command from user
        printf("Enter your command: ");
        scanf(" %c", &command);

        // Execute command
        switch(command)
        {
            case 'f':
                y_pos++;
                break;
            case 'b':
                y_pos--;
                break;
            case 'l':
                x_pos--;
                break;
            case 'r':
                x_pos++;
                break;
            case 's':
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
    }

    return 0;
}