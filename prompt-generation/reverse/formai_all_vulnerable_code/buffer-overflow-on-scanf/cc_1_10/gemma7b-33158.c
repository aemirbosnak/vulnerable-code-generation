//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store the player's inventory
typedef struct Inventory {
    char items[10];
    int numItems;
} Inventory;

// Define a function to display the player's inventory
void displayInventory(Inventory *inventory) {
    printf("Your inventory: ");
    for (int i = 0; i < inventory->numItems; i++) {
        printf("%s, ", inventory->items[i]);
    }
    printf("\n");
}

// Define a function to add an item to the player's inventory
void addToInventory(Inventory *inventory, char item) {
    inventory->items[inventory->numItems++] = item;
}

// Define a function to move an item from the player's inventory
void moveItem(Inventory *inventory, char item) {
    for (int i = 0; i < inventory->numItems; i++) {
        if (inventory->items[i] == item) {
            inventory->items[i] = '\0';
            inventory->numItems--;
            return;
        }
    }
    printf("Item not found.\n");
}

// Main game loop
int main() {
    // Create an inventory structure
    Inventory inventory;
    inventory.numItems = 0;

    // Initialize the inventory
    inventory.items[0] = '\0';

    // Start the game
    int choice;
    char item;

    // Display the initial inventory
    displayInventory(&inventory);

    // Loop until the player chooses to quit
    while (1) {
        // Get the player's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process the player's choice
        switch (choice) {
            case 1: // Add an item to the inventory
                printf("Enter the item you want to add: ");
                scanf("%s", &item);
                addToInventory(&inventory, item);
                break;
            case 2: // Move an item from the inventory
                printf("Enter the item you want to move: ");
                scanf("%s", &item);
                moveItem(&inventory, item);
                break;
            case 3: // Quit the game
                printf("Thank you for playing. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        // Display the updated inventory
        displayInventory(&inventory);
    }

    return 0;
}