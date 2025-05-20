//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showInstructions() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You will navigate through a spooky house, make choices, and face random encounters.\n");
    printf("Type '1' to go left, '2' to go right, or '3' to check your inventory.\n");
    printf("Surviving the house depends on your choices... Good luck!\n");
}

void randomEncounter() {
    int encounter = rand() % 5;
    switch(encounter) {
        case 0:
            printf("You encounter a ghost! It wails loudly and disappears. Phew!\n");
            break;
        case 1:
            printf("A bat flies overhead and narrowly misses you! Be careful!\n");
            break;
        case 2:
            printf("You find a dusty old book. It's a cursed spellbook! Better not touch it.\n");
            break;
        case 3:
            printf("A door slams shut behind you! You feel a chill down your spine.\n");
            break;
        case 4:
            printf("You hear eerie laughter echoing in the hallway. Someone... or something is watching you!\n");
            break;
    }
}

void leftPath() {
    printf("You choose the left path. It's dark and creepy.\n");
    randomEncounter();
    printf("You see a flickering light at the end of the hallway.\n");
}

void rightPath() {
    printf("You choose the right path. It smells musty and is eerily quiet.\n");
    randomEncounter();
    printf("Something moves in the shadows... do you dare to investigate?\n");
}

void checkInventory(char* inventory, int* itemCount) {
    if (*itemCount == 0) {
        printf("Your inventory is empty. Better find something!\n");
    } else {
        printf("Your inventory contains:\n");
        for (int i = 0; i < *itemCount; i++) {
            printf("- %s\n", &inventory[i * 20]);  // Assuming max item name length is 20
        }
    }
}

void addItem(char* inventory, int* itemCount) {
    if (*itemCount < 5) {  // Max 5 items
        // Just randomly generate item names for simplicity
        snprintf(&inventory[*itemCount * 20], 20, "Item%d", *itemCount + 1);
        (*itemCount)++;
        printf("You found an item! Inventory now has %d item(s).\n", *itemCount);
    } else {
        printf("Your inventory is full! Can't carry more than 5 items.\n");
    }
}

int main() {
    srand(time(NULL));
    char inventory[100];  // 5 items, each max 20 chars
    int itemCount = 0;

    showInstructions();
    
    int choice = 0;
    while (1) {
        printf("\nWhat do you want to do? ");
        if (scanf("%d", &choice) != 1) break;  // Check for valid input

        switch (choice) {
            case 1:
                leftPath();
                addItem(inventory, &itemCount);
                break;
            case 2:
                rightPath();
                addItem(inventory, &itemCount);
                break;
            case 3:
                checkInventory(inventory, &itemCount);
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    }

    printf("Thank you for playing the Haunted House Simulator. Goodbye!\n");
    return 0;
}