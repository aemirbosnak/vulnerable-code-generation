//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define NUM_UFOS 10
#define NUM_CIRCLES 5
#define NUM_SIGNALS 3

typedef struct {
    int sightings;
    int circles;
    int signals;
} invasion_data;

float calculate_probability(invasion_data data) {
    float ufo_probability = (float) data.sightings / NUM_UFOS;
    float circle_probability = (float) data.circles / NUM_CIRCLES;
    float signal_probability = (float) data.signals / NUM_SIGNALS;

    return pow(ufo_probability, 3) * circle_probability * signal_probability;
}

int main() {
    srand(time(NULL));

    invasion_data data;

    printf("Alien Invasion Probability Calculator\n");
    printf("------------------------------------\n");

    for (int i = 0; i < NUM_UFOS; i++) {
        data.sightings += rand() % 11 + 1;
        printf("UFO sighting %d: %d\n", i + 1, data.sightings);
    }

    for (int i = 0; i < NUM_CIRCLES; i++) {
        data.circles += rand() % 6 + 1;
        printf("Crop circle %d: %d\n", i + 1, data.circles);
    }

    for (int i = 0; i < NUM_SIGNALS; i++) {
        data.signals += rand() % 4 + 1;
        printf("Radio signal %d: %d\n", i + 1, data.signals);
    }

    float invasion_probability = calculate_probability(data);
    printf("\nAlien Invasion Probability: %.2f\n", invasion_probability);

    return 0;
}