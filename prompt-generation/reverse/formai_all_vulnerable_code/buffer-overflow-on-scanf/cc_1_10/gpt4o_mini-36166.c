//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
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

int addItem(Warehouse *w, const char *name, int quantity) {
    if (w->count >= MAX_ITEMS) {
        return -1; // Warehouse is full
    }
    strcpy(w->items[w->count].name, name);
    w->items[w->count].quantity = quantity;
    w->count++;
    return 0; // Item added successfully
}

int removeItem(Warehouse *w, const char *name) {
    for (int i = 0; i < w->count; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            for (int j = i; j < w->count - 1; j++) {
                w->items[j] = w->items[j + 1]; // Shift items left
            }
            w->count--;
            return 0; // Item removed successfully
        }
    }
    return -1; // Item not found
}

void displayItems(const Warehouse *w) {
    if (w->count == 0) {
        printf("Warehouse is empty!\n");
        return;
    }
    printf("Items in the warehouse:\n");
    for (int i = 0; i < w->count; i++) {
        printf("Item: %s, Quantity: %d\n", w->items[i].name, w->items[i].quantity);
    }
}

int updateItemQuantity(Warehouse *w, const char *name, int quantity) {
    for (int i = 0; i < w->count; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            w->items[i].quantity = quantity;
            return 0; // Quantity updated successfully
        }
    }
    return -1; // Item not found
}

void sortItems(Warehouse *w) {
    for (int i = 0; i < w->count - 1; i++) {
        for (int j = 0; j < w->count - i - 1; j++) {
            if (strcmp(w->items[j].name, w->items[j + 1].name) > 0) {
                Item temp = w->items[j];
                w->items[j] = w->items[j + 1];
                w->items[j + 1] = temp;
            }
        }
    }
}

void menu() {
    printf("\n--- Warehouse Management System ---\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Update Item Quantity\n");
    printf("4. Display Items\n");
    printf("5. Sort Items\n");
    printf("6. Exit\n");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice = 0;
    char name[NAME_LENGTH];
    int quantity;

    while (choice != 6) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                if (addItem(&warehouse, name, quantity) == 0) {
                    printf("Item added successfully!\n");
                } else {
                    printf("Warehouse is full!\n");
                }
                break;
            case 2:
                printf("Enter item name to remove: ");
                scanf("%s", name);
                if (removeItem(&warehouse, name) == 0) {
                    printf("Item removed successfully!\n");
                } else {
                    printf("Item not found!\n");
                }
                break;
            case 3:
                printf("Enter item name to update quantity: ");
                scanf("%s", name);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                if (updateItemQuantity(&warehouse, name, quantity) == 0) {
                    printf("Quantity updated successfully!\n");
                } else {
                    printf("Item not found!\n");
                }
                break;
            case 4:
                displayItems(&warehouse);
                break;
            case 5:
                sortItems(&warehouse);
                printf("Items sorted alphabetically!\n");
                break;
            case 6:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}