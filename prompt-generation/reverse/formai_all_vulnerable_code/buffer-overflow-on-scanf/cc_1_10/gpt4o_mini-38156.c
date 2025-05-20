//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: beginner-friendly
#include <stdio.h>

// Function declarations
void displayInstructions();
float calculateProbability(float techLevel, float militaryPresence, float publicAwareness);

int main() {
    float techLevel, militaryPresence, publicAwareness, probability;

    // Display instructions on how to use the program
    displayInstructions();

    // Get user input for technology level
    printf("Enter the technology level (1-100): ");
    scanf("%f", &techLevel);

    // Get user input for military presence
    printf("Enter the military presence (1-100): ");
    scanf("%f", &militaryPresence);

    // Get user input for public awareness
    printf("Enter the public awareness (1-100): ");
    scanf("%f", &publicAwareness);

    // Calculate the alien invasion probability
    probability = calculateProbability(techLevel, militaryPresence, publicAwareness);

    // Display the invasion probability
    printf("The probability of an alien invasion is: %.2f%%\n", probability);

    // Check if the probability is above a certain threshold
    if (probability > 50.0) {
        printf("Warning: High probability of alien invasion!\n");
    } else {
        printf("Probability is low; we are safe for now!\n");
    }

    return 0;
}

// Function to display instructions to the user
void displayInstructions() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter values that represent the following:\n");
    printf("1. Technology Level: How advanced is our technology? (1 - Least advanced, 100 - Most advanced)\n");
    printf("2. Military Presence: What is the state of our military readiness? (1 - Weak, 100 - Strong)\n");
    printf("3. Public Awareness: How aware is the public about potential alien threats? (1 - Unaware, 100 - Highly aware)\n");
    printf("Based on these inputs, the program will calculate the probability of an alien invasion.\n");
    printf("Let's get started!\n\n");
}

// Function to calculate the probability of an alien invasion
float calculateProbability(float techLevel, float militaryPresence, float publicAwareness) {
    float invasionProbability;

    // Normalize inputs: Convert to range [0, 1]
    float normTech = techLevel / 100;
    float normMilitary = militaryPresence / 100;
    float normPublicAwareness = publicAwareness / 100;

    // Calculate invasion probability (arbitrary formula for demonstration)
    invasionProbability = (1 - normTech) * (1 - normMilitary) * (1 - normPublicAwareness) * 100;

    return invasionProbability;
}