//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 50

typedef struct {
    char name[30];
    int quantity;
    float price;
} Item;

void addItem(Item inventory[], int *itemCount) {
    if (*itemCount >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    inventory[*itemCount] = newItem;
    (*itemCount)++;
    printf("Item added successfully!\n");
}

void removeItem(Item inventory[], int *itemCount) {
    char name[30];
    printf("Enter item name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < *itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Shift items to remove the one at index i
            for (int j = i; j < *itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*itemCount)--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void displayInventory(const Item inventory[], int itemCount) {
    if (itemCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    printf("=========================================================\n");
    printf("| %-15s | %-10s | %-10s |\n", "Item Name", "Quantity", "Price");
    printf("=========================================================\n");
    for (int i = 0; i < itemCount; i++) {
        printf("| %-15s | %-10d | $%-9.2f |\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("=========================================================\n");
}

void saveInventory(const Item inventory[], int itemCount) {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
    printf("Inventory saved to inventory.txt\n");
}

void loadInventory(Item inventory[], int *itemCount) {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("No saved inventory found. Starting fresh.\n");
        return;
    }
    while (fscanf(file, "%s %d %f", inventory[*itemCount].name, &inventory[*itemCount].quantity, &inventory[*itemCount].price) != EOF) {
        (*itemCount)++;
    }
    fclose(file);
    printf("Inventory loaded successfully!\n");
}

void displayMenu() {
    printf("\n--- Inventory Management System ---\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Inventory\n");
    printf("4. Save Inventory to File\n");
    printf("5. Load Inventory from File\n");
    printf("6. Exit\n");
}

int main() {
    Item inventory[MAX_ITEMS]; // Inventory array
    int itemCount = 0;
    int choice;

    // Load existing inventory at start
    loadInventory(inventory, &itemCount);

    do {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &itemCount);
                break;
            case 2:
                removeItem(inventory, &itemCount);
                break;
            case 3:
                displayInventory(inventory, itemCount);
                break;
            case 4:
                saveInventory(inventory, itemCount);
                break;
            case 5:
                loadInventory(inventory, &itemCount);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}