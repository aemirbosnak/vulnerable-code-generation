//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[30];
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
        strcpy(warehouse->items[warehouse->itemCount].name, name);
        warehouse->items[warehouse->itemCount].quantity = quantity;
        warehouse->items[warehouse->itemCount].price = price;
        warehouse->itemCount++;
        printf("Item '%s' added successfully!\n", name);
    } else {
        printf("Warehouse is full, cannot add more items.\n");
    }
}

void removeItem(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            printf("Item '%s' removed successfully!\n", name);
            return;
        }
    }
    printf("Item '%s' not found in the warehouse.\n", name);
}

void displayItems(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    
    printf("Items in Warehouse:\n");
    printf("%-20s %-10s %-10s\n", "Item Name", "Quantity", "Price");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%-20s %-10d $%-9.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the standard input buffer
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    int choice;
    char name[30];
    int quantity;
    float price;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the input buffer before next input

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                addItem(&warehouse, name, quantity, price);
                break;
            case 2:
                printf("Enter item name to remove: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                removeItem(&warehouse, name);
                break;
            case 3:
                displayItems(&warehouse);
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