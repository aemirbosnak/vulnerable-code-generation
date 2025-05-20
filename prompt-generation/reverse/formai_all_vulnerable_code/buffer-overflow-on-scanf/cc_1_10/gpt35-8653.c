//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double calculateProbability(double distance, int armySize, int spaceshipCount);

int main() {

    double distanceFromEarth;
    int alienArmySize, spaceships;

    // Getting user input
    printf("Enter the distance from Earth to the alien planet (in light years): ");
    scanf("%lf", &distanceFromEarth);

    printf("Enter the estimated size of the alien army: ");
    scanf("%d", &alienArmySize);

    printf("Enter the count of spaceships they have: ");
    scanf("%d", &spaceships);

    // Calculating the probability
    double probability = calculateProbability(distanceFromEarth, alienArmySize, spaceships) * 100;

    // Output to user
    printf("\n\nThe probability of alien invasion is: %lf%%\n\n", probability);

    return 0;
}

double calculateProbability(double distance, int armySize, int spaceshipCount) {

    //Initializing variables
    double randomNumber;
    double distanceFactor, armyFactor, spaceshipFactor;
    double invasionProbability; 

    // Generating random number
    srand(time(NULL));
    randomNumber = (double)rand() / (double)RAND_MAX;

    // Calculating the distance probability factor
    if (distance <= 50) {
        distanceFactor = 0.9;
    }
    else if (distance <= 100) {
        distanceFactor = 0.8;
    }
    else if (distance <= 150) {
        distanceFactor = 0.7;
    }
    else if (distance <= 200) {
        distanceFactor = 0.6;
    }
    else if (distance <= 250) {
        distanceFactor = 0.5;
    }
    else {
        distanceFactor = 0.4;
    }

    // Calculating the army size probability factor
    if (armySize <= 1000) {
        armyFactor = 0.1;
    }
    else if (armySize <= 5000) {
        armyFactor = 0.2;
    }
    else if (armySize <= 10000) {
        armyFactor = 0.4;
    }
    else if (armySize <= 50000) {
        armyFactor = 0.7;
    }
    else {
        armyFactor = 1.0;
    }

    // Calculating the spaceship count probability factor
    if (spaceshipCount <= 1) {
        spaceshipFactor = 0.1;
    }
    else if (spaceshipCount <= 3) {
        spaceshipFactor = 0.3;
    }
    else if (spaceshipCount <= 5) {
        spaceshipFactor = 0.5;
    }
    else if (spaceshipCount <= 7) {
        spaceshipFactor = 0.7;
    }
    else {
        spaceshipFactor = 0.9;
    }

    // Calculating the final probability
    invasionProbability = distanceFactor * armyFactor * spaceshipFactor * randomNumber;

    return invasionProbability;
}