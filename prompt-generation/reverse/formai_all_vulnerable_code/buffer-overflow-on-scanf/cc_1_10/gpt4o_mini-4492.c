//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define ELEVATOR_IDLE 0
#define ELEVATOR_MOVING_UP 1
#define ELEVATOR_MOVING_DOWN 2

typedef struct {
    int current_floor;
    int direction;
    int requested_floors[MAX_FLOORS];
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0;
    elevator->direction = ELEVATOR_IDLE;
    for (int i = 0; i < MAX_FLOORS; i++) {
        elevator->requested_floors[i] = 0;
    }
}

void request_floor(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor: %d\n", floor);
        return;
    }
    elevator->requested_floors[floor] = 1;
    printf("Floor %d requested.\n", floor);
}

void move_elevator(Elevator *elevator) {
    if (elevator->direction == ELEVATOR_IDLE) {
        for (int i = 0; i < MAX_FLOORS; i++) {
            if (elevator->requested_floors[i]) {
                if (i > elevator->current_floor) {
                    elevator->direction = ELEVATOR_MOVING_UP;
                } else {
                    elevator->direction = ELEVATOR_MOVING_DOWN;
                }
                break;
            }
        }
    }  

    if (elevator->direction == ELEVATOR_MOVING_UP) {
        if (elevator->current_floor < MAX_FLOORS - 1) {
            elevator->current_floor++;
            printf("Elevator moving up to floor %d\n", elevator->current_floor);
            usleep(1000000); // Simulate time taken to move
        } else {
            elevator->direction = ELEVATOR_IDLE;
        }
    } else if (elevator->direction == ELEVATOR_MOVING_DOWN) {
        if (elevator->current_floor > 0) {
            elevator->current_floor--;
            printf("Elevator moving down to floor %d\n", elevator->current_floor);
            usleep(1000000); // Simulate time taken to move
        } else {
            elevator->direction = ELEVATOR_IDLE;
        }
    }

    // Check if the current floor has requests
    if (elevator->requested_floors[elevator->current_floor]) {
        printf("Stopping at floor %d\n", elevator->current_floor);
        elevator->requested_floors[elevator->current_floor] = 0;
    }
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);

    int choice;
    while (1) {
        printf("\nElevator Simulation:\n");
        printf("1. Request floor (0-%d)\n", MAX_FLOORS - 1);
        printf("2. Move elevator\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int floor;
                printf("Enter floor number to request: ");
                scanf("%d", &floor);
                request_floor(&elevator, floor);
                break;
            }
            case 2:
                move_elevator(&elevator);
                break;
            case 3:
                printf("Exiting simulation.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}