//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 100
#define MIN_SPEED 50

int main()
{
    printf("Welcome to Drone Remote Control\n");
    printf("-----------------------------\n");

    bool isOn = false;
    int speed = 0;

    while (true)
    {
        char input;
        printf("\nEnter command (o: on, f: off, +: increase speed, -: decrease speed): ");
        scanf("%c", &input);

        switch (input)
        {
            case 'o':
                printf("Turning drone on...\n");
                isOn = true;
                break;
            case 'f':
                printf("Turning drone off...\n");
                isOn = false;
                break;
            case '+':
                if (isOn)
                {
                    if (speed < MAX_SPEED)
                    {
                        speed += 10;
                        printf("Increasing speed to %d...\n", speed);
                    }
                    else
                    {
                        printf("Maximum speed reached\n");
                    }
                }
                else
                {
                    printf("Drone is off, please turn it on first\n");
                }
                break;
            case '-':
                if (isOn)
                {
                    if (speed > MIN_SPEED)
                    {
                        speed -= 10;
                        printf("Decreasing speed to %d...\n", speed);
                    }
                    else
                    {
                        printf("Minimum speed reached\n");
                    }
                }
                else
                {
                    printf("Drone is off, please turn it on first\n");
                }
                break;
            default:
                printf("Invalid command\n");
                break;
        }

        // clear input buffer
        while ((getchar()) != '\n');
    }

    return 0;
}