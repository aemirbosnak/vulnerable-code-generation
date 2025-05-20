//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_DESTINATIONS 10
#define NUM_BAGGAGES 5
#define DELAY_TIME 2

typedef struct {
    int destination;
    int baggage_index;
    time_t timestamp;
} Baggage;

int main() {
    int i, j;
    Baggage bags[NUM_BAGS];
    int destinations[NUM_DESTINATIONS];
    int baggages[NUM_BAGGAGES];

    srand(time(NULL));

    // Initialize destinations
    for (i = 0; i < NUM_DESTINATIONS; i++) {
        destinations[i] = rand() % NUM_DESTINATIONS;
    }

    // Initialize baggages
    for (i = 0; i < NUM_BAGGAGES; i++) {
        baggages[i] = rand() % NUM_DESTINATIONS;
    }

    // Initialize baggage data
    for (i = 0; i < NUM_BAGS; i++) {
        bags[i].destination = rand() % NUM_DESTINATIONS;
        bags[i].baggage_index = i;
        bags[i].timestamp = time(NULL) + DELAY_TIME;
    }

    // Sort baggages by destination
    for (i = 0; i < NUM_BAGGAGES; i++) {
        for (j = i + 1; j < NUM_BAGGAGES; j++) {
            if (destinations[baggages[i]] > destinations[baggages[j]]) {
                int temp = baggages[i];
                baggages[i] = baggages[j];
                baggages[j] = temp;
            }
        }
    }

    // Process baggage
    for (i = 0; i < NUM_BAGS; i++) {
        printf("Baggage %d is destined for %d and is being processed at %ld\n", bags[i].baggage_index, bags[i].destination, bags[i].timestamp);
        for (j = 0; j < NUM_BAGGAGES; j++) {
            if (baggages[j] == bags[i].destination) {
                printf("Baggage %d is being loaded onto baggage %d\n", bags[i].baggage_index, j);
                break;
            }
        }
    }

    return 0;
}