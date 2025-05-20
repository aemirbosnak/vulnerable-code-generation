//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int stock;
    float price;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    newItem.id = itemCount + 1; // Assigning a unique ID
    printf("Enter the name of the item: ");
    scanf("%s", newItem.name);
    printf("Enter the stock quantity: ");
    scanf("%d", &newItem.stock);
    printf("Enter the price of the item: ");
    scanf("%f", &newItem.price);

    warehouse[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully!\n");
}

void viewItems() {
    printf("\nCurrent Items in Warehouse:\n");
    printf("-------------------------------------\n");
    printf("ID\tName\t\tStock\tPrice\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%-10s\t%d\t%.2f\n", warehouse[i].id, warehouse[i].name, warehouse[i].stock, warehouse[i].price);
    }
}

void updateItem() {
    int id;
    printf("Enter the ID of the item you want to update: ");
    scanf("%d", &id);
    if (id < 1 || id > itemCount) {
        printf("Invalid ID!\n");
        return;
    }

    Item* item = &warehouse[id - 1];
    printf("Updating item: %s\n", item->name);
    printf("Current stock: %d. Enter new stock quantity: ", item->stock);
    scanf("%d", &item->stock);
    printf("Current price: %.2f. Enter new price: ", item->price);
    scanf("%f", &item->price);
    printf("Item updated successfully!\n");
}

void deleteItem() {
    int id;
    printf("Enter the ID of the item to delete: ");
    scanf("%d", &id);
    if (id < 1 || id > itemCount) {
        printf("Invalid ID!\n");
        return;
    }

    for (int i = id - 1; i < itemCount - 1; i++) {
        warehouse[i] = warehouse[i + 1]; // Shift items left
    }
    itemCount--;
    printf("Item deleted successfully!\n");
}

void searchItem() {
    char name[50];
    printf("Enter the name of the item to search: ");
    scanf("%s", name);

    printf("\nSearch Results:\n");
    printf("-------------------------------------\n");
    printf("ID\tName\t\tStock\tPrice\n");
    printf("-------------------------------------\n");
    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcasecmp(warehouse[i].name, name) == 0) {
            printf("%d\t%-10s\t%d\t%.2f\n", warehouse[i].id, warehouse[i].name, warehouse[i].stock, warehouse[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Item not found!\n");
    }
}

void warehouseMenu() {
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Search Item\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                searchItem();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    warehouseMenu();
    return 0;
}