//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

int main() {
    int floors[10];
    int n = sizeof(floors) / sizeof(floors[0]);
    int top = -1;
    int passengers[10];
    int n_passengers = 0;
    int waiting = 0;
    int desired_floor = 0;
    int i;

    while (1) {
        printf("Enter desired floor (0 to exit): ");
        scanf("%d", &desired_floor);
        if (desired_floor == 0) {
            break;
        }
        for (i = 0; i < n; i++) {
            if (floors[i] == desired_floor) {
                top = i;
                break;
            }
        }
        if (top == -1) {
            printf("Elevator not at desired floor.\n");
            continue;
        }
        while (waiting > 0) {
            printf("Waiting: %d\n", waiting);
            if (n_passengers > 0) {
                printf("Passengers waiting: %d\n", n_passengers);
                passengers[n_passengers - 1] = -1;
                n_passengers--;
            }
            if (top!= -1) {
                printf("Moving to floor %d...\n", top + 1);
                top++;
            } else {
                printf("Elevator is not moving.\n");
            }
            if (n_passengers == 0) {
                waiting--;
            }
        }
        if (waiting == 0) {
            printf("No passengers waiting.\n");
        }
    }

    return 0;
}