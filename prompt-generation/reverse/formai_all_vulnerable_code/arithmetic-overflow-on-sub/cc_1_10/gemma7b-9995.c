//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

int main()
{
    int speed = 0;
    int direction = 1;
    char key;

    // Initialize timer
    time_t start_time = time(NULL);
    time_t end_time = start_time + 1;

    // Game loop
    while (1)
    {
        // Check for key press
        key = getchar();

        // Control car
        switch (key)
        {
            case 'w':
                speed = MAX_SPEED;
                direction = 1;
                break;
            case 'a':
                speed = MAX_SPEED;
                direction = -1;
                break;
            case 's':
                speed = 0;
                direction = 0;
                break;
            case 'd':
                speed = MAX_SPEED;
                direction = 1;
                break;
            default:
                speed = 0;
                direction = 0;
                break;
        }

        // Update car position
        speed *= direction;
        // Simulate driving
        printf("Car is moving at %d km/h in direction %d.\n", speed, direction);

        // Check if time is up
        if (time(NULL) - start_time >= end_time)
        {
            // End game
            break;
        }
    }

    // End program
    return 0;
}