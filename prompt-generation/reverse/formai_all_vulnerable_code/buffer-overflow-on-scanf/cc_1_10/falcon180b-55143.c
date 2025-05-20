//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 100
#define MAX_PROBABILITY 100

struct alien {
    char name[20];
    int probability;
};

void populateAliens(struct alien aliens[], int numAliens) {
    int i;
    for (i = 0; i < numAliens; i++) {
        aliens[i].probability = rand() % MAX_PROBABILITY;
        sprintf(aliens[i].name, "Alien %d", i + 1);
    }
}

int main() {
    int numAliens;
    printf("How many aliens do you want to simulate? ");
    scanf("%d", &numAliens);

    struct alien aliens[numAliens];
    populateAliens(aliens, numAliens);

    int invasionCount = 0;
    int totalProbability = 0;

    srand(time(NULL));

    printf("\nAlien Invasion Probability Calculator\n");
    printf("======================================\n");

    while (invasionCount < numAliens) {
        int maxProbability = 0;
        int maxAlienIndex = 0;

        for (int i = 0; i < numAliens; i++) {
            if (aliens[i].probability > maxProbability) {
                maxProbability = aliens[i].probability;
                maxAlienIndex = i;
            }
        }

        totalProbability += maxProbability;
        invasionCount++;

        printf("\nAlien %s has invaded with a probability of %d%%!\n", aliens[maxAlienIndex].name, maxProbability);
        printf("Total invasion probability so far: %d%%\n\n", totalProbability);
    }

    printf("\nAll aliens have invaded! Final invasion probability: %d%%\n", totalProbability);

    return 0;
}