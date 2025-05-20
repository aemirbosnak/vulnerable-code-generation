//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

#define INTERSECTION_SIZE 4

int main() {
    int intersection[INTERSECTION_SIZE] = {0, 0, 0, 0};
    int current_time = 0;
    int time_per_cycle = 1000; // milliseconds
    int cycle_count = 0;
    int current_cycle = 0;
    int current_state = RED;
    int next_state = GREEN;
    int state_count = 0;

    srand(time(NULL));

    while (1) {
        current_time += time_per_cycle;
        cycle_count++;

        if (cycle_count == 4) {
            cycle_count = 0;
            current_cycle++;
        }

        if (current_cycle == 1) {
            current_state = GREEN;
            next_state = YELLOW;
        } else if (current_cycle == 2) {
            current_state = YELLOW;
            next_state = RED;
        } else if (current_cycle == 3) {
            current_state = RED;
            next_state = GREEN;
        }

        if (current_time >= time_per_cycle * (current_cycle - 1) + state_count * time_per_cycle) {
            state_count++;
            intersection[current_cycle] = next_state;
        }

        for (int i = 0; i < INTERSECTION_SIZE; i++) {
            if (intersection[i] == RED) {
                printf("%d: ", i);
            } else {
                printf("%d ", i);
            }
        }
        printf("\n");

        fflush(stdout);
        usleep(time_per_cycle * 1000);
    }

    return 0;
}