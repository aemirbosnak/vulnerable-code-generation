//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

typedef struct Car {
    int x, y, facing;
    int speed;
} Car;

Car car;

void move_car(int direction) {
    switch (direction) {
        case 0:
            car.x++;
            break;
        case 1:
            car.y++;
            break;
        case 2:
            car.x--;
            break;
        case 3:
            car.y--;
            break;
    }
}

void accelerate(int acceleration) {
    if (acceleration > MAX_SPEED) {
        car.speed = MAX_SPEED;
    } else {
        car.speed += acceleration;
    }
}

void brake(int deceleration) {
    if (car.speed - deceleration < 0) {
        car.speed = 0;
    } else {
        car.speed -= deceleration;
    }
}

int main() {
    car.x = 0;
    car.y = 0;
    car.facing = 0;
    car.speed = 0;

    time_t start_time = time(NULL);

    while (time(NULL) - start_time < 10) {
        move_car(rand() % 4);
        accelerate(rand() % 5);
        brake(rand() % 3);

        printf("Car position: (%d, %d), Speed: %d, Facing: %d\n", car.x, car.y, car.speed, car.facing);

        sleep(1);
    }

    return 0;
}