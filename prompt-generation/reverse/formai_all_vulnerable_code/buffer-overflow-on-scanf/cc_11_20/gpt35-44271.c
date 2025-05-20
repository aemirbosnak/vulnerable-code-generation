//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 300            // maximum height the drone can fly
#define MIN_HEIGHT 0              // minimum height the drone can fly
#define MAX_DISTANCE 500          // maximum distance the drone can fly
#define MIN_DISTANCE 0            // minimum distance the drone can fly
#define MAX_BATTERY_LEVEL 100     // maximum battery level of the drone
#define MIN_BATTERY_LEVEL 0       // minimum battery level of the drone
#define BATTERY_CONSUMPTION_RATE 2 // battery consumption rate in percent
#define MOVE_UP 1                 // move up command
#define MOVE_DOWN 2               // move down command
#define MOVE_FORWARD 3            // move forward command
#define MOVE_BACKWARD 4           // move backward command
#define TURN_LEFT 5               // turn left command
#define TURN_RIGHT 6              // turn right command
#define LAND 7                    // land command
#define QUIT 8                    // quit command

int main()
{
    int height = MIN_HEIGHT;           // initialize height to minimum height
    int distance = MIN_DISTANCE;       // initialize distance to minimum distance
    int battery_level = MAX_BATTERY_LEVEL; // initialize battery level to maximum level
    int command = 0;                   // initialize command to 0

    printf("Welcome to C Drone Remote Control!\n");
    printf("Please input one of the following commands:\n");
    printf("1: Move up\n");
    printf("2: Move down\n");
    printf("3: Move forward\n");
    printf("4: Move backward\n");
    printf("5: Turn left\n");
    printf("6: Turn right\n");
    printf("7: Land\n");
    printf("8: Quit\n");

    while (command != QUIT)
    {
        printf("\n\nCurrent height: %d\n", height);
        printf("Current distance: %d\n", distance);
        printf("Current battery level: %d%%\n", battery_level);

        printf("Please enter a command: ");
        scanf("%d", &command);

        switch (command)
        {
            case MOVE_UP:
                if (height < MAX_HEIGHT)
                    height++;
                else
                    printf("The drone cannot go any higher.\n");
                break;

            case MOVE_DOWN:
                if (height > MIN_HEIGHT)
                    height--;
                else
                    printf("The drone cannot go any lower.\n");
                break;

            case MOVE_FORWARD:
                if (distance < MAX_DISTANCE)
                    distance++;
                else
                    printf("The drone cannot go any further.\n");
                break;

            case MOVE_BACKWARD:
                if (distance > MIN_DISTANCE)
                    distance--;
                else
                    printf("The drone cannot go any closer.\n");
                break;

            case TURN_LEFT:
                printf("The drone turns left.\n");
                break;

            case TURN_RIGHT:
                printf("The drone turns right.\n");
                break;

            case LAND:
                printf("The drone lands safely.\n");
                height = MIN_HEIGHT;
                break;

            case QUIT:
                printf("Thank you for using the C Drone Remote Control!\n");
                break;

            default:
                printf("Invalid command.\n");
                break;
        }

        // simulate battery consumption
        battery_level -= BATTERY_CONSUMPTION_RATE;

        // check battery level
        if (battery_level < MIN_BATTERY_LEVEL)
        {
            printf("The drone has run out of battery.\n");
            command = QUIT;
        }
    }

    return 0;
}