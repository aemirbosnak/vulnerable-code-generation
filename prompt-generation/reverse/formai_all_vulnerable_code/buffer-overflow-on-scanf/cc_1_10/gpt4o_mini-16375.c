//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse, const char *name, int quantity, float price) {
    if (warehouse->count < MAX_ITEMS) {
        strcpy(warehouse->items[warehouse->count].name, name);
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->items[warehouse->count].price = price;
        warehouse->count++;
        printf("Added item: %s, Quantity: %d, Price: %.2f\n", name, quantity, price);
    } else {
        printf("Warehouse is full! Cannot add more items.\n");
    }
}

void removeItem(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Removed item: %s\n", name);
            return;
        }
    }
    printf("Item %s not found in warehouse.\n", name);
}

void updateItem(Warehouse *warehouse, const char *name, int newQuantity, float newPrice) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity = newQuantity;
            warehouse->items[i].price = newPrice;
            printf("Updated item: %s to Quantity: %d, Price: %.2f\n", name, newQuantity, newPrice);
            return;
        }
    }
    printf("Item %s not found in warehouse.\n", name);
}

void listItems(Warehouse *warehouse) {
    printf("\nItems in the Warehouse:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("Item: %s, Quantity: %d, Price: %.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

void searchItem(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Found item: %s, Quantity: %d, Price: %.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
            return;
        }
    }
    printf("Item %s not found in warehouse.\n", name);
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice;
    char name[50];
    int quantity;
    float price;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Item\n");
        printf("4. List All Items\n");
        printf("5. Search Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                addItem(&warehouse, name, quantity, price);
                break;
            case 2:
                printf("Enter item name to remove: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                removeItem(&warehouse, name);
                break;
            case 3:
                printf("Enter item name to update: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                printf("Enter new price: ");
                scanf("%f", &price);
                updateItem(&warehouse, name, quantity, price);
                break;
            case 4:
                listItems(&warehouse);
                break;
            case 5:
                printf("Enter item name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                searchItem(&warehouse, name);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}