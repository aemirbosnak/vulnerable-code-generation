//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 100
#define MAX_REPORTS 1000

typedef struct {
    int year;
    int sightings;
    int reports;
} AlienSighting;

void initializeSightingData(AlienSighting *data, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        data[i].year = 2021 + i;
        data[i].sightings = rand() % 100; // Random sightings between 0-99
        data[i].reports = rand() % 200; // Random reports between 0-199
    }
}

double calculateProbabilities(AlienSighting *data, int size) {
    int totalSightings = 0;
    int totalReports = 0;

    for (int i = 0; i < size; i++) {
        totalSightings += data[i].sightings;
        totalReports += data[i].reports;
    }

    if (totalReports == 0) return 0; // Avoid division by zero

    return (double)totalSightings / totalReports * 100; // Probability as a percentage
}

void displayData(AlienSighting *data, int size) {
    printf("Year\tSightings\tReports\n");
    printf("-----------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t\t%d\n", data[i].year, data[i].sightings, data[i].reports);
    }
}

void displayProbability(double probability) {
    printf("\n\nAlien Invasion Probability: %.2f%%\n", probability);
}

int main() {
    int size;
    AlienSighting sightings[MAX_YEARS];

    printf("Enter the number of years to analyze (up to %d): ", MAX_YEARS);
    scanf("%d", &size);
    
    if (size < 1 || size > MAX_YEARS) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_YEARS);
        return 1;
    }

    initializeSightingData(sightings, size);
    displayData(sightings, size);
    
    double probability = calculateProbabilities(sightings, size);
    displayProbability(probability);

    return 0;
}