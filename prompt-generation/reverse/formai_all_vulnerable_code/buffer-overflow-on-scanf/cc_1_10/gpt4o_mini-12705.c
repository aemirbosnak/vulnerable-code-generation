//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    bool moving_up;
} Elevator;

void call_elevator(Elevator *elevator, int requested_floor) {
    if (requested_floor < 1 || requested_floor > MAX_FLOORS) {
        printf("Invalid floor requested! Please request a floor between 1 and %d.\n", MAX_FLOORS);
        return;
    }

    printf("Elevator is currently on floor %d.\n", elevator->current_floor);

    if (requested_floor == elevator->current_floor) {
        printf("Elevator is already on the requested floor %d.\n", requested_floor);
        return;
    }

    if (requested_floor > elevator->current_floor) {
        elevator->moving_up = true;
    } else {
        elevator->moving_up = false;
    }

    while (elevator->current_floor != requested_floor) {
        elevator->moving_up ? (elevator->current_floor)++ : (elevator->current_floor)--;
        printf("Elevator is now on floor %d.\n", elevator->current_floor);
        sleep(1);  // Simulating time taken to move between floors
    }

    printf("Elevator has arrived at floor %d.\n", elevator->current_floor);
}

int main() {
    Elevator elevator = {1, true};  // Start on the ground floor

    int requested_floor;

    while (true) {
        printf("----- Elevator Simulation -----\n");
        printf("Current floor: %d\n", elevator.current_floor);
        printf("Enter the floor you want to go to (1 to %d), or 0 to exit: ", MAX_FLOORS);
        scanf("%d", &requested_floor);

        if (requested_floor == 0) {
            printf("Exiting the elevator simulation program.\n");
            break;
        }

        call_elevator(&elevator, requested_floor);
    }

    return 0;
}