//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *w) {
    w->count = 0;
}

void addItem(Warehouse *w, int id, const char *name, int quantity) {
    if (w->count < MAX_ITEMS) {
        w->items[w->count].id = id;
        strncpy(w->items[w->count].name, name, NAME_LENGTH); 
        w->items[w->count].quantity = quantity;
        w->count++;
        printf("Added item: %s (ID: %d, Quantity: %d)\n", name, id, quantity);
    } else {
        printf("Error: Warehouse is full.\n");
    }
}

void removeItem(Warehouse *w, int id) {
    for (int i = 0; i < w->count; i++) {
        if (w->items[i].id == id) {
            printf("Removing item: %s (ID: %d)\n", w->items[i].name, id);
            for (int j = i; j < w->count - 1; j++) {
                w->items[j] = w->items[j + 1];
            }
            w->count--;
            return;
        }
    }
    printf("Error: Item with ID %d not found.\n", id);
}

void updateItemQuantity(Warehouse *w, int id, int quantity) {
    for (int i = 0; i < w->count; i++) {
        if (w->items[i].id == id) {
            w->items[i].quantity = quantity;
            printf("Updated item (ID: %d) quantity to: %d\n", id, quantity);
            return;
        }
    }
    printf("Error: Item with ID %d not found.\n", id);
}

void listItems(const Warehouse *w) {
    if (w->count == 0) {
        printf("No items in warehouse.\n");
        return;
    }
    printf("Items in Warehouse:\n");
    for (int i = 0; i < w->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", w->items[i].id, w->items[i].name, w->items[i].quantity);
    }
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Item Quantity\n");
        printf("4. List Items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id, quantity;
                char name[NAME_LENGTH];
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                addItem(&warehouse, id, name, quantity);
                break;
            }
            case 2: {
                int id;
                printf("Enter item ID to remove: ");
                scanf("%d", &id);
                removeItem(&warehouse, id);
                break;
            }
            case 3: {
                int id, quantity;
                printf("Enter item ID to update: ");
                scanf("%d", &id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateItemQuantity(&warehouse, id, quantity);
                break;
            }
            case 4: {
                listItems(&warehouse);
                break;
            }
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}