//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEMS];

void displayItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity > 0) {
            printf("%s - %d - %.2lf\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

void addItem() {
    Item newItem;

    printf("Enter item name: ");
    scanf("%s", newItem.name);

    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter item price: ");
    scanf("%lf", &newItem.price);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity == 0) {
            items[i] = newItem;
            break;
        }
    }

    printf("Item added successfully!\n");
}

void updateItemQuantity(char *itemName) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Item quantity updated successfully!\n");
            break;
        }
    }
}

void removeItem(char *itemName) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            items[i].quantity = 0;
            printf("Item removed successfully!\n");
            break;
        }
    }
}

int main() {
    int choice;

    displayItems();

    printf("Enter 1 to add item, 2 to update item quantity, 3 to remove item: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addItem();
            break;
        case 2:
            updateItemQuantity("Item Name");
            break;
        case 3:
            removeItem("Item Name");
            break;
        default:
            printf("Invalid input.\n");
    }

    displayItems();

    return 0;
}