//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100
#define MAX_FLIGHTS 20

struct Baggage {
    int weight;
    int destination;
};

typedef struct Baggage Baggage;

struct Flight {
    int flight_no;
    int departure_time;
    int num_bags;
    Baggage *bags;
};

typedef struct Flight Flight;

struct BaggageNode {
    Baggage *bag;
    struct BaggageNode *next;
};

typedef struct BaggageNode BaggageNode;

struct Belt {
    BaggageNode *head;
    int capacity;
};

typedef struct Belt Belt;

struct Bin {
    Baggage *bag;
};

typedef struct Bin Bin;

int main() {
    int num_flights, max_bag_weight, num_bins, num_passengers;
    printf("Enter the number of flights: ");
    scanf("%d", &num_flights);
    printf("Enter the maximum bag weight: ");
    scanf("%d", &max_bag_weight);
    printf("Enter the number of bins: ");
    scanf("%d", &num_bins);
    printf("Enter the number of passengers: ");
    scanf("%d", &num_passengers);

    // Allocate memory for flights
    Flight *flights = (Flight*)malloc(num_flights * sizeof(Flight));

    // Initialize flights
    for (int i = 0; i < num_flights; i++) {
        flights[i].flight_no = i + 1;
        printf("\nEnter flight %d details:\n", flights[i].flight_no);
        printf("Departure time: ");
        scanf("%d", &flights[i].departure_time);
        printf("Number of bags: ");
        scanf("%d", &flights[i].num_bags);

        // Allocate memory for bags
        flights[i].bags = (Baggage*)malloc(flights[i].num_bags * sizeof(Baggage));

        // Initialize bags
        for (int j = 0; j < flights[i].num_bags; j++) {
            printf("[Bag %d] Weight: ", j + 1);
            scanf("%d", &flights[i].bags[j].weight);
            printf("[Bag %d] Destination: ", j + 1);
            scanf("%d", &flights[i].bags[j].destination);
        }
    }

    // Allocate memory for bins
    Bin *bins = (Bin*)malloc(num_bins * sizeof(Bin));

    // Initialize bins
    for (int i = 0; i < num_bins; i++) {
        bins[i].bag = NULL;
    }

    // Allocate memory for belts
    Belt *belts = (Belt*)malloc(num_flights * sizeof(Belt));

    // Initialize belts
    for (int i = 0; i < num_flights; i++) {
        belts[i].head = NULL;
        belts[i].capacity = MAX_CAPACITY;
    }

    // Simulate baggage handling
    for (int i = 0; i < num_flights; i++) {
        // Load bags into bins
        for (int j = 0; j < flights[i].num_bags; j++) {
            // Find an empty bin
            int bin_idx = -1;
            for (int k = 0; k < num_bins; k++) {
                if (bins[k].bag == NULL) {
                    bin_idx = k;
                    break;
                }
            }
            // If all bins are full, skip this bag
            if (bin_idx == -1) {
                printf("[Flight %d] Bag %d skipped, no empty bin available!\n", flights[i].flight_no, j + 1);
                continue;
            }
            // Check bag weight
            if (flights[i].bags[j].weight > max_bag_weight) {
                printf("[Flight %d] Bag %d skipped, exceeds maximum weight limit!\n", flights[i].flight_no, j + 1);
                continue;
            }
            // Load bag into bin
            bins[bin_idx].bag = &flights[i].bags[j];
            printf("[Flight %d] Bag %d loaded into bin %d\n", flights[i].flight_no, j + 1, bin_idx + 1);
        }

        // Transfer bags from bins to belt
        for (int j = 0; j < num_bins; j++) {
            if (bins[j].bag != NULL) {
                // Find an empty slot on the belt
                BaggageNode *node = (BaggageNode*)malloc(sizeof(BaggageNode));
                node->bag = bins[j].bag;
                node->next = NULL;

                if (belts[i].head == NULL) {
                    belts[i].head = node;
                } else {
                    BaggageNode *tail = belts[i].head;
                    while (tail->next != NULL) {
                        tail = tail->next;
                    }
                    tail->next = node;
                }

                // Free the bin
                bins[j].bag = NULL;
            }
        }

        // Simulate passengers picking up bags from the belt
        printf("\n[Flight %d] Belts started moving at time %d\n", flights[i].flight_no, flights[i].departure_time);
        BaggageNode *current = belts[i].head;
        while (current != NULL && num_passengers > 0) {
            printf("[Flight %d] Passenger picked up bag to destination %d\n", flights[i].flight_no, current->bag->destination);
            BaggageNode *tmp = current;
            current = current->next;
            free(tmp);
            num_passengers--;
        }
    }

    // Free memory
    for (int i = 0; i < num_flights; i++) {
        free(flights[i].bags);
    }
    free(flights);
    free(bins);
    free(belts);

    return 0;
}