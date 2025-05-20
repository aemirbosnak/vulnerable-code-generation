//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 1000
#define MAX_CIVS 1000
#define MAX_YEARS 1000

int num_tries = 0;
int num_civs = 0;
int num_years = 0;

float prob_invasion = 0.0;

int main() {
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    while (num_tries < MAX_TRIES) {
        printf("How many simulations would you like to run? ");
        scanf("%d", &num_tries);
        if (num_tries <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            continue;
        }
        break;
    }

    while (num_civs < MAX_CIVS) {
        printf("How many civilizations are there in the universe? ");
        scanf("%d", &num_civs);
        if (num_civs <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            continue;
        }
        break;
    }

    while (num_years < MAX_YEARS) {
        printf("How many years would you like to simulate? ");
        scanf("%d", &num_years);
        if (num_years <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            continue;
        }
        break;
    }

    float invasions = 0.0;

    for (int i = 0; i < num_tries; i++) {
        int invasions_this_year = 0;

        for (int j = 0; j < num_civs; j++) {
            int rand_num = rand() % 100; // Random number between 0 and 99

            if (rand_num < 5) { // 5% chance of invasion
                invasions_this_year++;
            }
        }

        invasions += invasions_this_year;
    }

    prob_invasion = invasions / (num_tries * num_civs * num_years);

    printf("Based on %d simulations of %d civilizations over %d years,\n", num_tries, num_civs, num_years);
    printf("the probability of an alien invasion is %.2f%%.\n", prob_invasion * 100);

    return 0;
}