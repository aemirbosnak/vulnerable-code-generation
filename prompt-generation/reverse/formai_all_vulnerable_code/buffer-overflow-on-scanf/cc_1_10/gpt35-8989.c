//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100         // Maximum speed of the vehicle
#define MAX_TURN_ANGLE 45     // Maximum angle the vehicle can turn at a time
#define ACCELERATION_RATE 5   // Rate at which the vehicle accelerates
#define DECELERATION_RATE 10  // Rate at which the vehicle decelerates
#define TIMEOUT_PERIOD 30     // Time after which the vehicle stops automatically

int main()
{
    srand(time(0));  // Seed the random number generator
    
    printf("Welcome to the Remote Control Vehicle Simulation!\n");

    int speed = 0;               // Initial speed of the vehicle
    int direction = rand() % 360;  // Initial direction of the vehicle
    int time_remaining = TIMEOUT_PERIOD;

    // Loop until the time runs out
    while (time_remaining > 0)
    {
        printf("Speed: %d mph | Direction: %d degrees\n", speed, direction);
        printf("Enter a command (f=forward,r=right,l=left,b=brake): ");

        char command;
        scanf(" %c", &command);

        switch (command)
        {
            case 'f':
                speed += ACCELERATION_RATE;
                if (speed > MAX_SPEED)
                    speed = MAX_SPEED;
                break;
            case 'r':
                direction += (rand() % MAX_TURN_ANGLE) + 1;
                direction %= 360;
                break;
            case 'l':
                direction -= (rand() % MAX_TURN_ANGLE) + 1;
                direction += 360;
                direction %= 360;
                break;
            case 'b':
                speed -= DECELERATION_RATE;
                if (speed < 0)
                    speed = 0;
                break;
            default:
                printf("Invalid command!\n");
        }

        // Decrement the time remaining
        time_remaining--;

        // If the speed is 0, reset the time remaining to the initial value
        if (speed == 0)
            time_remaining = TIMEOUT_PERIOD;

        printf("\n");
    }

    // Time's up!
    printf("Time's up! Vehicle stopped.\n");

    return 0;
}