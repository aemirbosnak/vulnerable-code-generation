//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define FORWARD 4
#define BACKWARD 5
#define STOP 6

#define INIT 0
#define MOVE 1
#define TURN 2
#define STOPPED 3

int main() {

    int state = INIT;
    int direction = STOPPED;
    int speed = 0;

    while (1) {

        switch (state) {

            case INIT:
                printf("Enter speed (0-100): ");
                scanf("%d", &speed);
                state = MOVE;
                break;

            case MOVE:
                printf("Enter direction (1-6): ");
                scanf("%d", &direction);

                switch (direction) {

                    case UP:
                        printf("Drone is moving up at %d speed\n", speed);
                        break;

                    case DOWN:
                        printf("Drone is moving down at %d speed\n", speed);
                        break;

                    case LEFT:
                        printf("Drone is moving left at %d speed\n", speed);
                        break;

                    case RIGHT:
                        printf("Drone is moving right at %d speed\n", speed);
                        break;

                    case FORWARD:
                        printf("Drone is moving forward at %d speed\n", speed);
                        break;

                    case BACKWARD:
                        printf("Drone is moving backward at %d speed\n", speed);
                        break;

                    default:
                        printf("Invalid direction\n");
                        break;
                }

                state = STOPPED;
                break;

            case STOPPED:
                printf("Enter speed (0-100): ");
                scanf("%d", &speed);
                state = MOVE;
                break;

            default:
                printf("Invalid state\n");
                break;
        }
    }

    return 0;
}