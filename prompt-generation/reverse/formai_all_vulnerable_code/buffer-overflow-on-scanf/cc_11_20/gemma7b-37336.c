//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int i, j, x, y;
    char command;
    int drone_x = 0, drone_y = 0;

    printf("Enter Command (F/L/R/B/H/C): ");
    scanf(" %c", &command);

    switch (command)
    {
        case 'F':
            for (i = 0; i < MAX; i++)
            {
                drone_y++;
                printf("Drone position: (%d, %d)\n", drone_x, drone_y);
            }
            break;
        case 'L':
            for (i = 0; i < MAX; i++)
            {
                drone_x--;
                printf("Drone position: (%d, %d)\n", drone_x, drone_y);
            }
            break;
        case 'R':
            for (i = 0; i < MAX; i++)
            {
                drone_x++;
                printf("Drone position: (%d, %d)\n", drone_x, drone_y);
            }
            break;
        case 'B':
            for (i = 0; i < MAX; i++)
            {
                drone_y--;
                printf("Drone position: (%d, %d)\n", drone_x, drone_y);
            }
            break;
        case 'H':
            printf("Height: %d\n", drone_y);
            break;
        case 'C':
            printf("Landing...\n");
            drone_x = 0;
            drone_y = 0;
            break;
        default:
            printf("Invalid Command\n");
            break;
    }

    return 0;
}