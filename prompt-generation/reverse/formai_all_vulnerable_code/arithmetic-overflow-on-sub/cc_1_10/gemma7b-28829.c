//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = rand() % MAX_LANE;
    car->position = rand() % MAX_LANE;
    car->speed = rand() % 3;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow() {
    Car* head = createCar();
    head->next = createCar();
    head->next->next = createCar();

    time_t start = time(NULL);
    time_t end = start + 10;

    while (time(NULL) < end) {
        // Move cars
        Car* currentCar = head;
        while (currentCar) {
            currentCar->position = (currentCar->position + currentCar->speed) % MAX_LANE;
            currentCar = currentCar->next;
        }

        // Collisions
        Car* car1 = head;
        while (car1) {
            Car* car2 = head;
            while (car2) {
                if (car1 != car2 && car1->lane == car2->lane && car1->position == car2->position) {
                    printf("Collision!\n");
                    exit(1);
                }
                car2 = car2->next;
            }
            car1 = car1->next;
        }

        // Print traffic flow
        printf("Traffic flow at time %ld:\n", time(NULL) - start);
        Car* car = head;
        while (car) {
            printf("Car lane: %d, position: %d, speed: %d\n", car->lane, car->position, car->speed);
            car = car->next;
        }

        // Sleep
        sleep(1);
    }

    return;
}

int main() {
    simulateTrafficFlow();
    return 0;
}