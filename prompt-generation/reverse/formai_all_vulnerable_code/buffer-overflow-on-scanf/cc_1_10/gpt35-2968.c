//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 1000
#define MIN_SPEED 0
#define STEP_SIZE 50

int main()
{
    int speed = MIN_SPEED;
    char command;

    printf("Welcome to the C Drone Remote Control Program\n");
    printf("Use the following commands to control the drone:\n");
    printf("u: increase speed\n");
    printf("d: decrease speed\n");
    printf("s: stop the drone\n");
    printf("q: quit the program\n");

    while (1)
    {
        printf("Current speed: %d\n", speed);
        printf("Enter command: ");
        scanf(" %c", &command);

        switch (command)
        {
            case 'u':
            {
                if (speed + STEP_SIZE <= MAX_SPEED)
                {
                    speed += STEP_SIZE;
                    printf("Speed increased to %d.\n", speed);
                }
                else
                {
                    printf("Maximum speed reached.\n");
                }
                break;
            }
            case 'd':
            {
                if (speed - STEP_SIZE >= MIN_SPEED)
                {
                    speed -= STEP_SIZE;
                    printf("Speed decreased to %d.\n", speed);
                }
                else
                {
                    printf("Minimum speed reached.\n");
                }
                break;
            }
            case 's':
            {
                speed = MIN_SPEED;
                printf("Drone stopped.\n");
                break;
            }
            case 'q':
            {
                printf("Quitting the program...\n");
                exit(0);
            }
            default:
            {
                printf("Invalid command. Please try again.\n");
            }
        }
    }

    return 0;
}