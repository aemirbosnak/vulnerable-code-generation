//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
/**
 * C Medical Store Management System
 * Written in a Claude Shannon style 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items the store can hold
#define MAX_ITEMS 100

// Structure to hold information about an item
struct item {
    char name[50];
    int quantity;
    double price;
};

// Function prototypes
void add_item(struct item store[], int *num_items);
void remove_item(struct item store[], int *num_items);
void display_inventory(struct item store[], int num_items);
void calculate_total(struct item store[], int num_items);

int main() {
    // Variable to hold the number of items in the store
    int num_items = 0;

    // Array to hold the store's inventory
    struct item store[MAX_ITEMS];

    // Main menu loop
    int choice;
    do {
        printf("Please choose an option:\n");
        printf("1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. Display inventory\n");
        printf("4. Calculate total inventory value\n");
        printf("5. Quit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add item to inventory
                add_item(store, &num_items);
                break;
            case 2: // Remove item from inventory
                remove_item(store, &num_items);
                break;
            case 3: // Display inventory
                display_inventory(store, num_items);
                break;
            case 4: // Calculate total inventory value
                calculate_total(store, num_items);
                break;
            case 5: // Exit program
                printf("Goodbye!\n");
                break;
            default: // Invalid option
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

/**
 * Function to add an item to the inventory
 */
void add_item(struct item store[], int *num_items) {
    // Check if there is room in the store for another item
    if (*num_items >= MAX_ITEMS) {
        printf("Sorry, the store is full.\n");
        return;
    }

    // Get item information from user
    printf("Enter item name: ");
    scanf("%s", store[*num_items].name);
    printf("Enter item quantity: ");
    scanf("%d", &store[*num_items].quantity);
    printf("Enter item price: $");
    scanf("%lf", &store[*num_items].price);

    // Increment the number of items in the store
    (*num_items)++;
}

/**
 * Function to remove an item from the inventory
 */
void remove_item(struct item store[], int *num_items) {
    // Check if there are any items to remove
    if (*num_items == 0) {
        printf("Sorry, there are no items in the store.\n");
        return;
    }

    // Get item name from user
    char name[50];
    printf("Enter item name: ");
    scanf("%s", name);

    // Look for item in the store
    int index = -1;
    for (int i = 0; i < *num_items; i++) {
        if (strcmp(store[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Remove item from the store
    if (index != -1) {
        for (int i = index; i < *num_items - 1; i++) {
            store[i] = store[i + 1];
        }
        (*num_items)--;
        printf("Item removed from store.\n");
    } else {
        printf("Item not found in store.\n");
    }
}

/**
 * Function to display the store's inventory
 */
void display_inventory(struct item store[], int num_items) {
    // Check if there are any items to display
    if (num_items == 0) {
        printf("Sorry, there are no items in the store.\n");
        return;
    }

    // Display inventory header
    printf("%-20s%-10s%-10s\n", "Item Name", "Quantity", "Price");

    // Display inventory items
    for (int i = 0; i < num_items; i++) {
        printf("%-20s%-10d$%.2lf\n", store[i].name, store[i].quantity, store[i].price);
    }
}

/**
 * Function to calculate the total value of the store's inventory
 */
void calculate_total(struct item store[], int num_items) {
    // Check if there are any items to calculate
    if (num_items == 0) {
        printf("Sorry, there are no items in the store.\n");
        return;
    }

    // Calculate total value of inventory
    double total = 0.0;
    for (int i = 0; i < num_items; i++) {
        total += (store[i].quantity * store[i].price);
    }

    // Display total value of inventory
    printf("Total inventory value: $%.2lf\n", total);
}