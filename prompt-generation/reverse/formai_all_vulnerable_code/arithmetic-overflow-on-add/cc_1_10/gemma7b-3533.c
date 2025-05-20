//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: genius
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 50

typedef struct Car {
    int lane;
    int speed;
    int position;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = rand() % NUM_LANE;
    car->speed = rand() % 5 + 1;
    car->position = rand() % 1000;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow() {
    Car* head = createCar();
    head->next = createCar();
    head->next->next = createCar();
    head->next->next->next = createCar();
    head->next->next->next->next = createCar();

    time_t start = time(NULL);
    time_t end = start + 60;

    while (time(NULL) < end) {
        for (Car* car = head; car; car = car->next) {
            car->position += car->speed;
            if (car->position >= 1000) {
                car->position = 0;
            }
        }

        sleep(1);
    }

    free(head);
}

int main() {
    simulateTrafficFlow();
    return 0;
}