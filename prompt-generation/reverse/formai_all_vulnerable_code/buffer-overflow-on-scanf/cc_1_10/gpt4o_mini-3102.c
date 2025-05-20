//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CYBERPUNK_COLOR_GREEN "\x1b[32m"
#define CYBERPUNK_COLOR_RED "\x1b[31m"
#define CYBERPUNK_COLOR_RESET "\x1b[0m"
#define MAX_YEARS 100

typedef struct {
    char name[30];
    float estimatedInvasionChance; // In percentage
} AlienRace;

// Function Declarations
void initializeAlienRaces(AlienRace races[], int size);
void displayRaces(AlienRace races[], int size);
void calculateInvasionProbability(AlienRace races[], int size);
void displayProbability(AlienRace selectedRace);

int main() {
    srand(time(NULL)); // Seed the random number generator

    int numRaces = 5;
    AlienRace alienRaces[numRaces];

    initializeAlienRaces(alienRaces, numRaces);
    displayRaces(alienRaces, numRaces);
    
    char continueCalc;
    
    do {
        calculateInvasionProbability(alienRaces, numRaces);
        printf("Would you like to calculate again? (y/n): ");
        scanf(" %c", &continueCalc);
    } while (continueCalc == 'y' || continueCalc == 'Y');

    printf(CYBERPUNK_COLOR_GREEN "\nStay vigilant in this neon-lit dystopia!" CYBERPUNK_COLOR_RESET "\n");
    return 0;
}

void initializeAlienRaces(AlienRace races[], int size) {
    // Seed data for alien races and their estimated invasion chances
    char *names[] = {
        "Zyglora", "K'Varok", "Mythor", "Quarnation", "Jandir"
    };
    float invasionChances[] = {
        62.4, 47.8, 77.5, 55.1, 34.2
    };

    for (int i = 0; i < size; i++) {
        snprintf(races[i].name, sizeof(races[i].name), "%s", names[i]);
        races[i].estimatedInvasionChance = invasionChances[i];
    }
}

void displayRaces(AlienRace races[], int size) {
    printf(CYBERPUNK_COLOR_GREEN "\n--- Alien Races ---\n" CYBERPUNK_COLOR_RESET);
    for (int i = 0; i < size; i++) {
        printf("%d. %s (Invasion Probability: %.2f%%)\n", i + 1, races[i].name, races[i].estimatedInvasionChance);
    }
}

void calculateInvasionProbability(AlienRace races[], int size) {
    int selectedRaceIndex;
    printf(CYBERPUNK_COLOR_GREEN "\nSelect an alien race by number (1-%d): ", size);
    scanf("%d", &selectedRaceIndex);
    if (selectedRaceIndex < 1 || selectedRaceIndex > size) {
        printf(CYBERPUNK_COLOR_RED "Invalid selection. Please try again." CYBERPUNK_COLOR_RESET "\n");
        return;
    }
    
    AlienRace selectedRace = races[selectedRaceIndex - 1];
    int yearsUntilInvasion = rand() % MAX_YEARS + 1;
    
    printf(CYBERPUNK_COLOR_GREEN "\nCalculating invasion probability...\n" CYBERPUNK_COLOR_RESET);
    displayProbability(selectedRace);
    printf("Estimated years until invasion: %d years\n", yearsUntilInvasion);
}

void displayProbability(AlienRace selectedRace) {
    float randomFactor = ((float)rand() / RAND_MAX) * 100;
    float finalProbability = selectedRace.estimatedInvasionChance + randomFactor - 50; // Adjusting probability with noise
    
    if (finalProbability < 0) {
        finalProbability = 0;
    } else if (finalProbability > 100) {
        finalProbability = 100;
    }

    printf(CYBERPUNK_COLOR_GREEN "Danger Level: %.2f%%\n" CYBERPUNK_COLOR_RESET, finalProbability);
    
    if (finalProbability > 75) {
        printf(CYBERPUNK_COLOR_RED "Warning! High probability of invasion! Prepare your defense shields!\n" CYBERPUNK_COLOR_RESET);
    } else if (finalProbability > 50) {
        printf(CYBERPUNK_COLOR_RED "Moderate threat detected! Stay alert!\n" CYBERPUNK_COLOR_RESET);
    } else {
        printf(CYBERPUNK_COLOR_GREEN "Low probability. For now, enjoy the virtual nightlife!\n" CYBERPUNK_COLOR_RESET);
    }
}