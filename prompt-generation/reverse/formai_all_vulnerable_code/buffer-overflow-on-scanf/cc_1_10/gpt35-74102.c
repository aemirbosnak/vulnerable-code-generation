//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100  // Maximum number of items the warehouse can store

struct Item {
    int id;
    char name[50];
    int quantity;
};

struct Warehouse {
    struct Item items[MAX_ITEMS];
    int count;
};

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("----------------------------------\n");
    printf("1. Add an item to the warehouse\n");
    printf("2. Remove an item from the warehouse\n");
    printf("3. Display warehouse inventory\n");
    printf("4. Exit\n");
}

void addItem(struct Warehouse *warehouse) {
    if (warehouse->count < MAX_ITEMS) {
        struct Item item;
        printf("Enter item ID: ");
        scanf("%d", &item.id);
        printf("Enter item name: ");
        scanf(" %[^\n]", item.name);
        printf("Enter item quantity: ");
        scanf("%d", &item.quantity);
        warehouse->items[warehouse->count++] = item;
        printf("Item added successfully!\n");
    } else {
        printf("Warehouse is full\n");
    }
}

void removeItem(struct Warehouse *warehouse) {
    int id, index = -1;
    printf("Enter item ID: ");
    scanf("%d", &id);
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        memmove(warehouse->items + index, warehouse->items + index + 1, (warehouse->count - index - 1) * sizeof(struct Item));
        warehouse->count--;
        printf("Item removed successfully!\n");
    } else {
        printf("Item not found\n");
    }
}

void displayInventory(struct Warehouse *warehouse) {
    if (warehouse->count > 0) {
        printf("\nWarehouse Inventory\n");
        printf("----------------------------------\n");
        for (int i = 0; i < warehouse->count; i++) {
            printf("%d | %s | %d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
        }
    } else {
        printf("No items in the warehouse\n");
    }
}

int main() {
    struct Warehouse warehouse = { .count = 0 };
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                removeItem(&warehouse);
                break;
            case 3:
                displayInventory(&warehouse);
                break;
            case 4:
                printf("Exiting Warehouse Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}