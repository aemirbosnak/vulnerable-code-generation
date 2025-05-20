//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int id;
    int quantity;
} Item;

typedef struct {
    Item inventory[MAX_ITEMS];
    int itemCount;
} Warehouse;

void addItem(Warehouse *w, const char *name, int id, int quantity) {
    if (w->itemCount >= MAX_ITEMS) {
        printf("Inventory Full!\n");
        return;
    }
    strncpy(w->inventory[w->itemCount].name, name, ITEM_NAME_LENGTH);
    w->inventory[w->itemCount].id = id;
    w->inventory[w->itemCount].quantity = quantity;
    w->itemCount++;
    printf("Added Item: %s, ID: %d, Quantity: %d\n", name, id, quantity);
}

void removeItem(Warehouse *w, int id) {
    for (int i = 0; i < w->itemCount; i++) {
        if (w->inventory[i].id == id) {
            printf("Removing Item: %s, ID: %d\n", w->inventory[i].name, id);
            for (int j = i; j < w->itemCount - 1; j++) {
                w->inventory[j] = w->inventory[j + 1];
            }
            w->itemCount--;
            return;
        }
    }
    printf("Item with ID: %d not found!\n", id);
}

void printInventory(Warehouse *w) {
    printf("Current Inventory:\n");
    for (int i = 0; i < w->itemCount; i++) {
        printf("Item Name: %s, ID: %d, Quantity: %d\n", 
               w->inventory[i].name, w->inventory[i].id, w->inventory[i].quantity);
    }
}

int findItemById(Warehouse *w, int id) {
    for (int i = 0; i < w->itemCount; i++) {
        if (w->inventory[i].id == id) {
            return i;
        }
    }
    return -1;
}

void updateQuantity(Warehouse *w, int id, int quantity) {
    int index = findItemById(w, id);
    if (index != -1) {
        w->inventory[index].quantity += quantity;
        printf("Updated Quantity for Item ID: %d, New Quantity: %d\n", 
               id, w->inventory[index].quantity);
    } else {
        printf("Item with ID: %d not found!\n", id);
    }
}

void searchItem(Warehouse *w, const char *name) {
    printf("Searching for Item: %s\n", name);
    for (int i = 0; i < w->itemCount; i++) {
        if (strcmp(w->inventory[i].name, name) == 0) {
            printf("Item Found: %s, ID: %d, Quantity: %d\n", 
                   w->inventory[i].name, w->inventory[i].id, w->inventory[i].quantity);
            return;
        }
    }
    printf("Item %s not found in inventory!\n", name);
}

int main() {
    Warehouse myWarehouse = {.itemCount = 0};
    int choice, id, quantity;
    char name[ITEM_NAME_LENGTH];

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Quantity\n");
        printf("4. Search Item\n");
        printf("5. Print Inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Item Name: ");
                scanf("%s", name);
                printf("Enter Item ID: ");
                scanf("%d", &id);
                printf("Enter Item Quantity: ");
                scanf("%d", &quantity);
                addItem(&myWarehouse, name, id, quantity);
                break;
            case 2:
                printf("Enter Item ID to remove: ");
                scanf("%d", &id);
                removeItem(&myWarehouse, id);
                break;
            case 3:
                printf("Enter Item ID to update: ");
                scanf("%d", &id);
                printf("Enter New Quantity: ");
                scanf("%d", &quantity);
                updateQuantity(&myWarehouse, id, quantity);
                break;
            case 4:
                printf("Enter Item Name to search: ");
                scanf("%s", name);
                searchItem(&myWarehouse, name);
                break;
            case 5:
                printInventory(&myWarehouse);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}