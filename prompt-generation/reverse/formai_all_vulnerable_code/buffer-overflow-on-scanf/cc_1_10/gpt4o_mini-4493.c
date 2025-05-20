//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the probability recursively
double calculateProbability(int aliens, double techStrength, double earthDefense) {
    // Base case
    if (aliens <= 0) {
        return 0.0; // No aliens, no invasion
    }
    if (earthDefense <= 0) {
        return 1.0; // No defenses, certain invasion
    }
    
    // Recursive case
    double invasionChance = techStrength / (techStrength + earthDefense);
    
    // Calculate the probability considering the aliens
    return invasionChance * calculateProbability(aliens - 1, techStrength, earthDefense) + 
           (1 - invasionChance) * calculateProbability(aliens - 1, techStrength * 0.95, earthDefense * 1.02);
}

// Main function to take user input and initiate the calculator
int main() {
    int numberOfAliens;
    double technologyStrength, earthDefense;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of aliens: ");
    scanf("%d", &numberOfAliens);

    // Ensure a non-negative number of aliens
    if (numberOfAliens < 0) {
        printf("Number of aliens cannot be negative.\n");
        return -1;
    }

    printf("Please enter the technology strength of the aliens (0.0 to 10.0): ");
    scanf("%lf", &technologyStrength);
    
    // Ensure technology strength is within the valid range
    if (technologyStrength < 0.0 || technologyStrength > 10.0) {
        printf("Technology strength must be between 0.0 and 10.0.\n");
        return -1;
    }

    printf("Please enter the strength of Earth's defenses (0.0 to 10.0): ");
    scanf("%lf", &earthDefense);
    
    // Ensure earth defense is within the valid range
    if (earthDefense < 0.0 || earthDefense > 10.0) {
        printf("Earth defense must be between 0.0 and 10.0.\n");
        return -1;
    }
    
    // Calculate the invasion probability
    double invasionProbability = calculateProbability(numberOfAliens, technologyStrength, earthDefense);
    
    // Display the result
    printf("The calculated probability of an alien invasion with %d aliens,\n", numberOfAliens);
    printf("technology strength of %.2f and Earth's defenses of %.2f is: %.2f%%\n", 
           technologyStrength, earthDefense, invasionProbability * 100);
    
    return 0;
}