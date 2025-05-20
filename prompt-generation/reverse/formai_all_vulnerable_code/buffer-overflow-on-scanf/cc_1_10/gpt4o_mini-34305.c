//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50
#define CODE_LENGTH 20
#define FILENAME "warehouse.dat"

typedef struct {
    char name[NAME_LENGTH];
    char code[CODE_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

void loadWarehouse(Warehouse *warehouse) {
    FILE *file = fopen(FILENAME, "rb");
    if (file) {
        fread(warehouse, sizeof(Warehouse), 1, file);
        fclose(file);
    }
}

void saveWarehouse(Warehouse *warehouse) {
    FILE *file = fopen(FILENAME, "wb");
    fwrite(warehouse, sizeof(Warehouse), 1, file);
    fclose(file);
}

void addItem(Warehouse *warehouse) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full, cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item code: ");
    scanf("%s", newItem.code);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    warehouse->items[warehouse->itemCount++] = newItem;
    saveWarehouse(warehouse);
    printf("Item added successfully!\n");
}

void displayItems(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("\nItems in Warehouse:\n");
    printf("Name\t\tCode\t\tQuantity\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%s\t\t%s\t\t%d\n", warehouse->items[i].name, warehouse->items[i].code, warehouse->items[i].quantity);
    }
}

void searchItem(Warehouse *warehouse) {
    char code[CODE_LENGTH];
    printf("Enter item code to search: ");
    scanf("%s", code);

    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].code, code) == 0) {
            printf("Item found:\n");
            printf("Name: %s, Code: %s, Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].code, warehouse->items[i].quantity);
            return;
        }
    }
    printf("Item with code %s not found.\n", code);
}

void removeItem(Warehouse *warehouse) {
    char code[CODE_LENGTH];
    printf("Enter item code to remove: ");
    scanf("%s", code);

    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].code, code) == 0) {
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            saveWarehouse(warehouse);
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item with code %s not found.\n", code);
}

void displayMenu() {
    printf("\n--- Warehouse Management System ---\n");
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Search Item\n");
    printf("4. Remove Item\n");
    printf("5. Exit\n");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    loadWarehouse(&warehouse);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                displayItems(&warehouse);
                break;
            case 3:
                searchItem(&warehouse);
                break;
            case 4:
                removeItem(&warehouse);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}