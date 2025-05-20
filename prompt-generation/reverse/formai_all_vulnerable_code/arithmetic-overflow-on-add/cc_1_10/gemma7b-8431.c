//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

void simulateTrafficFlow(Car* head) {
    time_t t = time(NULL);
    int current_time = 0;

    while (current_time < t + 10) {
        for (Car* car = head; car; car = car->next) {
            switch (car->direction) {
                case 0: // North
                    car->x++;
                    break;
                case 1: // East
                    car->y++;
                    break;
                case 2: // South
                    car->x--;
                    break;
                case 3: // West
                    car->y--;
                    break;
            }

            car->speed++;
            if (car->speed > 5) {
                car->speed = 5;
            }
        }

        current_time++;
    }

    free(head);
}

int main() {
    Car* head = malloc(sizeof(Car));
    head->x = 0;
    head->y = 0;
    head->direction = 0;
    head->speed = 1;
    head->next = NULL;

    simulateTrafficFlow(head);

    return 0;
}