//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100 // Maximum number of items
#define MAX_NAME_LENGTH 50 // Maximum length of item name
#define MAX_LOT_NUMBER 9999 // Maximum lot number
#define MIN_LOT_NUMBER 1000 // Minimum lot number

// Struct for each item
typedef struct {
    char name[MAX_NAME_LENGTH];
    int lotNumber;
    int quantity;
} Item;

// Function to generate a random lot number
int generateLotNumber() {
    return (rand() % (MAX_LOT_NUMBER - MIN_LOT_NUMBER + 1)) + MIN_LOT_NUMBER;
}

int main() {
    Item warehouse[MAX_ITEMS];
    int itemCount = 0;

    // Set up multiplayer mode
    bool multiplayer = false;
    bool player1Turn = true;
    printf("Would you like to play in multiplayer mode? (y/n)\n");
    char input[2];
    scanf("%s", input);
    if (input[0] == 'y') {
        multiplayer = true;
    } else if (input[0] != 'n') {
        printf("Invalid input. Defaulting to single player mode.\n");
    }

    // Loop to add items to the warehouse
    while (true) {
        // Print current player's turn if in multiplayer mode
        if (multiplayer) {
            if (player1Turn) {
                printf("\nPlayer 1's turn:\n");
            } else {
                printf("\nPlayer 2's turn:\n");
            }
        }

        // Get input for new item
        Item newItem;
        printf("Add a new item (name, quantity):\n");
        scanf("%s %d", newItem.name, &newItem.quantity);
        newItem.lotNumber = generateLotNumber();

        // Check if the item already exists and update quantity if it does
        bool itemExists = false;
        for (int i = 0; i < itemCount; i++) {
            if (strcmp(newItem.name, warehouse[i].name) == 0 && newItem.lotNumber == warehouse[i].lotNumber) {
                warehouse[i].quantity += newItem.quantity;
                printf("%d more %s added to lot #%d.\n", newItem.quantity, newItem.name, newItem.lotNumber);
                itemExists = true;
                break;
            }
        }

        // Add new item if it doesn't already exist
        if (!itemExists) {
            if (itemCount == MAX_ITEMS) {
                printf("Warehouse capacity reached. %s not added.\n", newItem.name);
            } else {
                warehouse[itemCount] = newItem;
                itemCount++;
                printf("%d %s added to lot #%d.\n", newItem.quantity, newItem.name, newItem.lotNumber);                
            }
        }

        // Switch player turns if in multiplayer mode
        if (multiplayer) {
            player1Turn = !player1Turn;
        }

        // Check if user wants to add more items
        printf("Add another item? (y/n)\n");
        scanf("%s", input);
        if (input[0] == 'n') {
            break;
        }
    }

    // Print out warehouse contents
    printf("\nWarehouse Contents:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%s lot #%d: %d\n", warehouse[i].name, warehouse[i].lotNumber, warehouse[i].quantity);
    }

    return 0;
}