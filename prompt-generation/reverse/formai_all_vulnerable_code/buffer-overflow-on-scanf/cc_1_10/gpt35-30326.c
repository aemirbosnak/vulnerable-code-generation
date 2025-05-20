//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /* Seed random number generator */
    srand(time(NULL));

    /* Initialize variables */
    int numAliens = 0;
    int numDays = 0;
    int numAttacks = 0;

    /* Ask user for input */
    printf("How many aliens are estimated to be in the vicinity?: ");
    scanf("%d", &numAliens);

    printf("How many days will the invasion last?: ");
    scanf("%d", &numDays);

    printf("What is the probability of an alien attack per day (in percentage)?: ");
    float attackProbability = 0.0;
    scanf("%f", &attackProbability);
    attackProbability /= 100.0;

    /* Simulate the invasion */
    for (int i = 0; i < numDays; i++) {
        for (int j = 0; j < numAliens; j++) {
            /* Generate a random number between 0 and 1 */
            float randomNum = (float)rand() / RAND_MAX;

            /* Determine if the alien will launch an attack */
            if (randomNum <= attackProbability) {
                numAttacks++;
            }
        }
    }

    /* Calculate the probability of an attack */
    float invasionProbability = (float)numAttacks / (numDays * numAliens) * 100;

    /* Display results */
    printf("\n\nAlien invasion probability calculator\n");
    printf("=====================================\n");
    printf("Number of aliens: %d\n", numAliens);
    printf("Number of days: %d\n", numDays);
    printf("Attack probability per day: %.2f%%\n", attackProbability * 100);
    printf("Number of attacks: %d\n", numAttacks);
    printf("Invasion probability: %.2f%%\n", invasionProbability);

    return 0;
}