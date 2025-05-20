//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void displayWelcomeMessage();
double calculateInvasionProbability(int ufoSightings, int population, int year);
void logData(int year, int ufoSightings, int population, double probability);
void displayStatistics();

#define MAX_LOG_ENTRIES 100
typedef struct {
    int year;
    int ufoSightings;
    int population;
    double invasionProbability;
} LogEntry;

LogEntry logs[MAX_LOG_ENTRIES];
int currentLogIndex = 0;

int main() {
    int year, ufoSightings, population;
    char choice;

    displayWelcomeMessage();

    do {
        printf("\nEnter the year of observation: ");
        scanf("%d", &year);
        
        printf("Enter the number of UFO sightings: ");
        scanf("%d", &ufoSightings);
        
        printf("Enter the total population of the area: ");
        scanf("%d", &population);

        double probability = calculateInvasionProbability(ufoSightings, population, year);
        printf("The calculated probability of an alien invasion for the year %d is: %.2f%%\n", year, probability * 100);

        logData(year, ufoSightings, population, probability);
        
        printf("Do you want to calculate another probability? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    displayStatistics();
    return 0;
}

void displayWelcomeMessage() {
    printf("====================================\n");
    printf("     Alien Invasion Probability\n");
    printf("       Calculator Program\n");
    printf("====================================\n");
}

double calculateInvasionProbability(int ufoSightings, int population, int year) {
    if (population <= 0) {
        return 0.0; // Prevent division by zero
    }
    
    // Using a simple formula based on sightings and population
    double probability = ((double)ufoSightings / population) * 0.05; // Arbitrary constant to scale
    if (probability > 1.0) {
        probability = 1.0; // Maximum probability capped at 100%
    }
    
    // Adjust probability based on a fictional time trend
    int currentYear = 2023;
    if (year > currentYear) {
        probability *= 0.95; // Decrease probability for the future
    } else if (year < currentYear) {
        probability *= 1.1; // Increase probability for the past
    }

    return probability;
}

void logData(int year, int ufoSightings, int population, double probability) {
    if (currentLogIndex < MAX_LOG_ENTRIES) {
        logs[currentLogIndex].year = year;
        logs[currentLogIndex].ufoSightings = ufoSightings;
        logs[currentLogIndex].population = population;
        logs[currentLogIndex].invasionProbability = probability;
        currentLogIndex++;
    } else {
        printf("Log capacity reached! Cannot record more data.\n");
    }
}

void displayStatistics() {
    printf("\n==========================\n");
    printf("       Log Statistics\n");
    printf("==========================\n");
    
    for (int i = 0; i < currentLogIndex; i++) {
        printf("Year: %d, Sightings: %d, Population: %d, Probability: %.2f%%\n",
               logs[i].year, logs[i].ufoSightings, logs[i].population, logs[i].invasionProbability * 100);
    }
    
    printf("==========================\n");
}