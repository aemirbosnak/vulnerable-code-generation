//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_BAGS 1
#define MAX_BAGS 5
#define NUM_GATES 5
#define MAX_DELAY 10

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Initialize counters
    int total_bags = 0;
    int missing_bags = 0;
    
    // Initialize arrays to track the status of each gate and each bag
    int gate_statuses[NUM_GATES] = {0}; // 0 indicates empty, 1 indicates occupied
    int baggage_statuses[MAX_BAGS] = {0}; // 0 indicates not checked, 1 indicates checked
    
    // Main loop to simulate the baggage handling process
    while (1) {
        // Check if all gates are occupied
        int all_occupied = 1;
        for (int i = 0; i < NUM_GATES; i++) {
            if (gate_statuses[i] == 0) {
                all_occupied = 0;
                break;
            }
        }
        if (all_occupied) {
            printf("All gates are occupied!\n");
            break; // End the simulation
        }
        
        // Check if any bags are missing
        int any_missing = 0;
        for (int i = 0; i < total_bags; i++) {
            if (baggage_statuses[i] == 0) {
                any_missing = 1;
                break;
            }
        }
        if (any_missing) {
            printf("Some bags are missing!\n");
            break; // End the simulation
        }
        
        // Generate a random number of bags to add to the system
        int num_bags = rand() % (MAX_BAGS - MIN_BAGS + 1) + MIN_BAGS;
        
        // Add the bags to the system
        for (int i = 0; i < num_bags; i++) {
            baggage_statuses[total_bags] = 0; // Bag has not been checked
            total_bags++;
        }
        
        // Check each gate to see if it is empty
        for (int i = 0; i < NUM_GATES; i++) {
            if (gate_statuses[i] == 0) {
                // Assign a bag to this gate
                int bag_assigned = 0;
                for (int j = 0; j < total_bags; j++) {
                    if (baggage_statuses[j] == 0) {
                        baggage_statuses[j] = 1; // Bag has been checked
                        gate_statuses[i] = 1; // Gate is now occupied
                        printf("Bag %d assigned to gate %d\n", j+1, i+1);
                        bag_assigned = 1;
                        break;
                    }
                }
                if (!bag_assigned) {
                    missing_bags++;
                }
            }
        }
        
        // Random delay before checking the next set of gates
        int delay = rand() % MAX_DELAY;
        printf("Delaying check for new bags by %d seconds...\n", delay);
        sleep(delay);
    }
    
    // Print final results
    printf("\n--- Simulation Results ---\n");
    printf("Total number of bags: %d\n", total_bags);
    printf("Number of missing bags: %d\n", missing_bags);
    
    return 0;
}