//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to calculate the probability of an alien invasion
double calc_probability(int num_planets, int num_inhabited_planets, int num_civilizations) {
    double probability = 0.0;

    // Calculate the probability based on the Drake equation
    probability = (double)num_civilizations / (num_planets * num_inhabited_planets);

    return probability;
}

int main() {
    int num_planets, num_inhabited_planets, num_civilizations;
    double probability;
    char choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get user input for the number of planets, inhabited planets, and civilizations
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);

    printf("Enter the number of inhabited planets: ");
    scanf("%d", &num_inhabited_planets);

    printf("Enter the number of civilizations: ");
    scanf("%d", &num_civilizations);

    // Calculate the probability of an alien invasion
    probability = calc_probability(num_planets, num_inhabited_planets, num_civilizations);

    // Print the result
    printf("The probability of an alien invasion is %.2f%%\n", probability * 100.0);

    // Ask the user if they want to run the program again
    printf("Do you want to run the program again? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        return 0;
    }
}