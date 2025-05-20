//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define UP 'U'
#define DOWN 'D'
#define LEFT 'L'
#define RIGHT 'R'
#define FORWARD 'F'
#define BACK 'B'

int main() {
    int x = 0, y = 0, z = 0; // coordinates of the drone
    int direction = 0; // direction of movement

    char command[4];

    while(1) {
        printf("Enter command: ");
        scanf("%s", command);

        if(strcmp(command, "UP") == 0)
            direction = UP;
        else if(strcmp(command, "DOWN") == 0)
            direction = DOWN;
        else if(strcmp(command, "LEFT") == 0)
            direction = LEFT;
        else if(strcmp(command, "RIGHT") == 0)
            direction = RIGHT;
        else if(strcmp(command, "FORWARD") == 0)
            direction = FORWARD;
        else if(strcmp(command, "BACK") == 0)
            direction = BACK;
        else
            printf("Invalid command.\n");

        switch(direction) {
            case UP:
                y++;
                break;
            case DOWN:
                y--;
                break;
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case FORWARD:
                if(x > 0 && y > 0 && z < 1000) {
                    x++;
                    y++;
                    z++;
                }
                break;
            case BACK:
                if(x < 1000 && y < 1000 && z > 0) {
                    x--;
                    y--;
                    z--;
                }
                break;
        }

        printf("X: %d, Y: %d, Z: %d\n", x, y, z);
    }

    return 0;
}