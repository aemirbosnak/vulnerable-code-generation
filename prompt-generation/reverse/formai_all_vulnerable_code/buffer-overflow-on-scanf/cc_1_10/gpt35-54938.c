//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the probability of alien invasion given a set of factors
float calculateProbability(int technology, int resources, int defense) {
    float prob = 0.0;
    if (technology >= 75 && resources >= 50 && defense >= 25) {
        prob = ((float) (technology + resources + defense) / 300) * 100;
        printf("The probability of alien invasion is %.2f%%\n", prob);
    } else {
        printf("Insufficient data to calculate probability\n");
    }
    return prob;
}

int main() {
    int technology = 0;
    int resources = 0;
    int defense = 0;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the following data to calculate the probability of alien invasion:\n");

    // Get input for technology, resources, and defense
    printf("Technology level (out of 100): ");
    scanf("%d", &technology);
    printf("Resource availability (out of 100): ");
    scanf("%d", &resources);
    printf("Defensive capability (out of 100): ");
    scanf("%d", &defense);

    // Ensure values are within range of 0-100
    if (technology < 0 || technology > 100 || resources < 0 || resources > 100 || defense < 0 || defense > 100) {
        printf("ERROR: Invalid input values. All values must be between 0 and 100.\n");
        return 1;
    }

    // Calculate probability of alien invasion
    float probability = calculateProbability(technology, resources, defense);

    // Generate random events based on probability
    srand(time(NULL));
    int random = rand() % 101;
    bool alienAppears = false;

    if (random <= probability) {
        alienAppears = true;
    }

    if (alienAppears) {
        printf("ALERT: ALIEN INVASION DETECTED!\n");
    } else {
        printf("No signs of alien invasion detected at this time.\n");
    }

    return 0;
}