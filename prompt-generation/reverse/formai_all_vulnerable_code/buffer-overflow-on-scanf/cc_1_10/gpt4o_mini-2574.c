//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    newItem.id = itemCount + 1;

    printf("Enter item name: ");
    scanf(" %[^\n]", newItem.name);
    
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    inventory[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully!\n");
}

void updateItem() {
    int id;
    printf("Enter the item ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > itemCount) {
        printf("Invalid item ID.\n");
        return;
    }

    Item *itemToUpdate = &inventory[id - 1];
    
    printf("Updating item '%s'.\n", itemToUpdate->name);
    
    printf("Enter new quantity: ");
    scanf("%d", &itemToUpdate->quantity);

    printf("Enter new price: ");
    scanf("%f", &itemToUpdate->price);

    printf("Item updated successfully!\n");
}

void displayInventory() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", 
               inventory[i].id, inventory[i].name, 
               inventory[i].quantity, inventory[i].price);
    }
}

void menu() {
    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Update Item\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}