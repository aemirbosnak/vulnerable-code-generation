//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ada Lovelace
#include <stdio.h>

// Function to calculate the invasion probability based on various factors
float calculateProbability(float planetCondition, float technologyLevel, float historicalIncidents) {
    // Hypothetical formula for calculating alien invasion probability
    float baseProbability = 0.1; // base probability of invasion
    float adjustedProbability = baseProbability + (planetCondition * 0.3) + (technologyLevel * 0.4) + (historicalIncidents * 0.2);
    
    // Ensure the probability does not exceed 1
    if (adjustedProbability > 1) {
        adjustedProbability = 1;
    }
    return adjustedProbability;
}

// Function to display the probability in a user-friendly manner
void displayProbability(float probability) {
    printf("The calculated probability of an alien invasion is: %.2f%%\n", probability * 100);
}

// Function to get user input and validate it
float getUserInput(char *prompt) {
    float value;
    printf("%s", prompt);
    while (1) {
        if (scanf("%f", &value) != 1 || value < 0) {
            printf("Invalid input. Please enter a non-negative number: ");
            while(getchar() != '\n'); // clear input buffer
        } else {
            break;
        }
    }
    return value;
}

// Main function
int main() {
    float planetCondition, technologyLevel, historicalIncidents;

    printf("Welcome to the Alien Invasion Probability Calculator\n");
    printf("Please enter the following factors on a scale of 0 to 1:\n");

    planetCondition = getUserInput("Enter the current planetary conditions (0 to 1): ");
    technologyLevel = getUserInput("Enter the level of technological advancement (0 to 1): ");
    historicalIncidents = getUserInput("Enter the number of historical incidents related to aliens (0 to 1): ");

    float invasionProbability = calculateProbability(planetCondition, technologyLevel, historicalIncidents);
    displayProbability(invasionProbability);

    // Additional information and insights
    printf("** Insights **\n");
    if (invasionProbability > 0.7) {
        printf("Warning: High probability of alien invasion detected!\n");
    } else if (invasionProbability > 0.4) {
        printf("Caution: Moderate chance of alien appearance.\n");
    } else {
        printf("Low probability of alien activities; continue with regular life.\n");
    }

    // Loop to allow multiple calculations
    char continueCalc;
    do {
        printf("\nWould you like to calculate again? (y/n): ");
        getchar(); // clear newline character from previous input
        scanf("%c", &continueCalc);
        if (continueCalc == 'y' || continueCalc == 'Y') {
            planetCondition = getUserInput("Enter the current planetary conditions (0 to 1): ");
            technologyLevel = getUserInput("Enter the level of technological advancement (0 to 1): ");
            historicalIncidents = getUserInput("Enter the number of historical incidents related to aliens (0 to 1): ");
            invasionProbability = calculateProbability(planetCondition, technologyLevel, historicalIncidents);
            displayProbability(invasionProbability);
        }
    } while (continueCalc == 'y' || continueCalc == 'Y');

    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}