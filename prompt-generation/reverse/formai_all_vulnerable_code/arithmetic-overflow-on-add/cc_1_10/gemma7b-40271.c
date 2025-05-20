//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct car {
    int position;
    int direction;
    int speed;
    struct car* next;
} car;

void simulateTrafficFlow(car* head) {
    time_t tStart = time(NULL);
    time_t tEnd = tStart + 60;

    while (time(NULL) < tEnd) {
        for (car* currentCar = head; currentCar; currentCar = currentCar->next) {
            switch (currentCar->direction) {
                case 0: // Eastbound
                    currentCar->position++;
                    if (currentCar->position >= MAX_CARS) {
                        currentCar->direction = 1;
                    }
                    break;
                case 1: // Westbound
                    currentCar->position--;
                    if (currentCar->position <= 0) {
                        currentCar->direction = 0;
                    }
                    break;
            }

            currentCar->speed++;
            if (currentCar->speed >= 10) {
                currentCar->speed = 0;
            }
        }

        sleep(1);
    }

    printf("Traffic flow simulation complete.\n");
}

int main() {
    car* head = malloc(sizeof(car));
    head->position = 0;
    head->direction = 0;
    head->speed = 0;
    head->next = NULL;

    simulateTrafficFlow(head);

    return 0;
}