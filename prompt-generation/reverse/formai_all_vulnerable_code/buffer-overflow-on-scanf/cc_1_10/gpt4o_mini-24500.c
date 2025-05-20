//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_REQUESTS 5

typedef struct Elevator {
    int current_floor;
    int destination_floor[MAX_REQUESTS];
    int request_count;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // Ground floor
    elevator->request_count = 0;
    for (int i = 0; i < MAX_REQUESTS; i++) {
        elevator->destination_floor[i] = -1; // No requests initially
    }
}

void request_floor(Elevator *elevator, int floor) {
    if (elevator->request_count < MAX_REQUESTS && floor >= 0 && floor < MAX_FLOORS) {
        elevator->destination_floor[elevator->request_count++] = floor;
        printf("Floor %d requested.\n", floor);
    } else {
        printf("Unable to request floor %d. Please ensure floor is between 0 and %d and request limit is not exceeded.\n", floor, MAX_FLOORS - 1);
    }
}

void move_elevator(Elevator *elevator) {
    while (elevator->request_count > 0) {
        int next_floor = elevator->destination_floor[0];
        
        // Move to the next requested floor
        printf("Elevator moving from floor %d to floor %d...\n", elevator->current_floor, next_floor);
        while (elevator->current_floor != next_floor) {
            if (elevator->current_floor < next_floor) {
                elevator->current_floor++;
            } else {
                elevator->current_floor--;
            }
            printf("Current floor: %d\n", elevator->current_floor);
            sleep(1); // Simulate time taken to move
        }
        
        printf("Elevator has arrived at floor %d.\n", elevator->current_floor);
        
        // Remove the fulfilled request
        for (int i = 0; i < elevator->request_count - 1; i++) {
            elevator->destination_floor[i] = elevator->destination_floor[i + 1];
        }
        elevator->destination_floor[--elevator->request_count] = -1; // Clear the last entry
    }
    printf("All requests have been fulfilled.\n");
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);

    int choice, floor;

    while (true) {
        printf("\nElevator Simulation:\n");
        printf("1. Request Floor\n");
        printf("2. Move Elevator\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the floor you want to go to (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                request_floor(&elevator, floor);
                break;
            case 2:
                move_elevator(&elevator);
                break;
            case 3:
                printf("Exiting simulation...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}