//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayIntroduction();
double calculateProbability(double technologyLevel, double spaceExploration, 
                            double alienIntelligence, double intentionToInvade);
void displayResults(double probability);

int main() {
    // Declare variables for user inputs
    double technologyLevel, spaceExploration, alienIntelligence, intentionToInvade;
    
    // Function to display introduction
    displayIntroduction();
    
    // Get user input for technology level
    printf("Enter the technology level on Earth (0.0 to 10.0): ");
    scanf("%lf", &technologyLevel);
    
    // Get user input for space exploration level
    printf("Enter the space exploration level (0.0 to 10.0): ");
    scanf("%lf", &spaceExploration);

    // Get user input for alien intelligence
    printf("Enter the average alien intelligence (0.0 to 10.0): ");
    scanf("%lf", &alienIntelligence);

    // Get user input for intention to invade
    printf("Enter the alien intention to invade (0.0 to 10.0): ");
    scanf("%lf", &intentionToInvade);

    // Call function to calculate probability
    double invasionProbability = calculateProbability(technologyLevel, 
                                                      spaceExploration, 
                                                      alienIntelligence, 
                                                      intentionToInvade);
    
    // Call function to display results
    displayResults(invasionProbability);

    return 0;
}

// Function to display introduction
void displayIntroduction() {
    printf("========================================\n");
    printf("     Welcome to the Alien Invasion      \n");
    printf("          Probability Calculator        \n");
    printf("========================================\n");
    printf("Please enter the values from 0.0 (low) to 10.0 (high)\n");
}

// Function to calculate the probability of alien invasion
double calculateProbability(double technologyLevel, double spaceExploration, 
                            double alienIntelligence, double intentionToInvade) {
    // Ensure inputs are clamped between 0.0 and 10.0
    technologyLevel = (technologyLevel < 0.0) ? 0.0 : (technologyLevel > 10.0) ? 10.0 : technologyLevel;
    spaceExploration = (spaceExploration < 0.0) ? 0.0 : (spaceExploration > 10.0) ? 10.0 : spaceExploration;
    alienIntelligence = (alienIntelligence < 0.0) ? 0.0 : (alienIntelligence > 10.0) ? 10.0 : alienIntelligence;
    intentionToInvade = (intentionToInvade < 0.0) ? 0.0 : (intentionToInvade > 10.0) ? 10.0 : intentionToInvade;

    // Calculate probability using a simple formula
    double probability = (technologyLevel * 0.2) + 
                         (spaceExploration * 0.3) + 
                         (alienIntelligence * 0.4) + 
                         (intentionToInvade * 0.5);

    // Normalize the probability (assume max possible value is 10)
    probability = (probability > 100.0) ? 100.0 : probability;
    return probability;
}

// Function to display the results of the invasion probability
void displayResults(double probability) {
    printf("========================================\n");
    printf("The calculated probability of alien invasion is: %.2f%%\n", probability);
    
    if (probability > 80.0) {
        printf("Warning! Extremely high probability of invasion! Prepare accordingly!\n");
    } else if (probability > 50.0) {
        printf("Caution! Moderate probability of invasion. Stay alert!\n");
    } else {
        printf("Low probability of invasion. No immediate threat detected.\n");
    }
    
    printf("========================================\n");
}