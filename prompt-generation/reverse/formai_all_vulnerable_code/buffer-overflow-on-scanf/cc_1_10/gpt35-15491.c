//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100  // maximum number of bags to simulate

typedef struct {
    int flight_num;
    int bag_id;
} Baggage;

int main() {
    Baggage bags[MAX_BAGS];
    int total_bags = 0;
    int total_flights = 0;
    int flight_num = 0;
    int num_bags = 0;

    // get input from user
    printf("Enter the total number of flights: ");
    scanf("%d", &total_flights);

    srand(time(0));  // seed random number generator

    // simulate baggage handling for each flight
    for (int i = 0; i < total_flights; i++) {
        printf("\nFLIGHT #%d\n", flight_num + 1);
        printf("Enter the number of bags for flight #%d: ", flight_num + 1);
        scanf("%d", &num_bags);

        // generate random baggage ID for each bag
        for (int j = 0; j < num_bags; j++) {
            Baggage bag;
            bag.flight_num = flight_num + 1;
            bag.bag_id = rand() % 1000 + 1;
            bags[total_bags++] = bag;
        }

        flight_num++;
    }

    // display list of all bags for each flight
    for (int i = 0; i < flight_num; i++) {
        printf("\nFLIGHT #%d\n", i + 1);

        for (int j = 0; j < total_bags; j++) {
            if (bags[j].flight_num == i + 1) {
                printf("Bag ID: %d\n", bags[j].bag_id);
            }
        }
    }

    return 0;
}