//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct Elevator {
    int current_floor;
    int destination_floor;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // Start at ground floor
    elevator->destination_floor = 0; // No destination yet
}

void display_elevator_status(Elevator *elevator) {
    printf("Elevator is currently on floor: %d\n", elevator->current_floor);
}

void call_elevator(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor! Please choose a floor between 0 and %d.\n", MAX_FLOORS - 1);
        return;
    }
    elevator->destination_floor = floor;
    printf("Elevator called to floor: %d\n", floor);
}

void move_elevator(Elevator *elevator) {
    if (elevator->destination_floor < 0 || elevator->destination_floor >= MAX_FLOORS) {
        printf("Elevator can't move to an invalid floor!\n");
        return;
    }

    printf("Elevator moving ");
    while (elevator->current_floor != elevator->destination_floor) {
        if (elevator->current_floor < elevator->destination_floor) {
            elevator->current_floor++;
            printf("up to floor %d\n", elevator->current_floor);
        } else {
            elevator->current_floor--;
            printf("down to floor %d\n", elevator->current_floor);
        }
        sleep(1); // Simulate time taken to move between floors
    }

    printf("Elevator arrived at floor %d! Doors opening...\n", elevator->current_floor);
    sleep(2); // Simulate doors opening
    printf("Doors are now open!\n");
}

void close_doors() {
    printf("Doors are closing...\n");
    sleep(2);
    printf("Doors are now closed!\n");
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    int choice;

    printf("Welcome to the Elevator Simulation! 🚠\n");

    while (1) {
        display_elevator_status(&elevator);
        printf("Please select a floor to go to (0-%d) or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &choice);

        if (choice == -1) {
            printf("Exiting the Elevator Simulation. Goodbye! 😊\n");
            break;
        }

        call_elevator(&elevator, choice);
        move_elevator(&elevator);
        close_doors();
        elevator.destination_floor = 0; // Reset destination after reaching
    }

    return 0;
}