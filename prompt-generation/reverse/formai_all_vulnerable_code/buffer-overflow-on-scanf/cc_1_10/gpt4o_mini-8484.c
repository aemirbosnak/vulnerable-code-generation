//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_REQUESTS 20

typedef struct {
    int current_floor;
    int requests[MAX_REQUESTS];
    int request_count;
    int direction; // 1 for up, -1 for down
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // start from ground floor
    elevator->request_count = 0;
    elevator->direction = 0; // no direction
}

void request_floor(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor: %d. Must be between 0 and %d.\n", floor, MAX_FLOORS - 1);
        return;
    }
    if (elevator->request_count < MAX_REQUESTS) {
        elevator->requests[elevator->request_count++] = floor;
        printf("Requested floor %d added to the elevator requests.\n", floor);
    } else {
        printf("Request limit reached. Please wait for previous requests to be fulfilled.\n");
    }
}

void move_elevator(Elevator *elevator) {
    if (elevator->request_count == 0) {
        printf("No requests to handle.\n");
        return;
    }

    while (elevator->request_count > 0) {
        if (elevator->direction == 0) {
            elevator->direction = (elevator->requests[0] > elevator->current_floor) ? 1 : -1;
        }

        if (elevator->direction == 1) {
            for (int i = 0; i < elevator->request_count; i++) {
                if (elevator->requests[i] > elevator->current_floor) {
                    elevator->current_floor++;
                    printf("Moving up: Current floor %d\n", elevator->current_floor);
                    if (elevator->current_floor == elevator->requests[i]) {
                        printf("Arrived at floor %d\n", elevator->current_floor);
                        elevator->requests[i] = elevator->requests[elevator->request_count - 1];
                        elevator->request_count--;
                        i--; // Check current index again since it's now valid
                    }
                }
            }
        } else {
            for (int i = elevator->request_count - 1; i >= 0; i--) {
                if (elevator->requests[i] < elevator->current_floor) {
                    elevator->current_floor--;
                    printf("Moving down: Current floor %d\n", elevator->current_floor);
                    if (elevator->current_floor == elevator->requests[i]) {
                        printf("Arrived at floor %d\n", elevator->current_floor);
                        elevator->requests[i] = elevator->requests[elevator->request_count - 1];
                        elevator->request_count--;
                        i++; // Check current index again since it's now valid
                    }
                }
            }
        }

        if (elevator->request_count > 0 && elevator->current_floor == elevator->requests[0]) {
            elevator->direction = (elevator->requests[0] > elevator->current_floor) ? 1 : -1;
        }
    }

    elevator->direction = 0; // reset direction after finishing requests
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    int choice, floor;

    printf("=== Elevator Simulation ===\n");
    do {
        printf("\n1. Request Floor\n2. Move Elevator\n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter floor to request (0 to %d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                request_floor(&elevator, floor);
                break;
            case 2:
                move_elevator(&elevator);
                break;
            case 3:
                printf("Exiting the simulation.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}