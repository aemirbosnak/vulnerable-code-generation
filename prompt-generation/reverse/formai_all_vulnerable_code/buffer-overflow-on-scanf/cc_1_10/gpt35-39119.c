//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for controlling the drone
#define MAX_SPEED 100
#define MAX_ANGLE 90
#define MAX_HEIGHT 100

// Function for flying the drone
void flyDrone(int speed, int angle, int height);

int main()
{
    int speed = 0;
    int angle = 0;
    int height = 0;

    printf("Welcome to the Retro Drone Remote Control!\n\n");
    printf("Type 'help' for a list of commands.\n\n");

    while (1)
    {
        char userInput[256];
        printf("> ");
        scanf("%s", userInput);

        if (strcmp(userInput, "exit") == 0)
        {
            break;
        }

        if (strcmp(userInput, "help") == 0)
        {
            printf("Available Commands:\n");
            printf("help - display this help message\n");
            printf("fly - control the drone (speed,angle,height)\n");
            printf("exit - exit the program\n\n");
        }

        if (strcmp(userInput, "fly") == 0)
        {
            printf("Enter speed (0-%d): ", MAX_SPEED);
            scanf("%d", &speed);

            printf("Enter angle (-%d to %d): ", MAX_ANGLE, MAX_ANGLE);
            scanf("%d", &angle);

            printf("Enter height (0-%d): ", MAX_HEIGHT);
            scanf("%d", &height);

            if (speed < 0 || speed > MAX_SPEED || angle < -MAX_ANGLE || angle > MAX_ANGLE || height < 0 || height > MAX_HEIGHT)
            {
                printf("Invalid input! Please try again.\n\n");
                continue;
            }

            flyDrone(speed, angle, height);
        }
    }

    printf("\nGoodbye!\n");

    return 0;
}

void flyDrone(int speed, int angle, int height)
{
    printf("\nFlying drone...\n");
    printf("Speed: %d\n", speed);
    printf("Angle: %d\n", angle);
    printf("Height: %d\n\n", height);
}