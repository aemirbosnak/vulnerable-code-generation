//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct car {
    int xpos;
    int ypos;
    int direction; // 0 - North, 1 - East, 2 - South, 3 - West
};

typedef struct car Car;

void move(Car *car, int distance) {
    switch(car->direction) {
        case 0:
            car->ypos += distance;
            break;
        case 1:
            car->xpos += distance;
            break;
        case 2:
            car->ypos -= distance;
            break;
        case 3:
            car->xpos -= distance;
            break;
    }
}

void turn_left(Car *car) {
    car->direction = (car->direction + 3) % 4;
}

void turn_right(Car *car) {
    car->direction = (car->direction + 1) % 4;
}

int main() {
    Car car = {0, 0, 0};
    int command, distance;

    printf("Welcome to Remote Control Vehicle Simulation\n");
    printf("-------------------------------------------\n");

    do {
        printf("Current position -> x: %d, y: %d\n", car.xpos, car.ypos);
        printf("Enter command (1 - Move, 2 - Turn left, 3 - Turn right, 4 - Quit): ");
        scanf("%d", &command);

        switch(command) {
            case 1:
                printf("Enter distance to move: ");
                scanf("%d", &distance);
                move(&car, distance);
                break;
            case 2:
                turn_left(&car);
                break;
            case 3:
                turn_right(&car);
                break;
            case 4:
                printf("Exiting simulation...\n");
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
    } while(command != 4);

    return 0;
}