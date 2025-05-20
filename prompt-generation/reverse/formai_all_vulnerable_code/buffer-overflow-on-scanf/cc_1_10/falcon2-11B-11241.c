//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLIGHTS 5
#define MAX_BAGS 100
#define MAX_DESTINATIONS 3

int main(int argc, char *argv[]) {
    srand(time(0)); // seed the random number generator

    // create arrays to store flight data and baggage data
    int flights[MAX_FLIGHTS];
    int bags[MAX_BAGS];
    int destinations[MAX_DESTINATIONS];

    // read in flight data
    printf("Enter arrival times for %d flights:\n", MAX_FLIGHTS);
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        int arrival_time;
        printf("Arrival time for flight %d: ", i+1);
        scanf("%d", &arrival_time);
        flights[i] = arrival_time;
    }

    // generate random baggage data
    for (int i = 0; i < MAX_BAGS; i++) {
        bags[i] = rand() % 100;
    }

    // assign baggage to flights
    int num_bags_per_flight = rand() % 5;
    int num_bags = 0;
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        int num_bags_this_flight = rand() % num_bags_per_flight;
        for (int j = 0; j < num_bags_this_flight; j++) {
            int bag_index = rand() % MAX_BAGS;
            bags[bag_index] -= 1;
            if (bags[bag_index] == 0) {
                destinations[num_bags] = i;
                num_bags++;
            }
        }
    }

    // sort bags by destination
    for (int i = 0; i < num_bags; i++) {
        int destination = destinations[i];
        int bin_index = rand() % MAX_DESTINATIONS;
        destinations[i] = bin_index;
    }

    // print out summary
    printf("Flight\tArrival time\tNum bags\n");
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("%d\t%d\t%d\n", i+1, flights[i], destinations[i]);
    }

    // free memory
    free(flights);
    free(bags);
    free(destinations);

    return 0;
}