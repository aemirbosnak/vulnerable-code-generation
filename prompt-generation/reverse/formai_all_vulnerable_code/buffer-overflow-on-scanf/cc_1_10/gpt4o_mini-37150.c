//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the probability
double calculateProbability(double distance, int signals, double conditions) {
    // Simple model for probability calculation
    // Probability is inversely related to distance and directly related to signals and conditions
    double baseProbability = 0.001; // Base probability factor
    double probability = baseProbability * signals / (distance + 1) * conditions;
    return fmin(probability, 1.0); // Probability cannot exceed 1
}

// Function to get environmental conditions
double getEnvironmentalConditions() {
    double condition;
    printf("Enter the environmental conditions (1.0 to 5.0, where 5.0 is very favorable): ");
    while (1) {
        scanf("%lf", &condition);
        if (condition >= 1.0 && condition <= 5.0) {
            break;
        }
        printf("Invalid input. Please enter a value between 1.0 and 5.0: ");
    }
    return condition;
}

int main() {
    double distance; // Distance from Earth in light years
    int signals;     // Number of detected alien signals
    double conditions; // Environmental conditions factor

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    // Getting user input for distance
    printf("Enter the distance from Earth (in light years): ");
    scanf("%lf", &distance);
    while (distance < 0) {
        printf("Distance cannot be negative. Please enter a valid distance: ");
        scanf("%lf", &distance);
    }

    // Getting user input for number of signals
    printf("Enter the number of detected alien signals: ");
    scanf("%d", &signals);
    while (signals < 0) {
        printf("Number of signals cannot be negative. Please enter a valid number of signals: ");
        scanf("%d", &signals);
    }

    // Getting environmental conditions
    conditions = getEnvironmentalConditions();

    // Calculating probability
    double invasionProbability = calculateProbability(distance, signals, conditions);

    // Displaying the result
    printf("\nBased on your inputs:\n");
    printf("Distance from Earth: %.2f light years\n", distance);
    printf("Number of detected signals: %d\n", signals);
    printf("Environmental conditions factor: %.2f\n", conditions);
    printf("Estimated probability of alien invasion: %.2f%%\n", invasionProbability * 100);

    // Providing conclusion based on calculated probability
    if (invasionProbability > 0.5) {
        printf("Warning! The chance of an alien invasion is high. Take necessary precautions!\n");
    } else if (invasionProbability > 0.2) {
        printf("Caution! There is a moderate chance of an alien invasion. Stay aware of your surroundings.\n");
    } else {
        printf("Low probability of alien invasion. You can relax...\n");
    }

    return 0;
}