//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

// Item structure
typedef struct Item {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Item;

// Function declarations
void add_item(Item *items, int *num_items);
void remove_item(Item *items, int *num_items);
void print_items(Item *items, int num_items);
void search_item(Item *items, int num_items);

// Main function
int main() {
    // Declare and initialize variables
    Item items[MAX_ITEMS];
    int num_items = 0;

    // Main loop
    while (1) {
        // Print the menu
        printf("Welcome to the Medical Store Management System, Detective.\n");
        printf("What would you like to do?\n");
        printf("1. Add an item\n");
        printf("2. Remove an item\n");
        printf("3. Print all items\n");
        printf("4. Search for an item\n");
        printf("5. Quit\n");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                remove_item(items, &num_items);
                break;
            case 3:
                print_items(items, num_items);
                break;
            case 4:
                search_item(items, num_items);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add an item
void add_item(Item *items, int *num_items) {
    // Check if the maximum number of items has been reached
    if (*num_items == MAX_ITEMS) {
        printf("The maximum number of items has been reached. Cannot add any more items.\n");
        return;
    }

    // Get the item's details from the user
    printf("Enter the item's name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter the item's description: ");
    scanf("%s", items[*num_items].description);
    printf("Enter the item's quantity: ");
    scanf("%d", &items[*num_items].quantity);
    printf("Enter the item's price: ");
    scanf("%f", &items[*num_items].price);

    // Increment the number of items
    (*num_items)++;
}

// Function to remove an item
void remove_item(Item *items, int *num_items) {
    // Check if there are any items to remove
    if (*num_items == 0) {
        printf("There are no items to remove.\n");
        return;
    }

    // Get the name of the item to be removed from the user
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the item to be removed: ");
    scanf("%s", name);

    // Find the index of the item to be removed
    int index = -1;
    for (int i = 0; i < *num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the item was found
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    // Remove the item from the array
    for (int i = index; i < *num_items - 1; i++) {
        items[i] = items[i + 1];
    }

    // Decrement the number of items
    (*num_items)--;
}

// Function to print all items
void print_items(Item *items, int num_items) {
    // Check if there are any items to print
    if (num_items == 0) {
        printf("There are no items to print.\n");
        return;
    }

    // Print the items
    for (int i = 0; i < num_items; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", items[i].name);
        printf("Description: %s\n", items[i].description);
        printf("Quantity: %d\n", items[i].quantity);
        printf("Price: %f\n", items[i].price);
        printf("\n");
    }
}

// Function to search for an item
void search_item(Item *items, int num_items) {
    // Check if there are any items to search
    if (num_items == 0) {
        printf("There are no items to search.\n");
        return;
    }

    // Get the name of the item to be searched from the user
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the item to be searched: ");
    scanf("%s", name);

    // Find the index of the item to be searched
    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the item was found
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    // Print the item's details
    printf("Item found:\n");
    printf("Name: %s\n", items[index].name);
    printf("Description: %s\n", items[index].description);
    printf("Quantity: %d\n", items[index].quantity);
    printf("Price: %f\n", items[index].price);
}