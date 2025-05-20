//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int main() 
{
    int numPlanets; 
    float invasionProb; 

    printf("Enter number of planets in the galaxy: ");
    scanf("%d", &numPlanets);

    if (numPlanets <= 0) { //check if numPlanets is valid
        printf("Invalid input. Number of planets must be greater than 0.\n"); 
        return 1; //exit program with error code 
    }

    //initialize array to store planet data 
    int planetData[numPlanets][2]; 

    //ask user to input planet data 
    for (int i = 0; i < numPlanets; i++) {
        int n, m; 

        printf("Enter data for planet %d:\n", i+1); 

        printf("Enter number of alien species on the planet: ");
        scanf("%d", &n); 

        printf("Enter number of space-faring alien species on the planet: ");
        scanf("%d", &m); 

        if (n < 0 || m < 0) { //check if n and m are valid 
            printf("Invalid input. Number of alien species and space-faring alien species must be non-negative.\n"); 
            return 1; //exit program with error code 
        }

        planetData[i][0] = n; 
        planetData[i][1] = m; 
    }

    //calculate invasion probability for each planet 
    for (int i = 0; i < numPlanets; i++) {
        float p = (float) planetData[i][1] / (float) planetData[i][0]; //space-faring alien species as a percentage of total alien species 
        invasionProb = invasionProb + p; //add percentage to total invasion probability 
    }

    invasionProb = invasionProb / numPlanets; //average invasion probability across all planets 

    //output result 
    printf("Alien invasion probability for this galaxy is %.2f%%.\n", invasionProb*100); 

    return 0; //exit program with success code 
}