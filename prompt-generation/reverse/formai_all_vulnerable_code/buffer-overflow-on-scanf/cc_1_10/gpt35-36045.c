//FormAI DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 // Maximum number of items in inventory
#define MAX_NAME_LENGTH 50 // Maximum length of product name

// Structure to represent an item in inventory
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

// Global variables
Item inventory[MAX_ITEMS]; // Array to store inventory items
int itemCount = 0; // Number of items currently in inventory

// Function to add an item to inventory
void addItem(char name[], int quantity, float price) {
    if (itemCount < MAX_ITEMS) { // Check if there is space in inventory
        strcpy(inventory[itemCount].name, name); // Copy item name to inventory
        inventory[itemCount].quantity = quantity; // Set item quantity in inventory
        inventory[itemCount].price = price; // Set item price in inventory
        itemCount++; // Increment item count in inventory
        printf("Item added to inventory successfully!\n");
    } else {
        printf("Unable to add item to inventory. Maximum capacity reached!\n");
    }
}

// Function to remove an item from inventory
void removeItem(char name[]) {
    int i, j, found = 0;
    for (i = 0; i < itemCount; i++) { // Look for item in inventory
        if (strcmp(inventory[i].name, name) == 0) { // If item found
            found = 1;
            for (j = i; j < itemCount - 1; j++) { // Shift items in inventory to fill the gap
                inventory[j] = inventory[j + 1];
            }
            itemCount--; // Decrement item count in inventory
            printf("Item removed from inventory successfully!\n");
            break;
        }
    }
    if (!found) { // If item not found
        printf("Item '%s' not found in inventory!\n", name);
    }
}

// Function to display all items in inventory
void displayInventory() {
    int i;
    printf("Name\t\tQuantity\tPrice\n");
    for (i = 0; i < itemCount; i++) {
        printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice, quantity;
    float price;
    char name[MAX_NAME_LENGTH];
    do {
        printf("Product Inventory System Menu\n");
        printf("1. Add Item to Inventory\n");
        printf("2. Remove Item from Inventory\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                printf("Enter item price: ");
                scanf("%f", &price);
                addItem(name, quantity, price);
                break;
            case 2:
                printf("\nEnter item name: ");
                scanf("%s", name);
                removeItem(name);
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
        printf("\n");
    } while (choice != 4);
    return 0;
}