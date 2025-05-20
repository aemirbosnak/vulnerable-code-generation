//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_LENGTH 50

typedef struct {
    int id;
    char name[MAX_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
    printf("Warehouse initialized. Ready to store items!\n");
}

void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Cannot add more items, warehouse is full!\n");
        return;
    }

    Item newItem;
    newItem.id = warehouse->count + 1;

    printf("Enter item name: ");
    scanf(" %[^\n]s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    printf("Item added successfully! ID: %d\n", newItem.id);
}

void displayItems(const Warehouse *warehouse) {
    printf("\nWarehouse Inventory:\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: $%.2f\n",
               warehouse->items[i].id,
               warehouse->items[i].name,
               warehouse->items[i].quantity,
               warehouse->items[i].price);
    }
    printf("-----------------------------------\n");
}

void updateItem(Warehouse *warehouse) {
    int id;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);

    if (id < 1 || id > warehouse->count) {
        printf("Invalid item ID!\n");
        return;
    }

    Item *item = &warehouse->items[id - 1];
    printf("Current Name: %s, Quantity: %d, Price: $%.2f\n",
           item->name, item->quantity, item->price);
    printf("Enter new name (or press Enter to keep current): ");
    char newName[MAX_LENGTH];
    getchar(); // eat extra newline
    fgets(newName, MAX_LENGTH, stdin);
    newName[strcspn(newName, "\n")] = 0; // remove newline

    if (strlen(newName) > 0) {
        strcpy(item->name, newName);
    }

    printf("Enter new quantity (or -1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity != -1) {
        item->quantity = newQuantity;
    }

    printf("Enter new price (or -1.0 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice != -1.0) {
        item->price = newPrice;
    }

    printf("Item updated successfully!\n");
}

void removeItem(Warehouse *warehouse) {
    int id;
    printf("Enter the ID of the item to remove: ");
    scanf("%d", &id);

    if (id < 1 || id > warehouse->count) {
        printf("Invalid item ID!\n");
        return;
    }

    for (int i = id - 1; i < warehouse->count - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->count--;
    printf("Item removed successfully!\n");
}

void storageMenu(Warehouse *warehouse) {
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Update Item\n");
        printf("4. Remove Item\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(warehouse);
                break;
            case 2:
                displayItems(warehouse);
                break;
            case 3:
                updateItem(warehouse);
                break;
            case 4:
                removeItem(warehouse);
                break;
            case 5:
                printf("Exiting Warehouse Management System. Have a great day!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 5);
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    storageMenu(&warehouse);
    return 0;
}