//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function prototypes
double calculateProbability(int numShips, int numPlanets);
void printResults(int numShips, int numPlanets, double probability);
double generateRandomNumber();

int main() {
    int numShips, numPlanets;
    char choice;

    printf("👾 Welcome to the Alien Invasion Probability Calculator! 👽\n");
    printf("---------------------------------------------------------\n");

    do {
        // Input number of UFOs (Spaceships)
        printf("Enter the number of Alien Spaceships (1-10): ");
        scanf("%d", &numShips);

        // Input number of planets to attack
        printf("Enter the number of Planets (1-10): ");
        scanf("%d", &numPlanets);

        // Input validation
        if (numShips < 1 || numShips > 10 || numPlanets < 1 || numPlanets > 10) {
            printf("😱 Invalid input! Please enter numbers between 1 and 10!\n");
            continue;
        }

        // Calculate the probability of an attack
        double probability = calculateProbability(numShips, numPlanets);
        printResults(numShips, numPlanets, probability);

        // Ask user if they want to run again
        printf("Do you want to calculate again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("💥 Thank you for using the Alien Invasion Probability Calculator! 💥\n");
    return 0;
}

// Function to calculate the invasion probability
double calculateProbability(int numShips, int numPlanets) {
    // Using a random number generation to simulate some uncertainty in probability
    double baseProbability = (double)numShips / (double)(numShips + numPlanets);
    double randomness = generateRandomNumber();
    
    return (baseProbability + randomness / 10.0) * 100.0; // Return percentage
}

// Function to generate a random number between 0 and 1
double generateRandomNumber() {
    return (double)rand() / (double)RAND_MAX; // Returns a floating point number between 0.0 and 1.0
}

// Function to print the results
void printResults(int numShips, int numPlanets, double probability) {
    printf("\n⚠️  Alien Invasion Risk Assessment ⚠️\n");
    printf("--------------------------------------\n");
    printf("Number of Alien Spaceships: %d\n", numShips);
    printf("Number of Planets in Danger: %d\n", numPlanets);
    printf("Calculated Invasion Probability: %.2f%%\n", probability);

    // Shocked responses based on probability
    if (probability < 20) {
        printf("😌 Minor risk! The aliens seem to be heading elsewhere...\n");
    } else if (probability < 50) {
        printf("😟 Moderate risk! Prepare to defend yourselves!\n");
    } else if (probability < 80) {
        printf("😱 High risk! Brace for impact!\n");
    } else {
        printf("⚠️ Extreme risk! It's an all-out invasion! Take cover!\n");
    }
    printf("--------------------------------------\n");
}