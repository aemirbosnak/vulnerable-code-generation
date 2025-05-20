//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to calculate probabilities of alien invasion
double calculate_invasion_probability(int encounters, int successful_invasions) {
    if (encounters <= 0) {
        return 0.0; // Avoid division by zero
    }
    return (double)successful_invasions / encounters * 100.0; // Return percentage
}

// Function to simulate encounters and successful invasions
void simulate_encounters(int *encounters, int *successful_invasions) {
    for (int i = 0; i < *encounters; i++) {
        // Randomly determine if the encounter was a success (use rand for simulation)
        if (rand() % 100 < 20) { // 20% chance of successful invasion
            (*successful_invasions)++;
        }
    }
}

// Function to display the results of simulation
void display_results(double probability) {
    printf("The probability of an alien invasion is: %.2f%%\n", probability);
}

// Function to get user input while ensuring it is of type int
int get_user_input(const char *prompt) {
    int input;
    printf("%s", prompt);
    while (scanf("%d", &input) != 1 || input <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        while (getchar() != '\n'); // Clear invalid input from buffer
    }
    return input;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("=== Alien Invasion Probability Calculator ===\n");

    // User inputs for encounters and successful invasions
    int encounters = get_user_input("Enter the number of encounters: ");
    int successful_invasions = 0;

    // Simulate encounters
    simulate_encounters(&encounters, &successful_invasions);

    // Calculate the probability
    double probability = calculate_invasion_probability(encounters, successful_invasions);

    // Display results
    display_results(probability);

    return 0;
}