//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 5
#define MAX_ENCOUNTERS 3

typedef struct {
    char *name;
    int hasItem;
} Item;

typedef struct {
    char *description;
    int encounterChance;
} Encounter;

void printWelcomeMessage();
void initializeItems(Item items[], int size);
void initializeEncounters(Encounter encounters[], int size);
void explore(Item items[], int itemCount, Encounter encounters[], int encounterCount);
void displayItems(Item items[], int itemCount);
void encounterChallenge(Encounter encounters[], int encounterCount);
int getRandomNumber(int max);

int main() {
    Item items[MAX_ITEMS];
    Encounter encounters[MAX_ENCOUNTERS];

    printWelcomeMessage();
    initializeItems(items, MAX_ITEMS);
    initializeEncounters(encounters, MAX_ENCOUNTERS);
    
    char input[20];
    while (1) {
        printf("\nChoose an action: (explore/items/quit) ");
        scanf("%s", input);

        if (strcmp(input, "explore") == 0) {
            explore(items, MAX_ITEMS, encounters, MAX_ENCOUNTERS);
        } else if (strcmp(input, "items") == 0) {
            displayItems(items, MAX_ITEMS);
        } else if (strcmp(input, "quit") == 0) {
            printf("Thank you for playing!\n");
            break;
        } else {
            printf("Invalid action! Try again.\n");
        }
    }

    return 0;
}

void printWelcomeMessage() {
    printf("Welcome to the Mystery Adventure Game!\n");
    printf("In this game, you will explore a mysterious forest,\n");
    printf("collect items, and face various challenges.\n");
    printf("Good luck!\n");
}

void initializeItems(Item items[], int size) {
    items[0].name = "Magic Stone";
    items[1].name = "Ancient Scroll";
    items[2].name = "Healing Potion";
    items[3].name = "Golden Key";
    items[4].name = "Mystic Amulet";
    
    for (int i = 0; i < size; i++) {
        items[i].hasItem = 0;
    }
}

void initializeEncounters(Encounter encounters[], int size) {
    encounters[0].description = "You encounter a wild beast!";
    encounters[0].encounterChance = 50; // 50% chance
    encounters[1].description = "You find a hidden treasure!";
    encounters[1].encounterChance = 30; // 30% chance
    encounters[2].description = "You meet a wise sage.";
    encounters[2].encounterChance = 20; // 20% chance
}

void explore(Item items[], int itemCount, Encounter encounters[], int encounterCount) {
    printf("You wander deeper into the forest...\n");
    
    int encounterRoll = getRandomNumber(100);
    for (int i = 0; i < encounterCount; i++) {
        if (encounterRoll < encounters[i].encounterChance) {
            encounterChallenge(encounters, encounterCount);
            return;
        }
    }

    printf("Nothing happens. It's eerily calm.\n");
}

void displayItems(Item items[], int itemCount) {
    printf("You have the following items:\n");
    for (int i = 0; i < itemCount; i++) {
        if (items[i].hasItem) {
            printf("- %s\n", items[i].name);
        }
    }
}

void encounterChallenge(Encounter encounters[], int encounterCount) {
    int chosenEncounter = getRandomNumber(encounterCount);
    printf("%s\n", encounters[chosenEncounter].description);

    if (chosenEncounter == 0) {
        printf("You bravely fight the beast!\n");
        printf("You found a healing potion!\n");
    } else if (chosenEncounter == 1) {
        printf("You discovered a hidden treasure chest!\n");
        printf("You obtained a magic stone!\n");
    } else if (chosenEncounter == 2) {
        printf("The wise sage grants you a gift!\n");
        printf("You received an ancient scroll!\n");
    }
}

int getRandomNumber(int max) {
    return rand() % max;
}