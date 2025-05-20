//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main() {
    int floors[100];
    int num_floors = 0;
    int floor = 1;
    int elevator_state = 0;

    printf("Welcome to the Elevator Simulator!\n");

    while (1) {
        printf("Floor: %d\n", floor);

        scanf("%d", &num_floors);
        if (num_floors == -1) {
            break;
        }

        floor += num_floors;

        if (elevator_state == 0) {
            if (floor <= 99) {
                elevator_state = 1;
                printf("Going up to floor %d...\n", floor);
            } else {
                printf("Invalid floor, going down to floor 99...\n");
                floor = 99;
            }
        } else if (elevator_state == 1) {
            if (floor <= 99) {
                elevator_state = 2;
                printf("Going down to floor %d...\n", floor);
            } else {
                printf("Invalid floor, going up to floor 1...\n");
                floor = 1;
            }
        } else if (elevator_state == 2) {
            if (floor <= 99) {
                elevator_state = 0;
                printf("Going up to floor %d...\n", floor);
            } else {
                printf("Invalid floor, going down to floor 99...\n");
                floor = 99;
            }
        }
    }

    return 0;
}