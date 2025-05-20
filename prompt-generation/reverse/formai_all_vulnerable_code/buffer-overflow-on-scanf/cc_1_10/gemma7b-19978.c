//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[20];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEMS];

void add_item() {
    Item new_item;

    printf("Enter item name: ");
    scanf("%s", new_item.name);

    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);

    printf("Enter item price: ");
    scanf("%lf", &new_item.price);

    items[MAX_ITEMS - 1] = new_item;
}

void list_items() {
    int i;

    printf("Items:\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - %d - %.2lf\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

void update_item() {
    char item_name[20];

    printf("Enter item name: ");
    scanf("%s", item_name);

    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);

            printf("Enter new item price: ");
            scanf("%lf", &items[i].price);

            break;
        }
    }

    if (i == MAX_ITEMS) {
        printf("Item not found.\n");
    }
}

void remove_item() {
    char item_name[20];

    printf("Enter item name: ");
    scanf("%s", item_name);

    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            items[i].name[0] = '\0';
            items[i].quantity = 0;
            items[i].price = 0.0;

            break;
        }
    }

    if (i == MAX_ITEMS) {
        printf("Item not found.\n");
    }
}

int main() {
    int choice;

    printf("Inventory Management System\n");
    printf("1. Add Item\n");
    printf("2. List Items\n");
    printf("3. Update Item\n");
    printf("4. Remove Item\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            list_items();
            break;
        case 3:
            update_item();
            break;
        case 4:
            remove_item();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}