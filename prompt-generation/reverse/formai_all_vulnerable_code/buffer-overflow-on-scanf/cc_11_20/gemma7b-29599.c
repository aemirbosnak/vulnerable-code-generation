//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTROLS 5

#define LEFT_CONTROL 0
#define RIGHT_CONTROL 1
#define FORWARD_CONTROL 2
#define BACKWARD_CONTROL 3
#define STOP_CONTROL 4

int main()
{
    int controls = MAX_CONTROLS;
    char input[2];

    while (1)
    {
        printf("Enter command (L/R/F/B/S): ");
        scanf("%s", input);

        switch (input[0])
        {
            case 'L':
                controls = LEFT_CONTROL;
                break;
            case 'R':
                controls = RIGHT_CONTROL;
                break;
            case 'F':
                controls = FORWARD_CONTROL;
                break;
            case 'B':
                controls = BACKWARD_CONTROL;
                break;
            case 'S':
                controls = STOP_CONTROL;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Control the drone
        switch (controls)
        {
            case LEFT_CONTROL:
                printf("Moving left.\n");
                break;
            case RIGHT_CONTROL:
                printf("Moving right.\n");
                break;
            case FORWARD_CONTROL:
                printf("Moving forward.\n");
                break;
            case BACKWARD_CONTROL:
                printf("Moving backward.\n");
                break;
            case STOP_CONTROL:
                printf("Stopped.\n");
                break;
        }
    }

    return 0;
}