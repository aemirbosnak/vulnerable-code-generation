//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 50

typedef struct Car {
    int x, y, speed, lane;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = malloc(sizeof(Car));
    car->x = rand() % 1000;
    car->y = rand() % 1000;
    car->speed = rand() % 5 + 1;
    car->lane = rand() % NUM_LANE;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow() {
    Car* head = createCar();
    head->next = createCar();
    head->next->next = createCar();
    head->next->next->next = createCar();
    head->next->next->next->next = createCar();

    time_t t = time(NULL);
    while (time(NULL) - t < 60) {
        for (Car* car = head; car; car = car->next) {
            car->x += car->speed * (time(NULL) - t) / 60;
            car->y += car->speed * (time(NULL) - t) / 60;
            if (car->x > 1000) {
                car->x = -1;
            }
            if (car->y > 1000) {
                car->y = -1;
            }
        }
        t = time(NULL);
    }

    free(head);
}

int main() {
    simulateTrafficFlow();
    return 0;
}