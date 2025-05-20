//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_REQUESTS 10

typedef struct Elevator {
    int current_floor;
    int requests[MAX_REQUESTS];
    int request_count;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // Start at ground floor
    elevator->request_count = 0;
}

void request_floor(Elevator *elevator, int floor) {
    if (elevator->request_count < MAX_REQUESTS && floor >= 0 && floor < MAX_FLOORS) {
        elevator->requests[elevator->request_count++] = floor;
        printf("Requested floor: %d\n", floor);
    } else {
        printf("Invalid request or too many requests!\n");
    }
}

void move_elevator(Elevator *elevator) {
    for (int i = 0; i < elevator->request_count; ++i) {
        while (elevator->current_floor != elevator->requests[i]) {
            if (elevator->current_floor < elevator->requests[i]) {
                elevator->current_floor++;
            } else {
                elevator->current_floor--;
            }
            printf("Elevator at floor: %d\n", elevator->current_floor);
            sleep(1); // Simulate time taken to move
        }
        printf("Elevator arrived at floor: %d\n", elevator->current_floor);
    }
    elevator->request_count = 0; // Clear requests after serving
}

void show_instructions() {
    printf("Elevator Simulation\n");
    printf("Enter floor numbers (0 to %d) to request, -1 to exit:\n", MAX_FLOORS - 1);
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    int floor;

    show_instructions();

    while (1) {
        printf("Current elevator at floor: %d\n", elevator.current_floor);
        printf("Enter floor to request: ");
        scanf("%d", &floor);

        if (floor == -1) {
            printf("Exiting elevator simulation...\n");
            break;
        }

        request_floor(&elevator, floor);
        move_elevator(&elevator);
    }

    return 0;
}