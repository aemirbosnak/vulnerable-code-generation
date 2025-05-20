//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CIVILIZATIONS 1000
#define MAX_YEARS 100
#define MIN_YEARS 1
#define PROBABILITY_THRESHOLD 0.5

typedef struct {
    int num_civilizations;
    int num_years;
    double probability;
} SimulationResult;

void run_simulation(int num_civilizations, int num_years, double *probability) {
    int i;
    int num_invaded = 0;

    srand(time(NULL));

    for (i = 0; i < num_civilizations; i++) {
        int invaded = rand() % 2; // 0 = not invaded, 1 = invaded
        if (invaded == 1) {
            num_invaded++;
        }
    }

    *probability = (double)num_invaded / num_civilizations;
}

int main() {
    int num_civilizations;
    int num_years;
    double probability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This program will simulate alien invasions and calculate the probability of an invasion occurring.\n");
    printf("Please enter the number of civilizations you want to simulate (between 1 and %d): ", MAX_CIVILIZATIONS);
    scanf("%d", &num_civilizations);

    printf("Please enter the number of years you want to simulate (between %d and %d): ", MIN_YEARS, MAX_YEARS);
    scanf("%d", &num_years);

    run_simulation(num_civilizations, num_years, &probability);

    if (probability >= PROBABILITY_THRESHOLD) {
        printf("WARNING: The probability of an alien invasion is %.2f%% or higher!\n", probability * 100);
    } else {
        printf("The probability of an alien invasion is %.2f%% or lower.\n", probability * 100);
    }

    return 0;
}