//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    int requested_floor;
} Elevator;

void initialize_elevator(Elevator* elevator) {
    elevator->current_floor = 0;  // Start from ground floor
    elevator->requested_floor = -1; // No floor requested
}

void request_floor(Elevator* elevator, int floor) {
    if (floor >= 0 && floor < MAX_FLOORS) {
        elevator->requested_floor = floor;
    } else {
        printf("Invalid floor request: %d\n", floor);
    }
}

void move_elevator(Elevator* elevator) {
    if (elevator->requested_floor != -1) {
        printf("Elevator moving from floor %d to floor %d...\n", elevator->current_floor, elevator->requested_floor);
        while (elevator->current_floor != elevator->requested_floor) {
            if (elevator->current_floor < elevator->requested_floor) {
                elevator->current_floor++;
            } else {
                elevator->current_floor--;
            }
            printf("Elevator is now at floor %d\n", elevator->current_floor);
            sleep(1); // Simulate time taken to move
        }
        printf("Elevator has arrived at floor %d\n", elevator->current_floor);
        elevator->requested_floor = -1; // Reset after arriving
    }
}

void display_menu() {
    printf("\nElevator System Menu:\n");
    printf("Select a floor (0 to %d) or -1 to exit: ", MAX_FLOORS - 1);
}

int main() {
    Elevator elevator;
    int floor_request;

    initialize_elevator(&elevator);

    while (1) {
        display_menu();
        scanf("%d", &floor_request);

        if (floor_request == -1) {
            printf("Exiting the elevator simulation...\n");
            break;
        }

        request_floor(&elevator, floor_request);
        move_elevator(&elevator);
    }

    return 0;
}