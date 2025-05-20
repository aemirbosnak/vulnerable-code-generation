//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 10

typedef struct Car {
    int lane;
    int speed;
    int position;
    struct Car* next;
} Car;

Car* createCar(int lane, int speed, int position) {
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = lane;
    car->speed = speed;
    car->position = position;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow(Car* head) {
    time_t tStart = time(NULL);
    time_t tEnd = tStart + 5;

    while (time(NULL) < tEnd) {
        for (Car* car = head; car; car = car->next) {
            switch (car->lane) {
                case 0:
                    car->position++;
                    break;
                case 1:
                    car->position--;
                    break;
                case 2:
                    car->position++;
                    break;
            }

            if (car->position > NUM_LANE - 1) {
                car->position = 0;
            } else if (car->position < 0) {
                car->position = NUM_LANE - 1;
            }
        }

        sleep(1);
    }

    time_t tEndFinal = time(NULL);
    printf("Time elapsed: %ld seconds\n", tEndFinal - tStart);
}

int main() {
    Car* head = createCar(0, 5, 0);
    head = createCar(1, 3, 1);
    head = createCar(2, 4, 2);

    simulateTrafficFlow(head);

    return 0;
}