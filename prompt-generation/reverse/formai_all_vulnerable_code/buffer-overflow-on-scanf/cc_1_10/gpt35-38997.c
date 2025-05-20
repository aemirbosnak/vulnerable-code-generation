//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maximum number of passengers 
#define MAX_PASSENGERS 100

// Function prototypes 
void generateLuggage(int numPassengers, int numBags, int* luggageWeights);
void loadLuggage(int numBags, int* luggageWeights);
void sortLuggage(int* luggageWeights);

int main() {
    int numPassengers, numBags;
    int luggageWeights[MAX_PASSENGERS];
    srand(time(NULL));

    printf("Welcome to the Airport Baggage Handling System Simulation\n\n");
    printf("Enter number of passengers: ");
    scanf("%d", &numPassengers);
    printf("Enter number of bags per passenger: ");
    scanf("%d", &numBags);

    // Generate luggage weights for each passenger 
    generateLuggage(numPassengers, numBags, luggageWeights);

    // Load luggage into airplane 
    loadLuggage(numPassengers*numBags, luggageWeights);

    // Sort luggage by weight 
    sortLuggage(luggageWeights);

    printf("Luggage handling simulation complete.\n");

    return 0;
}

// Generate random luggage weight for each passenger
void generateLuggage(int numPassengers, int numBags, int* luggageWeights) {
    int i, j;
    for (i = 0; i < numPassengers; i++) {
        for (j = 0; j < numBags; j++) {
            // Generate random integer between 10 and 50 (inclusive) 
            luggageWeights[i*numBags + j] = rand() % 41 + 10;
        }
    }
}

// Load luggage into the airplane 
void loadLuggage(int numBags, int* luggageWeights) {
    int totalWeight = 0;
    int maxWeight = 5000; // Maximum weight capacity of airplane 

    printf("\nLoading luggage into airplane...\n");

    for (int i = 0; i < numBags; i++) {
        totalWeight += luggageWeights[i];
        if (totalWeight <= maxWeight) {
            printf("Bag %d (Weight: %d) loaded.\n", i+1, luggageWeights[i]);
        }
        else {
            printf("Bag %d (Weight: %d) exceeds weight capacity. Cannot load.\n", i+1, luggageWeights[i]);
        }
    }
}

// Sort luggage by weight 
void sortLuggage(int* luggageWeights) {
    int i, j, temp;
    int numBags = MAX_PASSENGERS; // maximum number of bags 
    printf("\nSorting luggage by weight...\n");

    // Bubble sort 
    for (i = 0; i < numBags-1; i++) {
        for (j = 0; j < numBags-i-1; j++) {
            if (luggageWeights[j] > luggageWeights[j+1]) {
                temp = luggageWeights[j];
                luggageWeights[j] = luggageWeights[j+1];
                luggageWeights[j+1] = temp;
            }
        }
    }

    // Print sorted list 
    printf("Sorted luggage weights: ");
    for (i = 0; i < numBags; i++) {
        printf("%d ", luggageWeights[i]);
    }
}