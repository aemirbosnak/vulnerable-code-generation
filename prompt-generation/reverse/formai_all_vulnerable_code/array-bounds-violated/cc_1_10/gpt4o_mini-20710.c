//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int current_floor;
    int destination_floor;
    int people_count;
} Elevator;

typedef struct {
    int requests[MAX_FLOORS];
} FloorRequest;

void initialize(FloorRequest *floor_request) {
    for (int i = 0; i < MAX_FLOORS; i++) {
        floor_request->requests[i] = 0;
    }
}

void display_status(Elevator *elevator, FloorRequest *floor_request) {
    printf("\nElevator is at floor: %d\n", elevator->current_floor);
    printf("Current people count: %d\n", elevator->people_count);
    printf("Destination floor: %d\n", elevator->destination_floor);
    
    printf("Floor Requests: ");
    for (int i = 0; i < MAX_FLOORS; i++) {
        if (floor_request->requests[i] > 0) {
            printf("Floor %d (%d requests), ", i, floor_request->requests[i]);
        }
    }
    printf("\n");
}

int get_user_input(const char *prompt) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}

void process_requests(Elevator *elevator, FloorRequest *floor_request) {
    if (elevator->destination_floor < 0 || elevator->destination_floor >= MAX_FLOORS) {
        printf("Invalid floor selected! \n");
        return;
    }

    if (floor_request->requests[elevator->destination_floor] > 0) {
        floor_request->requests[elevator->destination_floor]--;

        if (elevator->people_count < MAX_CAPACITY) {
            printf("Loading a passenger at floor %d.\n", elevator->current_floor);
            elevator->people_count++;
        } else {
            printf("Elevator is at full capacity!\n");
            return;
        }

        printf("Elevator moving to floor %d...\n", elevator->destination_floor);
        while (elevator->current_floor != elevator->destination_floor) {
            elevator->current_floor += (elevator->current_floor < elevator->destination_floor) ? 1 : -1;
            sleep(1);
            display_status(elevator, floor_request);
        }
        
        printf("Arrived at floor %d!\n", elevator->current_floor);
    } else {
        printf("No requests for floor %d.\n", elevator->destination_floor);
    }
}

void unload_passenger(Elevator *elevator) {
    printf("Unloading passenger at floor %d.\n", elevator->current_floor);
    elevator->people_count--;
}

void run_elevator_simulation() {
    Elevator elevator = {0, -1, 0}; // Start at ground floor with no destination and no passengers
    FloorRequest floor_request;
    initialize(&floor_request);

    while (true) {
        display_status(&elevator, &floor_request);

        elevator.destination_floor = get_user_input("Select a floor to go to (0-9, -1 to exit): ");
        if (elevator.destination_floor == -1) {
            printf("Exiting simulation...\n");
            break;
        }

        floor_request.requests[elevator.destination_floor]++; // Adding request for the destination floor
        process_requests(&elevator, &floor_request);

        if (elevator.people_count > 0) {
            unload_passenger(&elevator);
        }
    }
}

int main() {
    printf("Welcome to the Elevator Simulation!\n");
    run_elevator_simulation();
    return 0;
}