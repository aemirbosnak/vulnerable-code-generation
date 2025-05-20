//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define MIN_UFO_SIGHTINGS 5
#define MAX_UFO_SIGHTINGS 25
#define ALIEN_PROBABILITY_BASE 1
#define ALIEN_PROBABILITY_INCREASE 0.05

typedef unsigned long long int ull;

double alien_invasion_probability(int ufo_sightings);

int main() {
    srand(time(NULL));
    int num_trials = 100000;
    ull total_probability = 0;

    for (int i = MIN_UFO_SIGHTINGS; i <= MAX_UFO_SIGHTINGS; i++) {
        printf("UFO sightings: %d\n", i);
        double avg_probability = alien_invasion_probability(i);
        total_probability += avg_probability * (ull)pow(10, 6); // Multiply by a large number to get decent precision
        printf("Average probability of invasion: %.6f\n", avg_probability);
        printf("\n");
    }

    printf("Total probability of invasion across all UFO sightings: %.6f\n", (double)total_probability / (ull)pow(10, 6));

    return 0;
}

double alien_invasion_probability(int ufo_sightings) {
    if (ufo_sightings < MIN_UFO_SIGHTINGS) {
        return 0;
    }

    double base_probability = ALIEN_PROBABILITY_BASE;
    double probability_increase = ALIEN_PROBABILITY_INCREASE;

    if (rand() % (1 << ufo_sightings) == 0) {
        base_probability += probability_increase;
    }

    if (ufo_sightings > 1) {
        return base_probability * alien_invasion_probability(ufo_sightings - 1);
    } else {
        return base_probability;
    }
}