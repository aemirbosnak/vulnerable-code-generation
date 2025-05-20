//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 50
#define NUM_DESTINATIONS 10
#define NUM_PASSENGERS 100

typedef struct {
    int destination;
    int passenger_id;
} Baggage;

int main() {
    srand(time(NULL));

    Baggage *bags = malloc(NUM_BAGS * sizeof(Baggage));
    int *destinations = malloc(NUM_DESTINATIONS * sizeof(int));
    int *passengers = malloc(NUM_PASSENGERS * sizeof(int));

    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i].destination = rand() % NUM_DESTINATIONS;
        bags[i].passenger_id = rand() % NUM_PASSENGERS;
    }

    for (int i = 0; i < NUM_DESTINATIONS; i++) {
        destinations[i] = rand() % NUM_DESTINATIONS;
    }

    for (int i = 0; i < NUM_PASSENGERS; i++) {
        passengers[i] = rand() % NUM_DESTINATIONS;
    }

    int num_correct = 0;

    for (int i = 0; i < NUM_BAGS; i++) {
        int bag_dest = bags[i].destination;
        int bag_passenger = bags[i].passenger_id;

        int dest_index = -1;
        for (int j = 0; j < NUM_DESTINATIONS; j++) {
            if (destinations[j] == bag_dest) {
                dest_index = j;
                break;
            }
        }

        if (dest_index >= 0) {
            int pass_index = -1;
            for (int j = 0; j < NUM_PASSENGERS; j++) {
                if (passengers[j] == bag_dest && passengers[j] == bag_passenger) {
                    pass_index = j;
                    break;
                }
            }

            if (pass_index >= 0) {
                num_correct++;
            }
        }
    }

    printf("Correctly sorted bags: %d\n", num_correct);

    free(bags);
    free(destinations);
    free(passengers);

    return 0;
}