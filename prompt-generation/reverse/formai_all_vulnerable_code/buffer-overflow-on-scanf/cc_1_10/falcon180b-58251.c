//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LIFE_FORMS 1000000
#define MAX_PLANETS 1000000
#define MAX_TRIALS 1000000

typedef struct {
    int life_forms;
    int planets;
    int trials;
} Simulation;

double calculate_probability(int life_forms, int planets, int trials) {
    double probability = 0.0;
    for (int i = 0; i < trials; i++) {
        if (life_forms > planets) {
            probability += 1.0;
        }
    }
    return probability / trials;
}

int main() {
    Simulation simulation;
    simulation.life_forms = 0;
    simulation.planets = 0;
    simulation.trials = 0;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of life forms in the universe: ");
    scanf("%d", &simulation.life_forms);

    printf("Please enter the number of planets in the universe: ");
    scanf("%d", &simulation.planets);

    printf("Please enter the number of trials you would like to run: ");
    scanf("%d", &simulation.trials);

    srand(time(NULL));

    for (int i = 0; i < simulation.trials; i++) {
        printf("Trial #%d:\n", i + 1);
        simulation.life_forms = rand() % MAX_LIFE_FORMS;
        simulation.planets = rand() % MAX_PLANETS;
        double probability = calculate_probability(simulation.life_forms, simulation.planets, simulation.trials);
        printf("Probability of alien invasion: %.2f%%\n\n", probability * 100);
    }

    return 0;
}