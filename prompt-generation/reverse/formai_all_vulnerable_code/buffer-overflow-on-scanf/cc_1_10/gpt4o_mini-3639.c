//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a mythical creature
typedef struct {
    char name[50];
    int age;
    float powerLevel;
} Creature;

// Function prototypes
void createCreature(Creature** creature);
void displayCreature(const Creature* creature);
void freeCreature(Creature* creature);

int main() {
    printf("Welcome to the Magical Creature Registry!\n");

    Creature* mythicalCreature = NULL;
    createCreature(&mythicalCreature);

    printf("\nCreating your mythical creature...\n");
    displayCreature(mythicalCreature);

    freeCreature(mythicalCreature);
    return 0;
}

void createCreature(Creature** creature) {
    // Allocate memory for the creature
    *creature = (Creature*)malloc(sizeof(Creature));
    if (*creature == NULL) {
        printf("Failed to allocate memory for the creature. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    // Fill in the creature's details
    printf("Enter the name of your creature: ");
    fgets((*creature)->name, sizeof((*creature)->name), stdin);
    strtok((*creature)->name, "\n"); // Remove newline character

    printf("Enter the age of your creature: ");
    scanf("%d", &(*creature)->age);

    printf("Enter the power level of your creature (0.0 - 100.0): ");
    scanf("%f", &(*creature)->powerLevel);

    // Validate power level
    while ((*creature)->powerLevel < 0.0 || (*creature)->powerLevel > 100.0) {
        printf("Power level must be between 0.0 and 100.0. Please try again: ");
        scanf("%f", &(*creature)->powerLevel);
    }

    printf("Your creature has been created!\n");
}

void displayCreature(const Creature* creature) {
    printf("\n=== Creature Details ===\n");
    printf("Name: %s\n", creature->name);
    printf("Age: %d\n", creature->age);
    printf("Power Level: %.2f\n", creature->powerLevel);
    printf("========================\n");
}

void freeCreature(Creature* creature) {
    if (creature != NULL) {
        free(creature);
        printf("The creature has been freed from the registry. 🧚✨\n");
    }
}