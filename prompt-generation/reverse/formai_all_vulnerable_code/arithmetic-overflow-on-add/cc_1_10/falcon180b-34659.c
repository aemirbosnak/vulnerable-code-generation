//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to simulate an alien invasion and return the probability of success
float simulateInvasion(int numShips, int numCities, int shipStrength, int cityDefense) {
    float successProbability = 0.0;
    int numSuccessfulAttacks = 0;

    // Simulate attacks on each city
    for (int i = 0; i < numCities; i++) {
        int attackStrength = randInt(1, shipStrength);
        int defenseStrength = randInt(1, cityDefense);

        if (attackStrength > defenseStrength) {
            numSuccessfulAttacks++;
        }
    }

    // Calculate success probability
    successProbability = ((float)numSuccessfulAttacks / numCities) * 100.0;

    return successProbability;
}

int main() {
    srand(time(NULL));

    // Get user input for number of ships, cities, ship strength, and city defense
    int numShips, numCities, shipStrength, cityDefense;
    printf("Enter the number of alien ships: ");
    scanf("%d", &numShips);
    printf("Enter the number of cities on Earth: ");
    scanf("%d", &numCities);
    printf("Enter the strength of each alien ship (1-100): ");
    scanf("%d", &shipStrength);
    printf("Enter the defense strength of each city (1-100): ");
    scanf("%d", &cityDefense);

    // Simulate invasion and print results
    float successProbability = simulateInvasion(numShips, numCities, shipStrength, cityDefense);
    printf("The probability of a successful alien invasion is %.2f%%\n", successProbability);

    return 0;
}