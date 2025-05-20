//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define a structure to represent the baggage
typedef struct {
    int id;
    int weight;
} Baggage;

// Define a structure to represent the passenger
typedef struct {
    int id;
    bool hasBaggage;
    Baggage baggage;
} Passenger;

// Define a function to generate random weight for baggage
int generateRandomWeight() {
    return rand() % 30 + 1;  // Generate weight between 1 and 30 kgs
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    // Declare variables for simulation
    int numPassengers, numBaggage, totalWeight = 0;
    printf("Enter number of passengers: ");
    scanf("%d", &numPassengers);
    printf("Enter number of baggage per passenger: ");
    scanf("%d", &numBaggage);

    // Declare array to store all passengers and their baggage
    Passenger passengers[numPassengers];
    Baggage baggage[numPassengers*numBaggage];

    // Initialize passengers and their baggage
    for (int i = 0; i < numPassengers; i++) {
        passengers[i].id = i;
        passengers[i].hasBaggage = false;
        for (int j = 0; j < numBaggage; j++) {
            Baggage b;
            b.id = j;
            b.weight = generateRandomWeight();
            baggage[i*numBaggage + j] = b;
            passengers[i].hasBaggage = true;
            passengers[i].baggage = b;
            totalWeight += b.weight;
        }
    }

    // Print simulation details
    printf("Simulation starting with %d passengers and %d baggage per passenger\n", numPassengers, numBaggage);
    printf("Total baggage weight: %d kgs\n", totalWeight);

    // Simulate the baggage handling process
    for (int i = 0; i < numPassengers; i++) {
        if (passengers[i].hasBaggage) {
            printf("Processing baggage for passenger %d\n", passengers[i].id);
            for (int j = 0; j < numBaggage; j++) {
                Baggage b = passengers[i].baggage;
                printf("- Baggage %d: weight %d kgs\n", b.id, b.weight);
            }
        } else {
            printf("Passenger %d has no baggage\n", passengers[i].id);
        }
    }

    // End simulation
    printf("Simulation complete! Have a nice flight!\n");

    return 0;
}