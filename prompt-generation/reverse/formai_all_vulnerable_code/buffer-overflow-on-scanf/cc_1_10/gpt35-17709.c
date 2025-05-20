//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 // Maximum number of items in warehouse
#define MAX_NAME_LENGTH 50 // Maximum length of item name
#define MAX_LOCATION_LENGTH 10 // Maximum length of location name

// Structure to hold item information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    char location[MAX_LOCATION_LENGTH];
} Item;

Item items[MAX_ITEMS]; // Array of items in the warehouse
int num_items = 0; // Number of items currently in the warehouse

// Function to add an item to the warehouse
void add_item(char *name, int quantity, char *location) {
    // Make sure there is room for the item
    if (num_items >= MAX_ITEMS) {
        printf("Sorry, there is no room for additional items in the warehouse.\n");
        return;
    }
    // Add the item to the array
    Item item;
    strncpy(item.name, name, MAX_NAME_LENGTH - 1);
    item.quantity = quantity;
    strncpy(item.location, location, MAX_LOCATION_LENGTH - 1);
    items[num_items] = item;
    num_items++;
    printf("%d %s(s) added to location %s.\n", quantity, name, location);
}

// Function to remove an item from the warehouse
void remove_item(char *name, int quantity) {
    // Find the item in the array
    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    // If the item was not found, print an error message and return
    if (index == -1) {
        printf("Sorry, there are no %s(s) currently in the warehouse.\n", name);
        return;
    }
    // If the item was found but there are not enough, print an error message and return
    if (items[index].quantity < quantity) {
        printf("Sorry, there are only %d %s(s) in the warehouse.\n", items[index].quantity, name);
        return;
    }
    // Otherwise, remove the item(s)
    items[index].quantity -= quantity;
    printf("%d %s(s) removed from the warehouse.\n", quantity, name);
    // If there are no more items of this type, remove the item from the array
    if (items[index].quantity == 0) {
        for (int i = index + 1; i < num_items; i++) {
            items[i - 1] = items[i];
        }
        num_items--;
    }
}

int main() {
    // Welcome message
    printf("Welcome to Happy Warehouse Management System!\n");
    // Main loop
    while (1) {
        // Print menu
        printf("\nWhat would you like to do?\n");
        printf("1. Add an item to the warehouse\n");
        printf("2. Remove an item from the warehouse\n");
        printf("3. List all items in the warehouse\n");
        printf("4. Exit\n");
        // Get user's choice
        int choice;
        scanf("%d", &choice);
        // Process user's choice
        switch (choice) {
            case 1: // Add an item
                printf("\nEnter the name of the item: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                printf("Enter the quantity of %s: ", name);
                int quantity;
                scanf("%d", &quantity);
                printf("Enter the location of %s (max %d characters): ", name, MAX_LOCATION_LENGTH - 1);
                char location[MAX_LOCATION_LENGTH];
                scanf("%s", location);
                add_item(name, quantity, location);
                break;
            case 2: // Remove an item
                printf("\nEnter the name of the item to be removed: ");
                char remove_name[MAX_NAME_LENGTH];
                scanf("%s", remove_name);
                printf("Enter the quantity of %s to be removed: ", remove_name);
                int remove_quantity;
                scanf("%d", &remove_quantity);
                remove_item(remove_name, remove_quantity);
                break;
            case 3: // List all items
                printf("\nCurrent items in the warehouse:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("Name: %s | Quantity: %d | Location: %s\n", items[i].name, items[i].quantity, items[i].location);
                }
                break;
            case 4: // Exit
                printf("\nThank you for using Happy Warehouse Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please choose again.\n");
        }
    }
}