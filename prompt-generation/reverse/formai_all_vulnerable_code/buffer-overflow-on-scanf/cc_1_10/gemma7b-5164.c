//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medical store items
typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

// Define a function to add an item to the store
void addItem(Item *items, int *numItems) {
    // Allocate memory for a new item
    items = (Item *)realloc(items, (*numItems + 1) * sizeof(Item));

    // Get the item name, quantity, and price
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[*numItems].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);

    // Increment the number of items
    *numItems++;
}

// Define a function to search for an item
void searchItem(Item *items, int numItems) {
    // Get the item name
    char name[50];
    printf("Enter item name: ");
    scanf("%s", name);

    // Search for the item
    int found = 0;
    for (int i = 0; i < numItems; i++) {
        if (strcmp(name, items[i].name) == 0) {
            // Print the item information
            printf("Item name: %s\n", items[i].name);
            printf("Item quantity: %d\n", items[i].quantity);
            printf("Item price: %.2f\n", items[i].price);
            found = 1;
        }
    }

    // If the item was not found, print an error message
    if (!found) {
        printf("Item not found.\n");
    }
}

// Define a function to update an item
void updateItem(Item *items, int numItems) {
    // Get the item name
    char name[50];
    printf("Enter item name: ");
    scanf("%s", name);

    // Search for the item
    int found = 0;
    for (int i = 0; i < numItems; i++) {
        if (strcmp(name, items[i].name) == 0) {
            // Get the item quantity and price
            printf("Enter item quantity: ");
            scanf("%d", &items[i].quantity);

            printf("Enter item price: ");
            scanf("%f", &items[i].price);

            // Update the item
            found = 1;
        }
    }

    // If the item was not found, print an error message
    if (!found) {
        printf("Item not found.\n");
    }
}

// Define a function to remove an item
void removeItem(Item *items, int *numItems) {
    // Get the item name
    char name[50];
    printf("Enter item name: ");
    scanf("%s", name);

    // Search for the item
    int found = 0;
    for (int i = 0; i < *numItems; i++) {
        if (strcmp(name, items[i].name) == 0) {
            // Remove the item
            items = (Item *)realloc(items, (*numItems - 1) * sizeof(Item));

            // Decrement the number of items
            *numItems--;

            found = 1;
        }
    }

    // If the item was not found, print an error message
    if (!found) {
        printf("Item not found.\n");
    }
}

int main() {
    // Create an array of items
    Item *items = NULL;
    int numItems = 0;

    // Main loop
    while (1) {
        // Display the menu options
        printf("1. Add Item\n");
        printf("2. Search Item\n");
        printf("3. Update Item\n");
        printf("4. Remove Item\n");
        printf("Enter your choice: ");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Switch statement to handle the user's choice
        switch (choice) {
            case 1:
                addItem(items, &numItems);
                break;
            case 2:
                searchItem(items, numItems);
                break;
            case 3:
                updateItem(items, numItems);
                break;
            case 4:
                removeItem(items, &numItems);
                break;
            default:
                printf("Invalid choice.\n");
        }

        // Check if the user wants to continue
        printf("Do you want to continue? (Y/N): ");
        char continueChoice;
        scanf("%c", &continueChoice);

        // If the user does not want to continue, break out of the loop
        if (continueChoice == 'N' || continueChoice == 'n') {
            break;
        }
    }

    // Free the memory allocated for the items
    free(items);

    return 0;
}