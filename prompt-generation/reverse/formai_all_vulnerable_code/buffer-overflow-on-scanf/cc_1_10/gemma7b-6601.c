//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_TURN 90

typedef struct Vehicle {
    int x;
    int y;
    int direction;
    int speed;
} Vehicle;

Vehicle createVehicle() {
    Vehicle v;
    v.x = 0;
    v.y = 0;
    v.direction = 0;
    v.speed = 0;
    return v;
}

void moveVehicle(Vehicle *v, int direction, int speed) {
    switch (direction) {
        case 0:
            v->x++;
            break;
        case 1:
            v->y++;
            break;
        case 2:
            v->x--;
            break;
        case 3:
            v->y--;
            break;
    }

    v->speed = speed;
}

int main() {
    Vehicle myVehicle = createVehicle();

    while (1) {
        int command;
        printf("Enter command (0-3, 4-8): ");
        scanf("%d", &command);

        switch (command) {
            case 0:
                moveVehicle(&myVehicle, 0, MAX_SPEED);
                break;
            case 1:
                moveVehicle(&myVehicle, 1, MAX_SPEED);
                break;
            case 2:
                moveVehicle(&myVehicle, 2, MAX_SPEED);
                break;
            case 3:
                moveVehicle(&myVehicle, 3, MAX_SPEED);
                break;
            case 4:
                moveVehicle(&myVehicle, 0, -MAX_SPEED);
                break;
            case 5:
                moveVehicle(&myVehicle, 1, -MAX_SPEED);
                break;
            case 6:
                moveVehicle(&myVehicle, 2, -MAX_SPEED);
                break;
            case 7:
                moveVehicle(&myVehicle, 3, -MAX_SPEED);
                break;
            case 8:
                printf("X: %d, Y: %d\n", myVehicle.x, myVehicle.y);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}