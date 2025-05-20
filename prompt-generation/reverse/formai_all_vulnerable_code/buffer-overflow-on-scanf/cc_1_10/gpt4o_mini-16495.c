//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    bool direction_up;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // Starting from the ground floor
    elevator->direction_up = true; // Initially going up
}

void display_elevator_status(const Elevator *elevator) {
    printf("Elevator is currently on floor %d.\n", elevator->current_floor + 1);
}

void move_elevator(Elevator *elevator, int target_floor) {
    while (elevator->current_floor != target_floor) {
        display_elevator_status(elevator);
        
        if (target_floor > elevator->current_floor) {
            elevator->current_floor++;
            elevator->direction_up = true;
            printf("Elevator is moving up to floor %d...\n", elevator->current_floor + 1);
        }
        else {
            elevator->current_floor--;
            elevator->direction_up = false;
            printf("Elevator is moving down to floor %d...\n", elevator->current_floor + 1);
        }
        
        sleep(1); // Simulate time taken to move between floors
    }

    printf("Elevator has arrived at floor %d.\n", elevator->current_floor + 1);
}

void request_elevator(Elevator *elevator) {
    int target_floor;

    printf("Please enter the target floor (1 to %d): ", MAX_FLOORS);
    scanf("%d", &target_floor);

    // Validate target floor
    if (target_floor < 1 || target_floor > MAX_FLOORS) {
        printf("Invalid floor. Please enter a number between 1 and %d.\n", MAX_FLOORS);
    } else {
        move_elevator(elevator, target_floor - 1); // Adjust for 0-indexed array
    }
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    
    char continue_simulation;

    do {
        request_elevator(&elevator);
        
        printf("Do you want to make another request? (y/n): ");
        scanf(" %c", &continue_simulation);
    } while (continue_simulation == 'y' || continue_simulation == 'Y');

    printf("Thanks for using the elevator simulation!\n");
    return 0;
}