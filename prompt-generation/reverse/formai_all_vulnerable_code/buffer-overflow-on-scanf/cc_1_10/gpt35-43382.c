//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define constants
#define NUM_OF_BAGS 100
#define MAX_WEIGHT 50
#define MAX_DELAY 10

// Define structures
typedef struct Baggage {
    int id;
    int weight;
} Baggage;

// Declare global variables
Baggage baggage[NUM_OF_BAGS];
int totalWeight = 0;
bool baggageRemoved = false;
int delay;

// Function to generate random integer within range
int randInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to simulate baggage handling process
void bagHandler() {
    // Add random baggage to conveyor belt
    for (int i = 0; i < NUM_OF_BAGS; i++) {
        baggage[i].id = i;
        baggage[i].weight = randInt(1, MAX_WEIGHT);
        totalWeight += baggage[i].weight;
        printf("Baggage ID: %d, Weight: %d kg\n", baggage[i].id, baggage[i].weight);
    }

    // Wait for delay time
    printf("\nDelay time before baggage removal: %d seconds\n\n", delay);
    sleep(delay);

    // Remove baggage from conveyor belt
    for (int i = 0; i < NUM_OF_BAGS; i++) {
        totalWeight -= baggage[i].weight;
        if (totalWeight < 0) {
            totalWeight = 0;
        }
        printf("Baggage ID: %d removed from conveyor belt\n", baggage[i].id);
        baggageRemoved = true;
    }

    // If no baggage was removed, display message
    if (!baggageRemoved) {
        printf("No baggage was removed from the conveyor belt\n");
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Get delay time from user
    printf("Enter delay time (in seconds) before baggage removal: ");
    scanf("%d", &delay);

    // Call baggage handling function
    bagHandler();

    return 0;
}