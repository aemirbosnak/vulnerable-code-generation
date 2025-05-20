//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 10

typedef struct Car {
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

void initialize_simulation(Car** head) {
    *head = NULL;
}

void add_car(Car** head, int lane, int position, int speed) {
    Car* new_car = malloc(sizeof(Car));
    new_car->lane = lane;
    new_car->position = position;
    new_car->speed = speed;
    new_car->next = NULL;

    if (*head == NULL) {
        *head = new_car;
    } else {
        ((*head)->next = new_car);
        *head = new_car;
    }
}

void simulate_traffic(Car* head) {
    time_t start_time = time(NULL);
    time_t current_time = start_time;

    while (time(NULL) - start_time < 10) {
        current_time = time(NULL);

        for (Car* car = head; car; car = car->next) {
            car->position++;

            if (car->position >= MAX_CARS) {
                car->position = 0;
            }

            if (car->speed > 0) {
                car->position++;
            }
        }

        sleep(1);
    }
}

int main() {
    Car* head = NULL;
    initialize_simulation(&head);

    add_car(&head, 0, 0, 5);
    add_car(&head, 1, 2, 3);
    add_car(&head, 2, 4, 2);

    simulate_traffic(head);

    return 0;
}