//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayGreeting() {
    printf("***************************************\n");
    printf("* Welcome to the Alien Invasion       *\n");
    printf("* Probability Calculator!             *\n");
    printf("***************************************\n");
    printf("Let's have some fun calculating the  \n");
    printf("probability of an alien invasion!    \n");
    printf("***************************************\n");
}

float getInput(char *prompt) {
    float input;
    printf("%s", prompt);
    scanf("%f", &input);
    return input;
}

float calculateBaseProbability(float beliefInLife, float beliefInIntelligence) {
    return (beliefInLife * beliefInIntelligence) / 100.0;
}

float calculateInvasionProbability(float baseProbability) {
    float randomness = (float)rand() / RAND_MAX; // Get a random float between 0.0 and 1.0
    return baseProbability + (randomness * (1.0 - baseProbability));  // Randomly adjust the invasion probability
}

void displayProbability(float probability) {
    printf("The probability of an alien invasion is: %.2f%%\n", probability * 100);
    if (probability > 0.75) {
        printf("Whoa! Better get your tinfoil hat on!\n");
    } else if (probability > 0.5) {
        printf("There might be something going on up there!\n");
    } else {
        printf("Looks like Earth is safe for now!\n");
    }
}

int main() {
    srand(time(0)); // Seed the random number generator

    // Display greeting
    displayGreeting();

    // Get user beliefs
    float beliefInLife = getInput("On a scale of 0 to 100, how much do you believe in alien life? ");
    float beliefInIntelligence = getInput("On a scale of 0 to 100, how much do you believe alien life is intelligent? ");

    // Calculate probabilities
    float baseProbability = calculateBaseProbability(beliefInLife, beliefInIntelligence);
    float invasionProbability = calculateInvasionProbability(baseProbability);

    // Display the result
    displayProbability(invasionProbability);

    // Thank the user
    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    printf("Keep looking at the stars!\n");
    
    return 0;
}