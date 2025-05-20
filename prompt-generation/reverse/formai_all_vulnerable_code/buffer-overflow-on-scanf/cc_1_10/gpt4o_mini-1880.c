//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define NUM_TRIALS 10000
#define ALIEN_ATTACK_RATE 0.002 // Probability of an alien attack each month

// Function to simulate the occurrence of an alien attack
int simulate_attack() {
    // Generate a random number between 0 and 1
    double random_value = (double) rand() / RAND_MAX;
    if (random_value < ALIEN_ATTACK_RATE) {
        return 1; // Attack occurs
    }
    return 0; // No attack
}

// Function to calculate the probability of an alien invasion over a given number of months
double calculate_invasion_probability(int num_months) {
    int attack_count = 0;
    
    for (int i = 0; i < NUM_TRIALS; i++) {
        int invasion_occurred = 0;
        
        for (int month = 0; month < num_months; month++) {
            invasion_occurred += simulate_attack();
        }
        
        if (invasion_occurred > 0) {
            attack_count++;
        }
    }
    
    return (double) attack_count / NUM_TRIALS;
}

// Function to display the invasion probability
void display_probability(int months) {
    double probability = calculate_invasion_probability(months);
    printf("The probability of an alien invasion in %d months is: %.2f%%\n", 
           months, probability * 100);
}

// Main function
int main() {
    int months;

    // Seed the random number generator
    srand(time(NULL));

    printf("Alien Invasion Probability Calculator\n");
    printf("======================================\n");
    
    // Input from user
    printf("Enter the number of months to calculate the invasion probability: ");
    scanf("%d", &months);

    // Validate input
    while (months <= 0) {
        printf("Please enter a positive number of months: ");
        scanf("%d", &months);
    }

    // Calculate and display probability
    display_probability(months);

    return 0;
}