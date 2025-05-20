//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef enum { IDLE, MOVING_UP, MOVING_DOWN } ElevatorStatus;

typedef struct {
    int current_floor;
    ElevatorStatus status;
    int destination_floor;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0;  // Start at ground floor
    elevator->status = IDLE;
    elevator->destination_floor = -1; // No destination
}

void request_floor(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor request: %d\n", floor);
        return;
    }
    elevator->destination_floor = floor;
    
    if (floor > elevator->current_floor) {
        elevator->status = MOVING_UP;
    } else if (floor < elevator->current_floor) {
        elevator->status = MOVING_DOWN;
    }
}

void move_elevator(Elevator *elevator) {
    while (elevator->destination_floor != elevator->current_floor) {
        if (elevator->status == MOVING_UP) {
            elevator->current_floor++;
        } else if (elevator->status == MOVING_DOWN) {
            elevator->current_floor--;
        }
        printf("Elevator is at floor %d\n", elevator->current_floor);
        sleep(1); // Simulate time taken to move
    }
    printf("Elevator arrived at floor %d\n", elevator->current_floor);
    elevator->status = IDLE;
    elevator->destination_floor = -1; // Arrived
}

void print_status(const Elevator *elevator) {
    printf("Current Floor: %d\n", elevator->current_floor);
    printf("Status: %s\n", elevator->status == IDLE ? "Idle" : 
                           elevator->status == MOVING_UP ? "Moving Up" : "Moving Down");
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);

    int choice;
    while (1) {
        print_status(&elevator);
        printf("Select a floor (0 to %d) to request elevator (or -1 to exit): ", MAX_FLOORS - 1);
        scanf("%d", &choice);

        if (choice == -1) {
            printf("Exiting elevator simulation. Goodbye!\n");
            break;
        }

        request_floor(&elevator, choice);
        move_elevator(&elevator);
    }

    return 0;
}