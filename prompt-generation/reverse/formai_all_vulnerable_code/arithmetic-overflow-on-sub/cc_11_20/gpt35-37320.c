//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    int map[10][10] = { // initialize a 10x10 map
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };
    int command;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");

    do {
        printf("\nPlease enter a command (1: move forward, 2: move backward, 3: turn left, 4: turn right): ");
        scanf("%d", &command);

        switch (command) {
        case 1: // move forward
            if (y + 1 > 9) {
                printf("Cannot move forward!\n");
            } else {
                map[x][y] = 0;
                y++;
                map[x][y] = 1;
                printf("Moved forward successfully!\n");
            }
            break;
        case 2: // move backward
            if (y - 1 < 0) {
                printf("Cannot move backward!\n");
            } else {
                map[x][y] = 0;
                y--;
                map[x][y] = 1;
                printf("Moved backward successfully!\n");
            }
            break;
        case 3: // turn left
            if (x - 1 < 0) {
                printf("Cannot turn left!\n");
            } else {
                map[x][y] = 0;
                x--;
                map[x][y] = 1;
                printf("Turned left successfully!\n");
            }
            break;
        case 4: // turn right
            if (x + 1 > 9) {
                printf("Cannot turn right!\n");
            } else {
                map[x][y] = 0;
                x++;
                map[x][y] = 1;
                printf("Turned right successfully!\n");
            }
            break;
        default:
            printf("Invalid command!\n");
        }

        // print out the map
        printf("\nCurrent Map:\n");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] == 1) {
                    printf("X ");
                } else {
                    printf("_ ");
                }
            }
            printf("\n");
        }

    } while (command != 0);

    printf("\nThank you for using this program!\n");

    return 0;
}