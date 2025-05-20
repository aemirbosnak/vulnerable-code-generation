//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 1000
#define MAX_DISTANCE 1000
#define MIN_DISTANCE 1
#define MAX_YEARS 100
#define MIN_YEARS 1
#define MIN_POPULATION 1000
#define MAX_POPULATION 1000000000

double calculate_probability(int attempts, int distance, int years, int population);

int main() {
    int attempts, distance, years, population;
    double probability;

    printf("Enter the number of attempts: ");
    scanf("%d", &attempts);

    printf("Enter the distance in light years: ");
    scanf("%d", &distance);

    printf("Enter the number of years to simulate: ");
    scanf("%d", &years);

    printf("Enter the estimated population: ");
    scanf("%d", &population);

    probability = calculate_probability(attempts, distance, years, population);

    printf("The probability of an alien invasion is %.2f%%\n", probability * 100);

    return 0;
}

double calculate_probability(int attempts, int distance, int years, int population) {
    int i, invasions = 0;
    double probability = 0;

    srand(time(NULL));

    for (i = 0; i < attempts; i++) {
        if (rand() % 100 <= population) {
            invasions++;
        }
    }

    probability = ((double) invasions / attempts) * 100;

    return probability;
}