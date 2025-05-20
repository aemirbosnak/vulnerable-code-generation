//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 100

typedef struct Passenger {
    char name[50];
    int flight_number;
    int baggage_weight;
} Passenger;

void handle_baggage(Passenger *passenger) {
    int baggage_weight = passenger->baggage_weight;
    if (baggage_weight > 20) {
        printf("Excess baggage fee of $50 applied to %s.\n", passenger->name);
        passenger->baggage_weight -= 20;
        passenger->baggage_weight += 20;
    }
}

int main() {
    Passenger passengers[MAX_PASSENGERS];
    int num_passengers = 0;

    // Create a loop to add passengers
    while (num_passengers < MAX_PASSENGERS) {
        printf("Enter your name: ");
        scanf("%s", passengers[num_passengers].name);

        printf("Enter your flight number: ");
        scanf("%d", &passengers[num_passengers].flight_number);

        printf("Enter your baggage weight (in kg): ");
        scanf("%d", &passengers[num_passengers].baggage_weight);

        num_passengers++;
    }

    // Handle baggage for each passenger
    for (int i = 0; i < num_passengers; i++) {
        handle_baggage(&passengers[i]);
    }

    // Print the total baggage weight
    int total_baggage_weight = 0;
    for (int i = 0; i < num_passengers; i++) {
        total_baggage_weight += passengers[i].baggage_weight;
    }
    printf("Total baggage weight: %d kg\n", total_baggage_weight);

    return 0;
}