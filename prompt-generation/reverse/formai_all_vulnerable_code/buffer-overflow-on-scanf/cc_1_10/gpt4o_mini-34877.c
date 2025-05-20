//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    char name[30];
    int collected;
} Item;

typedef struct {
    char name[30];
    char description[100];
} Location;

void displayIntro();
void displayMenu();
void chooseAction(Item items[], int *itemCount);
void gatherItem(Item items[], int *itemCount);
void explore(Location locations[], int locationCount);
void displayInventory(Item items[], int itemCount);

int main() {
    Item items[MAX_ITEMS] = { {"Flower", 0}, {"Mushroom", 0}, {"Berry", 0}, {"Feather", 0}, {"Stone", 0} };
    int itemCount = 0;

    Location locations[] = {
        {"Sunny Meadow", "A vibrant meadow filled with blooming flowers."},
        {"Whispering Woods", "A tranquil forest where trees gently sway."},
        {"Crystal Lake", "A serene lake with sparkling clear water."},
        {"Gentle Hill", "A soft grassy hill perfect for sitting and relaxing."}
    };
    int locationCount = sizeof(locations) / sizeof(locations[0]);

    displayIntro();
    while (1) {
        displayMenu();
        chooseAction(items, &itemCount);
    }

    return 0;
}

void displayIntro() {
    printf("Welcome to the Peaceful Adventure Game!\n");
    printf("Explore the beautiful surroundings of nature, gather items, and enjoy tranquility.\n\n");
}

void displayMenu() {
    printf("What would you like to do?\n");
    printf("1. Explore the forest\n");
    printf("2. Gather an item\n");
    printf("3. View inventory\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void chooseAction(Item items[], int *itemCount) {
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            explore((Location[]){
                {"Sunny Meadow", "A vibrant meadow filled with blooming flowers."},
                {"Whispering Woods", "A tranquil forest where trees gently sway."},
                {"Crystal Lake", "A serene lake with sparkling clear water."},
                {"Gentle Hill", "A soft grassy hill perfect for sitting and relaxing."}
            }, 4);
            break;
        case 2:
            gatherItem(items, itemCount);
            break;
        case 3:
            displayInventory(items, *itemCount);
            break;
        case 4:
            printf("Thanks for playing! Enjoy your peaceful day!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void gatherItem(Item items[], int *itemCount) {
    if (*itemCount >= MAX_ITEMS) {
        printf("Your inventory is full! Can't gather more items.\n");
        return;
    }
    
    char itemNames[5][30] = { "Flower", "Mushroom", "Berry", "Feather", "Stone" };

    printf("You find a %s. Do you want to collect it? (y/n): ", itemNames[*itemCount]);
    char response;
    scanf(" %c", &response);

    if (response == 'y') {
        strcpy(items[*itemCount].name, itemNames[*itemCount]);
        items[*itemCount].collected = 1;
        (*itemCount)++;
        printf("You have collected a %s!\n", itemNames[*itemCount - 1]);
    } else {
        printf("You leave the %s where it is.\n", itemNames[*itemCount]);
    }
}

void explore(Location locations[], int locationCount) {
    int locIndex = rand() % locationCount;  // random location exploration
    printf("You wander into the %s.\n", locations[locIndex].name);
    printf("%s\n\n", locations[locIndex].description);
}

void displayInventory(Item items[], int itemCount) {
    if (itemCount == 0) {
        printf("Your inventory is empty.\n");
    } else {
        printf("Your collected items:\n");
        for (int i = 0; i < itemCount; i++) {
            printf("- %s\n", items[i].name);
        }
    }
    printf("\n");
}