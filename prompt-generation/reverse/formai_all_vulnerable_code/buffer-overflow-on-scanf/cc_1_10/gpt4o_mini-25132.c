//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    bool doors_open;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // Start on ground floor
    elevator->doors_open = true;  // Doors open when system starts
}

void display_status(Elevator *elevator) {
    printf("\nElevator Status:\n");
    printf("Current Floor: %d\n", elevator->current_floor);
    printf("Doors are %s\n", elevator->doors_open ? "Open" : "Closed");
}

void move_elevator(Elevator *elevator, int target_floor) {
    if (target_floor < 0 || target_floor >= MAX_FLOORS) {
        printf("Invalid floor request: %d\n", target_floor);
        return;
    }
    
    elevator->doors_open = false; // Close doors before moving
    printf("Moving from floor %d to floor %d...\n", elevator->current_floor, target_floor);
    
    while (elevator->current_floor != target_floor) {
        if (elevator->current_floor < target_floor) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }
        printf("Current floor: %d\n", elevator->current_floor);
        sleep(1); // Simulate the time taken to move between floors
    }

    elevator->doors_open = true; // Open doors upon arriving
    printf("Arrived on floor %d. Doors are now open.\n", elevator->current_floor);
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    
    while (true) {
        display_status(&elevator);
        
        int requested_floor;
        printf("Enter the floor number (0-%d) to request the elevator, or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &requested_floor);
        
        if (requested_floor == -1) {
            printf("Exiting the elevator simulation. Bye!\n");
            break;
        }
        
        move_elevator(&elevator, requested_floor);
    }
    
    return 0;
}