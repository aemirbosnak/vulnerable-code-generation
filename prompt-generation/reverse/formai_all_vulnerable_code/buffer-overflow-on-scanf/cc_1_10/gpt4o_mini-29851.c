//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define STRING_LENGTH 50

typedef struct {
    int id;
    char name[STRING_LENGTH];
    int quantity;
    float price;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full, cannot add more items.\n");
        return;
    }
    
    Item newItem;
    newItem.id = itemCount + 1;  // Assign new ID

    printf("Enter item name: ");
    scanf("%s", newItem.name);
    
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    warehouse[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully.\n");
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

void searchItem() {
    int id;
    printf("Enter item ID to search: ");
    scanf("%d", &id);
    
    if (id < 1 || id > itemCount) {
        printf("Item not found.\n");
        return;
    }
    
    Item item = warehouse[id - 1];
    printf("Item found: %s, Quantity: %d, Price: %.2f\n", item.name, item.quantity, item.price);
}

void updateItem() {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > itemCount) {
        printf("Item not found.\n");
        return;
    }
    
    Item *item = &warehouse[id - 1];
    
    printf("Updating item: %s\n", item->name);
    printf("Enter new quantity: ");
    scanf("%d", &item->quantity);
    
    printf("Enter new price: ");
    scanf("%f", &item->price);
    
    printf("Item updated successfully.\n");
}

void deleteItem() {
    int id;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > itemCount) {
        printf("Item not found.\n");
        return;
    }
    
    for (int i = id - 1; i < itemCount - 1; i++) {
        warehouse[i] = warehouse[i + 1];  // Shift items down
    }
    
    itemCount--;
    printf("Item deleted successfully.\n");
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Search Item\n");
    printf("4. Update Item\n");
    printf("5. Delete Item\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
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
                displayItems();
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
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}