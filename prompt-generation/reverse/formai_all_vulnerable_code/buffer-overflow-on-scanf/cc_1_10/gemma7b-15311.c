//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void displayItems() {
    int i = 0;
    printf("Items:\n");
    for (i = 0; items[i].name[0] != '\0'; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void addItem() {
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    int i = 0;
    for (i = 0; items[i].name[0] != '\0'; i++) {
        if (strcmp(newItem.name, items[i].name) == 0) {
            items[i].quantity += newItem.quantity;
            return;
        }
    }

    items[i] = newItem;
}

void updateItem() {
    char itemName[20];
    printf("Enter item name: ");
    scanf("%s", itemName);

    int i = 0;
    for (i = 0; items[i].name[0] != '\0'; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new item price: ");
            scanf("%f", &items[i].price);
            return;
        }
    }

    printf("Item not found.\n");
}

void removeItem() {
    char itemName[20];
    printf("Enter item name: ");
    scanf("%s", itemName);

    int i = 0;
    for (i = 0; items[i].name[0] != '\0'; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            items[i].quantity = 0;
            return;
        }
    }

    printf("Item not found.\n");
}

int main() {
    int choice;

    printf("Medical Store Management System\n");
    printf("1. Display Items\n");
    printf("2. Add Item\n");
    printf("3. Update Item\n");
    printf("4. Remove Item\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            displayItems();
            break;
        case 2:
            addItem();
            break;
        case 3:
            updateItem();
            break;
        case 4:
            removeItem();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}