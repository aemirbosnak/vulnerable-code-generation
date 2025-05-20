//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5

// Function to display the menu of options
void displayMenu() {
    printf("You can: \n");
    printf("1. Explore Room\n");
    printf("2. Check Inventory\n");
    printf("3. Quit Game\n");
}

// Function to explore rooms
void exploreRoom(char *inventory[], int *inventoryCount) {
    int choice;
    printf("You enter a dark room. You see two doors: one to the left and one to the right.\n");
    printf("Which door do you choose? (1 for left, 2 for right): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You find a mysterious key!\n");
        if (*inventoryCount < MAX_ITEMS) {
            inventory[*inventoryCount] = "Mysterious Key";
            (*inventoryCount)++;
            printf("Key added to your inventory.\n");
        } else {
            printf("Your inventory is full!\n");
        }
    } else if (choice == 2) {
        printf("You encounter a ghost! It scares you away!\n");
    } else {
        printf("Invalid choice! You lost your turn.\n");
    }
}

// Function to check inventory
void checkInventory(char *inventory[], int inventoryCount) {
    if (inventoryCount == 0) {
        printf("Your inventory is empty.\n");
    } else {
        printf("Your inventory contains:\n");
        for (int i = 0; i < inventoryCount; i++) {
            printf("- %s\n", inventory[i]);
        }
    }
}

int main() {
    int choice;
    char *inventory[MAX_ITEMS];
    int inventoryCount = 0;
    
    printf("Welcome to the Haunted Mansion Adventure!\n");
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                exploreRoom(inventory, &inventoryCount);
                break;
            case 2:
                checkInventory(inventory, inventoryCount);
                break;
            case 3:
                printf("Thank you for playing! Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    return 0;
}