//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: recursive
#include <stdio.h>

// Function declarations
double invasion_probability(int days, double base_chance, int attempts);
void print_probability(double probability);

int main() {
    int days;
    double base_chance;
    int attempts;

    // Input the number of days for the calculation
    printf("Enter the number of days until the alien invasion: ");
    scanf("%d", &days);

    // Input the base chance of invasion per attempt
    printf("Enter the base chance of invasion per attempt (0 to 1): ");
    scanf("%lf", &base_chance);

    // Input the number of attempts made
    printf("Enter the number of invasion attempts: ");
    scanf("%d", &attempts);

    // Validate inputs
    if (days < 0 || base_chance < 0 || base_chance > 1 || attempts < 1) {
        printf("Invalid input values. Please ensure days are non-negative, base chance is between 0 and 1, and attempts are at least 1.\n");
        return 1;
    }

    // Calculate probability of invasion using recursion
    double probability = invasion_probability(days, base_chance, attempts);
    
    // Print the result
    print_probability(probability);

    return 0;
}

// Recursive function to calculate the probability of invasion
double invasion_probability(int days, double base_chance, int attempts) {
    if (days == 0) {
        return 0.0;  // No days left means no chance of invasion
    }

    if (attempts == 0) {
        return 0.0;  // No attempts means no chance of invasion
    }

    // Calculate the probability of no invasion in this attempt
    double no_invasion_chance = (1.0 - base_chance);
    
    // Recursive call to the previous day with one less attempt
    double probability_next_day = invasion_probability(days - 1, base_chance, attempts - 1);
    
    // Total probability of invasion
    double total_probability = 1.0 - (no_invasion_chance * (1.0 - probability_next_day));
    
    return total_probability;
}

// Function to print the invasion probability
void print_probability(double probability) {
    printf("The probability of an alien invasion is: %.4f (%.2f%%)\n", probability, probability * 100);
}