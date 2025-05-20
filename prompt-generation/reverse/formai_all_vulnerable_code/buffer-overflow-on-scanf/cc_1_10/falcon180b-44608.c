//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 1000
#define MAX_NUM_ALIENS 100
#define MAX_ALIEN_STRENGTH 1000
#define MAX_EARTH_STRENGTH 1000
#define PROBABILITY_OF_SUCCESS 0.5

typedef struct {
    int numAliens;
    int alienStrength;
    int earthStrength;
} Invasion;

int main() {
    srand(time(NULL));
    int numAliens = 0;
    int alienStrength = 0;
    int earthStrength = 0;
    int numTries = 0;
    int numSuccesses = 0;
    float probability = 0.0;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of aliens (max %d): ", MAX_NUM_ALIENS);
    scanf("%d", &numAliens);
    printf("Please enter the strength of the aliens (max %d): ", MAX_ALIEN_STRENGTH);
    scanf("%d", &alienStrength);
    printf("Please enter the strength of Earth's defenses (max %d): ", MAX_EARTH_STRENGTH);
    scanf("%d", &earthStrength);

    for (int i = 0; i < MAX_TRIES; i++) {
        numTries++;
        if (alienStrength > earthStrength) {
            printf("Invasion #%d: Aliens win!\n", i+1);
        } else if (alienStrength < earthStrength) {
            printf("Invasion #%d: Earth wins!\n", i+1);
        } else {
            printf("Invasion #%d: Tie!\n", i+1);
        }
        if (alienStrength > earthStrength) {
            numSuccesses++;
        }
    }

    probability = (float)numSuccesses / numTries;
    printf("The probability of an alien invasion succeeding is %.2f%%\n", probability * 100);

    return 0;
}