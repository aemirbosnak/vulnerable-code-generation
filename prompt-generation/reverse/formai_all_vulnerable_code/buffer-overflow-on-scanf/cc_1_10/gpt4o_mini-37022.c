//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    int destination_floor;
    int is_moving;
} Elevator;

void print_elevator_state(Elevator elevator) {
    printf("\n--- Elevator Status ---\n");
    printf("Current Floor: %d\n", elevator.current_floor);
    printf("Destination Floor: %d\n", elevator.destination_floor);
    printf("Moving: %s\n", elevator.is_moving ? "Yes" : "No");
    printf("-----------------------\n");
}

void move_elevator(Elevator *elevator) {
    if (elevator->current_floor < elevator->destination_floor) {
        while (elevator->current_floor < elevator->destination_floor) {
            elevator->is_moving = 1;
            elevator->current_floor++;
            print_elevator_state(*elevator);
            sleep(1); // Simulate time taken to move
        }
    } else if (elevator->current_floor > elevator->destination_floor) {
        while (elevator->current_floor > elevator->destination_floor) {
            elevator->is_moving = 1;
            elevator->current_floor--;
            print_elevator_state(*elevator);
            sleep(1); // Simulate time taken to move
        }
    }
    elevator->is_moving = 0;
    printf("Elevator has arrived at floor %d.\n", elevator->current_floor);
}

int main() {
    Elevator elevator = {1, 1, 0}; // Starting on floor 1
    int desired_floor;

    printf("Welcome to the Elevator Simulation!\n");
    printf("The building has %d floors (1 to %d).\n", MAX_FLOORS, MAX_FLOORS);
    
    while (1) {
        print_elevator_state(elevator);
        printf("Enter the floor number (1-%d) to go to, or 0 to exit: ", MAX_FLOORS);
        scanf("%d", &desired_floor);

        if (desired_floor == 0) {
            printf("Exiting elevator simulation. Goodbye!\n");
            break;
        }

        if (desired_floor < 1 || desired_floor > MAX_FLOORS) {
            printf("Invalid floor selected. Please try again.\n");
            continue;
        }

        elevator.destination_floor = desired_floor;
        move_elevator(&elevator);
    }

    return 0;
}