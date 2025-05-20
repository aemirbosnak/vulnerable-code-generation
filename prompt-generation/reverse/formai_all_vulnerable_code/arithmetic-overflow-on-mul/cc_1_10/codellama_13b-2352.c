//Code Llama-13B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: futuristic
// Alien Invasion Probability Calculator
// Written in a futuristic style

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_ALIENS 100

// Function prototypes
int calculate_probability(int num_planets, int num_aliens);
void print_probability(int probability);

int main() {
    // Get number of planets and aliens from user
    int num_planets, num_aliens;
    printf("Enter number of planets: ");
    scanf("%d", &num_planets);
    printf("Enter number of aliens: ");
    scanf("%d", &num_aliens);

    // Calculate probability of alien invasion
    int probability = calculate_probability(num_planets, num_aliens);

    // Print probability
    print_probability(probability);

    return 0;
}

// Calculate probability of alien invasion
int calculate_probability(int num_planets, int num_aliens) {
    int probability = 0;

    // Calculate probability based on number of planets and aliens
    probability = (num_aliens * 100) / num_planets;

    // Add randomness to the probability
    probability += (rand() % 100);

    // Return probability
    return probability;
}

// Print probability
void print_probability(int probability) {
    // Print probability message
    printf("The probability of an alien invasion is %d%%.\n", probability);

    // Print message based on probability
    if (probability >= 100) {
        printf("ALIENS WILL INVADE!\n");
    } else if (probability >= 50) {
        printf("ALIENS MAY INVADE!\n");
    } else {
        printf("ALIENS WON'T INVADE!\n");
    }
}