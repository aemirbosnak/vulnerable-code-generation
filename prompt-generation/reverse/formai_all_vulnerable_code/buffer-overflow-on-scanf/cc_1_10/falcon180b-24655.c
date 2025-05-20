//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define INITIAL_POSITION 0
#define LEFT_TURN -1
#define RIGHT_TURN 1
#define FORWARD_MOVE 1
#define BACKWARD_MOVE -1

int main() {
    int position = INITIAL_POSITION, speed = 0, turn = 0;
    char command;

    while (1) {
        printf("Enter command (f for forward, b for backward, l for left, r for right, s for stop): ");
        scanf(" %c", &command);

        switch (command) {
            case 'f':
                speed = MAX_SPEED;
                turn = FORWARD_MOVE;
                break;
            case 'b':
                speed = MAX_SPEED;
                turn = BACKWARD_MOVE;
                break;
            case 'l':
                speed = MAX_SPEED;
                turn = LEFT_TURN;
                break;
            case 'r':
                speed = MAX_SPEED;
                turn = RIGHT_TURN;
                break;
            case's':
                speed = 0;
                turn = 0;
                break;
            default:
                printf("Invalid command\n");
        }

        if (turn == LEFT_TURN) {
            position -= speed;
        } else if (turn == RIGHT_TURN) {
            position += speed;
        } else if (speed > 0) {
            position += speed;
        }

        printf("Current position: %d\n", position);
        printf("Current speed: %d\n", speed);
        printf("Current turn: %d\n", turn);
        printf("\n");

        usleep(100000); // delay for 100ms
    }

    return 0;
}