//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayIntro() {
    printf("************************************************************\n");
    printf("*            Welcome to the Medieval Alien Invasion        *\n");
    printf("*                    Probability Calculator                 *\n");
    printf("************************************************************\n");
}

int gatherWarriorInput() {
    int warriors;
    printf("Hark! Brave Knight, how many warriors dost thou possess? ");
    scanf("%d", &warriors);
    return warriors;
}

int gatherResourcesInput() {
    int resources;
    printf("Lo! How many resources (gold coins) dost thou have to defend the realm? ");
    scanf("%d", &resources);
    return resources;
}

void calculateInvasionProbability(int warriors, int resources) {
    // Basic probability model for alien invasion based on warriors and resources
    double baseProbability = 0.05; // Base chance of invasion
    double warriorFactor = 0.01;    // Each warrior decreases invasion chance
    double resourceFactor = 0.0005;  // Each resource decreases invasion chance
    
    double invasionProbability = baseProbability - (warriorFactor * warriors) - (resourceFactor * resources);
    
    // Ensuring the invasion probability is within limits
    if (invasionProbability < 0) {
        invasionProbability = 0;
    }
    if (invasionProbability > 1) {
        invasionProbability = 1;
    }
    
    // Display the invading probability in a medieval fashion
    printf("\nThe chance of alien invasion upon thy kingdom is: %.2f%%\n", invasionProbability * 100);
}

void displayFinalMessage(double probability) {
    if (probability > 0.5) {
        printf("Beware! The invaders shall soon threaten thy lands!\n");
    } else {
        printf("Though the sky may darken, the invaders are less likely to come!\n");
    }
}

int main() {
    srand(time(NULL)); // Random seed for potential future randomness
    displayIntro();
    
    int warriors = gatherWarriorInput();
    int resources = gatherResourcesInput();
    
    calculateInvasionProbability(warriors, resources);
    
    double invasionProbability = 0.05 - (0.01 * warriors) - (0.0005 * resources);
    // Ensure the calculated probability is used for final message
    if (invasionProbability < 0) {
        invasionProbability = 0;
    }

    displayFinalMessage(invasionProbability);
    
    printf("May the spirits of ancient knights guide thee.\n");
    printf("************************************************************\n");
    
    return 0;
}