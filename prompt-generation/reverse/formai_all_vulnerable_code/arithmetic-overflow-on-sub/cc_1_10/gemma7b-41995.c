//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 50
#define MAX_TURN 45

typedef struct Car {
    int x, y;
    int direction;
    int speed;
} Car;

Car car;

void moveCar() {
    switch (car.direction) {
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

    car.speed++;

    if (car.speed > MAX_SPEED) {
        car.speed = MAX_SPEED;
    }
}

void turnCar(int angle) {
    car.direction = (car.direction + angle) % MAX_TURN;
}

int main() {
    car.x = 0;
    car.y = 0;
    car.direction = 0;
    car.speed = 0;

    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 10) {
        moveCar();
        turnCar(rand() % 10);
    }

    return 0;
}