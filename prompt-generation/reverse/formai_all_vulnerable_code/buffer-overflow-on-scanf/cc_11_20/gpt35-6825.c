//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variables
    int speed = 0;
    int direction = 0;
    int battery_level = 100;
    int distance_traveled = 0;
    int speed_limit = 30;
    int battery_threshold_1 = 20;
    int battery_threshold_2 = 10;
    srand(time(0)); // Seed random generator with time to get different random numbers on each run
    
    // Main loop
    while (battery_level > 0 && distance_traveled < 2000)
    {
        // Display interface
        printf("Remote Control Vehicle Simulation\n");
        printf("=================================\n");
        printf("Speed: %d mph\n", speed);
        printf("Direction: %d degrees\n", direction);
        printf("Battery level: %d%%\n", battery_level);
        printf("Distance traveled: %d feet\n", distance_traveled);
        
        // Get user input
        char command;
        printf("\nEnter command (F = Forward, B = Backward, L = Turn Left, R = Turn Right, Q = Quit): ");
        scanf(" %c", &command);
        
        // Execute command
        switch (command)
        {
            case 'F':
                printf("Going forward...\n");
                speed = rand() % speed_limit + 1;
                direction = rand() % 360;
                distance_traveled += speed;
                battery_level -= speed / 10;
                break;
            case 'B':
                printf("Going backward...\n");
                speed = rand() % speed_limit + 1;
                direction = rand() % 360;
                distance_traveled -= speed;
                battery_level -= speed / 10;
                break;
            case 'L':
                printf("Turning left...\n");
                direction -= 90;
                break;
            case 'R':
                printf("Turning right...\n");
                direction += 90;
                break;
            case 'Q':
                printf("Quitting...\n");
                return 0;
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
        
        // Check battery level
        if (battery_level <= battery_threshold_1 && battery_level > battery_threshold_2)
        {
            printf("Warning: Low battery level (%d%%).\n", battery_level);
        }
        else if (battery_level <= battery_threshold_2)
        {
            printf("Error: Very low battery level (%d%%). Aborting.\n", battery_level);
            return 1;
        }
        
        // Sleep for one second to simulate real time
        printf("=================================\n");
        sleep(1);
    }
    
    // End of simulation
    if (battery_level <= 0)
    {
        printf("Error: Battery depleted. Aborting.\n");
    }
    else
    {
        printf("Congratulations! You have completed the simulation.\n");
    }
    
    return 0;
}