//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    bool moving_up;
} Elevator;

typedef struct {
    int requested_floor;
    bool is_requested;
} Request;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // Starting at ground floor
    elevator->moving_up = true; // Initially set to move up
}

void print_elevator_status(Elevator elevator) {
    printf("Elevator is currently on floor %d.\n", elevator.current_floor);
}

void request_floor(Request *request, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor request: %d. Must be between 0 and %d.\n", floor, MAX_FLOORS - 1);
        return;
    }
    request->requested_floor = floor;
    request->is_requested = true;
    printf("Floor request for %d received.\n", floor);
}

void move_elevator(Elevator *elevator, Request *request) {
    while (request->is_requested) {
        print_elevator_status(*elevator);

        if (elevator->current_floor < request->requested_floor) {
            elevator->moving_up = true;
            elevator->current_floor++;
        } else if (elevator->current_floor > request->requested_floor) {
            elevator->moving_up = false;
            elevator->current_floor--;
        }

        print_elevator_status(*elevator);

        if (elevator->current_floor == request->requested_floor) {
            request->is_requested = false;
            printf("Elevator has reached the requested floor %d.\n", request->requested_floor);
        }

        sleep(1); // Simulate time taken to move between floors
    }
}

int main() {
    Elevator elevator;
    Request request = {0, false};

    initialize_elevator(&elevator);
    int user_input;

    printf("Welcome to the Elevator Simulation!\n");
    printf("Available floors: 0 to %d\n", MAX_FLOORS - 1);
    
    while (true) {
        printf("Enter a floor number to request (enter -1 to exit): ");
        scanf("%d", &user_input);

        if (user_input == -1) {
            printf("Exiting simulation. Thank you!\n");
            break;
        }

        request_floor(&request, user_input);

        move_elevator(&elevator, &request);
    }

    return 0;
}