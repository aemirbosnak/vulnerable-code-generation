//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALTITUDE 100
#define MAX_SPEED 50

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    FRONT,
    BACK
} Direction;

int main() {
    int altitude = 0;
    int speed = 0;
    char ch;
    Direction d;

    printf("Initializing C Drone\n");

    while(1) {
        printf("Enter your command (u/d/l/r/f/b): ");
        scanf("%c", &ch);

        switch(ch) {
            case 'u':
                altitude = (altitude + 1 > MAX_ALTITUDE) ? MAX_ALTITUDE : altitude + 1;
                printf("Altitude: %d\n", altitude);
                break;
            case 'd':
                altitude = (altitude - 1 < 0) ? 0 : altitude - 1;
                printf("Altitude: %d\n", altitude);
                break;
            case 'l':
                d = LEFT;
                printf("Direction: Left\n");
                break;
            case 'r':
                d = RIGHT;
                printf("Direction: Right\n");
                break;
            case 'f':
                d = FRONT;
                printf("Direction: Front\n");
                break;
            case 'b':
                d = BACK;
                printf("Direction: Back\n");
                printf("Speed: %d\n", speed);
                break;
            default:
                printf("Invalid command!\n");
        }

        if(ch == 'l' || ch == 'r' || ch == 'f' || ch == 'b') {
            printf("Enter speed (0-%d): ", MAX_SPEED);
            scanf("%d", &speed);

            if(speed < 0 || speed > MAX_SPEED) {
                printf("Invalid speed!\n");
                continue;
            }

            printf("Speed: %d\n", speed);

            switch(d) {
                case LEFT:
                    printf("Moving left with speed %d\n", speed);
                    break;
                case RIGHT:
                    printf("Moving right with speed %d\n", speed);
                    break;
                case FRONT:
                    printf("Moving forward with speed %d\n", speed);
                    break;
                case BACK:
                    printf("Moving backward with speed %d\n", speed);
                    break;
            }
        }

        while((ch = getchar()) != '\n' && ch != EOF);

        printf("------------------------------\n");
    }

    return 0;
}