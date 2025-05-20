//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define MAX_MONTHS 120
#define ALIEN_CONTACT_THRESHOLD 0.7

// Function to simulate alien contact based on previous events
bool simulateAlienContact(float previousEvents[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += previousEvents[i];
    }
    float averageProbability = sum / n;

    // A random chance to mimic unexpected events
    float randomFactor = (float)rand() / RAND_MAX;
    return (averageProbability + randomFactor) >= ALIEN_CONTACT_THRESHOLD;
}

// Function to estimate probabilities based on time and events
void estimateProbabilities(float probabilities[], int months) {
    for (int i = 0; i < months; i++) {
        // Example model where probability increases with time
        probabilities[i] = fmin(1.0, (0.05 * (i + 1))); 
    }
}

// Function to display the probabilities in a readable format
void displayProbabilities(float probabilities[], int months) {
    printf("\nEstimated Alien Invasion Probabilities Over Time:\n");
    printf("Month\tProbability\n");
    printf("========================\n");
    for (int i = 0; i < months; i++) {
        printf("%d\t%.2f\n", i + 1, probabilities[i]);
    }
}

// Function to initialize previous events from user data
void initPreviousEvents(float previousEvents[], int n) {
    printf("Enter the actual probabilities of contact for %d previous months:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Probability for month %d: ", i + 1);
        scanf("%f", &previousEvents[i]);
        previousEvents[i] = fmax(0, fmin(previousEvents[i], 1.0)); // Keep value in range [0,1]
    }
}

// Main function
int main() {
    srand(time(NULL));  // Seed the random number generator
    float probabilities[MAX_MONTHS];
    float previousEvents[12]; // Array for the last 12 months of contact probabilities
    int monthsToSimulate;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("How many months do you want to simulate (max is %d)? ", MAX_MONTHS);
    scanf("%d", &monthsToSimulate);
    
    if (monthsToSimulate > MAX_MONTHS) {
        printf("Can't simulate more than %d months!\n", MAX_MONTHS);
        return 1;
    }

    // Initialize previous events
    initPreviousEvents(previousEvents, 12);
    
    // Estimate probabilities based on the given months
    estimateProbabilities(probabilities, monthsToSimulate);
    
    // Display the estimated probabilities
    displayProbabilities(probabilities, monthsToSimulate);

    // Simulate alien contact based on previous events
    if (simulateAlienContact(previousEvents, 12)) {
        printf("\nAlert! Probability of Alien contact is high. Stay alert!\n");
    } else {
        printf("\nGood news! The probability of Alien contact is currently low.\n");
    }

    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}