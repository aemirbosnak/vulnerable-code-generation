//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 10

typedef struct Car {
    int lane;
    int position;
    int speed;
    int direction;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = malloc(sizeof(Car));
    car->lane = rand() % NUM_LANE;
    car->position = rand() % 1000;
    car->speed = rand() % 5 + 1;
    car->direction = rand() % 2;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow() {
    Car* head = createCar();
    head->next = createCar();
    head->next->next = createCar();

    time_t start = time(NULL);
    time_t end = start + 60;

    while (time(NULL) < end) {
        for (Car* car = head; car; car = car->next) {
            switch (car->direction) {
                case 0:
                    car->position++;
                    break;
                case 1:
                    car->position--;
                    break;
            }

            if (car->position >= 1000) {
                car->position = 0;
            } else if (car->position <= 0) {
                car->position = 1000;
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