#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_DIR 90

int main()
{
    int speed = 0;
    int direction = 0;
    int distance = 0;
    int elapsedTime = 0;

    char input;

    clock_t startTime = clock();

    while (1)
    {
        printf("Enter command (a/d/r/q): ");
        scanf(" %c", &input);

        switch (input)
        {
            case 'a':
                if (speed < MAX_SPEED)
                {
                    speed++;
                }
                break;
            case 'd':
                if (speed > 0)
                {
                    speed--;
                }
                break;
            case 'r':
                direction = (direction + 90) % MAX_DIR;
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid command.\n");
        }

        elapsedTime = clock() - startTime;
        distance += speed * elapsedTime / CLOCKS_PER_SEC;

        printf("Distance traveled: %d meters.\n", distance);
    }

    return 0;
}
