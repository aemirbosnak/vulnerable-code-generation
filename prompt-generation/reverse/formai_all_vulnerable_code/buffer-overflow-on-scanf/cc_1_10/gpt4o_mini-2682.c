//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    int destination_floor;
    bool is_moving;
} Elevator;

void initialize_elevator(Elevator* elevator) {
    elevator->current_floor = 0; // Ground floor
    elevator->destination_floor = -1; // No destination
    elevator->is_moving = false;
}

void display_elevator_status(Elevator* elevator) {
    printf("Current Floor: %d\n", elevator->current_floor);
    if (elevator->is_moving) {
        printf("Elevator is moving to floor %d...\n", elevator->destination_floor);
    } else {
        printf("Elevator is idle.\n");
    }
}

void call_elevator(Elevator* elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor selected.\n");
        return;
    }
    elevator->destination_floor = floor;
    elevator->is_moving = true;
    printf("Elevator called to floor %d\n", floor);
}

void move_elevator(Elevator* elevator) {
    if (elevator->is_moving) {
        while (elevator->current_floor != elevator->destination_floor) {
            if (elevator->current_floor < elevator->destination_floor) {
                elevator->current_floor++;
            } else {
                elevator->current_floor--;
            }
            sleep(1); // Simulate time taken to move
            printf("Elevator at floor %d\n", elevator->current_floor);
        }
        elevator->is_moving = false;
        printf("Elevator arrived at floor %d.\n", elevator->current_floor);
    }
}

void simulate_elevator(Elevator* elevator) {
    bool running = true;
    int command;

    while (running) {
        display_elevator_status(elevator);
        printf("Enter a floor to go to (0-%d), or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &command);

        if (command == -1) {
            printf("Exiting the elevator simulation.\n");
            running = false;
        } else {
            call_elevator(elevator, command);
            move_elevator(elevator);
        }
        printf("\n");
    }
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    printf("Welcome to the Elevator Simulation.\n");
    simulate_elevator(&elevator);
    return 0;
}