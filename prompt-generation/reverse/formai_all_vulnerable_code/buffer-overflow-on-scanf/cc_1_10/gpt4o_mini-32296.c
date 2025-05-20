//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CREATURES 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    char type[NAME_LENGTH];
    int strength;
    int agility;
    int intelligence;
} Creature;

void generateRandomCreature(Creature *c) {
    const char *names[] = {"Fizzlewing", "Glimmerfang", "Thunderclaw", "Sparklebeak", "Shadowmist"};
    const char *types[] = {"Fairy", "Dragon", "Griffin", "Phoenix", "Unicorn"};
    
    strcpy(c->name, names[rand() % 5]);
    strcpy(c->type, types[rand() % 5]);
    c->strength = rand() % 100 + 1; // Strength between 1 and 100
    c->agility = rand() % 100 + 1;  // Agility between 1 and 100
    c->intelligence = rand() % 100 + 1; // Intelligence between 1 and 100
}

void displayCreature(const Creature *c) {
    printf("Name: %s | Type: %s | Strength: %d | Agility: %d | Intelligence: %d\n",
        c->name, c->type, c->strength, c->agility, c->intelligence);
}

void calculateAverageStats(Creature creatures[], int count) {
    int totalStrength = 0, totalAgility = 0, totalIntelligence = 0;

    for (int i = 0; i < count; i++) {
        totalStrength += creatures[i].strength;
        totalAgility += creatures[i].agility;
        totalIntelligence += creatures[i].intelligence;
    }

    printf("\nAverage Statistics:\n");
    printf("Average Strength: %.2f\n", (float)totalStrength / count);
    printf("Average Agility: %.2f\n", (float)totalAgility / count);
    printf("Average Intelligence: %.2f\n", (float)totalIntelligence / count);
}

void findStrongestCreature(Creature creatures[], int count) {
    int maxStrengthIdx = 0;
    for (int i = 1; i < count; i++) {
        if (creatures[i].strength > creatures[maxStrengthIdx].strength) {
            maxStrengthIdx = i;
        }
    }

    printf("\nStrongest Creature:\n");
    displayCreature(&creatures[maxStrengthIdx]);
}

void findMostAgileCreature(Creature creatures[], int count) {
    int maxAgilityIdx = 0;
    for (int i = 1; i < count; i++) {
        if (creatures[i].agility > creatures[maxAgilityIdx].agility) {
            maxAgilityIdx = i;
        }
    }

    printf("\nMost Agile Creature:\n");
    displayCreature(&creatures[maxAgilityIdx]);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Creature creatures[MAX_CREATURES];
    int numCreatures;

    // Input number of creatures
    printf("Enter the number of magical creatures to generate (max %d): ", MAX_CREATURES);
    scanf("%d", &numCreatures);
    
    if (numCreatures > MAX_CREATURES) {
        numCreatures = MAX_CREATURES;
        printf("Limiting to maximum allowed creatures: %d\n", MAX_CREATURES);
    }

    // Generate random creatures
    for (int i = 0; i < numCreatures; i++) {
        generateRandomCreature(&creatures[i]);
    }

    // Display creatures
    printf("\nGenerated Magical Creatures:\n");
    for (int i = 0; i < numCreatures; i++) {
        displayCreature(&creatures[i]);
    }

    // Calculate average stats
    calculateAverageStats(creatures, numCreatures);

    // Find strongest creature
    findStrongestCreature(creatures, numCreatures);

    // Find most agile creature
    findMostAgileCreature(creatures, numCreatures);

    return 0;
}