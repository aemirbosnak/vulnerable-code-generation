//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>

// Define a struct for the warehouse inventory item
struct InventoryItem {
    char name[50];
    int quantity;
    float price;
};

// Define a function to add a new item to the inventory
void addInventoryItem(struct InventoryItem *inventory, int index) {

    // Prompt user for item name
    char name[50];
    printf("Enter name of item:\n");
    fgets(name, 50, stdin);

    // Prompt user for item quantity
    int quantity;
    printf("Enter quantity of item:\n");
    scanf("%d", &quantity);
    getchar();  // Clear input buffer

    // Prompt user for item price
    float price;
    printf("Enter price of item:\n");
    scanf("%f", &price);
    getchar();  // Clear input buffer

    // Add item to inventory
    struct InventoryItem item = {name, quantity, price};
    inventory[index] = item;
}

// Define a function to print the current inventory
void printInventory(struct InventoryItem *inventory, int numItems) {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d: %sQuantity: %d%sPrice: $%.2f\n", i+1, inventory[i].name, inventory[i].quantity, "\t", inventory[i].price);
    }
}

int main() {
    // Define array to hold inventory items
    struct InventoryItem inventory[50];
    int numItems = 0;

    // Print welcome message
    printf("Welcome to the Warehouse Management System!\n");

    // Loop through menu until user chooses to exit
    int choice;
    do {
        // Print menu options
        printf("\nMenu Options:\n");
        printf("1. Add new item to inventory\n");
        printf("2. Print current inventory\n");
        printf("3. Exit\n");
        printf("Enter your choice [1-3]:\n");

        // Get user choice
        scanf("%d", &choice);
        getchar();  // Clear input buffer

        // Handle user choice
        switch (choice) {
            case 1:
                addInventoryItem(inventory, numItems);
                numItems++;
                printf("\nItem added to inventory.\n");
                break;
            case 2:
                printInventory(inventory, numItems);
                break;
            case 3:
                printf("\nThank you for using the Warehouse Management System!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}