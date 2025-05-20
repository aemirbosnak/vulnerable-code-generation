//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_PROBABILITY 100
#define MIN_PROBABILITY 0
#define EVENT_TIME 100

typedef struct {
    int probability;
    bool isAlienInvasion;
} AlienInvasionProbability;

int main(void) {
    srand(time(0));
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    sleep(1);
    printf("Please enter a probability between %d and %d: ", MIN_PROBABILITY, MAX_PROBABILITY);

    int enteredProbability;
    scanf("%d", &enteredProbability);

    if (enteredProbability > MAX_PROBABILITY || enteredProbability < MIN_PROBABILITY) {
        printf("\nInvalid probability entered. Please enter a number between %d and %d\n\n", MIN_PROBABILITY, MAX_PROBABILITY);
        exit(EXIT_FAILURE);
    }

    AlienInvasionProbability probability = {
        .probability = enteredProbability,
        .isAlienInvasion = false
    };

    printf("Calculating probability...\n\n");

    // Wait for some time to simulate an event happening
    sleep(EVENT_TIME);

    // Generate random number to check if there is an alien invasion
    int randomProbability = rand() % MAX_PROBABILITY + 1;

    if (randomProbability <= probability.probability) {
        probability.isAlienInvasion = true;
    }

    if (probability.isAlienInvasion) {
        printf("The probability of an alien invasion was %d%% and an invasion occurred!\n\n", probability.probability);
    } else {
        printf("The probability of an alien invasion was %d%% and no invasion occurred.\n\n", probability.probability);
    }

    return 0;
}