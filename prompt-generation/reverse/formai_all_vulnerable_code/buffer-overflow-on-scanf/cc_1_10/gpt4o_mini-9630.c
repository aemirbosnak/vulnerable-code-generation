//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    bool going_up;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0;  // Starts at ground floor
    elevator->going_up = true;     // Initial direction
}

void display_elevator_status(Elevator *elevator) {
    printf("Elevator is currently at floor %d and moving %s.\n", 
           elevator->current_floor, elevator->going_up ? "up" : "down");
}

void move_elevator(Elevator *elevator, int target_floor) {
    while (elevator->current_floor != target_floor) {
        if (target_floor > elevator->current_floor) {
            elevator->going_up = true;
            elevator->current_floor++;
        } else {
            elevator->going_up = false;
            elevator->current_floor--;
        }
        display_elevator_status(elevator);
        sleep(1);  // Simulate time taken to move
    }
    printf("Elevator has reached floor %d.\n", elevator->current_floor);
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);

    int requests[MAX_FLOORS];
    int floor_count = 0;

    printf("Welcome to the Elevator Simulation!\n");
    printf("You can request the elevator to any floor (0 to %d). Type -1 to finish.\n", MAX_FLOORS - 1);

    while (true) {
        int request;
        printf("Enter a floor request: ");
        scanf("%d", &request);

        if (request == -1) {
            break;  // End input
        }
        if (request < 0 || request >= MAX_FLOORS) {
            printf("Invalid floor request! Please choose a floor between 0 and %d.\n", MAX_FLOORS - 1);
            continue;
        }

        requests[floor_count++] = request;
        printf("Elevator request received for floor %d.\n", request);
        
        // Process the requests
        for (int i = 0; i < floor_count; i++) {
            move_elevator(&elevator, requests[i]);
        }
        
        // Reset requests
        floor_count = 0;
    }

    printf("Exiting simulation. Thank you for using the elevator!\n");
    return 0;
}