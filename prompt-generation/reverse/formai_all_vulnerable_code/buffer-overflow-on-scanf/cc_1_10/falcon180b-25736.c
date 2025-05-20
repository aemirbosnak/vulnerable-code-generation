//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {

    // Initialize the random number generator
    srand(time(NULL));

    // Declare variables
    int numPlanets, numVisited, numInhabited;
    float distance, probability;

    // Get user input for number of planets
    printf("Enter the number of planets to visit: ");
    scanf("%d", &numPlanets);

    // Loop through each planet
    for (int i = 1; i <= numPlanets; i++) {

        // Generate distance from Earth to current planet
        distance = rand() % 100;

        // Calculate probability of alien life based on distance
        if (distance < 10) {
            probability = 0.9;
        } else if (distance < 20) {
            probability = 0.7;
        } else if (distance < 30) {
            probability = 0.5;
        } else if (distance < 40) {
            probability = 0.3;
        } else if (distance < 50) {
            probability = 0.2;
        } else {
            probability = 0.1;
        }

        // Determine if planet is inhabited
        if (rand() % 100 < probability) {
            numInhabited++;
        }

        numVisited++;
    }

    // Calculate and display probability of alien invasion
    float invasionProbability = (float)numInhabited / numVisited * 100;
    printf("Based on your journey, the probability of an alien invasion is %.2f%%\n", invasionProbability);

    return 0;
}