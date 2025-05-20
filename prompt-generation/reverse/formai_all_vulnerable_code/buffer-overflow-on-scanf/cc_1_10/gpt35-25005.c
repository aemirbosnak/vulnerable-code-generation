//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_RUNS 10

int main() {
    srand(time(NULL)); // set random seed
    int num_runs = 0; // number of times to run simulation
    
    // get user input for number of runs
    while (num_runs <= 0 || num_runs > MAX_RUNS) {
        printf("How many times would you like to run the simulation? (Maximum %d): ", MAX_RUNS);
        fflush(stdout);
        scanf("%d", &num_runs);
    }

    int num_cars = rand() % MAX_CARS + 1; // generate random number of cars
    
    // simulate traffic flow for each run
    for (int i = 0; i < num_runs; i++) {
        printf("====== RUN %d ======\n", i+1);
        fflush(stdout);
        
        // create array to track car positions
        int car_positions[MAX_CARS] = {[0 ... MAX_CARS-1] = -1};
        car_positions[0] = 0; // first car starts at position 0
        
        // simulate car movement
        for (int j = 1; j < num_cars; j++) {
            int distance = rand() % 10 + 1; // car moves between 1-10 units
            int new_pos = car_positions[j-1] + distance; // new position of car
            
            // check for collision
            if (new_pos <= car_positions[j-1]) {
                printf("CAR %d COLLIDED WITH CAR %d AT POSITION %d\n", j, j-1, new_pos);
                fflush(stdout);
                break;
            } else {
                car_positions[j] = new_pos;
            }
        }
        
        // print final positions of cars (if no collisions occurred)
        printf("FINAL POSITIONS: ");
        for (int k = 0; k < num_cars; k++) {
            printf("%d ", car_positions[k]);
        }
        printf("\n\n");
    }

    return 0;
}