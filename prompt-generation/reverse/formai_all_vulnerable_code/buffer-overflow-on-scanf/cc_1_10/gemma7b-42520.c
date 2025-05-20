//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void display_items() {
    int i = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity > 0) {
            printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

void add_item() {
    Item new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.name);

    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);

    printf("Enter item price: ");
    scanf("%f", &new_item.price);

    int i = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity == 0) {
            strcpy(items[i].name, new_item.name);
            items[i].quantity = new_item.quantity;
            items[i].price = new_item.price;
            return;
        }
    }

    printf("Error: item limit reached.\n");
}

void update_item() {
    char item_name[20];
    printf("Enter item name: ");
    scanf("%s", item_name);

    int i = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);

            printf("Enter new price: ");
            scanf("%f", &items[i].price);

            return;
        }
    }

    printf("Error: item not found.\n");
}

void delete_item() {
    char item_name[20];
    printf("Enter item name: ");
    scanf("%s", item_name);

    int i = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            items[i].quantity = 0;

            return;
        }
    }

    printf("Error: item not found.\n");
}

int main() {
    int choice;

    printf("Welcome to the C Medical Store Management System!\n");

    printf("1. Display Items\n");
    printf("2. Add Item\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            display_items();
            break;
        case 2:
            add_item();
            break;
        case 3:
            update_item();
            break;
        case 4:
            delete_item();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}