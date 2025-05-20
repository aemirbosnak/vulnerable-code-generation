//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

typedef struct {
    int x;
    int y;
} position;

typedef struct {
    int direction;
    position current_position;
} vehicle;

void move_vehicle(vehicle *vehicle, int direction) {
    switch (direction) {
        case FORWARD:
            vehicle->current_position.x++;
            break;
        case BACKWARD:
            vehicle->current_position.x--;
            break;
        case LEFT:
            vehicle->current_position.y--;
            break;
        case RIGHT:
            vehicle->current_position.y++;
            break;
    }
}

void print_position(position position) {
    printf("X: %d, Y: %d\n", position.x, position.y);
}

void remote_control(vehicle *vehicle) {
    int direction;

    while (1) {
        printf("Enter direction: FORWARD(1), BACKWARD(2), LEFT(3), RIGHT(4): ");
        scanf("%d", &direction);

        move_vehicle(vehicle, direction);
        print_position(vehicle->current_position);
    }
}

int main() {
    vehicle my_vehicle = {0};

    printf("Initial position: \n");
    print_position(my_vehicle.current_position);

    remote_control(&my_vehicle);

    return 0;
}