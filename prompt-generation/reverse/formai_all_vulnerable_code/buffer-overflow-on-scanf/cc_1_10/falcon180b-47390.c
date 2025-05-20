//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TRIES 100

/* Function to generate a random number between min and max */
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/* Function to calculate the probability of an alien invasion */
double calc_probability(int num_civilizations, int num_planets, int num_years) {
    double prob = 1.0;
    int i;

    /* Loop through each civilization and planet */
    for (i = 0; i < num_civilizations; i++) {
        prob *= pow(0.5, num_planets);
    }

    /* Loop through each year */
    for (i = 0; i < num_years; i++) {
        prob *= 0.99;
    }

    return prob;
}

int main() {
    int num_civilizations, num_planets, num_years;
    double probability;
    int tries = 0;

    /* Get user input */
    printf("Enter the number of civilizations: ");
    scanf("%d", &num_civilizations);
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);
    printf("Enter the number of years: ");
    scanf("%d", &num_years);

    /* Calculate probability */
    srand(time(NULL));
    while (tries < MAX_TRIES) {
        probability = calc_probability(num_civilizations, num_planets, num_years);
        if (probability >= 0.5) {
            break;
        }
        tries++;
    }

    /* Print results */
    printf("The probability of an alien invasion in %d years is %.2f%%\n", num_years, probability * 100.0);

    return 0;
}