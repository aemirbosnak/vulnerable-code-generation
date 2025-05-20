//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse* warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse* warehouse, const char* name, int quantity, float price) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }
    strcpy(warehouse->items[warehouse->count].name, name);
    warehouse->items[warehouse->count].quantity = quantity;
    warehouse->items[warehouse->count].price = price;
    warehouse->count++;
    printf("Item added: %s, Quantity: %d, Price: %.2f\n", name, quantity, price);
}

void removeItem(Warehouse* warehouse, const char* name) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item removed: %s\n", name);
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

void updateItemQuantity(Warehouse* warehouse, const char* name, int quantity) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity = quantity;
            printf("Updated %s quantity to %d\n", name, quantity);
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

void displayItems(Warehouse* warehouse) {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("Name: %s | Quantity: %d | Price: %.2f\n", 
               warehouse->items[i].name,
               warehouse->items[i].quantity,
               warehouse->items[i].price);
    }
    printf("\n");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int option;
    char name[NAME_LENGTH];
    int quantity;
    float price;

    while (1) {
        printf("Warehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Item Quantity\n");
        printf("4. Display Items\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
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
                printf("Enter item name to update: ");
                scanf("%s", name);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateItemQuantity(&warehouse, name, quantity);
                break;
            case 4:
                displayItems(&warehouse);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
    return 0;
}