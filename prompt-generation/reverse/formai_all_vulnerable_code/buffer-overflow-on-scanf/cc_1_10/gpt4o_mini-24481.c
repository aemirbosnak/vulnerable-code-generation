//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate alien invasion probability
double calculateAlienInvasionProbability(int years, double initialProb, double growthRate) {
    return initialProb * (1 + growthRate) * years;
}

// Function to display a beautiful ASCII art representation of aliens
void displayAlienArt() {
    printf("     .       .\n");
    printf("      \\     /\n");
    printf("       \\   /\n");
    printf("        \\_/\n");
    printf("        (o o)  *  BEEP BEEP! ALIENS HAVE LANDED! *\n");
    printf("         \\_/\n");
    printf("        /   \\\n");
    printf("       |     |\n");
    printf("       |     |\n");
    printf("       |     |\n");
    printf("       |_____\n");
    printf("\n");
}

// Function to take user input safely
void getUserInput(int *years, double *initialProb, double *growthRate) {
    printf("Enter the number of years (1-100): ");
    while (scanf("%d", years) != 1 || *years < 1 || *years > 100) {
        printf("Please enter a valid number of years (1-100): ");
        while(getchar() != '\n'); // Clear buffer
    }
    
    printf("Enter the initial probability of alien invasion (0.0 to 1.0): ");
    while (scanf("%lf", initialProb) != 1 || *initialProb < 0.0 || *initialProb > 1.0) {
        printf("Please enter a valid initial probability (0.0 to 1.0): ");
        while(getchar() != '\n'); // Clear buffer
    }
    
    printf("Enter the growth rate of the probability (0.0 to 0.1): ");
    while (scanf("%lf", growthRate) != 1 || *growthRate < 0.0 || *growthRate > 0.1) {
        printf("Please enter a valid growth rate (0.0 to 0.1): ");
        while(getchar() != '\n'); // Clear buffer
    }
}

// Function to display the results
void displayResults(int years, double initialProb, double growthRate, double prob) {
    printf("\n===== Alien Invasion Probability Report =====\n");
    printf("Number of years: %d\n", years);
    printf("Initial probability: %.2f\n", initialProb);
    printf("Growth rate: %.2f\n", growthRate);
    printf("Calculated probability of an alien invasion: %.2f\n", prob);
    
    if (prob > 0.5) {
        printf("Warning: High probability of alien invasion!\n");
    } else {
        printf("Probability is low, but stay vigilant!\n");
    }
    printf("=============================================\n");
}

int main() {
    srand(time(0)); // Seed for random number generation
    
    int years = 0;
    double initialProb = 0.0;
    double growthRate = 0.0;

    displayAlienArt();
    getUserInput(&years, &initialProb, &growthRate);
    
    double invasionProb = calculateAlienInvasionProbability(years, initialProb, growthRate);
    
    displayResults(years, initialProb, growthRate, invasionProb);
    
    // Asking user if they want to run the calculation again
    char choice;
    printf("Do you want to calculate again? (y/n): ");
    while (1) {
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            main(); // restart the main procedure
        } else if (choice == 'n' || choice == 'N') {
            printf("Thank you for using the Alien Invasion Probability Calculator!\n");
            exit(0);
        } else {
            printf("Invalid choice. Please enter 'y' or 'n': ");
        }
    }

    return 0;
}