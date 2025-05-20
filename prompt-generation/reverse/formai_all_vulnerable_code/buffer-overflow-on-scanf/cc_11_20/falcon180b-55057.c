//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10
#define MAX_FACTORS 10

int main() {
    int num_attempts = 0;
    int num_factors = 0;
    int factors[MAX_FACTORS];
    int i, j, factor;
    int num_to_factor;
    int total_attempts = 0;
    int valid_attempts = 0;
    double probability = 0.0;
    char choice;

    do {
        printf("Welcome to the Alien Invasion Probability Calculator!\n");
        printf("This program will calculate the probability of an alien invasion based on the number of attempts made.\n");
        printf("Please enter the number of attempts you want to make (1-10): ");
        scanf("%d", &num_attempts);

        if (num_attempts < 1 || num_attempts > MAX_ATTEMPTS) {
            printf("Invalid number of attempts. Please enter a number between 1 and 10.\n");
        }
    } while (num_attempts < 1 || num_attempts > MAX_ATTEMPTS);

    do {
        printf("Now enter the number of factors you want to use (1-10): ");
        scanf("%d", &num_factors);

        if (num_factors < 1 || num_factors > MAX_FACTORS) {
            printf("Invalid number of factors. Please enter a number between 1 and 10.\n");
        }
    } while (num_factors < 1 || num_factors > MAX_FACTORS);

    srand(time(NULL));

    for (i = 0; i < num_factors; i++) {
        factors[i] = rand() % 100 + 1;
    }

    for (i = 0; i < num_attempts; i++) {
        num_to_factor = rand() % 100 + 1;
        total_attempts++;

        for (j = 0; j < num_factors; j++) {
            factor = factors[j];

            if (num_to_factor % factor == 0) {
                valid_attempts++;
                break;
            }
        }
    }

    probability = (double)valid_attempts / total_attempts;

    printf("\nThe probability of an alien invasion is %.2f%%\n", probability * 100.0);

    do {
        printf("Do you want to calculate the probability again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice!= 'y' && choice!= 'n');

    return 0;
}