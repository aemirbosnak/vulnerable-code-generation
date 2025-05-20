//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10
#define MAX_BAG_TYPES 5
#define MAX_BAG_CONTENTS 10

typedef struct {
    int flight_number;
    int destination;
    int num_bags;
    int *bag_types;
    int *bag_contents;
} Flight;

typedef struct {
    int flight_number;
    int bag_type;
    int bag_contents;
} Bag;

int main() {
    srand(time(NULL));

    // Initialize flights
    Flight flights[MAX_FLIGHTS];
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i].flight_number = i + 1;
        flights[i].destination = rand() % 10 + 1;
        flights[i].num_bags = rand() % 10 + 1;
        flights[i].bag_types = (int *)malloc(flights[i].num_bags * sizeof(int));
        flights[i].bag_contents = (int *)malloc(flights[i].num_bags * sizeof(int));
        for (int j = 0; j < flights[i].num_bags; j++) {
            flights[i].bag_types[j] = rand() % MAX_BAG_TYPES + 1;
            flights[i].bag_contents[j] = rand() % MAX_BAG_CONTENTS + 1;
        }
    }

    // Simulate baggage handling
    int baggage_claim_area[MAX_BAGS];
    for (int i = 0; i < MAX_BAGS; i++) {
        baggage_claim_area[i] = -1;
    }

    for (int i = 0; i < MAX_FLIGHTS; i++) {
        for (int j = 0; j < flights[i].num_bags; j++) {
            Bag bag = {flights[i].flight_number, flights[i].bag_types[j], flights[i].bag_contents[j]};
            int bag_index = rand() % MAX_BAGS;
            while (baggage_claim_area[bag_index]!= -1) {
                bag_index = rand() % MAX_BAGS;
            }
            baggage_claim_area[bag_index] = i;
        }
    }

    // Print results
    printf("Baggage claim area:\n");
    for (int i = 0; i < MAX_BAGS; i++) {
        if (baggage_claim_area[i]!= -1) {
            printf("Bag %d is from flight %d and contains %d items of type %d.\n", i + 1, baggage_claim_area[i], flights[baggage_claim_area[i]].bag_contents[baggage_claim_area[i] - 1], flights[baggage_claim_area[i]].bag_types[baggage_claim_area[i] - 1]);
        } else {
            printf("Bag %d is empty.\n", i + 1);
        }
    }

    return 0;
}