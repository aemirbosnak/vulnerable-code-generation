//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    bool doors_open;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // The ground floor
    elevator->doors_open = false;
}

void open_doors(Elevator *elevator) {
    elevator->doors_open = true;
    printf("Doors are now open at floor %d.\n", elevator->current_floor);
}

void close_doors(Elevator *elevator) {
    elevator->doors_open = false;
    printf("Doors are now closed.\n");
}

void move_elevator(Elevator *elevator, int target_floor) {
    if (target_floor < 0 || target_floor >= MAX_FLOORS) {
        printf("Invalid floor selection. Please select a floor between 0 and %d.\n", MAX_FLOORS - 1);
        return;
    }

    close_doors(elevator);
    printf("Moving from floor %d to floor %d...\n", elevator->current_floor, target_floor);
    elevator->current_floor = target_floor;
    open_doors(elevator);
}

void display_menu() {
    printf("\nElevator Control System\n");
    printf("Select the floor (0 to %d) or -1 to exit:\n", MAX_FLOORS - 1);
}

int main() {
    Elevator elevator;
    int target_floor;
    initialize_elevator(&elevator);

    while (true) {
        display_menu();
        scanf("%d", &target_floor);

        if (target_floor == -1) {
            printf("Exiting the elevator system. Goodbye!\n");
            break;
        }

        move_elevator(&elevator, target_floor);
    }

    return 0;
}