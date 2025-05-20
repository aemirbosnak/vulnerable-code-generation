//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Claude Shannon
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_SPEED 100
#define MAX_TURN 90

typedef struct {
    int speed;
    int turn;
} Vehicle;

void move(Vehicle* v, int speed, int turn) {
    printf("Moving...\n");
    v->speed = speed;
    v->turn = turn;
}

void turnLeft(Vehicle* v) {
    printf("Turning left...\n");
    v->turn -= 10;
    if (v->turn < 0) {
        v->turn = 0;
    }
}

void turnRight(Vehicle* v) {
    printf("Turning right...\n");
    v->turn += 10;
    if (v->turn > MAX_TURN) {
        v->turn = MAX_TURN;
    }
}

void accelerate(Vehicle* v) {
    printf("Accelerating...\n");
    v->speed += 10;
    if (v->speed > MAX_SPEED) {
        v->speed = MAX_SPEED;
    }
}

void decelerate(Vehicle* v) {
    printf("Decelerating...\n");
    v->speed -= 10;
    if (v->speed < 0) {
        v->speed = 0;
    }
}

int main() {
    Vehicle car;
    int choice;

    printf("Welcome to the Remote Control Vehicle Simulation!\n\n");
    printf("Press 1 to move forward, 2 to turn left, 3 to turn right, 4 to accelerate, 5 to decelerate, or any other key to exit.\n");

    while (TRUE) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move(&car, 50, 0);
                break;
            case 2:
                turnLeft(&car);
                break;
            case 3:
                turnRight(&car);
                break;
            case 4:
                accelerate(&car);
                break;
            case 5:
                decelerate(&car);
                break;
            default:
                printf("Exiting...\n");
                return 0;
        }
    }

    return 0;
}