//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int getRandomNumber(int min, int max);
void printAlienInvasionMessage(float probability);
float calculateInvasionProbability(int years, float techFactor);

int main() {
    srand(time(NULL)); // Seed the random number generator

    int years;
    float techFactor;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Let's explore how likely our extraterrestrial friends will pay us a visit.\n");
    
    // Input years until invasion
    printf("Enter the number of years until the expected invasion (e.g., 10, 20, 50): ");
    scanf("%d", &years);
    
    // Input technology factor
    printf("Assign a technology factor (0.0 to 2.0, where 1.0 is normal tech level): ");
    scanf("%f", &techFactor);
    
    // Validate techFactor
    while (techFactor < 0.0 || techFactor > 2.0) {
        printf("Invalid input! Technology factor must be between 0.0 and 2.0. Please try again: ");
        scanf("%f", &techFactor);
    }

    // Calculate the invasion probability
    float invasionProbability = calculateInvasionProbability(years, techFactor);
    
    // Print the alien invasion message based on probability
    printAlienInvasionMessage(invasionProbability);
    
    return 0;
}

// Function to get a random number within a range
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to calculate the invasion probability based on years and technology factor
float calculateInvasionProbability(int years, float techFactor) {
    // Use an arbitrary calculation for the probability based on years and techFactor
    float baseProbability = (float)getRandomNumber(1, 100) / 100;  // Random base probability between 0.01 and 1.00
    float invasionChance = baseProbability * techFactor / years; 
    return invasionChance * 100;  // Convert to percentage
}

// Function to print alien invasion message based on calculated probability
void printAlienInvasionMessage(float probability) {
    printf("\n--- Alien Invasion Probability Report ---\n");
    printf("Based on your inputs, the probability of an alien invasion happening is approximately: %.2f%%\n", probability);
    
    if (probability < 5.0) {
        printf("Chill out! The aliens are not likely to invade anytime soon.\n");
    } else if (probability < 20.0) {
        printf("Possible! Maybe keep your eyes on the sky, just in case.\n");
    } else if (probability < 50.0) {
        printf("Getting serious! It might be time to build that bunker you've been thinking about!\n");
    } else {
        printf("Alert! The aliens are actually considering a visit soon. Prepare for takeoff!\n");
    }

    printf("\nThank you for using the Alien Invasion Probability Calculator!\n");
    printf("------------------------------------------\n\n");
}