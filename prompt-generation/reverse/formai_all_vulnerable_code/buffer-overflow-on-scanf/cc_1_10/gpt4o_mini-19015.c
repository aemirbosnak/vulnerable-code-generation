//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A medieval-style alien invasion probability calculator

void displayIntroduction() {
    printf("==== A Medieval Alien Invasion Probability Calculator ====\n");
    printf("In the realm of meddling sorcerers and otherworldly beasts,\n");
    printf("Ye shall calculate the likelihood of an extraterrestrial invasion.\n");
    printf("Be warned, brave adventurer, for numbers may lie.\n");
    printf("=========================================================\n");
}

int getRandomProbability() {
    // Generate a random probability for the alien invasion
    return rand() % 101; // Returns a value from 0 to 100
}

void displayProbability(int probability) {
    if (probability <= 20) {
        printf("The chance of invasion is low: %d%% - Peace reigns for now.\n", probability);
    } else if (probability <= 50) {
        printf("The chance of invasion is moderate: %d%% - Heed the call to arms!\n", probability);
    } else if (probability <= 80) {
        printf("The chance of invasion is high: %d%% - Prepare for a fierce battle!\n", probability);
    } else {
        printf("The chance of invasion is very high: %d%% - Run for the hills!\n", probability);
    }
}

void performFortuneTelling() {
    int numReadings = 5; // Perform 5 readings for the fortune-telling
    int totalProbability = 0;

    printf("\n=== Fortune Telling Session Begins ===\n");
    for (int i = 1; i <= numReadings; i++) {
        printf("Reading %d:\n", i);
        int reading = getRandomProbability();
        totalProbability += reading;
        displayProbability(reading);
    }

    int averageProbability = totalProbability / numReadings;
    printf("\n=== In Sum ===\n");
    printf("The average probability of invasion over %d readings is: %d%%\n", numReadings, averageProbability);
    displayProbability(averageProbability);
}

void invokeProvocation() {
    int provocationPower;

    printf("\n=== Provocation of the Alien Beasts ===\n");
    printf("Alas, the power ye possess to provoke their wrath (1-10): ");
    scanf("%d", &provocationPower);
    
    if (provocationPower < 1 || provocationPower > 10) {
        printf("Hark! Thy provocation must be between 1 and 10!\n");
    } else {
        // Multiply the randomness of alien invasion by provocation
        int chanceOfInvasion = (getRandomProbability() + provocationPower * 5) % 101;
        printf("By thy chosen provocation, the new probability of invasion is: %d%%\n", chanceOfInvasion);
        displayProbability(chanceOfInvasion);
    }
}

int main() {
    srand(time(NULL)); // Seeding the random number generator

    while (1) {
        displayIntroduction();
        performFortuneTelling();

        char continueChoice;
        printf("\nDost thou wish to provoke the alien beasts further? (Y/N): ");
        scanf(" %c", &continueChoice);
        
        if (continueChoice == 'Y' || continueChoice == 'y') {
            invokeProvocation();
        } else {
            printf("As ye wish, brave adventurer. The realm shall rest until next time.\n");
            break;
        }
    }

    return 0;
}