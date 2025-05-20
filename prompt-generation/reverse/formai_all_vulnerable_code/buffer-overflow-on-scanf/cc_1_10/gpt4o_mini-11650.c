//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Can't add more items.\n");
        return;
    }
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    warehouse[itemCount++] = newItem;
    printf("Item '%s' added successfully!\n", newItem.name);
}

void viewItems() {
    if (itemCount == 0) {
        printf("No items in warehouse yet!\n");
        return;
    }
    printf("Warehouse Inventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s | Quantity: %d | Price: %.2f\n", i + 1, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

void updateItem() {
    char itemName[50];
    printf("Enter the name of the item to update: ");
    scanf("%s", itemName);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(warehouse[i].name, itemName) == 0) {
            printf("Updating Item: %s\n", warehouse[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &warehouse[i].price);
            printf("Item '%s' updated successfully!\n", warehouse[i].name);
            return;
        }
    }
    printf("Item '%s' not found!\n", itemName);
}

void deleteItem() {
    char itemName[50];
    printf("Enter the name of the item to delete: ");
    scanf("%s", itemName);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(warehouse[i].name, itemName) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            itemCount--;
            printf("Item '%s' deleted successfully!\n", itemName);
            return;
        }
    }
    printf("Item '%s' not found!\n", itemName);
}

void displayMenu() {
    printf("\nWelcome to the Warehouse Management System!\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    do {
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
                updateItem();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                printf("Exiting the Warehouse Management System. Bye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}