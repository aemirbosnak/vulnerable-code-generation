//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Romeo and Juliet
/* Romeo and Juliet's C Warehouse Management System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constant values
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20
#define MAX_LOCATION_LENGTH 10

// Define a struct for the warehouse item
struct item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    char location[MAX_LOCATION_LENGTH];
};

// Initialize the warehouse inventory with empty values
struct item inventory[MAX_ITEMS] = { {"", 0, ""} };

// Function to add a new item to the inventory
void add_item() {
    // Initialize variables for the new item
    char name[MAX_NAME_LENGTH];
    int quantity;
    char location[MAX_LOCATION_LENGTH];

    // Prompt the user for the new item details
    printf("What is the name of the item you would like to add?\n");
    scanf("%s", name);
    printf("How many %ss would you like to add?\n", name);
    scanf("%d", &quantity);
    printf("Where would you like to store the %ss?\n", name);
    scanf("%s", location);

    // Find the next empty spot in the inventory
    int index = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(inventory[i].name, "") == 0) {
            index = i;
            break;
        }
    }

    // Add the new item to the inventory
    strcpy(inventory[index].name, name);
    inventory[index].quantity = quantity;
    strcpy(inventory[index].location, location);

    // Let the user know the item has been added
    printf("%d %ss have been added and will be stored in %s.\n", quantity, name, location);
}

// Function to remove an item from the inventory
void remove_item() {
    // Prompt the user for the item name to be removed
    char name[MAX_NAME_LENGTH];
    printf("What is the name of the item you would like to remove?\n");
    scanf("%s", name);

    // Find the index of the item to be removed
    int index = -1;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the item was found, remove it and update the inventory
    if (index != -1) {
        printf("%d %ss have been removed from %s.\n", inventory[index].quantity, inventory[index].name, inventory[index].location);
        inventory[index].quantity = 0;
        strcpy(inventory[index].name, "");
        strcpy(inventory[index].location, "");
    }
    else {
        printf("Item not found.\n");
    }
}

// Function to display the current inventory
void display_inventory() {
    // Loop through all inventory items and print each one
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(inventory[i].name, "") != 0) {
            printf("%s: %d in %s\n", inventory[i].name, inventory[i].quantity, inventory[i].location);
        }
    }
}

int main() {
    // Initialize variables for the user's choice and game status
    int choice = 0;
    int running = 1;

    // Greet the user and explain the available options
    printf("Welcome to Romeo and Juliet's Warehouse Management System!\n");
    printf("What would you like to do?\n");
    printf("1. Add an item\n");
    printf("2. Remove an item\n");
    printf("3. Display inventory\n");
    printf("4. Exit\n");

    // Continue looping until the user chooses to exit
    while (running) {
        // Prompt the user for their choice and call the appropriate function
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                running = 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    // Say goodbye to the user
    printf("Farewell from Romeo and Juliet's Warehouse Management System!\n");

    return 0;
}