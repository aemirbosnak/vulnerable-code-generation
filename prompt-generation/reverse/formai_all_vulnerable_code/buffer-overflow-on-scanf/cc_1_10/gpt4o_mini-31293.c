//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initWarehouse(Warehouse* warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse* warehouse, int id, const char* name, int quantity, float price) {
    if (warehouse->itemCount < MAX_ITEMS) {
        Item *newItem = &warehouse->items[warehouse->itemCount++];
        newItem->id = id;
        strncpy(newItem->name, name, MAX_NAME_LENGTH);
        newItem->quantity = quantity;
        newItem->price = price;
    } else {
        printf("Warehouse is full! Cannot add more items.\n");
    }
}

void displayItems(const Warehouse* warehouse) {
    printf("\nItems in the Warehouse:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%d\t%-15s\t%d\t\t%.2f\n", warehouse->items[i].id,
               warehouse->items[i].name, warehouse->items[i].quantity,
               warehouse->items[i].price);
    }
}

void updateItem(Warehouse* warehouse, int id, int newQuantity) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i].quantity = newQuantity;
            printf("Item %s updated to quantity %d.\n", 
                   warehouse->items[i].name, newQuantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void removeItem(Warehouse* warehouse, int id) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            printf("Item with ID %d has been removed.\n", id);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void searchItem(const Warehouse* warehouse, int id) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            printf("Item found:\n");
            printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   warehouse->items[i].id, warehouse->items[i].name,
                   warehouse->items[i].quantity, warehouse->items[i].price);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

int main() {
    Warehouse warehouse;
    initWarehouse(&warehouse);
    
    int choice, id, quantity;
    char name[MAX_NAME_LENGTH];
    float price;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Update Item\n");
        printf("4. Remove Item\n");
        printf("5. Search Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf(" %49[^\n]", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                printf("Enter item price: ");
                scanf("%f", &price);
                addItem(&warehouse, id, name, quantity, price);
                break;
            case 2:
                displayItems(&warehouse);
                break;
            case 3:
                printf("Enter item ID to update: ");
                scanf("%d", &id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateItem(&warehouse, id, quantity);
                break;
            case 4:
                printf("Enter item ID to remove: ");
                scanf("%d", &id);
                removeItem(&warehouse, id);
                break;
            case 5:
                printf("Enter item ID to search: ");
                scanf("%d", &id);
                searchItem(&warehouse, id);
                break;
            case 6:
                printf("Exiting the Warehouse Management System.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}