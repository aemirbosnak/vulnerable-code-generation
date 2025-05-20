//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_TURN 90
#define MIN_TURN -90
#define STOP 0

int speed = 0;
int turn = 0;
int moving = 0;
int direction = 1;

void move(int speed, int turn) {
    printf("Moving forward at %d units per second and turning %d degrees.\n", speed, turn);
}

void stop() {
    printf("Stopping the vehicle.\n");
}

void turnLeft() {
    turn = MAX_TURN;
}

void turnRight() {
    turn = MIN_TURN;
}

void accelerate() {
    if (speed < MAX_SPEED) {
        speed++;
    }
}

void decelerate() {
    if (speed > MIN_SPEED) {
        speed--;
    }
}

void changeDirection() {
    direction = -direction;
}

void main() {
    srand(time(0));

    printf("Welcome to the Romeo and Juliet Remote Control Vehicle Simulation!\n");

    int choice;

    do {
        printf("\n");
        printf("Please choose an option:\n");
        printf("1. Move forward\n");
        printf("2. Stop\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Accelerate\n");
        printf("6. Decelerate\n");
        printf("7. Change direction\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move(speed, turn);
                break;
            case 2:
                stop();
                break;
            case 3:
                turnLeft();
                break;
            case 4:
                turnRight();
                break;
            case 5:
                accelerate();
                break;
            case 6:
                decelerate();
                break;
            case 7:
                changeDirection();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
        }

        printf("\n");

    } while (choice!= 0);

}