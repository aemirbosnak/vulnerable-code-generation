//FormAI DATASET v1.0 Category: Robot movement control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x = 0, y = 0;
    char dir;

    printf("Enter the direction you want to move (N,E,W,S):\n");
    scanf("%c", &dir);

    // Set the seed for rand()
    srand(time(NULL));

    // Start moving in the selected direction
    switch(dir) {
        case 'N':
            while (y <= 10) {
                printf("Moving North...\n");
                y++; x += rand() % 3 - 1;
                printf("Current position: (%d, %d)\n", x, y);
            }
            break;

        case 'E':
            while (x <= 10) {
                printf("Moving East...\n");
                x++; y += rand() % 3 - 1;
                printf("Current position: (%d, %d)\n", x, y);
            }
            break;

        case 'W':
            while (x >= -10) {
                printf("Moving West...\n");
                x--; y += rand() % 3 - 1;
                printf("Current position: (%d, %d)\n", x, y);
            }
            break;

        case 'S':
            while (y >= -10) {
                printf("Moving South...\n");
                y--; x += rand() % 3 - 1;
                printf("Current position: (%d, %d)\n", x, y);
            }
            break;

        default:
            printf("Invalid direction. Please choose N, E, W, or S.\n");
            return 1;
    }

    printf("Final position: (%d, %d)\n", x, y);

    return 0;
}