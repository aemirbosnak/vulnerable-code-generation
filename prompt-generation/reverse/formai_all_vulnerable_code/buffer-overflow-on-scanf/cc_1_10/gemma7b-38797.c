//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: introspective
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
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity > 0) {
            printf("%s: %d, $%.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

void add_item() {
    char name[20];
    int quantity;
    float price;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    printf("Enter item price: ");
    scanf("%f", &price);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity += quantity;
            return;
        }
    }

    Item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    new_item.price = price;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity == 0) {
            strcpy(items[i].name, new_item.name);
            items[i].quantity = new_item.quantity;
            items[i].price = new_item.price;
            return;
        }
    }

    printf("Error: no space for new item.\n");
}

void remove_item() {
    char name[20];

    printf("Enter item name: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity = 0;
            return;
        }
    }

    printf("Item not found.\n");
}

int main() {
    int choice;

    printf("Welcome to the C Medical Store Management System!\n");

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
                printf("Invalid choice.\n");
                break;
        }

        printf("Please press any key to continue...");
        getchar();
    }

    return 0;
}