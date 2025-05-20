//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate the number of planets with intelligent life in the Milky Way galaxy
int calculatePlanetsWithLife() {
    int numPlanets;
    double drakeEquationResult;

    // Drake Equation: N = R* * fp * ne * fl * fi * fc * L
    double R = 7.0; // Average number of stars with planets per year
    double fp = 0.5; // Fraction of stars with planets
    double ne = 2.0; // Number of planets per star that can potentially support life
    double fl = 1.0; // Fraction of planets that actually develop life
    double fi = 0.01; // Fraction of planets with life where intelligent life evolves
    double fc = 0.01; // Fraction of planets with intelligent life that can communicate
    double L = 10.0; // Average length of time (in years) that a civilization can communicate

    // Calculate the number of planets with intelligent life
    drakeEquationResult = R * fp * ne * fl * fi * fc * L;
    numPlanets = (int)drakeEquationResult;

    return numPlanets;
}

// Function to calculate the probability of an alien invasion happening in the next 100 years
double calculateInvasionProbability() {
    int numPlanetsWithLife;
    double probability;

    // Calculate the number of planets with intelligent life
    numPlanetsWithLife = calculatePlanetsWithLife();

    // Calculate the probability of an alien invasion happening in the next 100 years
    probability = numPlanetsWithLife / (double)pow(10.0, 9.0);

    return probability;
}

// Main function
int main() {
    int numInvasions;
    double invasionProbability;

    // Calculate the probability of an alien invasion happening in the next 100 years
    invasionProbability = calculateInvasionProbability();

    // Simulate 1000 years and count the number of alien invasions
    numInvasions = 0;
    for (int i = 0; i < 1000; i++) {
        if (rand() % 100 < invasionProbability * 100.0) {
            numInvasions++;
        }
    }

    // Print the results
    printf("The probability of an alien invasion happening in the next 100 years is %.2f%%\n", invasionProbability * 100.0);
    printf("In 1000 years, there were %d alien invasions.\n", numInvasions);

    return 0;
}