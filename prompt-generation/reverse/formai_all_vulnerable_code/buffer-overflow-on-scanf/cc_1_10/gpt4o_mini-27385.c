//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct Elevator {
    int current_floor;
    bool moving_up;
    int requests[MAX_FLOORS];
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // Start at ground floor
    elevator->moving_up = true;
    for (int i = 0; i < MAX_FLOORS; i++) {
        elevator->requests[i] = 0; // No requests initially
    }
}

void request_floor(Elevator *elevator, int floor) {
    if (floor >= 0 && floor < MAX_FLOORS) {
        elevator->requests[floor]++;
        printf("Request added for floor %d\n", floor);
    } else {
        printf("Invalid floor requested!\n");
    }
}

void move_elevator(Elevator *elevator) {
    while (true) {
        if (elevator->requests[elevator->current_floor] > 0) {
            printf("Elevator stopped at floor %d to pick up passengers.\n", elevator->current_floor);
            elevator->requests[elevator->current_floor]--;
            sleep(1); // Simulates the stopping time
        }

        if (elevator->moving_up) {
            if (elevator->current_floor < MAX_FLOORS - 1) {
                elevator->current_floor++;
                printf("Moving up to floor %d...\n", elevator->current_floor);
            } else {
                elevator->moving_up = false; // Change direction if at top floor
            }
        } else {
            if (elevator->current_floor > 0) {
                elevator->current_floor--;
                printf("Moving down to floor %d...\n", elevator->current_floor);
            } else {
                elevator->moving_up = true; // Change direction if at ground floor
            }
        }
        sleep(1); // Simulate travel time
    }
}

void print_instructions() {
    printf("Welcome to the Elevator Simulation!\n");
    printf("Please enter the floor you want (0 to %d), or -1 to exit:\n", MAX_FLOORS - 1);
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    int floor_request;

    print_instructions();

    while (true) {
        scanf("%d", &floor_request);

        if (floor_request == -1) {
            printf("Exiting the simulation. Thank you!\n");
            break;
        }

        request_floor(&elevator, floor_request);
        move_elevator(&elevator);
    }

    return 0;
}