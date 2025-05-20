//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse, int id, const char *name, int quantity) {
    if (warehouse->count < MAX_ITEMS) {
        warehouse->items[warehouse->count].id = id;
        strcpy(warehouse->items[warehouse->count].name, name);
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->count++;
        printf("Item added: [%d] %s - Quantity: %d\n", id, name, quantity);
    } else {
        printf("Warehouse is full. Cannot add more items.\n");
    }
}

void removeItem(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item with ID %d removed.\n", id);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void displayItems(const Warehouse *warehouse) {
    printf("Warehouse Items:\n");
    printf("ID\tName\tQuantity\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d\t%s\t%d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void updateItemQuantity(Warehouse *warehouse, int id, int newQuantity) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i].quantity = newQuantity;
            printf("Updated item [%d] %s - New Quantity: %d\n", id, warehouse->items[i].name, newQuantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    char operation[10];
    int id, quantity;
    char name[50];

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("Options: add, remove, update, display, exit\n");
        printf("Enter operation: ");
        scanf("%s", operation);

        if (strcmp(operation, "add") == 0) {
            printf("Enter item ID: ");
            scanf("%d", &id);
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            addItem(&warehouse, id, name, quantity);
        } 
        else if (strcmp(operation, "remove") == 0) {
            printf("Enter item ID to remove: ");
            scanf("%d", &id);
            removeItem(&warehouse, id);
        } 
        else if (strcmp(operation, "update") == 0) {
            printf("Enter item ID to update: ");
            scanf("%d", &id);
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            updateItemQuantity(&warehouse, id, quantity);
        } 
        else if (strcmp(operation, "display") == 0) {
            displayItems(&warehouse);
        } 
        else if (strcmp(operation, "exit") == 0) {
            printf("Exiting the program.\n");
            break;
        } 
        else {
            printf("Invalid operation. Please try again.\n");
        }
    }

    return 0;
}