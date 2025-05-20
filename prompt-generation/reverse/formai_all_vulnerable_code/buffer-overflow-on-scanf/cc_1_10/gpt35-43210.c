//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // Initialize seed
    srand(time(0));

    // Initialize variables
    int numPlanets = 0;
    int numInhabited = 0;
    int numInvasions = 0;
    double invasionProb = 0.0;

    // Request user input
    printf("Enter the number of planets in the galaxy: ");
    scanf("%d", &numPlanets);
    printf("Enter the number of inhabited planets: ");
    scanf("%d", &numInhabited);

    // Verify input is valid
    if(numPlanets < numInhabited){
        printf("Error: Number of inhabited planets cannot be greater than the total number of planets.\n");
        return 1;
    }

    // Calculate invasion probability
    invasionProb = (double)numInhabited / numPlanets;

    // Execute simulation trials
    for(int i=0; i<10000; i++){
        // Generate random number between 0 and 1
        double randNum = (double)rand() / RAND_MAX;

        // Determine whether invasion occurs
        if(randNum <= invasionProb){
            numInvasions++;
        }
    }

    // Print results
    printf("Results of Alien Invasion Probability Calculator:\n");
    printf("Number of planets in the galaxy: %d\n", numPlanets);
    printf("Number of inhabited planets: %d\n", numInhabited);
    printf("Invasion probability: %f\n", invasionProb);
    printf("Number of simulation trials: %d\n", 10000);
    printf("Number of invasions: %d\n", numInvasions);
    printf("Probability of at least one invasion: %f\n", (double)numInvasions/10000);

    // End program
    return 0;
}