//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LIFEFORMS 100
#define BASE_PROBABILITY 0.25
#define AI_ADJUSTMENT 0.1
#define ENHANCED_TECH_COEF 0.2
#define TIME_OF_DAY_COEF 0.05

typedef struct {
    char name[30];
    int techLevel;
    int timeOfDay; // 0: Day, 1: Night
    char cyberDeck[30];
} lifeForm;

void initializeLifeForms(lifeForm* beings, int count) {
    const char* names[MAX_LIFEFORMS] = {
        "Xander", "Blade", "Neo", "Morpheus", "Trinity", 
        "Ghost", "Phantom", "Raven", "Nox", "Cipher", 
        "Zenith", "Matrix", "Cypher", "Electra", "Vortex"
    };
    
    for (int i = 0; i < count; i++) {
        snprintf(beings[i].name, sizeof(beings[i].name), "%s", names[rand() % 15]);
        beings[i].techLevel = rand() % 10 + 1; // Tech level from 1 to 10
        beings[i].timeOfDay = rand() % 2; // 0 or 1
        snprintf(beings[i].cyberDeck, sizeof(beings[i].cyberDeck), "Deck_%d", rand() % 100);
    }
}

double calculateInvasionProbability(lifeForm being) {
    double probability = BASE_PROBABILITY;

    // Adjust for Tech Level
    probability += being.techLevel * ENHANCED_TECH_COEF;

    // Adjust for Time of Day
    if (being.timeOfDay == 1) { // Night
        probability += TIME_OF_DAY_COEF;
    } else { // Day
        probability -= TIME_OF_DAY_COEF;
    }

    // AI Adjustment based on cyberdeck complexity
    if (rand() % 2 == 0) { // AI influence
        probability += AI_ADJUSTMENT;
    }

    // Ensure the probability is capped between 0 and 1
    if (probability > 1.0) probability = 1.0;
    if (probability < 0.0) probability = 0.0;

    return probability;
}

void printInvasionProbabilities(lifeForm* beings, int count) {
    printf("\n=== Alien Invasion Probability Report ===\n");
    printf("%-20s %-10s %-15s %-10s\n", "Life Form", "Tech Level", "CyberDeck", "Probability");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        double probability = calculateInvasionProbability(beings[i]);
        printf("%-20s %-10d %-15s %.2f\n", beings[i].name, beings[i].techLevel, beings[i].cyberDeck, probability);
    }
    printf("----------------------------------------------------\n");
}

int main() {
    srand(time(NULL));
    
    lifeForm beings[MAX_LIFEFORMS];
    int numberOfBeings;

    printf("Welcome to the Cyberpunk Alien Invasion Probability Calculator!\n");
    printf("Enter the number of life forms to simulate (1-%d): ", MAX_LIFEFORMS);
    scanf("%d", &numberOfBeings);

    if (numberOfBeings < 1 || numberOfBeings > MAX_LIFEFORMS) {
        printf("Invalid number of life forms. Defaulting to %d.\n", MAX_LIFEFORMS);
        numberOfBeings = MAX_LIFEFORMS;
    }

    initializeLifeForms(beings, numberOfBeings);
    printInvasionProbabilities(beings, numberOfBeings);

    return 0;
}