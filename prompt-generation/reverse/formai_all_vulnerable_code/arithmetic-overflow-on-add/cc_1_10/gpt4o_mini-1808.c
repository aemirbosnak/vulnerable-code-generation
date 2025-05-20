//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double calculate_probability(int aliens, int humans);
double calculate_exposure(int aliens, int humans, double exposure_rate);
void print_results(int aliens, int humans, double probability, double exposure);

// Constant
#define PI 3.14159265358979323846

int main() {
    int num_aliens, num_humans;
    double exposure_rate;
    
    // Introduction
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Let's assess the potential for an alien invasion based on the number of aliens and humans.\n");

    // Get number of aliens
    printf("Enter the estimated number of aliens: ");
    scanf("%d", &num_aliens);
    
    // Get number of humans
    printf("Enter the estimated population of humans: ");
    scanf("%d", &num_humans);
    
    // Get exposure rate
    printf("Enter the exposure rate (0.0 to 1.0): ");
    scanf("%lf", &exposure_rate);

    // Validate inputs
    if (num_aliens < 0 || num_humans <= 0 || exposure_rate < 0.0 || exposure_rate > 1.0) {
        printf("Invalid input. Please ensure the number of aliens is non-negative, number of humans is positive, and exposure rate is between 0.0 and 1.0.\n");
        return 1;
    }

    // Calculate the invasion probability
    double invasion_probability = calculate_probability(num_aliens, num_humans);
    
    // Calculate the exposure
    double exposure_probability = calculate_exposure(num_aliens, num_humans, exposure_rate);
    
    // Print the results
    print_results(num_aliens, num_humans, invasion_probability, exposure_probability);

    return 0;
}

// Function to calculate the probability of alien invasion
double calculate_probability(int aliens, int humans) {
    if (humans <= 0) return 0.0;
    return (double)aliens / humans;
}

// Function to calculate the exposure risk based on aliens, humans, and exposure rate
double calculate_exposure(int aliens, int humans, double exposure_rate) {
    return exposure_rate * ((double)aliens / (humans + aliens));
}

// Function to print the results in a neat format
void print_results(int aliens, int humans, double probability, double exposure) {
    printf("\nCalculations based on your input:\n");
    printf("-----------------------------------------------------\n");
    printf("Number of Aliens: %d\n", aliens);
    printf("Number of Humans: %d\n", humans);
    printf("Invasion Probability (Aliens to Humans Ratio): %.4f\n", probability);
    printf("Exposure Probability Based on Exposure Rate: %.4f\n", exposure);
    printf("-----------------------------------------------------\n");
    
    if (probability > 0.1) {
        printf("Warning: High invasion probability detected!\n");
    } else {
        printf("Invasion probability is low. Stay calm!\n");
    }
    
    if (exposure > 0.05) {
        printf("Warning: High exposure probability detected!\n");
    } else {
        printf("Exposure level is manageable.\n");
    }
    
    printf("-----------------------------------------------------\n");
    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
}