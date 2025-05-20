//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ELEVATOR_CAPACITY 10
#define NUM_FLOORS 10

typedef struct {
    int current_floor;
    int destination_floor;
    int passengers[ELEVATOR_CAPACITY];
    int num_passengers;
    bool going_up;
    bool going_down;
} Elevator;

void initialize_elevator(Elevator* e) {
    e->current_floor = 1;
    e->destination_floor = 1;
    e->num_passengers = 0;
    e->going_up = false;
    e->going_down = false;
}

void add_passenger(Elevator* e, int floor) {
    if (e->num_passengers == ELEVATOR_CAPACITY) {
        printf("Elevator is full, cannot add passenger.\n");
        return;
    }
    e->passengers[e->num_passengers++] = floor;
}

void remove_passenger(Elevator* e) {
    if (e->num_passengers == 0) {
        printf("Elevator is empty, cannot remove passenger.\n");
        return;
    }
    e->passengers[--e->num_passengers] = 0;
}

void move_elevator(Elevator* e) {
    if (e->going_up) {
        if (e->current_floor == NUM_FLOORS) {
            e->going_up = false;
            e->going_down = true;
            printf("Reached the top floor, changing direction. ");
        } else {
            printf("Going up to floor %d. ", ++e->current_floor);
        }
    } else if (e->going_down) {
        if (e->current_floor == 1) {
            e->going_up = true;
            e->going_down = false;
            printf("Reached the ground floor, changing direction. ");
        } else {
            printf("Going down to floor %d. ", --e->current_floor);
        }
    } else {
        printf("Elevator is stationary. ");
    }
    if (e->num_passengers > 0) {
        printf("Passengers: ");
        for (int i = 0; i < e->num_passengers; i++) {
            printf("%d ", e->passengers[i]);
        }
    } else {
        printf("No passengers. ");
    }
    printf("\n");
}

int main() {
    Elevator e;
    initialize_elevator(&e);
    printf("Elevator initialized.\n");
    while (true) {
        int input;
        printf("Enter 1 to add passenger, 2 to remove passenger, or 0 to quit: ");
        scanf("%d", &input);
        if (input == 1) {
            int floor;
            printf("Enter the passenger's starting floor (1-%d): ", NUM_FLOORS);
            scanf("%d", &floor);
            if (floor < 1 || floor > NUM_FLOORS) {
                printf("Invalid floor number.\n");
            } else {
                add_passenger(&e, floor);
                printf("Passenger added to elevator.\n");
            }
        } else if (input == 2) {
            remove_passenger(&e);
            printf("Passenger removed from elevator.\n");
        } else if (input == 0) {
            printf("Exiting elevator simulation.\n");
            break;
        } else {
            printf("Invalid input.\n");
        }
        move_elevator(&e);
    }
    return 0;
}