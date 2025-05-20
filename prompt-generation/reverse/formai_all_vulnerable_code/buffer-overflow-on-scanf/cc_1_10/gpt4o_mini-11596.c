//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    int destination_floor;
    bool moving_up;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // Start at ground floor
    elevator->destination_floor = -1; // No destination set
    elevator->moving_up = false;
}

void display_floor(int floor) {
    printf("You are currently at floor %d.\n", floor);
}

void request_floor(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor selection. Please choose a floor between 0 and %d.\n", MAX_FLOORS-1);
        return;
    }
    elevator->destination_floor = floor;
    elevator->moving_up = (elevator->destination_floor > elevator->current_floor);
}

void move_elevator(Elevator *elevator) {
    while (elevator->current_floor != elevator->destination_floor) {
        if (elevator->moving_up) {
            elevator->current_floor++;
            printf("Moving up to floor %d...\n", elevator->current_floor);
        } else {
            elevator->current_floor--;
            printf("Moving down to floor %d...\n", elevator->current_floor);
        }
        display_floor(elevator->current_floor);
        sleep(1);
    }
    printf("Arrived at floor %d!\n", elevator->current_floor);
    elevator->destination_floor = -1; // Clear destination after reaching it
}

void show_menu() {
    printf("Welcome to the Elevator Simulation!\n");
    printf("Please choose one of the following options:\n");
    printf("1. Request a floor\n");
    printf("2. Exit\n");
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    
    int choice, requested_floor;

    while (true) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the floor you want to go to (0 to %d): ", MAX_FLOORS-1);
                scanf("%d", &requested_floor);
                request_floor(&elevator, requested_floor);
                if (elevator.destination_floor != -1) {
                    move_elevator(&elevator);
                }
                break;
            case 2:
                printf("Exiting simulation. Thank you for using the Elevator!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}