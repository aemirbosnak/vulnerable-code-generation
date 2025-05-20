//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function prototypes */
int calculateProbability(int difficulty, int technologyLevel);
void printResult(int probability);

/* Main function */
int main() {
    int difficulty, technologyLevel, probability;

    /* Seed the random number generator */
    srand(time(NULL));

    /* Get user input */
    printf("Enter the difficulty level (1-10): ");
    scanf("%d", &difficulty);

    printf("Enter the technology level (1-10): ");
    scanf("%d", &technologyLevel);

    /* Calculate the probability of an alien invasion */
    probability = calculateProbability(difficulty, technologyLevel);

    /* Display the result */
    printResult(probability);

    return 0;
}

/* Function to calculate the probability of an alien invasion */
int calculateProbability(int difficulty, int technologyLevel) {
    int baseProbability, randomModifier;

    /* Calculate the base probability */
    baseProbability = difficulty * 10;

    /* Generate a random modifier */
    randomModifier = rand() % 20 - 10;

    /* Apply the random modifier */
    baseProbability += randomModifier;

    /* Apply the technology level modifier */
    if (technologyLevel >= 7) {
        baseProbability /= 2;
    } else if (technologyLevel <= 3) {
        baseProbability *= 2;
    }

    return baseProbability;
}

/* Function to print the result */
void printResult(int probability) {
    printf("The probability of an alien invasion is %d%%.\n", probability);
}