//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>
#include <stdbool.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
} Elevator;

void display_menu() {
    printf("\n----- Elevator Simulation -----\n");
    printf("Current Floor: ");
}

void go_to_floor(Elevator *elevator, int requested_floor) {
    if (requested_floor < 0 || requested_floor >= MAX_FLOORS) {
        printf("Invalid floor!\n");
        return;
    }

    printf("Moving from floor %d to floor %d...\n", elevator->current_floor, requested_floor);
    elevator->current_floor = requested_floor;
    printf("Arrived at floor %d.\n", elevator->current_floor);
}

void prompt_user(Elevator *elevator) {
    display_menu();
    printf("%d\n", elevator->current_floor);
    printf("Enter the floor number (0 to %d) or -1 to exit: ", MAX_FLOORS - 1);
    
    int requested_floor;
    scanf("%d", &requested_floor);

    if (requested_floor == -1) {
        printf("Exiting the elevator simulation. Goodbye!\n");
        return;
    }

    go_to_floor(elevator, requested_floor);
    prompt_user(elevator); // Recursive call
}

int main() {
    Elevator elevator = {0}; // Start at the ground floor

    printf("Welcome to the Elevator Simulation!\n");
    prompt_user(&elevator);

    return 0;
}