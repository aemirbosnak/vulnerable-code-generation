//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int flight_number;
    int origin;
    int destination;
    int num_bags;
} Flight;

typedef struct {
    int flight_number;
    int num_bags;
} Baggage;

Flight* create_flight(int flight_number, int origin, int destination, int num_bags) {
    Flight* flight = (Flight*) malloc(sizeof(Flight));
    flight->flight_number = flight_number;
    flight->origin = origin;
    flight->destination = destination;
    flight->num_bags = num_bags;
    return flight;
}

Baggage* create_baggage(int flight_number, int num_bags) {
    Baggage* baggage = (Baggage*) malloc(sizeof(Baggage));
    baggage->flight_number = flight_number;
    baggage->num_bags = num_bags;
    return baggage;
}

int main() {
    srand(time(NULL));

    // Create 10 flights
    Flight* flights[10];
    for (int i = 0; i < 10; i++) {
        int origin = rand() % 100;
        int destination = rand() % 100;
        int num_bags = rand() % 50 + 1;
        flights[i] = create_flight(i + 1, origin, destination, num_bags);
    }

    // Create baggage for each flight
    Baggage* baggages[100];
    int baggage_count = 0;
    for (int i = 0; i < 10; i++) {
        int num_bags = flights[i]->num_bags;
        for (int j = 0; j < num_bags; j++) {
            baggages[baggage_count++] = create_baggage(i + 1, num_bags);
        }
    }

    // Simulate baggage handling
    for (int i = 0; i < baggage_count; i++) {
        int flight_number = baggages[i]->flight_number;
        int num_bags = baggages[i]->num_bags;

        printf("Handling baggage for flight %d with %d bags...\n", flight_number, num_bags);
        fflush(stdout);

        // Randomly lose some bags
        int lost_bags = rand() % num_bags + 1;
        printf("Lost %d bags!\n", lost_bags);
        fflush(stdout);

        if (lost_bags == num_bags) {
            printf("All bags lost for flight %d.\n", flight_number);
        } else {
            printf("Delivered %d bags for flight %d.\n", num_bags - lost_bags, flight_number);
        }
    }

    return 0;
}