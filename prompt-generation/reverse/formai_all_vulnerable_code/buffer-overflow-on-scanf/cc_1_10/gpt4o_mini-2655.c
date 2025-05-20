//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Linus Torvalds
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
    int itemCount;
} Warehouse;

void addItem(Warehouse *warehouse, const char *name, int quantity, float price) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }

    strcpy(warehouse->items[warehouse->itemCount].name, name);
    warehouse->items[warehouse->itemCount].quantity = quantity;
    warehouse->items[warehouse->itemCount].price = price;
    warehouse->itemCount++;
    
    printf("Added item: %s, Quantity: %d, Price: %.2f\n", name, quantity, price);
}

void removeItem(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            printf("Removed item: %s\n", name);
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

void listItems(const Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in warehouse.\n");
        return;
    }

    printf("Items in warehouse:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%s - Quantity: %d, Price: %.2f\n",
               warehouse->items[i].name,
               warehouse->items[i].quantity,
               warehouse->items[i].price);
    }
}

void updateItemQuantity(Warehouse *warehouse, const char *name, int quantity) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity = quantity;
            printf("Updated %s quantity to %d\n", name, quantity);
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

void showMenu() {
    printf("Warehouse Management System\n");
    printf("============================\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. List Items\n");
    printf("4. Update Item Quantity\n");
    printf("5. Exit\n");
    printf("============================\n");
    printf("Enter your choice: ");
}

int main() {
    Warehouse warehouse;
    warehouse.itemCount = 0;

    int choice;
    char name[50];
    int quantity;
    float price;

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar(); // consume newline

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
                name[strcspn(name, "\n")] = 0; // remove newline
                removeItem(&warehouse, name);
                break;
            case 3:
                listItems(&warehouse);
                break;
            case 4:
                printf("Enter item name to update: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateItemQuantity(&warehouse, name, quantity);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}