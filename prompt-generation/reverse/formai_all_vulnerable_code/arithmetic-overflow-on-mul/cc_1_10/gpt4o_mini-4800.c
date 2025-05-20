//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIGHTINGS 1005

typedef struct {
    int year;
    int sightings;
} YearlyData;

YearlyData alienData[MAX_SIGHTINGS];
int count = 0;

void inputAlienData() {
    printf("Enter the number of years of data you want to input (maximum %d): ", MAX_SIGHTINGS);
    scanf("%d", &count);
    
    if (count > MAX_SIGHTINGS) {
        printf("Maximum data limit exceeded.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        printf("Enter year and number of sightings (separated by space): ");
        scanf("%d %d", &alienData[i].year, &alienData[i].sightings);
    }
}

double calculateProbability() {
    int totalSightings = 0;
    for (int i = 0; i < count; i++) {
        totalSightings += alienData[i].sightings;
    }
    return (double) totalSightings / (count * 1000); // Simplified model for probability
}

void displayResults(double probability) {
    printf("Based on your data, the calculated probability of an alien invasion is:\n");
    printf("Probability: %.2f%%\n", probability * 100);
    if (probability > 0.5) {
        printf("Warning: The probability is quite high! Be prepared!\n");
    } else {
        printf("The probability appears low, no immediate threat detected.\n");
    }
}

void displayHistoricalTrends() {
    printf("\n--- Historical Alien Sightings Trends ---\n");
    for (int i = 0; i < count; i++) {
        printf("Year: %d, Sightings: %d\n", alienData[i].year, alienData[i].sightings);
    }
}

void analyzeData() {
    double prob = calculateProbability();
    displayHistoricalTrends();
    displayResults(prob);
}

int main() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    inputAlienData();
    analyzeData();

    return 0;
}