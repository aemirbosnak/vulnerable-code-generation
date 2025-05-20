//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

int main() {
    int floors, current_floor, target_floor, direction, elevator_status;
    bool open_doors = false;

    printf("Enter number of floors: ");
    scanf("%d", &floors);

    current_floor = floors / 2;
    target_floor = current_floor;
    direction = 0;  // 0: stationary, -1: moving down, 1: moving up
    elevator_status = 0;  // 0: doors closed, 1: doors open

    printf("Starting at floor %d\n\n", current_floor);

    while (true) {
        if (elevator_status == 0) {
            printf("\n [ DOORS CLOSED ] \n\n");
            printf("Select a floor: ");
            scanf("%d", &target_floor);

            if (target_floor < current_floor) {
                direction = -1;
            } else if (target_floor > current_floor) {
                direction = 1;
            } else {
                printf("Already on that floor. ");
            }
        }

        if (target_floor != current_floor) {
            printf("\n [ MOVING ");
            if (direction == -1) {
                printf("DOWN");
            } else {
                printf("UP");
            }
            printf(" ] \n\n");

            while (current_floor != target_floor) {
                current_floor += direction;
                printf("Floor %d... ", current_floor);
            }
            printf("\n\n [ ARRIVED ] \n\n");
        }

        elevator_status = 1;
        printf("Doors open. ");
        open_doors = true;

        while (open_doors) {
            printf("Enter 'c' to close the doors: ");
            char input;
            scanf(" %c", &input);

            if (input == 'c') {
                elevator_status = 0;
                open_doors = false;
                printf("\n\n [ DOORS CLOSED ] \n\n");
            } else {
                printf("Invalid input. ");
            }
        }
    }

    return 0;
}