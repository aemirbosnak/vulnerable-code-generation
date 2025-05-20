//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: beginner-friendly
#include <stdio.h>

// Function to calculate the invasion probability
double calculateProbability(int sightings, double distance, int alienPopulation) {
    if (distance <= 0 || sightings < 0 || alienPopulation <= 0) {
        printf("Invalid input values. Please ensure distance is greater than zero and values are non-negative.\n");
        return -1.0;
    }
    
    // Simple probability formula (for demonstration purposes)
    double baseProbability = (double)sightings / (distance * alienPopulation);
    double invasionProbability = baseProbability * 100; // Convert to percentage

    // Limit the probability between 0% and 100%
    if (invasionProbability > 100) {
        invasionProbability = 100;
    }
    
    return invasionProbability;
}

int main() {
    int sightings;
    double distance;
    int alienPopulation;
    double probability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    while (1) {
        printf("\nPlease enter the number of alien sightings (or -1 to exit): ");
        scanf("%d", &sightings);
        
        // Exit condition
        if (sightings == -1) {
            printf("Thank you for using the calculator! Goodbye!\n");
            break;
        }

        printf("Please enter the average distance of sightings (in kilometers): ");
        scanf("%lf", &distance);
        
        printf("Please enter the current estimated alien population on Earth: ");
        scanf("%d", &alienPopulation);
        
        // Calculate probability
        probability = calculateProbability(sightings, distance, alienPopulation);
        
        // Check if probability calculation was valid
        if (probability >= 0) {
            printf("The estimated probability of an alien invasion based on your input is: %.2f%%\n", probability);
        }
    }
    
    return 0;
}