//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double probability;
    double mean;
    double variance;
} Distribution;

Distribution alien_invasion_probability(int year, int distance, int population) {
    Distribution distribution;

    if (year < 1000) {
        distribution.probability = 0.0;
    } else if (year < 2000) {
        distribution.probability = 0.001;
    } else if (year < 3000) {
        distribution.probability = 0.01;
    } else if (year < 4000) {
        distribution.probability = 0.05;
    } else if (year < 5000) {
        distribution.probability = 0.1;
    } else {
        distribution.probability = 0.2;
    }

    if (distance < 100) {
        distribution.mean = 0.0;
    } else if (distance < 500) {
        distribution.mean = 0.1;
    } else if (distance < 1000) {
        distribution.mean = 0.2;
    } else if (distance < 5000) {
        distribution.mean = 0.3;
    } else if (distance < 10000) {
        distribution.mean = 0.4;
    } else {
        distribution.mean = 0.5;
    }

    if (population < 1000000) {
        distribution.variance = 0.0;
    } else if (population < 10000000) {
        distribution.variance = 0.1;
    } else if (population < 100000000) {
        distribution.variance = 0.2;
    } else if (population < 1000000000) {
        distribution.variance = 0.3;
    } else if (population < 10000000000) {
        distribution.variance = 0.4;
    } else {
        distribution.variance = 0.5;
    }

    return distribution;
}

int main() {
    int year, distance, population;

    printf("Enter the year: ");
    scanf("%d", &year);

    printf("Enter the distance to the nearest star (in light years): ");
    scanf("%d", &distance);

    printf("Enter the population of the Earth: ");
    scanf("%d", &population);

    Distribution distribution = alien_invasion_probability(year, distance, population);

    printf("The probability of an alien invasion is: %.2f%%\n", distribution.probability * 100);
    printf("The mean time to an alien invasion is: %.2f years\n", distribution.mean);
    printf("The variance of the time to an alien invasion is: %.2f years^2\n", distribution.variance);

    return 0;
}