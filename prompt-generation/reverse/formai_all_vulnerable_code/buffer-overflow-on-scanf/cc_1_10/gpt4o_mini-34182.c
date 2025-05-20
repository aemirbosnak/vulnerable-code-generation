//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute the probability of alien invasion
double calculateInvasionProbability(double communicationFactor, double defencesFactor, double alienTechnologyFactor) {
    // Using Shannon's entropy concept to derive a measure of uncertainty
    double totalFactor = communicationFactor + defencesFactor + alienTechnologyFactor;
    if (totalFactor <= 0) return 0.0;

    // Probability derived from the factors (simplified model)
    double invasionProbability = (communicationFactor - defencesFactor + alienTechnologyFactor) / totalFactor;

    // Ensure the probability is bounded between 0 and 1
    if (invasionProbability < 0.0) invasionProbability = 0.0;
    if (invasionProbability > 1.0) invasionProbability = 1.0;

    return invasionProbability;
}

// Function to get user input safely
double getUserInput(const char *prompt) {
    double input;
    printf("%s", prompt);
    while (scanf("%lf", &input) != 1) {
        printf("Invalid input. Please enter a number: ");
        while(getchar() != '\n'); // Clear invalid input
    }
    return input;
}

// Main function
int main() {
    printf("=== Alien Invasion Probability Calculator ===\n");
    printf("This program calculates the probability of an alien invasion based on various factors.\n");

    // Get input from the user
    double communicationFactor = getUserInput("Enter the communication factor (0 to 10): ");
    double defencesFactor = getUserInput("Enter the defences factor (0 to 10): ");
    double alienTechnologyFactor = getUserInput("Enter the alien technology factor (0 to 10): ");

    // Validate the input ranges
    if (communicationFactor < 0 || communicationFactor > 10 ||
        defencesFactor < 0 || defencesFactor > 10 ||
        alienTechnologyFactor < 0 || alienTechnologyFactor > 10) {
        printf("Factors must be between 0 and 10. Please restart the program and enter valid values.\n");
        return 1;
    }

    // Calculate invasion probability
    double invasionProbability = calculateInvasionProbability(communicationFactor, defencesFactor, alienTechnologyFactor);

    // Display the result
    printf("Based on the given factors:\n");
    printf("- Communication Factor: %.2f\n", communicationFactor);
    printf("- Defences Factor: %.2f\n", defencesFactor);
    printf("- Alien Technology Factor: %.2f\n", alienTechnologyFactor);
    printf("The estimated probability of an alien invasion is: %.2f%%\n", invasionProbability * 100);

    // Conclusion based on the probability
    if (invasionProbability > 0.75) {
        printf("Warning: High probability of an alien invasion!\n");
    } else if (invasionProbability > 0.5) {
        printf("Caution: Moderate probability of an alien invasion.\n");
    } else {
        printf("Safe: Low probability of an alien invasion.\n");
    }

    // Cleanup and exit
    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}