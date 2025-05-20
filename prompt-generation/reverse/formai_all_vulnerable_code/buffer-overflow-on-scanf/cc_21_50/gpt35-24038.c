//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGGAGE_WEIGHT 50
#define MIN_BAGGAGE_WEIGHT 5
#define MAX_BAGGAGE_VOLUME 100
#define MIN_BAGGAGE_VOLUME 10
#define MAX_FLIGHTS 10
#define MAX_PASSENGERS 100
#define MAX_BAGGAGE_PER_PASSENGER 2
#define MAX_CONVEYOR_BELTS 5
#define MAX_CAPACITY_PER_CONVEYOR_BELT 50

// Define Baggage struct
typedef struct Baggage {
    int weight;
    int volume;
} Baggage;

// Define Passenger struct
typedef struct Passenger {
    Baggage baggages[MAX_BAGGAGE_PER_PASSENGER];
    int num_baggages;
} Passenger;

// Define Flights struct
typedef struct Flights {
    Passenger passengers[MAX_PASSENGERS];
    int num_passengers;
} Flights;

int main() {
    // Initialize variables
    Flights flights[MAX_FLIGHTS];
    int num_flights = 0;
    int num_conveyor_belts = 0;
    int conveyor_belt_capacities[MAX_CONVEYOR_BELTS] = {0};

    // Seed random number generator
    srand(time(NULL));

    // Get number of flights from user input
    printf("Enter number of flights: ");
    scanf("%d", &num_flights);

    // Get number of conveyor belts from user input
    printf("Enter number of conveyor belts: ");
    scanf("%d", &num_conveyor_belts);

    // Get capacity of each conveyor belt
    for (int i = 0; i < num_conveyor_belts; i++) {
        printf("Enter capacity of conveyor belt %d: ", i+1);
        scanf("%d", &conveyor_belt_capacities[i]);
    }

    // Generate random baggage for each passenger and add them to flights
    for (int i = 0; i < num_flights; i++) {
        Flights flight;
        flight.num_passengers = rand() % MAX_PASSENGERS + 1;
        for (int j = 0; j < flight.num_passengers; j++) {
            Passenger passenger;
            passenger.num_baggages = rand() % MAX_BAGGAGE_PER_PASSENGER + 1;
            for (int k = 0; k < passenger.num_baggages; k++) {
                Baggage baggage;
                baggage.weight = rand() % (MAX_BAGGAGE_WEIGHT - MIN_BAGGAGE_WEIGHT + 1) + MIN_BAGGAGE_WEIGHT;
                baggage.volume = rand() % (MAX_BAGGAGE_VOLUME - MIN_BAGGAGE_VOLUME + 1) + MIN_BAGGAGE_VOLUME;
                passenger.baggages[k] = baggage;
            }
            flight.passengers[j] = passenger;
        }
        flights[i] = flight;
    }

    // Sort passengers by baggage weight
    for (int i = 0; i < num_flights; i++) {
        for (int j = 0; j < flights[i].num_passengers-1; j++) {
            for (int k = j+1; k < flights[i].num_passengers; k++) {
                int total_weight_j = 0;
                int total_weight_k = 0;
                for (int l = 0; l < flights[i].passengers[j].num_baggages; l++) {
                    total_weight_j += flights[i].passengers[j].baggages[l].weight;
                }
                for (int l = 0; l < flights[i].passengers[k].num_baggages; l++) {
                    total_weight_k += flights[i].passengers[k].baggages[l].weight;
                }
                if (total_weight_k > total_weight_j) {
                    Passenger tmp = flights[i].passengers[j];
                    flights[i].passengers[j] = flights[i].passengers[k];
                    flights[i].passengers[k] = tmp;
                }
            }
        }
    }

    // Assign passengers to conveyor belts based on weight capacity
    for (int i = 0; i < num_flights; i++) {
        int conveyor_belts[MAX_CONVEYOR_BELTS][MAX_CAPACITY_PER_CONVEYOR_BELT] = {{0}};
        int num_passengers_on_conveyor_belt[MAX_CONVEYOR_BELTS] = {0};
        for (int j = 0; j < flights[i].num_passengers; j++) {
            int max_weight = 0;
            int conveyor_belt_index = 0;
            for (int k = 0; k < num_conveyor_belts; k++) {
                if (conveyor_belt_capacities[k] - num_passengers_on_conveyor_belt[k] > 0) {
                    int total_weight = 0;
                    for (int l = 0; l < flights[i].passengers[j].num_baggages; l++) {
                        total_weight += flights[i].passengers[j].baggages[l].weight;
                    }
                    if (total_weight <= conveyor_belt_capacities[k] - num_passengers_on_conveyor_belt[k] && total_weight > max_weight) {
                        max_weight = total_weight;
                        conveyor_belt_index = k;
                    }
                }
            }
            num_passengers_on_conveyor_belt[conveyor_belt_index]++;
            Passenger passenger = flights[i].passengers[j];
            for (int k = 0; k < passenger.num_baggages; k++) {
                conveyor_belts[conveyor_belt_index][num_passengers_on_conveyor_belt[conveyor_belt_index]-1] += passenger.baggages[k].volume;
            }
        }
        printf("Flight %d:\n", i+1);
        for (int j = 0; j < num_conveyor_belts; j++) {
            printf("Conveyor belt %d:\n", j+1);
            for (int k = 0; k < num_passengers_on_conveyor_belt[j]; k++) {
                printf("\tPassenger %d: ", k+1);
                printf("[");
                for (int l = 0; l < MAX_CAPACITY_PER_CONVEYOR_BELT; l++) {
                    printf("%d", conveyor_belts[j][l]);
                    if (l != MAX_CAPACITY_PER_CONVEYOR_BELT-1) {
                        printf(",");
                    }
                }
                printf("]\n");
            }
        }
    }

    return 0;
}