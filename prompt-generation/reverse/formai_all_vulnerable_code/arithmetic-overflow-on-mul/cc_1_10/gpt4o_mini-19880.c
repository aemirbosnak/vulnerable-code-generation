//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HISTORY 5

typedef struct {
    int year;
    float probability;
} ProbHistory;

void calculateProbability(int population, int technologyLevel, int sightings, ProbHistory *history, int *historyCount);
float computeProbability(int population, int technologyLevel, int sightings);
void displayProbability(float probability);
void displayHistory(ProbHistory *history, int historyCount);
void clearBuffer();

int main() {
    int population, technologyLevel, sightings;
    ProbHistory history[MAX_HISTORY];
    int historyCount = 0;
    char choice;

    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("----------------------------------------------------------\n");

    do {
        printf("Enter the current world population (billions): ");
        scanf("%d", &population);

        printf("Enter the technology level (1-10): ");
        scanf("%d", &technologyLevel);

        printf("Enter the number of reported alien sightings this year: ");
        scanf("%d", &sightings);

        calculateProbability(population, technologyLevel, sightings, history, &historyCount);
        
        printf("Do you want to calculate again? (y/n): ");
        clearBuffer();
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Alien Invasion Probability Calculator!\n");

    return 0;
}

void calculateProbability(int population, int technologyLevel, int sightings, ProbHistory *history, int *historyCount) {
    float probability = computeProbability(population, technologyLevel, sightings);
    displayProbability(probability);

    if (*historyCount < MAX_HISTORY) {
        history[*historyCount].year = 2023 + *historyCount; // Simple increment for years
        history[*historyCount].probability = probability;
        (*historyCount)++;
    } else { // Shift history if it is full
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i-1] = history[i];
        }
        history[MAX_HISTORY - 1].year = 2023 + (MAX_HISTORY - 1); // Overwrite oldest entry
        history[MAX_HISTORY - 1].probability = probability;
    }

    displayHistory(history, *historyCount);
}

float computeProbability(int population, int technologyLevel, int sightings) {
    // A hypothetical formula to compute alien invasion probability
    if (population <= 0) return 0.0;
    return (float)(sightings * technologyLevel) / (population * 10.0);
}

void displayProbability(float probability) {
    printf("The calculated probability of an alien invasion is: %.2f%%\n", probability * 100);
}

void displayHistory(ProbHistory *history, int historyCount) {
    printf("History of Calculated Probabilities:\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < historyCount; i++) {
        printf("Year: %d, Probability: %.2f%%\n", history[i].year, history[i].probability * 100);
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}