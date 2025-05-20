//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    bool is_moving_up;
    bool is_moving_down;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // Ground floor
    elevator->is_moving_up = false;
    elevator->is_moving_down = false;
}

void request_floor(Elevator *elevator, int requested_floor) {
    if (requested_floor < 0 || requested_floor >= MAX_FLOORS) {
        printf("Invalid floor request.\n");
        return;
    }

    if (elevator->current_floor == requested_floor) {
        printf("Elevator is already on floor %d.\n", requested_floor);
        return;
    }

    if (requested_floor > elevator->current_floor) {
        elevator->is_moving_up = true;
        elevator->is_moving_down = false;
        printf("Elevator moving up to floor %d...\n", requested_floor);
    } else {
        elevator->is_moving_down = true;
        elevator->is_moving_up = false;
        printf("Elevator moving down to floor %d...\n", requested_floor);
    }

    while (elevator->current_floor != requested_floor) {
        if (elevator->is_moving_up) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }
        printf("Elevator is now on floor %d.\n", elevator->current_floor);
        sleep(1); // Simulating time delay for elevator movement
    }

    printf("Elevator has arrived at floor %d. Doors opening...\n", elevator->current_floor);
    elevator->is_moving_up = false;
    elevator->is_moving_down = false;
}

void show_elevator_status(Elevator *elevator) {
    printf("Current floor: %d\n", elevator->current_floor);
    if (elevator->is_moving_up) {
        printf("Elevator is moving up.\n");
    } else if (elevator->is_moving_down) {
        printf("Elevator is moving down.\n");
    } else {
        printf("Elevator is idle.\n");
    }
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);

    int choice;

    while (true) {
        show_elevator_status(&elevator);
        printf("Select a floor (0-%d) or press -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &choice);

        if (choice == -1) {
            printf("Exiting elevator simulation. Goodbye!\n");
            break;
        }

        request_floor(&elevator, choice);
    }

    return 0;
}