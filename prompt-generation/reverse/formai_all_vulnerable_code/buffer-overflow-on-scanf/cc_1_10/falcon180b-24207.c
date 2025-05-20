//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TRIES 1000000
#define MAX_YEARS 10000
#define MIN_YEARS 1
#define PROBABILITY_THRESHOLD 0.05

int main() {
    int num_tries = 0;
    int num_successes = 0;
    double probability = 0.0;
    int max_years = MAX_YEARS;
    int min_years = MIN_YEARS;
    double threshold = PROBABILITY_THRESHOLD;
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("We will now simulate the arrival of aliens on Earth.\n");
    printf("Please enter the maximum number of years you want to simulate:\n");
    scanf("%d", &max_years);

    while (max_years < MIN_YEARS) {
        printf("Invalid input. Please enter a number greater than or equal to %d:\n", MIN_YEARS);
        scanf("%d", &max_years);
    }

    while (num_tries < MAX_TRIES) {
        num_tries++;
        num_successes = 0;
        for (int i = 0; i < 100; i++) {
            if (rand() % 2 == 1) {
                num_successes++;
            }
        }
        probability = ((double) num_successes / 100.0) * 100.0;
        if (probability >= threshold) {
            printf("ALIEN INVASION DETECTED!\n");
            printf("The probability of an alien invasion within the next %d years is %.2f%%.\n", max_years, probability);
            break;
        }
    }

    if (num_tries == MAX_TRIES) {
        printf("No alien invasion detected within the given time frame.\n");
    }

    return 0;
}