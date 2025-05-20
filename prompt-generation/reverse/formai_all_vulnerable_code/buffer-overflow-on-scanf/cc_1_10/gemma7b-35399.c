//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: multiplayer
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

void addItem(char *name, int quantity, double price) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity == 0) {
            strcpy(items[i].name, name);
            items[i].quantity = quantity;
            items[i].price = price;
            return;
        }
    }

    printf("Error: Inventory full!\n");
}

void updateItemQuantity(char *name, int quantity) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity = quantity;
            return;
        }
    }

    printf("Error: Item not found!\n");
}

void removeItem(char *name) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity = 0;
            return;
        }
    }

    printf("Error: Item not found!\n");
}

int main() {
    int choice;
    char name[50];
    int quantity;
    double price;

    displayItems();

    printf("Enter your choice:\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter item name:");
            scanf("%s", name);
            printf("Enter item quantity:");
            scanf("%d", &quantity);
            printf("Enter item price:");
            scanf("%lf", &price);
            addItem(name, quantity, price);
            break;
        case 2:
            printf("Enter item name:");
            scanf("%s", name);
            printf("Enter new item quantity:");
            scanf("%d", &quantity);
            updateItemQuantity(name, quantity);
            break;
        case 3:
            printf("Enter item name:");
            scanf("%s", name);
            removeItem(name);
            break;
        default:
            printf("Invalid choice!\n");
    }

    displayItems();

    return 0;
}