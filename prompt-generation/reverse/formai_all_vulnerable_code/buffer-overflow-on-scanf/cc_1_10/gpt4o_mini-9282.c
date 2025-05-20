//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
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
    
    inventory[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void viewItems() {
    printf("\nCurrent Inventory:\n");
    printf("%-20s %-10s %-10s\n", "Item Name", "Quantity", "Price");
    printf("--------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%-20s %-10d $%-9.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateItem() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the item to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Updating item '%s'. Current quantity: %d, Current price: $%.2f\n",
                   inventory[i].name, inventory[i].quantity, inventory[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void deleteItem() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the item to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item '%s' removed from inventory.\n", name);
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void menu() {
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}