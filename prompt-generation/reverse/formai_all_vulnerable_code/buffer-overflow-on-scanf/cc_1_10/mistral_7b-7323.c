//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT -2

typedef struct {
    int x, y;
    int speed;
    int direction;
} Car;

void move_car(Car *car, int direction, int speed) {
    switch (direction) {
        case FORWARD:
            car->y += car->speed;
            break;
        case BACKWARD:
            car->y -= car->speed;
            break;
        case LEFT:
            car->x -= car->speed;
            break;
        case RIGHT:
            car->x += car->speed;
            break;
        default:
            printf("Invalid direction\n");
            break;
    }
}

int main() {
    Car car = {0, 0, 5};
    int direction, speed;

    srand(time(NULL));

    while (1) {
        printf("Enter direction (F/B/L/R) and speed: ");
        scanf("%d %d", &direction, &speed);

        move_car(&car, direction, speed);

        printf("Car position: (%d, %d)\n", car.x, car.y);

        // Randomly change direction
        if (rand() % 2) {
            direction = rand() % 5 + 1;
            printf("Car direction changed to %d\n", direction);
        }
    }

    return 0;
}