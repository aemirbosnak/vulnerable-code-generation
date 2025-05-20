//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct Elevator {
    int current_floor;
    bool direction; // true for up, false for down
} Elevator;

void initialize(Elevator *elevator) {
    elevator->current_floor = 0; // Start at ground floor
    elevator->direction = true; // Start moving up
}

void display_elevator_status(Elevator *elevator) {
    printf("Elevator is currently at floor %d.\n", elevator->current_floor);
}

void move_elevator(Elevator *elevator) {
    if (elevator->direction) {
        if (elevator->current_floor < MAX_FLOORS - 1) {
            elevator->current_floor++;
        } else {
            elevator->direction = false; // Change direction if at the top floor
        }
    } else {
        if (elevator->current_floor > 0) {
            elevator->current_floor--;
        } else {
            elevator->direction = true; // Change direction if at the ground floor
        }
    }
    printf("Elevator is moving %s to floor %d...\n", elevator->direction ? "up" : "down", elevator->current_floor);
}

void request_elevator(Elevator *elevator, int requested_floor) {
    printf("Request received for floor %d.\n", requested_floor);
    while (elevator->current_floor != requested_floor) {
        move_elevator(elevator);
        sleep(1); // Simulate the time taken to move between floors
    }
    display_elevator_status(elevator);
}

void prompt_user(Elevator *elevator) {
    int requested_floor;
    while (true) {
        printf("Enter the floor you want to go to (0 to %d) or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &requested_floor);

        if (requested_floor == -1) {
            printf("Exiting the elevator simulation. Goodbye!\n");
            break;
        } else if (requested_floor < 0 || requested_floor >= MAX_FLOORS) {
            printf("Invalid floor! Please try again.\n");
        } else {
            request_elevator(elevator, requested_floor);
        }
    }
}

int main() {
    Elevator elevator;
    initialize(&elevator);
    
    printf("Welcome to the Elevator Simulation!\n");
    printf("The elevator can take you from floor %d to floor %d.\n", 0, MAX_FLOORS - 1);

    prompt_user(&elevator);

    return 0;
}