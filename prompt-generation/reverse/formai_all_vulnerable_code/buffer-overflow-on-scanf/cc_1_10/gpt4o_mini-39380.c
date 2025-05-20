//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    bool direction; // true for up, false for down
} Elevator;

void call_elevator(Elevator* elevator, int requested_floor);
void move_elevator(Elevator* elevator);
void display_elevator_status(Elevator* elevator);
void user_interface(Elevator* elevator);

int main() {
    Elevator elevator = {0, true}; // Start at ground floor (0) and going up
    user_interface(&elevator);
    return 0;
}

void call_elevator(Elevator* elevator, int requested_floor) {
    if (requested_floor < 0 || requested_floor >= MAX_FLOORS) {
        printf("Invalid floor request. Please select between 0 and %d.\n", MAX_FLOORS - 1);
        return;
    }
    
    if (elevator->current_floor == requested_floor) {
        printf("Elevator is already at floor %d.\n", requested_floor);
    } else {
        printf("Calling elevator to floor %d...\n", requested_floor);
        elevator->direction = (requested_floor > elevator->current_floor);
        move_elevator(elevator);
    }
}

void move_elevator(Elevator* elevator) {
    while (elevator->current_floor != -1 && elevator->current_floor != MAX_FLOORS) {
        if (elevator->direction) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }
        display_elevator_status(elevator);
        sleep(1); // Simulate time taken to move
    }
}

void display_elevator_status(Elevator* elevator) {
    printf("Elevator is now at floor %d.\n", elevator->current_floor);
}

void user_interface(Elevator* elevator) {
    int requested_floor;
    while (true) {
        printf("Current floor: %d\n", elevator->current_floor);
        printf("Please enter a desired floor (0-%d) or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &requested_floor);

        if (requested_floor == -1) {
            printf("Exiting the elevator simulation.\n");
            break;
        }

        call_elevator(elevator, requested_floor);
    }
}