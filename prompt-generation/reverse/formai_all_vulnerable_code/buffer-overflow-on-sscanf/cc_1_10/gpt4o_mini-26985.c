//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Struct for a garden item
typedef struct {
    char name[30];
    char type[30];
} GardenItem;

// Function prototypes
void addItem(GardenItem garden[], int *itemCount, const char *name, const char *type);
void displayGarden(GardenItem garden[], int itemCount);
void parseInput(GardenItem garden[], int *itemCount, const char *input);
void deliciousPlant(GardenItem *item);

int main() {
    GardenItem garden[MAX_ITEMS];
    int itemCount = 0;
    
    printf("🌼 Welcome to the Magical Garden Parser! 🌼\n");
    printf("Here you can plant delicious items in your garden!\n");
    printf("Type 'plant <item-name>' to add a plant.\n");
    printf("Type 'show' to see what's growing in your garden.\n");
    printf("Type 'exit' to leave the garden.\n\n");

    char input[50];

    // Main loop to keep the garden alive
    while (1) {
        printf("🌱 What would you like to do? ");
        fgets(input, sizeof(input), stdin);
        // Remove newline character from the input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("🌻 Thank you for visiting the magical garden! Bye! 🌻\n");
            break;
        } else if (strcmp(input, "show") == 0) {
            displayGarden(garden, itemCount);
        } else {
            parseInput(garden, &itemCount, input);
        }
    }

    return 0;
}

void addItem(GardenItem garden[], int *itemCount, const char *name, const char *type) {
    if (*itemCount < MAX_ITEMS) {
        strncpy(garden[*itemCount].name, name, 30);
        strncpy(garden[*itemCount].type, type, 30);
        (*itemCount)++;
        printf("🌿 You've planted a %s called '%s'! 🌿\n", type, name);
    } else {
        printf("🚫 The garden is full! Can't plant more items! 🚫\n");
    }
}

void displayGarden(GardenItem garden[], int itemCount) {
    if (itemCount == 0) {
        printf("🌸 Your garden is empty! Let's plant something! 🌸\n");
        return;
    }
    
    printf("🌼 Here's what's blooming in your garden! 🌼\n");
    for (int i = 0; i < itemCount; i++) {
        printf("- %s (%s)\n", garden[i].name, garden[i].type);
    }
}

void parseInput(GardenItem garden[], int *itemCount, const char *input) {
    char command[10], itemName[30];

    // Simple parsing for "plant <item-name>"
    if (sscanf(input, "%s %s", command, itemName) == 2) {
        if (strcmp(command, "plant") == 0) {
            addItem(garden, itemCount, itemName, "Flower");
        } else {
            printf("🌱 Unknown command! Please use 'plant <item-name>'. 🌱\n");
        }
    } else {
        printf("💚 Oops! Didn't quite get that. Try 'plant <item-name>' or 'show'. 💚\n");
    }
}

// Bonus function: invoke magical plants with special actions
void deliciousPlant(GardenItem *item) {
    printf("🍰 [Magical Moment!] The %s called '%s' is blooming delightfully! 🍰\n", item->type, item->name);
}