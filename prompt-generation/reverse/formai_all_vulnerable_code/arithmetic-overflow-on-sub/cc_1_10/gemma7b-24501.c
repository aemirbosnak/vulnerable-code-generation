//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: authentic
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

Car* createCar(int x, int y, int direction, int speed) {
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = x;
    car->y = y;
    car->direction = direction;
    car->speed = speed;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow(Car* cars) {
    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        for (Car* car = cars; car; car = car->next) {
            switch (car->direction) {
                case 0:
                    car->x++;
                    break;
                case 1:
                    car->y++;
                    break;
                case 2:
                    car->x--;
                    break;
                case 3:
                    car->y--;
                    break;
            }
            car->speed--;
            if (car->speed == 0) {
                car->direction = (car->direction + 1) % 4;
                car->speed = 5;
            }
        }
        sleep(1);
    }
}

int main() {
    Car* cars = createCar(0, 0, 0, 5);
    cars = createCar(10, 0, 1, 5);
    cars = createCar(0, 10, 2, 5);
    cars = createCar(10, 10, 3, 5);

    simulateTrafficFlow(cars);

    return 0;
}