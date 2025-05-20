//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    int desired_floor;
    int is_moving;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // Ground floor
    elevator->desired_floor = -1; // No floor requested
    elevator->is_moving = 0; // Not moving
}

void request_floor(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Floor %d is out of range! Please choose a floor between 0 and %d.\n", floor, MAX_FLOORS - 1);
        return;
    }
    elevator->desired_floor = floor;
    elevator->is_moving = 1;
    printf("Elevator requested to floor %d.\n", floor);
}

void move_elevator(Elevator *elevator) {
    while (elevator->is_moving) {
        if (elevator->current_floor < elevator->desired_floor) {
            printf("Elevator is moving up... Current floor: %d\n", elevator->current_floor);
            elevator->current_floor++;
        } else if (elevator->current_floor > elevator->desired_floor) {
            printf("Elevator is moving down... Current floor: %d\n", elevator->current_floor);
            elevator->current_floor--;
        } else {
            elevator->is_moving = 0; // Reached the desired floor
            printf("Elevator has arrived at floor %d!\n", elevator->current_floor);
        }
        sleep(1); // Simulate time taken for moving
    }
}

void display_menu() {
    printf("\nWelcome to the Elevator Simulation!\n");
    printf("Choose a floor between 0 and %d (or -1 to exit):\n", MAX_FLOORS - 1);
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);

    int requested_floor;

    while (1) {
        display_menu();
        scanf("%d", &requested_floor);

        if (requested_floor == -1) {
            printf("Exiting Elevator Simulation. Have a great day!\n");
            break;
        }

        request_floor(&elevator, requested_floor);
        move_elevator(&elevator);
        elevator.desired_floor = -1; // Reset after reaching floor
    }

    return 0;
}