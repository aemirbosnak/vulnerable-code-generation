//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    int target_floor;
    int moving_up; // 1 for up, 0 for down
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // Start at ground floor
    elevator->target_floor = -1; // No target initially
    elevator->moving_up = 1; // Default to moving up
}

void request_elevator(Elevator *elevator, int requested_floor) {
    if (requested_floor < 0 || requested_floor >= MAX_FLOORS) {
        printf("Invalid floor request. Please choose a floor between 0 and %d.\n", MAX_FLOORS - 1);
        return;
    }
    
    printf("Elevator requested to floor %d.\n", requested_floor);
    elevator->target_floor = requested_floor;
    elevator->moving_up = (requested_floor > elevator->current_floor) ? 1 : 0;
}

void move_elevator(Elevator *elevator) {
    if (elevator->target_floor == -1) {
        printf("No target floor set. Please request a floor.\n");
        return;
    }

    while (elevator->current_floor != elevator->target_floor) {
        sleep(1); // Simulate the time taken to move between floors
        
        if (elevator->moving_up) {
            elevator->current_floor++;
            printf("Elevator moving up to floor %d.\n", elevator->current_floor);
        } else {
            elevator->current_floor--;
            printf("Elevator moving down to floor %d.\n", elevator->current_floor);
        }
    }

    printf("Elevator has arrived at floor %d.\n", elevator->current_floor);
    elevator->target_floor = -1; // Reset target after arriving
}

void display_current_floor(Elevator *elevator) {
    printf("Elevator is currently at floor %d.\n", elevator->current_floor);
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);

    int input;

    while (1) {
        display_current_floor(&elevator);
        printf("Enter the floor number to request the elevator (0 - %d), or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &input);

        if (input == -1) {
            printf("Exiting the elevator simulation. Goodbye!\n");
            break;
        }

        request_elevator(&elevator, input);
        move_elevator(&elevator);
    }

    return 0;
}