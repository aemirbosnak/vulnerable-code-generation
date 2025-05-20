//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 50 // Maximum number of bags
#define MAX_DELAY 5 // Maximum delay time in seconds

typedef struct {
    int id; // Bag id
    int weight; // Bag weight in kg
} Bag;

// Function to generate random bag weights
int generateBagWeight() {
    return rand() % 30 + 1; // Random weight between 1 and 30 kg
}

// Function to simulate delay in seconds
void delay(int seconds) {
    time_t start_time = time(NULL);
    while (time(NULL) < start_time + seconds);
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    int n_bags = rand() % MAX_BAGS + 1; // Random number of bags between 1 and MAX_BAGS
    Bag bags[n_bags]; // Create array of bags

    // Generate bag ids and weights
    for (int i = 0; i < n_bags; i++) {
        bags[i].id = i + 1;
        bags[i].weight = generateBagWeight();
    }
    
    // Simulate baggage handling process
    printf("Starting baggage handling simulation...\n");
    for (int i = 0; i < n_bags; i++) {
        printf("Processing bag #%d (weight: %d kg)...\n", bags[i].id, bags[i].weight);
        bool bag_accepted = rand() % 2; // Randomly decide if bag is accepted or rejected
        if (bag_accepted) {
            printf("Bag #%d accepted for boarding.\n", bags[i].id);
        } else {
            printf("Bag #%d rejected due to security concerns.\n", bags[i].id);
        }
        int delay_time = rand() % MAX_DELAY + 1; // Generate random delay time 
        printf("Delaying baggage handling process by %d seconds...\n", delay_time);
        delay(delay_time); // Simulate delay
    }

    printf("Baggage handling simulation complete.\n");

    return 0;
}