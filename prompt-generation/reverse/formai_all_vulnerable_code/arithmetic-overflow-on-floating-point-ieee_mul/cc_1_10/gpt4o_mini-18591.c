//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALIEN_TYPE_COUNT 5
#define ENVIRONMENT_TYPE_COUNT 4

// Shape-shifting alien representation
typedef struct {
    char name[20];
    float probability_factor;
} Alien;

typedef struct {
    char environment[20];
    float base_probability;
} Environment;

// Function prototypes
float calculate_invasion_probability(Alien aliens[], Environment environments[], int alien_index, int environment_index);
void initialize_aliens(Alien aliens[]);
void initialize_environments(Environment environments[]);
void print_invasion_probability(float probability);

int main() {
    Alien aliens[ALIEN_TYPE_COUNT];
    Environment environments[ENVIRONMENT_TYPE_COUNT];

    // Initializing aliens and environments
    initialize_aliens(aliens);
    initialize_environments(environments);

    int alien_choice, environment_choice;

    // User input
    printf("Choose an alien type (0-%d):\n", ALIEN_TYPE_COUNT - 1);
    for (int i = 0; i < ALIEN_TYPE_COUNT; i++) {
        printf("%d: %s (Factor: %.2f)\n", i, aliens[i].name, aliens[i].probability_factor);
    }
    scanf("%d", &alien_choice);

    printf("Choose an environment type (0-%d):\n", ENVIRONMENT_TYPE_COUNT - 1);
    for (int j = 0; j < ENVIRONMENT_TYPE_COUNT; j++) {
        printf("%d: %s (Base Probability: %.2f)\n", j, environments[j].environment, environments[j].base_probability);
    }
    scanf("%d", &environment_choice);

    // Calculate invasion probability
    float invasion_probability = calculate_invasion_probability(aliens, environments, alien_choice, environment_choice);
    print_invasion_probability(invasion_probability);

    return 0;
}

void initialize_aliens(Alien aliens[]) {
    // Setting up different types of aliens
    snprintf(aliens[0].name, sizeof(aliens[0].name), "Zorgon");
    aliens[0].probability_factor = 0.8;

    snprintf(aliens[1].name, sizeof(aliens[1].name), "Glaargon");
    aliens[1].probability_factor = 1.2;

    snprintf(aliens[2].name, sizeof(aliens[2].name), "Klyx");
    aliens[2].probability_factor = 0.5;

    snprintf(aliens[3].name, sizeof(aliens[3].name), "Mogdroid");
    aliens[3].probability_factor = 1.5;

    snprintf(aliens[4].name, sizeof(aliens[4].name), "Slyth");
    aliens[4].probability_factor = 0.9;
}

void initialize_environments(Environment environments[]) {
    // Setting up different environmental conditions
    snprintf(environments[0].environment, sizeof(environments[0].environment), "Desert");
    environments[0].base_probability = 0.3;

    snprintf(environments[1].environment, sizeof(environments[1].environment), "Urban");
    environments[1].base_probability = 0.6;

    snprintf(environments[2].environment, sizeof(environments[2].environment), "Forest");
    environments[2].base_probability = 0.4;

    snprintf(environments[3].environment, sizeof(environments[3].environment), "Underground");
    environments[3].base_probability = 0.5;
}

float calculate_invasion_probability(Alien aliens[], Environment environments[], int alien_index, int environment_index) {
    return environments[environment_index].base_probability * aliens[alien_index].probability_factor;
}

void print_invasion_probability(float probability) {
    if (probability > 1.0) {
        probability = 1.0; // Cap the probability to a maximum of 1
    }

    printf("Invasion probability: %.2f%%\n", probability * 100);
    if (probability > 0.7) {
        printf("Warning! High risk of invasion detected!\n");
    } else if (probability > 0.4) {
        printf("Moderate risk! Stay alert!\n");
    } else {
        printf("Low risk of invasion. All is safe.\n");
    }
}