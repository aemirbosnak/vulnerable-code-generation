//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 10
#define MAX_TURN 90

int main()
{
    int speed = 0;
    int turn = 0;
    char command;

    printf("Welcome to the peaceful remote control vehicle simulation!\n");

    while (1)
    {
        printf("Enter a command (s, d, l, r, q): ");
        scanf("%c", &command);

        switch (command)
        {
            case 's':
                if (speed < MAX_SPEED)
                {
                    speed++;
                    printf("Vehicle speed increased to %d.\n", speed);
                }
                else
                {
                    printf("Vehicle is already traveling at maximum speed.\n");
                }
                break;
            case 'd':
                if (speed > 0)
                {
                    speed--;
                    printf("Vehicle speed decreased to %d.\n", speed);
                }
                else
                {
                    printf("Vehicle is already stopped.\n");
                }
                break;
            case 'l':
                if (turn < MAX_TURN)
                {
                    turn++;
                    printf("Vehicle turn increased to %d degrees.\n", turn);
                }
                else
                {
                    printf("Vehicle is already turning at maximum angle.\n");
                }
                break;
            case 'r':
                if (turn > 0)
                {
                    turn--;
                    printf("Vehicle turn decreased to %d degrees.\n", turn);
                }
                else
                {
                    printf("Vehicle is already straight.\n");
                }
                break;
            case 'q':
                printf("Thank you for playing! Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }
    }

    return 0;
}