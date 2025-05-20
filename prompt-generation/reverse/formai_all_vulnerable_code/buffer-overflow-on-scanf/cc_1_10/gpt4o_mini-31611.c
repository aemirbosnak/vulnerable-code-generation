//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    int requested_floor;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0;
    elevator->requested_floor = -1;
}

void display_elevator_status(Elevator *elevator) {
    printf("\nCurrent Floor: %d", elevator->current_floor);
    if (elevator->requested_floor != -1) {
        printf(" | Requested Floor: %d\n", elevator->requested_floor);
    } else {
        printf(" | No floor requested\n");
    }
}

void request_floor(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor request. Please select a floor between 0 and %d.\n", MAX_FLOORS - 1);
    } else {
        elevator->requested_floor = floor;
        printf("Floor %d requested.\n", floor);
    }
}

void move_elevator(Elevator *elevator) {
    if (elevator->requested_floor == -1) {
        printf("No floor has been requested!\n");
        return;
    }

    printf("\nElevator is moving...");
    while (elevator->current_floor != elevator->requested_floor) {
        sleep(1);  // Simulate time taken to move
        if (elevator->current_floor < elevator->requested_floor) {
            elevator->current_floor++;
            printf("\nUp to floor %d", elevator->current_floor);
        } else {
            elevator->current_floor--;
            printf("\nDown to floor %d", elevator->current_floor);
        }
    }

    printf("\nElevator has arrived at floor %d.\n", elevator->current_floor);
    elevator->requested_floor = -1; // Reset after arrival
}

void display_floor_menu() {
    printf("\n=== Welcome to the Elevator ===\n");
    printf("Please select a floor (0-%d) or -1 to exit:\n", MAX_FLOORS - 1);
}

int main() {
    Elevator elevator;
    int chosen_floor;

    initialize_elevator(&elevator);

    while (1) {
        display_elevator_status(&elevator);

        display_floor_menu();
        printf("Your choice: ");
        scanf("%d", &chosen_floor);

        if (chosen_floor == -1) {
            printf("Exiting the elevator simulation. Have a great day!\n");
            break;
        }

        request_floor(&elevator, chosen_floor);
        move_elevator(&elevator);
    }

    return 0;
}