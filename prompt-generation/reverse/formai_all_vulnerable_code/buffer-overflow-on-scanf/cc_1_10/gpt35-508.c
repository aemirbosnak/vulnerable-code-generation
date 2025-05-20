//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_PRODUCT_QUANTITY 100
#define MAX_PLAYERS 10

// Define struct for product
struct Product {
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
};

// Define struct for player
struct Player {
    char name[MAX_PRODUCT_NAME_LENGTH];
    struct Product inventory[MAX_PRODUCT_QUANTITY];
    int inventorySize;
};

// Declare global variables
struct Player players[MAX_PLAYERS];
int numPlayers = 0;

// Function to add a player
void addPlayer() {
    // Make sure there is room for the player
    if(numPlayers == MAX_PLAYERS) {
        printf("Maximum number of players reached.\n");
        return;
    }

    // Get the player's name
    printf("Enter the name of the player: ");
    scanf("%s", players[numPlayers].name);
    numPlayers++;
}

// Function to add a product to a player's inventory
void addProduct() {
    // Make sure there is at least one player
    if(numPlayers == 0) {
        printf("There are no players.\n");
        return;
    }

    // Get the player's name
    char playerName[MAX_PRODUCT_NAME_LENGTH];
    printf("Enter the name of the player who will receive the product: ");
    scanf("%s", playerName);

    // Find the player with that name
    int playerIndex = -1;
    for(int i = 0; i < numPlayers; i++) {
        if(strcmp(players[i].name, playerName) == 0) {
            playerIndex = i;
            break;
        }
    }
    if(playerIndex == -1) {
        printf("Player not found.\n");
        return;
    }

    // Make sure the player has room for the new product
    if(players[playerIndex].inventorySize == MAX_PRODUCT_QUANTITY) {
        printf("%s's inventory is full.\n", players[playerIndex].name);
        return;
    }

    // Get the product name and quantity
    char productName[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
    printf("Enter the name of the product: ");
    scanf("%s", productName);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    // Add the product to the player's inventory
    strcpy(players[playerIndex].inventory[players[playerIndex].inventorySize].name, productName);
    players[playerIndex].inventory[players[playerIndex].inventorySize].quantity = quantity;
    players[playerIndex].inventorySize++;

    printf("%d %ss added to %s's inventory.\n", quantity, productName, players[playerIndex].name);
}

// Function to display a player's inventory
void displayInventory() {
    // Make sure there is at least one player
    if(numPlayers == 0) {
        printf("There are no players.\n");
        return;
    }

    // Get the player's name
    char playerName[MAX_PRODUCT_NAME_LENGTH];
    printf("Enter the name of the player whose inventory you want to see: ");
    scanf("%s", playerName);

    // Find the player with that name
    int playerIndex = -1;
    for(int i = 0; i < numPlayers; i++) {
        if(strcmp(players[i].name, playerName) == 0) {
            playerIndex = i;
            break;
        }
    }
    if(playerIndex == -1) {
        printf("Player not found.\n");
        return;
    }

    // Print the player's inventory
    printf("%s's inventory:\n", players[playerIndex].name);
    for(int i = 0; i < players[playerIndex].inventorySize; i++) {
        printf("%s: %d\n", players[playerIndex].inventory[i].name, players[playerIndex].inventory[i].quantity);
    }
}

// Main function
int main() {
    int choice;
    do {
        // Display menu
        printf("\nPLAYER INVENTORY SYSTEM\n");
        printf("1. Add player\n");
        printf("2. Add product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user's choice
        switch(choice) {
            case 1:
                addPlayer();
                break;
            case 2:
                addProduct();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}