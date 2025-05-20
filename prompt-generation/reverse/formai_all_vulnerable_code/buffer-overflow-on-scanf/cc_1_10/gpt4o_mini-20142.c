//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int current_floor;
    int direction; // -1 = down, 0 = idle, 1 = up
    int occupants;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 1;
    elevator->direction = 0; // idle
    elevator->occupants = 0;
}

void display_status(Elevator *elevator) {
    printf("Elevator status:\n");
    printf("Current Floor: %d\n", elevator->current_floor);
    printf("Direction: %s\n", elevator->direction == 1 ? "Up" : elevator->direction == -1 ? "Down" : "Idle");
    printf("Occupants: %d\n\n", elevator->occupants);
}

void move_elevator(Elevator *elevator) {
    if (elevator->direction == 1 && elevator->current_floor < MAX_FLOORS) {
        elevator->current_floor++;
    } else if (elevator->direction == -1 && elevator->current_floor > 1) {
        elevator->current_floor--;
    } else {
        elevator->direction = 0; // stops if it can't go further
    }
}

bool enter_elevator(Elevator *elevator) {
    if (elevator->occupants < MAX_CAPACITY) {
        elevator->occupants++;
        printf("A person entered the elevator. Total occupants: %d\n", elevator->occupants);
        return true;
    } else {
        printf("Elevator is full! Cannot enter.\n");
        return false;
    }
}

bool exit_elevator(Elevator *elevator) {
    if (elevator->occupants > 0) {
        elevator->occupants--;
        printf("A person exited the elevator. Total occupants: %d\n", elevator->occupants);
        return true;
    } else {
        printf("No occupants to exit!\n");
        return false;
    }
}

void call_elevator(Elevator *elevator, int requested_floor) {
    if (requested_floor < 1 || requested_floor > MAX_FLOORS) {
        printf("Invalid floor request!\n");
        return;
    }

    if (elevator->current_floor < requested_floor) {
        elevator->direction = 1; // going up
    } else if (elevator->current_floor > requested_floor) {
        elevator->direction = -1; // going down
    } else {
        elevator->direction = 0; // already at requested floor
    }
    
    printf("Elevator called to floor %d\n", requested_floor);
}

void simulate_elevator(Elevator *elevator) {
    int action;
    do {
        display_status(elevator);
        printf("Choose an action:\n");
        printf("1. Enter Elevator\n");
        printf("2. Exit Elevator\n");
        printf("3. Call Elevator to a floor (1-%d)\n", MAX_FLOORS);
        printf("4. Move Elevator\n");
        printf("5. Exit Simulation\n");
        printf("Enter your choice: ");
        
        scanf("%d", &action);
        
        switch(action) {
            case 1:
                enter_elevator(elevator);
                break;
            case 2:
                exit_elevator(elevator);
                break;
            case 3: {
                int floor;
                printf("Enter the floor number: ");
                scanf("%d", &floor);
                call_elevator(elevator, floor);
                break;
            }
            case 4:
                move_elevator(elevator);
                printf("Elevator moved.\n");
                break;
            case 5:
                printf("Exiting simulation.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        sleep(1); // pause for a moment to observe the changes
    } while(action != 5);
}

int main() {
    Elevator elevator;

    initialize_elevator(&elevator);
    simulate_elevator(&elevator);

    return 0;
}