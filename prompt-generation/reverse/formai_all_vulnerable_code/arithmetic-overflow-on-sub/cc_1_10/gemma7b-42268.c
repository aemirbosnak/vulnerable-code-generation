//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define ROAD_LENGTH 100

int main() {
    int i, j, k, num_cars = 0, lane_change = 0;
    time_t t, start_time = time(NULL);

    // Create a 2D array to store the road status
    int road[ROAD_LENGTH][MAX_CARS] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Simulate traffic flow
    while (time(NULL) - start_time < 60) {
        // Randomly generate traffic
        if (num_cars < MAX_CARS) {
            num_cars++;
            road[rand() % ROAD_LENGTH][rand() % MAX_CARS] = 1;
        }

        // Move cars
        for (i = 0; i < num_cars; i++) {
            // Change lane
            if (lane_change % 3 == 0) {
                road[road[i][0]][i] = 0;
                road[road[i][1]][i] = 1;
                lane_change++;
            }

            // Drive forward
            road[road[i][0]][i] = 1;
        }

        // Update road status
        for (i = 0; i < ROAD_LENGTH; i++) {
            for (j = 0; j < MAX_CARS; j++) {
                if (road[i][j] == 1) {
                    printf("%c ", '#');
                } else {
                    printf(" ");
                }
            }

            printf("\n");
        }

        // Sleep for a while
        sleep(1);
    }

    return 0;
}