//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 10
#define MAX_TURN 90

int main()
{
    int speed = 0;
    int turn = 0;
    char command = ' ';

    while (command != 'q')
    {
        printf("Enter command (s, t, l, r, q): ");
        scanf(" %c", &command);

        switch (command)
        {
            case 's':
                speed++;
                if (speed > MAX_SPEED)
                    speed = MAX_SPEED;
                break;
            case 't':
                turn++;
                if (turn > MAX_TURN)
                    turn = MAX_TURN;
                break;
            case 'l':
                speed--;
                if (speed < 0)
                    speed = 0;
                break;
            case 'r':
                turn--;
                if (turn < 0)
                    turn = 0;
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