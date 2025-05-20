//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define UFO_SIGHTINGS_THRESHOLD 5
#define RADIO_SIGNALS_THRESHOLD 3
#define GOVERNMENT_SECRECY_HIGH 2
#define GOVERNMENT_SECRECY_MEDIUM 1
#define GOVERNMENT_SECRECY_LOW 0

typedef struct {
    int ufo_sightings;
    int radio_signals;
    int government_secrecy;
} InvasionData;

float calculate_probability(InvasionData data) {
    float ufo_probability = (float)data.ufo_sightings / 10.0;
    float radio_probability = (float)data.radio_signals / 10.0;

    float secrecy_factor;

    switch (data.government_secrecy) {
        case GOVERNMENT_SECRECY_HIGH:
            secrecy_factor = 0.5;
            break;
        case GOVERNMENT_SECRECY_MEDIUM:
            secrecy_factor = 0.2;
            break;
        case GOVERNMENT_SECRECY_LOW:
            secrecy_factor = 0.1;
            break;
        default:
            secrecy_factor = 0.0;
            break;
    }

    float probability = (ufo_probability + radio_probability + secrecy_factor) / 3.0;
    return probability;
}

int main() {
    srand(time(NULL));

    InvasionData invasion_data;

    printf("Welcome to the C Alien Invasion Probability Calculator!\n");
    printf("Enter the number of UFO sightings: ");
    scanf("%d", &invasion_data.ufo_sightings);

    printf("Enter the number of strange radio signals: ");
    scanf("%d", &invasion_data.radio_signals);

    printf("Enter the level of government secrecy (0 = low, 1 = medium, 2 = high): ");
    scanf("%d", &invasion_data.government_secrecy);

    printf("\nCalculating the probability of alien invasion...\n");

    float probability = calculate_probability(invasion_data);

    if (probability > 0.5) {
        printf("ALERT! Alien invasion probability is %f. Evacuate immediately!\n", probability);
    } else {
        printf("Alien invasion probability is %f. You are safe for now.\n", probability);
    }

    return 0;
}