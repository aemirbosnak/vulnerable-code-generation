//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: grateful
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

void add_item() {
    Item item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter item price: ");
    scanf("%f", &item.price);
    items[MAX_ITEMS - 1] = item;
}

void list_items() {
    int i = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s: %d, $%.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

void update_item(char *name) {
    int i = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new item price: ");
            scanf("%f", &items[i].price);
            return;
        }
    }
    printf("Item not found.\n");
}

void delete_item(char *name) {
    int i = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].name[0] = '\0';
            items[i].quantity = 0;
            items[i].price = 0.0f;
            return;
        }
    }
    printf("Item not found.\n");
}

int main() {
    int choice;
    char name[20];

    printf("Welcome to the Warehouse Management System!\n");
    printf("Please select an option:**\n");
    printf("1. Add Item\n");
    printf("2. List Items\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            list_items();
            break;
        case 3:
            printf("Enter item name: ");
            scanf("%s", name);
            update_item(name);
            break;
        case 4:
            printf("Enter item name: ");
            scanf("%s", name);
            delete_item(name);
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}