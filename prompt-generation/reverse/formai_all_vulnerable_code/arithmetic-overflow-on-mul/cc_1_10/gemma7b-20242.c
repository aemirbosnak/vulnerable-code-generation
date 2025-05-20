//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

typedef struct RemoteControlCar {
    int x, y, facing, speed;
    time_t last_updated;
} RemoteControlCar;

RemoteControlCar create_car() {
    RemoteControlCar car;
    car.x = 0;
    car.y = 0;
    car.facing = 0;
    car.speed = 0;
    car.last_updated = time(NULL);
    return car;
}

void move_car(RemoteControlCar* car, int direction, int acceleration) {
    switch (direction) {
        case 0:
            car->speed = acceleration;
            break;
        case 1:
            car->speed = acceleration;
            car->facing = 90;
            break;
        case 2:
            car->speed = acceleration;
            car->facing = 180;
            break;
        case 3:
            car->speed = acceleration;
            car->facing = 270;
            break;
    }

    car->last_updated = time(NULL);
}

void update_car(RemoteControlCar* car) {
    time_t now = time(NULL);
    if (now - car->last_updated > 1) {
        int elapsed_time = now - car->last_updated;
        int distance = car->speed * elapsed_time;

        switch (car->facing) {
            case 0:
                car->x += distance;
                break;
            case 90:
                car->y += distance;
                break;
            case 180:
                car->x -= distance;
                break;
            case 270:
                car->y -= distance;
                break;
        }

        car->last_updated = now;
    }
}

int main() {
    RemoteControlCar car = create_car();

    move_car(&car, 0, 5);
    move_car(&car, 1, 3);
    move_car(&car, 2, 2);
    move_car(&car, 3, 4);

    update_car(&car);

    printf("Car position: (%d, %d)\n", car.x, car.y);

    return 0;
}