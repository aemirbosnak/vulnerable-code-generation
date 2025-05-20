//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 100
#define MAX_TIME 60

// structure to represent a single bag
typedef struct {
    int id;
    int arrival_time;
    int flight_time;
    int processing_time;
} Baggage;

// function to simulate the airport baggage handling process
void simulate_baggage_handling(Baggage *bags, int num_bags) {
    int current_time = 0;
    int total_wait_time = 0;
    int max_wait_time = 0;
    int num_served = 0;

    while (num_served < num_bags) {
        Baggage *next_bag = NULL;
        int next_bag_index = -1;

        // find the next bag to serve
        for (int i = 0; i < num_bags; i++) {
            if (bags[i].processing_time == 0) {
                if (next_bag == NULL || bags[i].arrival_time < next_bag->arrival_time) {
                    next_bag = &bags[i];
                    next_bag_index = i;
                }
            }
        }

        if (next_bag == NULL) {
            // no bags available to serve at this time, increment the current time
            current_time++;
            continue;
        }

        // serve the next bag
        int wait_time = current_time - next_bag->arrival_time;
        total_wait_time += wait_time;
        max_wait_time = (wait_time > max_wait_time) ? wait_time : max_wait_time;
        next_bag->processing_time = next_bag->flight_time;
        num_served++;

        // update the processing times for the remaining bags
        for (int i = 0; i < num_bags; i++) {
            if (i != next_bag_index && bags[i].processing_time > 0) {
                bags[i].processing_time--;
            }
        }
    }

    // print the statistics
    printf("Average wait time: %.2f minutes\n", (float)total_wait_time / num_bags);
    printf("Maximum wait time: %d minutes\n", max_wait_time);
}

int main() {
    int num_bags;
    Baggage bags[MAX_BAGS];

    printf("Number of bags: ");
    scanf("%d", &num_bags);

    for (int i = 0; i < num_bags; i++) {
        printf("Arrival time for bag %d: ", i+1);
        scanf("%d", &bags[i].arrival_time);
        printf("Flight time for bag %d: ", i+1);
        scanf("%d", &bags[i].flight_time);
        bags[i].processing_time = 0;
        bags[i].id = i+1;
    }

    simulate_baggage_handling(bags, num_bags);

    return 0;
}