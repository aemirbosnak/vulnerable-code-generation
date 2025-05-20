//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 10
#define MAX_TURN 90

int main()
{
    int speed = 0;
    int turn = 0;
    char command = '\0';

    while (command != 'q')
    {
        printf("Enter command (w, a, s, d, q): ");
        scanf("%c", &command);

        switch (command)
        {
            case 'w':
                speed++;
                if (speed > MAX_SPEED)
                {
                    speed = MAX_SPEED;
                }
                break;
            case 'a':
                turn--;
                if (turn < -MAX_TURN)
                {
                    turn = -MAX_TURN;
                }
                break;
            case 's':
                speed--;
                if (speed < 0)
                {
                    speed = 0;
                }
                break;
            case 'd':
                turn++;
                if (turn > MAX_TURN)
                {
                    turn = MAX_TURN;
                }
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        printf("Speed: %d, Turn: %d\n", speed, turn);
    }

    return 0;
}