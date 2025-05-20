//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_ATTACKS 100
#define MAX_NUM_YEARS 100

struct Attack {
    int year;
    int success;
};

int main() {
    int num_attacks;
    int num_years;
    int total_successful_attacks;
    struct Attack attacks[MAX_NUM_ATTACKS];
    double probability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please answer the following questions:\n");

    // Get number of attacks
    do {
        printf("How many attacks have there been? (1-%d): ", MAX_NUM_ATTACKS);
        scanf("%d", &num_attacks);
    } while (num_attacks < 1 || num_attacks > MAX_NUM_ATTACKS);

    // Get number of years
    do {
        printf("How many years have passed since the first attack? (1-%d): ", MAX_NUM_YEARS);
        scanf("%d", &num_years);
    } while (num_years < 1 || num_years > MAX_NUM_YEARS);

    // Get success of each attack
    for (int i = 0; i < num_attacks; i++) {
        printf("Was attack #%d successful? (0 for no, 1 for yes): ", i+1);
        scanf("%d", &attacks[i].success);
    }

    // Calculate probability
    total_successful_attacks = 0;
    for (int i = 0; i < num_attacks; i++) {
        if (attacks[i].success == 1) {
            total_successful_attacks++;
        }
    }
    probability = ((double)total_successful_attacks / num_attacks) * 100;

    // Print results
    printf("\nThe probability of a successful alien invasion is %.2f%%\n", probability);

    return 0;
}