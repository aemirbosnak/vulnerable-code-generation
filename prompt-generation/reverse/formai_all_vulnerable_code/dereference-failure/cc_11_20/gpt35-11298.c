//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct bag {
    int bag_id;
    int flight_id;
    int weight;
} Bag;

typedef struct flight {
    int flight_id;
    int num_bags;
    Bag **bags;
} Flight;

typedef struct belt {
    int belt_id;
    Bag *bag;
} Belt;

int main() {
    srand(time(NULL));
    int num_flights = rand() % 10 + 1; // Generate random number of flights (1-10)
    Flight **flights = malloc(sizeof(Flight*) * num_flights);

    // Initialize flights and bags
    for (int i = 0; i < num_flights; i++) {
        flights[i] = malloc(sizeof(Flight));
        flights[i]->flight_id = i + 1;

        int num_bags = rand() % 100 + 1; // Generate random number of bags (1-100)
        flights[i]->num_bags = num_bags;
        flights[i]->bags = malloc(sizeof(Bag*) * num_bags);

        for (int j = 0; j < num_bags; j++) {
            flights[i]->bags[j] = malloc(sizeof(Bag));
            flights[i]->bags[j]->bag_id = j + 1;
            flights[i]->bags[j]->flight_id = i + 1;
            flights[i]->bags[j]->weight = rand() % 50 + 1; // Generate random weight (1-50)
        }
    }

    // Initialize belts
    int num_belts = rand() % 5 + 1; // Generate random number of belts (1-5)
    Belt *belts = malloc(sizeof(Belt) * num_belts);

    for (int i = 0; i < num_belts; i++) {
        belts[i].belt_id = i + 1;
        belts[i].bag = NULL;
    }

    // Simulate baggage handling
    for (int i = 0; i < num_flights; i++) {
        // Load bags onto belts
        for (int j = 0; j < flights[i]->num_bags; j++) {
            int belt_index = rand() % num_belts;
            while (belts[belt_index].bag != NULL) { // Find available belt
                belt_index = (belt_index + 1) % num_belts;
            }
            belts[belt_index].bag = flights[i]->bags[j];
            printf("Loading bag %d from flight %d onto belt %d\n", belts[belt_index].bag->bag_id, flights[i]->flight_id, belts[belt_index].belt_id);
        }

        // Unload bags from belts
        for (int j = 0; j < num_belts; j++) {
            if (belts[j].bag != NULL) {
                printf("Unloading bag %d from belt %d\n", belts[j].bag->bag_id, belts[j].belt_id);
                belts[j].bag = NULL;
            }
        }
    }

    // Free memory
    for (int i = 0; i < num_flights; i++) {
        for (int j = 0; j < flights[i]->num_bags; j++) {
            free(flights[i]->bags[j]);
        }
        free(flights[i]->bags);
        free(flights[i]);
    }
    free(flights);
    free(belts);

    return 0;
}