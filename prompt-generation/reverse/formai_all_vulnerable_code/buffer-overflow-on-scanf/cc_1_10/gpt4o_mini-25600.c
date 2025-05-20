//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10

// Structure to represent the Elevator
typedef struct {
    int current_floor;
    int direction; // 1 for up, -1 for down
    bool doors_open;
} Elevator;

// Function prototypes
void initialize_elevator(Elevator *elevator);
void request_floor(Elevator *elevator, int requested_floor);
void move_elevator(Elevator *elevator);
void open_doors(Elevator *elevator);
void close_doors(Elevator *elevator);
void display_elevator_status(Elevator *elevator);

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    
    int requested_floor;

    while (true) {
        display_elevator_status(&elevator);
        printf("Enter a floor number (1 to %d) (0 to exit): ", MAX_FLOORS);
        scanf("%d", &requested_floor);
        
        if (requested_floor == 0) {
            printf("Exiting the elevator simulation.\n");
            break;
        }
        
        if (requested_floor < 1 || requested_floor > MAX_FLOORS) {
            printf("Invalid floor number! Please try again.\n");
            continue;
        }

        request_floor(&elevator, requested_floor);
        move_elevator(&elevator);
    }

    return 0;
}

// Initializes the elevator state
void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 1; // Start at 1
    elevator->direction = 0; // No direction
    elevator->doors_open = false;
}

// Requests a floor for the elevator to go to
void request_floor(Elevator *elevator, int requested_floor) {
    printf("Requesting floor %d...\n", requested_floor);
    if (requested_floor > elevator->current_floor) {
        elevator->direction = 1; // Moving up
    } else if (requested_floor < elevator->current_floor) {
        elevator->direction = -1; // Moving down
    } else {
        elevator->direction = 0; // Already there
        printf("You are already on floor %d.\n", requested_floor);
        return;
    }
    close_doors(elevator);
}

// Simulates the movement of the elevator
void move_elevator(Elevator *elevator) {
    while (elevator->current_floor != elevator->direction + elevator->current_floor) {
        elevator->current_floor += elevator->direction;
        printf("Moving... Current Floor: %d\n", elevator->current_floor);
        sleep(1); // Simulate time taken to move
    }
    open_doors(elevator);
}

// Opens the elevator doors
void open_doors(Elevator *elevator) {
    elevator->doors_open = true;
    printf("Elevator doors opened on floor %d.\n", elevator->current_floor);
}

// Closes the elevator doors
void close_doors(Elevator *elevator) {
    elevator->doors_open = false;
    printf("Closing elevator doors...\n");
    sleep(1); // Simulate time taken to close doors
}

// Displays the current status of the elevator
void display_elevator_status(Elevator *elevator) {
    printf("\nElevator Status:\n");
    printf("Current Floor: %d\n", elevator->current_floor);
    printf("Direction: %s\n", elevator->direction == 1 ? "Up" : 
                                   elevator->direction == -1 ? "Down" : "Stationary");
    printf("Doors are currently: %s\n", elevator->doors_open ? "Open" : "Closed");
}