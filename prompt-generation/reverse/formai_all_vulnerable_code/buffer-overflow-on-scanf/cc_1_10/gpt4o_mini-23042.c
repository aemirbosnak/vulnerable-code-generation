//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 100
#define ALIEN_THRESHOLD 0.5

// Function to simulate an alien attack
double simulate_alien_attack() {
    return (double) rand() / RAND_MAX;
}

// Function to calculate invasion probability
double calculate_invasion_probability(int attempts) {
    int invasion_count = 0;

    for (int i = 0; i < attempts; i++) {
        if (simulate_alien_attack() > ALIEN_THRESHOLD) {
            invasion_count++;
        }
    }

    return (double) invasion_count / attempts;
}

// Function to display the results
void display_results(double probability, int attempts) {
    printf("\nAfter %d attempts, the calculated probability of an alien invasion is:\n", attempts);
    printf("Probability = %.2f%%\n", probability * 100);
    printf("Looks like we might be safe... for now!\n");
}

// Main function
int main() {
    srand(time(NULL));  // Seed the random number generator

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("We will determine the probability of an alien invasion based on random simulations.\n\n");
    
    int attempts;

    printf("Enter the number of simulation attempts (1 to %d): ", MAX_ATTEMPTS);
    scanf("%d", &attempts);

    // Input validation
    while (attempts < 1 || attempts > MAX_ATTEMPTS) {
        printf("Please enter a valid number of attempts (1 to %d): ", MAX_ATTEMPTS);
        scanf("%d", &attempts);
    }

    // Calculate and display the invasion probability
    double invasion_probability = calculate_invasion_probability(attempts);
    display_results(invasion_probability, attempts);

    // Bonus Round: Ask user if they want to run additional simulations
    char choice;
    printf("\nWould you like to run another simulation? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        printf("Enter the number of simulation attempts (1 to %d): ", MAX_ATTEMPTS);
        scanf("%d", &attempts);

        while (attempts < 1 || attempts > MAX_ATTEMPTS) {
            printf("Please enter a valid number of attempts (1 to %d): ", MAX_ATTEMPTS);
            scanf("%d", &attempts);
        }

        invasion_probability = calculate_invasion_probability(attempts);
        display_results(invasion_probability, attempts);
        
        printf("\nWould you like to run another simulation? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using the Alien Invasion Probability Calculator! Stay safe out there!\n");

    return 0;
}