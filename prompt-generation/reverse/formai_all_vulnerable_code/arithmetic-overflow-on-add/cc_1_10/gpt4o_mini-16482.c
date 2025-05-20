//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_HISTORY 10

typedef struct {
    char date[11];
    float probability;
} ProbabilityRecord;

typedef struct {
    ProbabilityRecord records[MAX_HISTORY];
    int count;
} ProbabilityHistory;

void initializeHistory(ProbabilityHistory *history) {
    history->count = 0;
}

void recordProbability(ProbabilityHistory *history, float probability) {
    if (history->count < MAX_HISTORY) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(history->records[history->count].date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        history->records[history->count].probability = probability;
        history->count++;
    } else {
        printf("History is full! Cannot record more probabilities.\n");
    }
}

void displayHistory(const ProbabilityHistory *history) {
    printf("\nProbability History (Last %d Records):\n", MAX_HISTORY);
    for (int i = 0; i < history->count; i++) {
        printf("%s: %.2f%%\n", history->records[i].date, history->records[i].probability);
    }
}

float calculateAlienInvasionProbability(int encounters, int sightings) {
    if (encounters <= 0) {
        return 0.0; // Prevent division by zero.
    }
    return (float)sightings / encounters * 100.0; // Returns percentage.
}

int main() {
    int encounters, sightings;
    char choice;
    ProbabilityHistory history;

    initializeHistory(&history);
    srand(time(NULL)); // Seed the random number generator.

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    do {
        printf("\nEnter the number of alien encounters: ");
        scanf("%d", &encounters);
        printf("Enter the number of sightings: ");
        scanf("%d", &sightings);

        float probability = calculateAlienInvasionProbability(encounters, sightings);
        printf("Probability of alien invasion is: %.2f%%\n", probability);

        recordProbability(&history, probability);

        printf("Would you like to calculate another probability? (y/n): ");
        getchar(); // Consume newline character
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    displayHistory(&history);
    printf("Thank you for using the Alien Invasion Probability Calculator!\n");

    return 0;
}