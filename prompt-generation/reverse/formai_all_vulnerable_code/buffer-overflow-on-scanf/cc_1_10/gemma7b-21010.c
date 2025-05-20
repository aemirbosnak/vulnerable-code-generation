//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void DroneCtrl(int current_state)
{
    switch (current_state)
    {
        case 0:
            printf("Current State: IDLE\n");
            printf("Enter Command (Land/TakeOff/Move): ");
            char command;
            scanf(" %c", &command);

            switch (command)
            {
                case 'L':
                    current_state = 1;
                    DroneCtrl(current_state);
                    break;
                case 'T':
                    current_state = 2;
                    DroneCtrl(current_state);
                    break;
                case 'M':
                    printf("Enter Direction (N/S/E/W): ");
                    char direction;
                    scanf(" %c", &direction);

                    printf("Enter Distance: ");
                    int distance;
                    scanf(" %d", &distance);

                    // Move Drone
                    break;
            }
            break;
        case 1:
            printf("Current State: LANDING\n");
            break;
        case 2:
            printf("Current State: TAKEOFF\n");
            break;
    }
}

int main()
{
    DroneCtrl(0);

    return 0;
}