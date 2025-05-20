//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

int item_count = 0;

void add_item() {
    Item new_item;

    printf("Enter item name: ");
    scanf("%s", new_item.name);

    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);

    printf("Enter item price: ");
    scanf("%f", &new_item.price);

    items[item_count++] = new_item;
}

void list_items() {
    int i;

    printf("Items:\n");
    for (i = 0; i < item_count; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void update_item(char *name) {
    int i;

    for (i = 0; i < item_count; i++) {
        if (strcmp(name, items[i].name) == 0) {
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
    int i;

    for (i = 0; i < item_count; i++) {
        if (strcmp(name, items[i].name) == 0) {
            items[i] = items[item_count - 1];
            item_count--;

            return;
        }
    }

    printf("Item not found.\n");
}

int main() {
    int choice;

    printf("Welcome to the C Medical Store Management System.\n");

    while (1) {
        printf("1. Add Item\n");
        printf("2. List Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
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
                update_item("Item Name");
                break;
            case 4:
                delete_item("Item Name");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}