//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the game's state
#define MAX_ITEMS 5
#define MAX_STRING_LENGTH 100

// Structure to hold the player's inventory
typedef struct {
    char items[MAX_ITEMS][MAX_STRING_LENGTH];
    int itemCount;
} Inventory;

// Function declarations
void exploreShip();
void findClue(Inventory *inv);
void showInventory(const Inventory *inv);
void displayIntroduction();
void investigateCrimeScene(Inventory *inv);

int main() {
    Inventory playerInventory = { .itemCount = 0 };
    displayIntroduction();
    exploreShip(&playerInventory);
    return 0;
}

void displayIntroduction() {
    printf("Welcome to the Space Mystery!\n");
    printf("You are Sherlock Holmes aboard the Spaceship Arcadia.\n");
    printf("Your mission is to investigate a crime that has occurred on the ship.\n");
    printf("Gather clues and solve the mystery. Good luck!\n\n");
}

void exploreShip(Inventory *inv) {
    int choice;
    printf("You are in the main deck of the Spaceship Arcadia.\n");
    printf("What would you like to do?\n");
    printf("1. Investigate the crime scene\n");
    printf("2. Search for clues in the library\n");
    printf("3. Check your inventory\n");
    printf("4. Leave the ship\n");
    
    while (1) {
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                investigateCrimeScene(inv);
                break;
            case 2:
                findClue(inv);
                break;
            case 3:
                showInventory(inv);
                break;
            case 4:
                printf("Goodbye, Sherlock! The case will remain unsolved...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void findClue(Inventory *inv) {
    if (inv->itemCount >= MAX_ITEMS) {
        printf("Your inventory is full. You cannot collect more items.\n");
        return;
    }

    char *clues[] = {
        "Suspicious Footprint",
        "Photograph of the Victim",
        "Strange Substance",
        "Encrypted Message",
        "Mysterious Key"
    };
    
    int clueIndex = rand() % 5; // Randomly select a clue

    strcpy(inv->items[inv->itemCount], clues[clueIndex]);
    inv->itemCount++;
    printf("You found a clue: %s\n", clues[clueIndex]);
}

void showInventory(const Inventory *inv) {
    if (inv->itemCount == 0) {
        printf("Your inventory is empty.\n");
        return;
    }

    printf("Your inventory contains:\n");
    for (int i = 0; i < inv->itemCount; i++) {
        printf(" - %s\n", inv->items[i]);
    }
}

void investigateCrimeScene(Inventory *inv) {
    if (inv->itemCount == 0) {
        printf("You need to gather clues first!\n");
        return;
    }

    printf("You investigate the crime scene...\n");
    printf("You analyze the following items:\n");
    
    for (int i = 0; i < inv->itemCount; i++) {
        printf("Analyzing: %s\n", inv->items[i]);
        // Here you can add further analysis and logic to deduce the crime
    }

    printf("After thorough investigation, you have enough clues to solve the mystery!\n");
    printf("Congratulations! You have unraveled the case aboard the Spaceship Arcadia!\n");
}