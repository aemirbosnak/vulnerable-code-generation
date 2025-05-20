//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
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

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse, int id, const char *name, int quantity, float price) {
    if (warehouse->count < MAX_ITEMS) {
        warehouse->items[warehouse->count].id = id;
        strncpy(warehouse->items[warehouse->count].name, name, sizeof(warehouse->items[warehouse->count].name) - 1);
        warehouse->items[warehouse->count].name[sizeof(warehouse->items[warehouse->count].name) - 1] = '\0';
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->items[warehouse->count].price = price;
        warehouse->count++;
        printf("Item added: %s (ID: %d)\n", name, id);
    } else {
        printf("Warehouse is full! Cannot add more items.\n");
    }
}

void removeItem(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            printf("Removing item: %s (ID: %d)\n", warehouse->items[i].name, warehouse->items[i].id);
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            return;
        }
    }
    printf("Item with ID %d not found!\n", id);
}

void viewItems(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in warehouse.\n");
        return;
    }
    printf("\nItems in Warehouse:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d\t%-15s\t%d\t\t%.2f\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

void editItem(Warehouse *warehouse, int id, const char *name, int quantity, float price) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            strncpy(warehouse->items[i].name, name, sizeof(warehouse->items[i].name) - 1);
            warehouse->items[i].name[sizeof(warehouse->items[i].name) - 1] = '\0';
            warehouse->items[i].quantity = quantity;
            warehouse->items[i].price = price;
            printf("Item updated: %s (ID: %d)\n", warehouse->items[i].name, id);
            return;
        }
    }
    printf("Item with ID %d not found!\n", id);
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice;
    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Items\n");
        printf("4. Edit Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int id, quantity;
            float price;
            char name[50];
            printf("Enter item ID: ");
            scanf("%d", &id);
            printf("Enter item name: ");
            scanf(" %[^\n]s", name);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            printf("Enter item price: ");
            scanf("%f", &price);
            addItem(&warehouse, id, name, quantity, price);
        } else if (choice == 2) {
            int id;
            printf("Enter item ID to remove: ");
            scanf("%d", &id);
            removeItem(&warehouse, id);
        } else if (choice == 3) {
            viewItems(&warehouse);
        } else if (choice == 4) {
            int id, quantity;
            float price;
            char name[50];
            printf("Enter item ID to edit: ");
            scanf("%d", &id);
            printf("Enter new item name: ");
            scanf(" %[^\n]s", name);
            printf("Enter new item quantity: ");
            scanf("%d", &quantity);
            printf("Enter new item price: ");
            scanf("%f", &price);
            editItem(&warehouse, id, name, quantity, price);
        } else if (choice == 5) {
            printf("Exiting the system.\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}