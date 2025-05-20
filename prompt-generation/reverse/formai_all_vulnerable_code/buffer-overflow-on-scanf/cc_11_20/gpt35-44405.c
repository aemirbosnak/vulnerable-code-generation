//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MAX_BAGGAGE_CAPACITY 100
#define MAX_NUM_FLIGHTS 10
#define MAX_NUM_TERMINALS 4

// Define struct to represent baggage
typedef struct {
    int weight;
    int terminalNum;
} Baggage;

// Define struct to represent flights
typedef struct {
    int flightNum;
    int numBags;
    Baggage baggage[MAX_BAGGAGE_CAPACITY];
} Flight;

int main() {
    // Define variables
    int numFlights, numTerminals, i, j, k;
    Flight flights[MAX_NUM_FLIGHTS];
    int numBagsPerTerminal[MAX_NUM_TERMINALS] = {0};
    int numBagsLoaded = 0;

    // Prompt user for number of flights and number of terminals
    printf("Enter number of flights: ");
    scanf("%d", &numFlights);
    printf("Enter number of terminals: ");
    scanf("%d", &numTerminals);

    // Prompt user for flight information
    for (i = 0; i < numFlights; i++) {
        printf("Enter flight number for flight %d: ", i+1);
        scanf("%d", &flights[i].flightNum);
        printf("Enter number of bags for flight %d: ", i+1);
        scanf("%d", &flights[i].numBags);

        // Prompt user for baggage information
        for (j = 0; j < flights[i].numBags; j++) {
            printf("Enter weight of bag %d: ", j+1);
            scanf("%d", &flights[i].baggage[j].weight);
        }
    }

    // Load baggage onto terminals
    for (i = 0; i < numFlights; i++) {
        for (j = 0; j < flights[i].numBags; j++) {
            // Find terminal with least number of bags loaded
            int minTerminal = 0;
            for (k = 0; k < numTerminals; k++) {
                if (numBagsPerTerminal[k] < numBagsPerTerminal[minTerminal]) {
                    minTerminal = k;
                }
            }
            // Load baggage onto terminal
            flights[i].baggage[j].terminalNum = minTerminal;
            numBagsPerTerminal[minTerminal]++;
            numBagsLoaded++;
            // Check if baggage capacity has been reached
            if (numBagsLoaded >= numTerminals * MAX_BAGGAGE_CAPACITY) {
                printf("Baggage capacity has been reached. Exiting program.\n");
                exit(1);
            }
        }
    }

    // Print out baggage information for each terminal
    for (i = 0; i < numTerminals; i++) {
        printf("Terminal %d:\n", i+1);
        for (j = 0; j < numFlights; j++) {
            for (k = 0; k < flights[j].numBags; k++) {
                if (flights[j].baggage[k].terminalNum == i) {
                    printf("Flight %d, Bag %d, Weight %d\n", flights[j].flightNum, k+1, flights[j].baggage[k].weight);
                }
            }
        }
        printf("\n");
    }

    return 0;
}