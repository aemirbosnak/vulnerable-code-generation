//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CREATURES 5
#define NAME_LENGTH 30

// Structure to hold creature information
typedef struct {
    char name[NAME_LENGTH];
    int health;
    int strength;
} Creature;

// Function prototypes
void createCreature(Creature *creature);
void displayCreatures(Creature **creatures, int count);
void freeCreatures(Creature **creatures, int count);

int main() {
    int creatureCount = 0;
    Creature **creatures = malloc(MAX_CREATURES * sizeof(Creature *));
    
    if (creatures == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    
    printf("Welcome to the Mysterious Forest Adventure!\n");
    
    while (creatureCount < MAX_CREATURES) {
        creatures[creatureCount] = malloc(sizeof(Creature));
        if (creatures[creatureCount] == NULL) {
            fprintf(stderr, "Memory allocation failed for creature %d!\n", creatureCount);
            freeCreatures(creatures, creatureCount);
            return 1;
        }
        
        createCreature(creatures[creatureCount]);
        creatureCount++;

        char choice;
        printf("Would you like to create another creature? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y') {
            break;
        }
    }
    
    printf("\nHere are the creatures you have encountered:\n");
    displayCreatures(creatures, creatureCount);
    
    // Clean up allocated memory
    freeCreatures(creatures, creatureCount);
    free(creatures);
    
    printf("Thank you for playing! The creatures have returned to the forest!\n");
    return 0;
}

void createCreature(Creature *creature) {
    printf("Enter the name of the creature: ");
    scanf("%s", creature->name);
    creature->health = rand() % 100 + 1; // Random health between 1 and 100
    creature->strength = rand() % 50 + 1; // Random strength between 1 and 50
}

void displayCreatures(Creature **creatures, int count) {
    for (int i = 0; i < count; i++) {
        printf("Creature %d: Name: %s, Health: %d, Strength: %d\n",
               i + 1, creatures[i]->name, creatures[i]->health, creatures[i]->strength);
    }
}

void freeCreatures(Creature **creatures, int count) {
    for (int i = 0; i < count; i++) {
        free(creatures[i]);
    }
}