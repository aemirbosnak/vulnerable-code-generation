//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    int direction; // 1 for up, -1 for down, 0 for idle
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0;
    elevator->direction = 0;
}

void call_elevator(Elevator *elevator, int target_floor) {
    if (target_floor < 0 || target_floor >= MAX_FLOORS) {
        printf("Invalid floor requested.\n");
        return;
    }
    
    if (elevator->current_floor == target_floor) {
        printf("Elevator is already on floor %d.\n", target_floor);
        return;
    }
    
    elevator->direction = (target_floor > elevator->current_floor) ? 1 : -1;

    while (elevator->current_floor != target_floor) {
        elevator->current_floor += elevator->direction;
        printf("Elevator moving %s to floor %d...\n", 
                elevator->direction == 1 ? "up" : "down", 
                elevator->current_floor);
        sleep(1); // Simulate time delay for elevator movement
    }
    
    printf("Elevator arrived at floor %d.\n", elevator->current_floor);
    elevator->direction = 0; // Set elevator to idle
}

void display_menu() {
    printf("\n=====================\n");
    printf(" Elevator Simulation \n");
    printf("=====================\n");
    printf("1. Call Elevator to Floor\n");
    printf("2. Exit\n");
    printf("=====================\n");
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    
    int choice, target_floor;

    while (true) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter target floor (0 to %d): ", MAX_FLOORS - 1);
                scanf("%d", &target_floor);
                call_elevator(&elevator, target_floor);
                break;
            case 2:
                printf("Exiting the elevator simulation. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}