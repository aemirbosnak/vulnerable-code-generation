//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_BAGS 100
#define MAX_FLIGHTS 10

typedef struct {
    int flight_number;
    int num_bags;
    int *bag_destinations;
} Flight;

typedef struct {
    int bag_id;
    int destination;
} Bag;

Flight flights[MAX_FLIGHTS];
Bag bags[MAX_BAGS];

void generate_flights() {
    int i;
    for (i = 0; i < MAX_FLIGHTS; i++) {
        flights[i].flight_number = i + 1;
        flights[i].num_bags = rand() % 10 + 1;
        flights[i].bag_destinations = (int *)malloc(flights[i].num_bags * sizeof(int));
        int j;
        for (j = 0; j < flights[i].num_bags; j++) {
            flights[i].bag_destinations[j] = rand() % MAX_BAGS + 1;
        }
    }
}

void generate_bags() {
    int i;
    for (i = 0; i < MAX_BAGS; i++) {
        bags[i].bag_id = i + 1;
        bags[i].destination = rand() % MAX_BAGS + 1;
    }
}

void print_flight(Flight flight) {
    printf("Flight %d has %d bags:\n", flight.flight_number, flight.num_bags);
    int j;
    for (j = 0; j < flight.num_bags; j++) {
        printf("Bag %d is destined for location %d\n", flight.bag_destinations[j], flight.bag_destinations[j]);
    }
}

void print_bag(Bag bag) {
    printf("Bag %d is destined for location %d\n", bag.bag_id, bag.destination);
}

int main() {
    srand(time(0));
    generate_flights();
    generate_bags();
    int i, j;
    for (i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight %d:\n", flights[i].flight_number);
        for (j = 0; j < flights[i].num_bags; j++) {
            print_bag(bags[flights[i].bag_destinations[j] - 1]);
        }
    }
    return 0;
}