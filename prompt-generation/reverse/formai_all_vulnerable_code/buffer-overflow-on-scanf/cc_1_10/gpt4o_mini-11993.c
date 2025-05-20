//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_YEARS 100
#define MAX_SIGHTINGS 1000

typedef struct {
    int year;
    int sightings;
    double probability;
} AlienInvasionData;

void printStatistics(AlienInvasionData data[], int count) {
    printf("\nYear\tSightings\tProbability of Invasion (%%)\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%4d\t%9d\t%10.2f\n", data[i].year, data[i].sightings, data[i].probability);
    }
}

double calculateProbability(int sightings) {
    // Simple heuristic: more sightings increase probability
    // For example: P = sightings / some factor
    const double factor = 50.0;
    double probability = (double)sightings / factor;

    // Ensure probability is not negative or greater than 100%
    if (probability < 0) {
        probability = 0;
    } else if (probability > 100) {
        probability = 100;
    }

    return probability;
}

int main() {
    AlienInvasionData invasionData[MAX_YEARS];
    int yearCount = 0;
    int year, sightings;
    char choice;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    do {
        if (yearCount >= MAX_YEARS) {
            printf("Maximum number of years reached. Cannot enter more!\n");
            break;
        }

        printf("Enter Year (e.g., 2023): ");
        scanf("%d", &year);
        invasionData[yearCount].year = year;

        printf("Enter Number of Reported UFO Sightings: ");
        scanf("%d", &sightings);
        invasionData[yearCount].sightings = sightings;

        invasionData[yearCount].probability = calculateProbability(sightings);
        yearCount++;

        printf("Do you want to enter another year? (y/n): ");
        scanf(" %c", &choice); // space before %c to skip any whitespace

    } while (choice == 'y' || choice == 'Y');

    printStatistics(invasionData, yearCount);

    double averageProbability = 0;

    for (int i = 0; i < yearCount; i++) {
        averageProbability += invasionData[i].probability;
    }

    if (yearCount > 0) {
        averageProbability /= yearCount;
        printf("\nAverage Probability of Alien Invasion: %.2f%%\n", averageProbability);
    }

    printf("Thank you for using the calculator! Stay safe!\n");

    return 0;
}