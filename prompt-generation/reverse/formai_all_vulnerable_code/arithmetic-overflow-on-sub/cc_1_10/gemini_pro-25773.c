//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: creative
// Welcome to the Enchanted Forest of Greedy Choices!

#include <stdio.h>
#include <stdlib.h>

// Define our adventurers and treasures
typedef struct {
    char *name;
    int strength;
} Adventurer;

typedef struct {
    char *name;
    int value;
    int weight;
} Treasure;

// Initialize our adventurers and treasures
Adventurer adventurers[] = {
    {"Bard", 5},
    {"Ranger", 7},
    {"Warrior", 10},
    {"Mage", 3}
};

Treasure treasures[] = {
    {"Sword of Truth", 100, 5},
    {"Armor of Courage", 50, 10},
    {"Ring of Wisdom", 20, 1},
    {"Amulet of Glamour", 15, 2},
    {"Healing Potion", 10, 1}
};

// Utility function to compare treasures based on their value-to-weight ratio
int compareTreasures(const void *a, const void *b) {
    Treasure *treasureA = (Treasure *)a;
    Treasure *treasureB = (Treasure *)b;
    float ratioA = (float)treasureA->value / treasureA->weight;
    float ratioB = (float)treasureB->value / treasureB->weight;
    return ratioB - ratioA;
}

// Function for the greedy adventurer to select the best treasures
Treasure *selectTreasures(Adventurer *adventurer, int numTreasures) {
    // Sort the treasures in decreasing order of value-to-weight ratio
    qsort(treasures, numTreasures, sizeof(Treasure), compareTreasures);

    // Initialize the adventurer's backpack with an empty array
    Treasure *backpack = malloc(0);
    int backpackSize = 0;

    // Loop through the sorted treasures
    for (int i = 0; i < numTreasures; i++) {
        Treasure *treasure = &treasures[i];

        // Check if the adventurer can carry the treasure
        if (adventurer->strength >= treasure->weight) {
            // Add the treasure to the backpack
            backpack = realloc(backpack, ++backpackSize * sizeof(Treasure));
            backpack[backpackSize - 1] = *treasure;

            // Update the adventurer's strength
            adventurer->strength -= treasure->weight;
        }
    }

    return backpack;
}

// Function to calculate the total value of the treasures in the backpack
int calculateTotalValue(Treasure *backpack, int backpackSize) {
    int totalValue = 0;
    for (int i = 0; i < backpackSize; i++) {
        totalValue += backpack[i].value;
    }
    return totalValue;
}

int main() {
    // Print a welcome message to our adventurers
    printf("Welcome to the Enchanted Forest, brave adventurers!\n");

    // Ask the user to select an adventurer
    printf("Please choose your adventurer:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, adventurers[i].name);
    }
    int adventurerChoice;
    scanf("%d", &adventurerChoice);

    // Get the selected adventurer
    Adventurer *adventurer = &adventurers[adventurerChoice - 1];

    // Ask the user to select the number of treasures to find
    printf("\nHow many treasures are hiding in the forest today?\n");
    int numTreasures;
    scanf("%d", &numTreasures);

    // Call the greedy function to select the best treasures for the adventurer
    Treasure *backpack = selectTreasures(adventurer, numTreasures);

    // Calculate the total value of the treasures in the backpack
    int totalValue = calculateTotalValue(backpack, numTreasures);

    // Print the adventurer's rewards
    printf("\nCongratulations, %s!\n", adventurer->name);
    printf("You have found %d treasures with a total value of %d gold!\n", numTreasures, totalValue);

    // Print the contents of the backpack
    printf("Your backpack contains:\n");
    for (int i = 0; i < numTreasures; i++) {
        printf("%s (value: %d, weight: %d)\n", backpack[i].name, backpack[i].value, backpack[i].weight);
    }

    return 0;
}