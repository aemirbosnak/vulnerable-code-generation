//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    inventory[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully!\n");
}

void viewItems() {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }
    
    printf("\nInventory:\n");
    printf("---------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Item Name", "Price", "Quantity");
    printf("---------------------------------------------------\n");
    
    for (int i = 0; i < itemCount; i++) {
        printf("| %-20s | %-10.2f | %-10d |\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    
    printf("---------------------------------------------------\n");
}

void searchItem() {
    char searchName[50];
    printf("Enter item name to search: ");
    scanf("%s", searchName);
    int found = 0;

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("Item found: %s, Price: %.2f, Quantity: %d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found in inventory.\n");
    }
}

void updateItem() {
    char updateName[50];
    printf("Enter item name to update: ");
    scanf("%s", updateName);
    int found = 0;

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, updateName) == 0) {
            printf("Current details - Name: %s, Price: %.2f, Quantity: %d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Item updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found in inventory.\n");
    }
}

void deleteItem() {
    char deleteName[50];
    printf("Enter item name to delete: ");
    scanf("%s", deleteName);
    int found = 0;

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, deleteName) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found in inventory.\n");
    }
}

void displayMenu() {
    printf("\nInventory Management System\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Search Item\n");
    printf("4. Update Item\n");
    printf("5. Delete Item\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateItem();
                break;
            case 5:
                deleteItem();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}