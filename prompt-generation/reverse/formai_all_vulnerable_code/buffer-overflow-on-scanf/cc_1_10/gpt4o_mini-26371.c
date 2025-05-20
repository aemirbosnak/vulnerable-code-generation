//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse full!\n");
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
    printf("Item added successfully!\n");
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items in warehouse.\n");
        return;
    }

    printf("Items in Warehouse:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - Quantity: %d, Price: %.2f\n", 
                i + 1, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

void updateItem() {
    int index;
    printf("Enter item index to update: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Invalid index!\n");
        return;
    }

    index--; // Convert to 0-based index
    printf("Updating: %s\n", warehouse[index].name);
    printf("Enter new quantity: ");
    scanf("%d", &warehouse[index].quantity);
    printf("Enter new price: ");
    scanf("%f", &warehouse[index].price);
    printf("Item updated successfully!\n");
}

void removeItem() {
    int index;
    printf("Enter item index to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Invalid index!\n");
        return;
    }

    index--; // Convert to 0-based index
    for (int i = index; i < itemCount - 1; i++) {
        warehouse[i] = warehouse[i + 1];
    }
    itemCount--;
    printf("Item removed successfully!\n");
}

void searchItem() {
    char searchName[NAME_LENGTH];
    printf("Enter item name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(warehouse[i].name, searchName) == 0) {
            printf("Found: %s - Quantity: %d, Price: %.2f\n",
                   warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Item not found!\n");
    }
}

void displayMenu() {
    printf("\n=== Warehouse Management System ===\n");
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Update Item\n");
    printf("4. Remove Item\n");
    printf("5. Search Item\n");
    printf("6. Exit\n");
    printf("====================================\n");
    printf("Choose an option: ");
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
                displayItems();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                removeItem();
                break;
            case 5:
                searchItem();
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}