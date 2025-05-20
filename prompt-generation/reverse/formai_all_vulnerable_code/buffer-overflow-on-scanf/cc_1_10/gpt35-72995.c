//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Sherlock Holmes
// "The Case of the Alien Invasion Probability Calculator"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//function to generate random number between min and max
int generateRandomNumber(int min, int max){
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int main(){
    int numPlanets = 0;
    float habitablePlanets = 0, alienLives = 0, invasionProbability = 0;
    char response;
    bool foundHabitablePlanet = false;
    
    srand(time(NULL));
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("How many planets will you be surveying today? ");
    scanf("%d", &numPlanets);
    
    //validate number of planets being surveyed
    while(numPlanets <= 0){
        printf("Invalid number of planets. Please enter a positive integer: ");
        scanf("%d", &numPlanets);
    }
    
    //surveying planets
    for(int i=1; i<=numPlanets; i++){
        printf("\nSurveying planet %d...\n", i);
        printf("Is the planet habitable? [y/n]: ");
        scanf(" %c", &response);
        
        //validate response
        while(response != 'y' && response != 'n'){
            printf("Invalid response. Please enter 'y' or 'n'.\n");
            printf("Is the planet habitable? [y/n]: ");
            scanf(" %c", &response);
        }
        
        //tracking habitable planets
        if(response == 'y'){
            foundHabitablePlanet = true;
            habitablePlanets++;
            
            //calculating alien life forms
            int numLifeForms = generateRandomNumber(1, 1000000);
            printf("Number of alien life forms found: %d\n", numLifeForms);
            alienLives += numLifeForms;
        }
        
        //end survey if probability of invasion is already 100%
        if(invasionProbability == 1){
            printf("Invasion probability is already 100%... No need to survey rest of the planets\n");
            break;
        }
    }
    
    //calculate invasion probability if a habitable planet is found
    if(foundHabitablePlanet){
        invasionProbability = (alienLives * 100) / (habitablePlanets * 1000000);
        printf("\nAlien Invasion Probability: %.2f%c\n", invasionProbability, 37);
    }
    else{
        printf("\nNo habitable planets found... Alien Invasion Probability is 0%%\n");
    }
    
    printf("\nThank you for using the Alien Invasion Probability Calculator!\n");
    
    //success
    return 0;
}