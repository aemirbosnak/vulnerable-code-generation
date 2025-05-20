//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEMS];

void display_items() {
    int i = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity > 0) {
            printf("%s - %d - $%.2lf\n", items[i].name, items[i].quantity, items[i].price);
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
    scanf("%lf", &new_item.price);

    int i = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity == 0) {
            items[i] = new_item;
            break;
        }
    }

    if (i == MAX_ITEMS) {
        printf("Error: Inventory full.\n");
    }
}

void remove_item() {
    char item_name[20];
    printf("Enter item name: ");
    scanf("%s", item_name);

    int i = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            items[i].quantity = 0;
            break;
        }
    }

    if (i == MAX_ITEMS) {
        printf("Error: Item not found.\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the Post-Apocalyptic Medical Store!\n");

    while (1) {
        printf("1. Display Items\n");
        printf("2. Add Item\n");
        printf("3. Remove Item\n");
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
                remove_item();
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}