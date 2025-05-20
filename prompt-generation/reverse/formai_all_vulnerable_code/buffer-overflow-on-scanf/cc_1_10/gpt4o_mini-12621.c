//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIGHTINGS 100
#define THRESHOLD 0.7

typedef struct {
    char location[50];
    float probability;
    int sightings;
} AlienSighting;

void displayIntro() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("The fate of humanity rests on our understanding of sightings.\n");
    printf("Let's calculate the probability of an alien invasion based on reported sightings.\n\n");
}

void collectSightings(AlienSighting *sightings, int *count) {
    printf("How many sighting reports do you want to enter (max %d)? ", MAX_SIGHTINGS);
    scanf("%d", count);
    
    if (*count > MAX_SIGHTINGS) {
        printf("You can only enter up to %d sightings. Limiting to %d.\n", MAX_SIGHTINGS, MAX_SIGHTINGS);
        *count = MAX_SIGHTINGS;
    }

    for (int i = 0; i < *count; i++) {
        printf("Enter the location for sighting %d: ", i + 1);
        scanf("%s", sightings[i].location);
        
        printf("Enter the probability (0.0 to 1.0) for %s: ", sightings[i].location);
        scanf("%f", &sightings[i].probability);
        
        // Simulating number of sightings for realism
        sightings[i].sightings = rand() % 20 + 1;  // Random sightings between 1 and 20
    }
}

void calculateInvasionProbability(AlienSighting *sightings, int count) {
    float totalProbability = 0;
    int totalSightings = 0;

    for (int i = 0; i < count; i++) {
        totalProbability += sightings[i].probability * sightings[i].sightings;
        totalSightings += sightings[i].sightings;
    }
    
    float invasionProbability = (totalSightings > 0) ? (totalProbability / totalSightings) : 0;
    
    printf("\n--- Invasion Probability Report ---\n");
    printf("Total Sightings: %d\n", totalSightings);
    printf("Calculated Probability of Alien Invasion: %.2f\n", invasionProbability);
    
    if (invasionProbability > THRESHOLD) {
        printf("Warning! The chance of an alien invasion is high! Prepare for possible contact!\n");
    } else {
        printf("The chance of an alien invasion is low. Continue your daily life.\n");
    }
}

void displaySightings(AlienSighting *sightings, int count) {
    printf("\n--- Recorded Alien Sightings ---\n");
    for (int i = 0; i < count; i++) {
        printf("Location: %s, Probability: %.2f, Sightings: %d\n", sightings[i].location, sightings[i].probability, sightings[i].sightings);
    }
}

int main() {
    srand(time(NULL));
    void displayIntro();
    void collectSightings();
    AlienSighting sightings[MAX_SIGHTINGS];
    
    int sightingCount = 0;
    
    displayIntro();
    collectSightings(sightings, &sightingCount);
    calculateInvasionProbability(sightings, sightingCount);
    displaySightings(sightings, sightingCount);
    
    return 0;
}