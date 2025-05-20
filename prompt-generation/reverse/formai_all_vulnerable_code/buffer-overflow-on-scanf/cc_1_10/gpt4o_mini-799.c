//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 30

// Structure to hold item details
typedef struct {
    char name[ITEM_NAME_LENGTH];
    float price;
    int quantity;
} Item;

// Function declarations
void displayMenu();
void addItem(Item *inventory, int *count);
void listItems(Item *inventory, int count);
void purchaseItem(Item *inventory, int count);
void exitProgram();

// Main function
int main() {
    Item inventory[MAX_ITEMS] = {0};
    int itemCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem(inventory, &itemCount);
                break;
            case 2:
                listItems(inventory, itemCount);
                break;
            case 3:
                purchaseItem(inventory, itemCount);
                break;
            case 4:
                exitProgram();
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Inventory Management Menu ---\n");
    printf("1. Add Item\n");
    printf("2. List Items\n");
    printf("3. Purchase Item\n");
    printf("4. Exit\n");
}

// Function to add an item to the inventory
void addItem(Item *inventory, int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }

    printf("Enter the name of the item: ");
    getchar();  // Clear the input buffer
    fgets(inventory[*count].name, ITEM_NAME_LENGTH, stdin);
    inventory[*count].name[strcspn(inventory[*count].name, "\n")] = 0;  // Remove newline

    printf("Enter the price of the item: ");
    scanf("%f", &inventory[*count].price);
    
    printf("Enter the quantity: ");
    scanf("%d", &inventory[*count].quantity);
    
    (*count)++;
    printf("Item '%s' added successfully!\n", inventory[*count - 1].name);
}

// Function to list all items in the inventory
void listItems(Item *inventory, int count) {
    if (count == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    printf("\n--- Inventory Items ---\n");
    printf("%-30s %-10s %-10s\n", "Item Name", "Price", "Quantity");
    for (int i = 0; i < count; i++) {
        printf("%-30s $%.2f %-10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Function to handle purchasing an item
void purchaseItem(Item *inventory, int count) {
    if (count == 0) {
        printf("No items available for purchase.\n");
        return;
    }

    listItems(inventory, count);
    char itemName[ITEM_NAME_LENGTH];
    printf("Enter the name of the item you want to purchase: ");
    getchar(); // Clear input buffer
    fgets(itemName, ITEM_NAME_LENGTH, stdin);
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            int quantity;
            printf("Enter the quantity to purchase: ");
            scanf("%d", &quantity);
            if (quantity > inventory[i].quantity) {
                printf("Insufficient quantity available. Only %d left in stock.\n", inventory[i].quantity);
            } else {
                inventory[i].quantity -= quantity;
                printf("You have purchased %d of '%s'. Total cost: $%.2f\n", quantity, inventory[i].name, inventory[i].price * quantity);
                if (inventory[i].quantity == 0) {
                    printf("Item '%s' is now out of stock!\n", inventory[i].name);
                }
            }
            return;
        }
    }
    printf("Item '%s' not found in inventory.\n", itemName);
}

// Function for clean exit
void exitProgram() {
    printf("Thank you for using the Inventory Management System. Goodbye!\n");
}