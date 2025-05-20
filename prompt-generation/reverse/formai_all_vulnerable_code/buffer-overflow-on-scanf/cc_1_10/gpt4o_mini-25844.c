//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

void addItem();
void viewItems();
void deleteItem();
void displayMenu();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                deleteItem();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Warehouse Management System ---\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Delete Item\n");
    printf("4. Exit\n");
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    scanf(" %[^\n]", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    warehouse[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully!\n");
}

void viewItems() {
    if (itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("\n--- Warehouse Items ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s | Quantity: %d | Price: $%.2f\n",
               i + 1, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

void deleteItem() {
    if (itemCount == 0) {
        printf("No items to delete.\n");
        return;
    }

    int index;
    viewItems();
    printf("Enter the item number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Invalid item number. Deletion failed!\n");
        return;
    }

    for (int i = index - 1; i < itemCount - 1; i++) {
        warehouse[i] = warehouse[i + 1];
    }
    itemCount--;
    printf("Item deleted successfully!\n");
}