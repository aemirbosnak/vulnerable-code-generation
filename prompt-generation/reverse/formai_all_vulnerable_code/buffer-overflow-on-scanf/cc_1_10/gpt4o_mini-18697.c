//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse *warehouse, const char *name, int quantity, float price) {
    if (warehouse->itemCount < MAX_ITEMS) {
        strncpy(warehouse->items[warehouse->itemCount].name, name, MAX_NAME_LENGTH);
        warehouse->items[warehouse->itemCount].quantity = quantity;
        warehouse->items[warehouse->itemCount].price = price;
        warehouse->itemCount++;
    } else {
        printf("Warehouse is full! Cannot add more items.\n");
    }
}

void removeItem(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            printf("Removed item: %s\n", name);
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

void displayInventory(const Warehouse *warehouse) {
    printf("Current Inventory:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("Item: %s, Quantity: %d, Price: %.2f\n",
                warehouse->items[i].name,
                warehouse->items[i].quantity,
                warehouse->items[i].price);
    }
}

void updateItemQuantity(Warehouse *warehouse, const char *name, int newQuantity) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity = newQuantity;
            printf("Updated item: %s, New Quantity: %d\n", name, newQuantity);
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

float calculateTotalValue(const Warehouse *warehouse) {
    float totalValue = 0.0f;
    for (int i = 0; i < warehouse->itemCount; i++) {
        totalValue += warehouse->items[i].quantity * warehouse->items[i].price;
    }
    return totalValue;
}

void menu() {
    printf("\nWarehouse Management System Menu:\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Inventory\n");
    printf("4. Update Item Quantity\n");
    printf("5. Calculate Total Value\n");
    printf("6. Exit\n");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                addItem(&warehouse, name, quantity, price);
                break;
            case 2:
                printf("Enter item name to remove: ");
                scanf("%s", name);
                removeItem(&warehouse, name);
                break;
            case 3:
                displayInventory(&warehouse);
                break;
            case 4:
                printf("Enter item name to update: ");
                scanf("%s", name);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateItemQuantity(&warehouse, name, quantity);
                break;
            case 5:
                printf("Total inventory value: %.2f\n", calculateTotalValue(&warehouse));
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}