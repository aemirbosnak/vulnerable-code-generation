//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void move_forward(int direction);
void move_backward(int direction);
void turn_left(int direction);
void turn_right(int direction);

int main() {
    srand(time(0));

    while(1) {
        printf("Press arrow keys to control the vehicle:\n");
        printf("Up: move forward\n");
        printf("Down: move backward\n");
        printf("Left: turn left\n");
        printf("Right: turn right\n");

        int direction;
        scanf("%d", &direction);

        if (direction == 1) {
            move_forward(1);
        } else if (direction == 2) {
            move_backward(1);
        } else if (direction == 3) {
            turn_left(1);
        } else if (direction == 4) {
            turn_right(1);
        }
    }

    return 0;
}

void move_forward(int direction) {
    printf("Moving forward %d meters.\n", rand() % 100);
}

void move_backward(int direction) {
    printf("Moving backward %d meters.\n", rand() % 100);
}

void turn_left(int direction) {
    printf("Turning left %d degrees.\n", rand() % 360);
}

void turn_right(int direction) {
    printf("Turning right %d degrees.\n", rand() % 360);
}