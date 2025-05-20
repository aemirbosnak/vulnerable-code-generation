//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    int target_floor;
    bool going_up;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0;  // Start at ground floor
    elevator->target_floor = -1;   // No target set
    elevator->going_up = true;
}

void request_floor(Elevator *elevator, int floor) {
    if (floor >= 0 && floor < MAX_FLOORS) {
        elevator->target_floor = floor;
        elevator->going_up = (floor > elevator->current_floor);
        printf("Floor %d requested.\n", floor);
    } else {
        printf("Invalid floor number!\n");
    }
}

void move_elevator(Elevator *elevator) {
    if (elevator->target_floor == -1) {
        printf("No floor requested.\n");
        return;
    }

    printf("Moving %s...\n", (elevator->going_up ? "up" : "down"));
    
    while (elevator->current_floor != elevator->target_floor) {
        if (elevator->going_up) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }

        printf("Current floor: %d\n", elevator->current_floor);
        sleep(1);  // Simulate time taken to move
    }

    printf("Arrived at floor %d!\n", elevator->current_floor);
    elevator->target_floor = -1;  // Reset target once arrived
}

void display_menu() {
    printf("Elevator Simulation Menu:\n");
    printf("1. Request Floor\n");
    printf("2. Move Elevator\n");
    printf("3. Exit\n");
    printf("Please select an option (1-3): ");
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    int choice;
    int requested_floor;

    while (true) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter floor (0 - %d): ", MAX_FLOORS - 1);
                scanf("%d", &requested_floor);
                request_floor(&elevator, requested_floor);
                break;
            case 2:
                move_elevator(&elevator);
                break;
            case 3:
                printf("Exiting simulation. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}