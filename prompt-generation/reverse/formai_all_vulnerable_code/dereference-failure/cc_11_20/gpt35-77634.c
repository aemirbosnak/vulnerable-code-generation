//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    // Setting up the baggage handling simulation variables
    int num_lanes = 5;
    int lane_capacity = 7;
    int max_baggage_weight = 50;
    srand(time(NULL));

    // Setting up the simulation timer
    time_t start_time, end_time;
    double simulation_time;
    time(&start_time);

    // Initializing the baggage lanes
    int** baggage_lanes = (int**)malloc(num_lanes*sizeof(int*));
    for(int i=0; i<num_lanes; i++) {
        baggage_lanes[i] = (int*)malloc(lane_capacity*sizeof(int));
        for(int j=0; j<lane_capacity; j++) {
            baggage_lanes[i][j] = 0;
        }
    }

    // Starting the baggage handling simulation
    for(int i=0; i<100; i++) {
        // Generating a random weight for the baggage
        int baggage_weight = rand() % max_baggage_weight + 1;

        // Finding the lane with the least weight total
        int min_weight_total = max_baggage_weight * lane_capacity;
        int min_weight_lane = 0;
        for(int j=0; j<num_lanes; j++) {
            int weight_total = 0;
            for(int k=0; k<lane_capacity; k++) {
                weight_total += baggage_lanes[j][k];
            }
            if(weight_total < min_weight_total) {
                min_weight_total = weight_total;
                min_weight_lane = j;
            }
        }

        // Adding the baggage to the chosen lane
        int added = 0;
        for(int j=0; j<lane_capacity; j++) {
            if(baggage_lanes[min_weight_lane][j] == 0) {
                baggage_lanes[min_weight_lane][j] = baggage_weight;
                added = 1;
                break;
            }
        }

        // Printing the status of the baggage lanes
        printf("Status of baggage lanes at time %d:\n", i+1);
        for(int j=0; j<num_lanes; j++) {
            printf("Lane %d: ", j+1);
            for(int k=0; k<lane_capacity; k++) {
                printf("%d ", baggage_lanes[j][k]);
            }
            printf("\n");
        }
        printf("\n");

        // Delaying the simulation for 1 second
        sleep(1);

        // Ending the simulation if all baggage lanes are full
        if(!added) {
            time(&end_time);
            break;
        }
    }

    // Calculating the total simulation time
    simulation_time = difftime(end_time, start_time);

    // Freeing the memory used for the baggage lanes
    for(int i=0; i<num_lanes; i++) {
        free(baggage_lanes[i]);
    }
    free(baggage_lanes);

    // Printing the simulation results
    printf("Simulation complete.\n");
    printf("Total simulation time: %.2f seconds\n", simulation_time);
    return 0;
}