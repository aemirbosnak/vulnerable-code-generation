//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n_floors = 10;
    int floor_state[n_floors];
    int floor_count[n_floors];
    int current_floor = 0;
    int direction = 1; // 1 for up, -1 for down

    for (int i = 0; i < n_floors; i++) {
        floor_state[i] = 0;
        floor_count[i] = 0;
    }

    srand(time(NULL));

    while (current_floor!= n_floors) {
        printf("The elevator is on the %dth floor.\n", current_floor + 1);
        if (floor_count[current_floor] < 2) {
            if (direction == 1) {
                current_floor++;
                if (current_floor > n_floors) {
                    direction = -1;
                }
            } else {
                current_floor--;
                if (current_floor < 0) {
                    direction = 1;
                }
            }
            floor_state[current_floor] = 1;
            floor_count[current_floor]++;
            printf("A passenger enters the elevator on the %dth floor.\n", current_floor + 1);
        } else {
            if (direction == 1) {
                current_floor++;
                if (current_floor > n_floors) {
                    direction = -1;
                }
            } else {
                current_floor--;
                if (current_floor < 0) {
                    direction = 1;
                }
            }
            floor_state[current_floor] = 0;
            floor_count[current_floor]--;
            printf("A passenger exits the elevator on the %dth floor.\n", current_floor + 1);
        }
    }

    return 0;
}