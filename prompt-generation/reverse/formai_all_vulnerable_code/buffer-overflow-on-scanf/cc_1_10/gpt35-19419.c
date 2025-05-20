//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define FLY_FORWARD 1
#define FLY_BACKWARD 2
#define TURN_RIGHT 3
#define TURN_LEFT 4
#define LAND 5

int main()
{
    int choice;
    int distance, angle;

    printf("Welcome to the C drone remote control program!\n\n");
    printf("Enter your command:\n");
    printf("1 - Fly Forward\n");
    printf("2 - Fly Backward\n");
    printf("3 - Turn Right\n");
    printf("4 - Turn Left\n");
    printf("5 - Land\n");

    while(1) {
        scanf("%d", &choice);

        switch(choice) {
            case FLY_FORWARD:
                printf("Enter the distance to fly forward: ");
                scanf("%d", &distance);
                printf("Flying forward for %d meters...\n", distance);
                break;

            case FLY_BACKWARD:
                printf("Enter the distance to fly backward: ");
                scanf("%d", &distance);
                printf("Flying backward for %d meters...\n", distance);
                break;

            case TURN_RIGHT:
                printf("Enter the angle to turn right: ");
                scanf("%d", &angle);
                printf("Turning right by %d degrees...\n", angle);
                break;

            case TURN_LEFT:
                printf("Enter the angle to turn left: ");
                scanf("%d", &angle);
                printf("Turning left by %d degrees...\n", angle);
                break;

            case LAND:
                printf("Landing the drone...\n");
                exit(0);

            default:
                printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}