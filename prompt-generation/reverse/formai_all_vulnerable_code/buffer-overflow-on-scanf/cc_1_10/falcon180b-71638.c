//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 1000
#define MAX_HUMANS 1000

struct Alien {
    int strength;
    int intelligence;
    int aggression;
};

struct Human {
    int strength;
    int intelligence;
    int aggression;
};

void generateAliens(struct Alien aliens[], int numAliens) {
    srand(time(0));
    for (int i = 0; i < numAliens; i++) {
        aliens[i].strength = rand() % 101;
        aliens[i].intelligence = rand() % 101;
        aliens[i].aggression = rand() % 101;
    }
}

void generateHumans(struct Human humans[], int numHumans) {
    srand(time(0));
    for (int i = 0; i < numHumans; i++) {
        humans[i].strength = rand() % 101;
        humans[i].intelligence = rand() % 101;
        humans[i].aggression = rand() % 101;
    }
}

int main() {
    int numAliens, numHumans;
    printf("Enter the number of aliens: ");
    scanf("%d", &numAliens);
    printf("Enter the number of humans: ");
    scanf("%d", &numHumans);

    struct Alien aliens[MAX_ALIENS];
    struct Human humans[MAX_HUMANS];

    generateAliens(aliens, numAliens);
    generateHumans(humans, numHumans);

    int alienStrengthSum = 0, humanStrengthSum = 0;
    for (int i = 0; i < numAliens; i++) {
        alienStrengthSum += aliens[i].strength;
    }

    for (int i = 0; i < numHumans; i++) {
        humanStrengthSum += humans[i].strength;
    }

    double alienStrengthAvg = (double) alienStrengthSum / numAliens;
    double humanStrengthAvg = (double) humanStrengthSum / numHumans;

    double invasionProbability = 0.0;

    if (alienStrengthAvg > humanStrengthAvg) {
        invasionProbability = 1.0;
    } else if (alienStrengthAvg < humanStrengthAvg) {
        invasionProbability = 0.0;
    } else {
        invasionProbability = 0.5;
    }

    printf("Invasion probability: %.2f%%\n", invasionProbability * 100.0);

    return 0;
}