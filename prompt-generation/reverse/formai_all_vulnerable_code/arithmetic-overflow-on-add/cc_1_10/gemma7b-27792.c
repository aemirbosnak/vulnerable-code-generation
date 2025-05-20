//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_ROTATION 90

typedef struct Car {
    int x, y, direction, speed, rotation;
} Car;

Car car;

void move(int direction, int speed) {
    switch (direction) {
        case 0:
            car.x++;
            break;
        case 1:
            car.x--;
            break;
        case 2:
            car.y++;
            break;
        case 3:
            car.y--;
            break;
    }

    car.speed = speed;
}

void turn(int rotation) {
    car.rotation = rotation;
}

int main() {
    car.x = 0;
    car.y = 0;
    car.direction = 0;
    car.speed = 0;
    car.rotation = 0;

    time_t start_time = time(NULL);
    time_t end_time = start_time + 10;

    while (time(NULL) < end_time) {
        move(2, MAX_SPEED);
        turn(MAX_ROTATION);
        sleep(0.1);
    }

    printf("Car's position: (%d, %d)\n", car.x, car.y);

    return 0;
}