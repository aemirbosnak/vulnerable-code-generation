//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROB 100

int calculateProbability(int, int);
void printResult(int);

int main() {
    int alienShipCount, alienSkillLevel;

    printf("\n\t-- Alien Invasion Probability Calculator --\n\n");
    printf("Enter the number of alien ships: ");
    scanf("%d", &alienShipCount);
    
    printf("Enter the skill level of the aliens (1-10): ");
    scanf("%d", &alienSkillLevel);

    int invasionProb = calculateProbability(alienShipCount, alienSkillLevel);
    
    printResult(invasionProb);

    return 0;
}

int calculateProbability(int alienShipCount, int alienSkillLevel) {
    // generate a random seed
    srand(time(0));

    // calculate the probability of invasion
    int prob = (rand() % (MAX_PROB - alienSkillLevel)) + alienShipCount;

    // return the probability
    return prob;
}

void printResult(int invasionProb) {
    printf("\nCalculating invasion probability...\n");

    // simulate a loading bar
    printf("\t[");
    for (int i = 0; i <= 100; i += 10) {
        printf("%d%%", i);
        if (i < 100) printf(" ");
        fflush(stdout);
        sleep(1);
    }
    printf("]\n");

    // print the result
    printf("\nInvasion Probability: %d%%\n", invasionProb);
    if (invasionProb >= 75) {
        printf("Warning: HIGH Probability of Alien Invasion! Seek Immediate Shelter!\n");
    } else if (invasionProb >= 50) {
        printf("CAUTION: Moderate Probability of Alien Invasion. Stay Alert!\n");
    } else {
        printf("The probability of alien invasion is currently low. No Need to Worry (for now)!\n");
    }
}