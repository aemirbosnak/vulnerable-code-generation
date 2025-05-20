//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
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

void addItem(Warehouse* warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter Item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter Item Name: ");
    scanf("%s", newItem.name);
    printf("Enter Item Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Item Price: ");
    scanf("%f", &newItem.price);

    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    printf("Item added successfully!\n");
}

void deleteItem(Warehouse* warehouse) {
    int id, found = 0;
    printf("Enter Item ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            found = 1;
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void viewItems(Warehouse* warehouse) {
    if (warehouse->count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("\nItems in Warehouse:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                warehouse->items[i].id,
                warehouse->items[i].name,
                warehouse->items[i].quantity,
                warehouse->items[i].price);
    }
}

void updateItem(Warehouse* warehouse) {
    int id, found = 0;
    printf("Enter Item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            found = 1;
            printf("Enter new Item Name: ");
            scanf("%s", warehouse->items[i].name);
            printf("Enter new Item Quantity: ");
            scanf("%d", &warehouse->items[i].quantity);
            printf("Enter new Item Price: ");
            scanf("%f", &warehouse->items[i].price);
            printf("Item updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Delete Item\n");
    printf("3. View Items\n");
    printf("4. Update Item\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                deleteItem(&warehouse);
                break;
            case 3:
                viewItems(&warehouse);
                break;
            case 4:
                updateItem(&warehouse);
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}