//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    bool door_open;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0;  // Starting at ground floor (0)
    elevator->door_open = false;   // Doors are initially closed
}

void open_door(Elevator *elevator) {
    elevator->door_open = true;
    printf("Doors are now open at floor %d.\n", elevator->current_floor);
}

void close_door(Elevator *elevator) {
    elevator->door_open = false;
    printf("Doors are now closed.\n");
}

void move_elevator(Elevator *elevator, int requested_floor) {
    if (requested_floor < 0 || requested_floor >= MAX_FLOORS) {
        printf("Invalid floor request. Please select a floor between 0 and %d.\n", MAX_FLOORS - 1);
        return;
    }
    
    close_door(elevator); 
    printf("Moving from floor %d to floor %d...\n", elevator->current_floor, requested_floor);

    // Simulate movement
    for (int i = elevator->current_floor; i != requested_floor; i += (requested_floor > i) ? 1 : -1) {
        elevator->current_floor = i;
        printf("Elevator at floor %d...\n", elevator->current_floor);
        // Simulate some delay for elevator movement
        for (volatile int j = 0; j < 100000000; j++);
    }
    
    elevator->current_floor = requested_floor;
    open_door(elevator);
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    
    int requested_floor;
    char choice;

    do {
        printf("\nCurrent Floor: %d\n", elevator.current_floor);
        printf("What floor would you like to go to? (0-%d): ", MAX_FLOORS - 1);
        scanf("%d", &requested_floor);

        move_elevator(&elevator, requested_floor);

        printf("Would you like to continue? (y/n): ");
        scanf(" %c", &choice); // Space before %c to consume any newline character

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the elevator simulator!\n");
    return 0;
}