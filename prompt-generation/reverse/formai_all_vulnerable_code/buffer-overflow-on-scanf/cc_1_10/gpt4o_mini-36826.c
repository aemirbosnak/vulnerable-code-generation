//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void displayWelcomeMessage();
int getAlienActivityLevel();
int getHumanReadinessLevel();
float calculateInvasionProbability(int activity, int readiness);
void displayResults(float probability);

int main() {
    // Seed the random number generator
    srand(time(0));

    displayWelcomeMessage();

    // Get activity and readiness levels from the user
    int alienActivity = getAlienActivityLevel();
    int humanReadiness = getHumanReadinessLevel();

    // Calculate the invasion probability
    float invasionProbability = calculateInvasionProbability(alienActivity, humanReadiness);

    // Display the results
    displayResults(invasionProbability);

    return 0;
}

void displayWelcomeMessage() {
    printf("************************************************************\n");
    printf("   WELCOME TO THE ALIEN INVASION PROBABILITY CALCULATOR!   \n");
    printf("************************************************************\n");
    printf("Let's find out how likely it is that aliens are invading!\n\n");
}

int getAlienActivityLevel() {
    int activity;
    printf("How much alien activity have you observed recently? (1-10): ");
    while (1) {
        scanf("%d", &activity);
        if (activity >= 1 && activity <= 10) {
            break;
        } else {
            printf("Please enter a valid number between 1 and 10: ");
        }
    }
    return activity;
}

int getHumanReadinessLevel() {
    int readiness;
    printf("On a scale from 1 to 10, how ready is humanity to face an invasion? ");
    while (1) {
        scanf("%d", &readiness);
        if (readiness >= 1 && readiness <= 10) {
            break;
        } else {
            printf("Please enter a valid number between 1 and 10: ");
        }
    }
    return readiness;
}

float calculateInvasionProbability(int activity, int readiness) {
    // Simplistic formula to calculate invasion probability
    // Just for the sake of humor and creativity!
    float probability = (float)activity / readiness * (rand() % 30 + 1) / 30.0;
    return probability;
}

void displayResults(float probability) {
    printf("\n********** INVASION PROBABILITY RESULTS *********\n");
    printf("Your calculated probability of an alien invasion is:\n");
    printf("        %.2f%%\n", probability * 100);

    if (probability < 0.15) {
        printf("Don't worry! The aliens are quite far away!\n");
    } else if (probability < 0.35) {
        printf("Hmm... you might want to keep an eye on the skies!\n");
    } else if (probability < 0.75) {
        printf("It's getting serious! Make sure you're prepared!\n");
    } else {
        printf("Warning! ALIEN INVASION IMMINENT! Get your gear!\n");
    }

    printf("***********************************************\n");
    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
}