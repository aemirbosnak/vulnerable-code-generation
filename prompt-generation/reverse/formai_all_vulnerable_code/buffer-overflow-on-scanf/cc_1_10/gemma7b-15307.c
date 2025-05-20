//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void display_items() {
    int i = 0;
    for (i = 0; items[i].name[0] != '\0'; i++) {
        printf("%s: %d, $%.2f\n", items[i].name, items[i].quantity, items[i].price);
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
    items[MAX_ITEMS - 1] = new_item;
}

void update_item() {
    char item_name[50];
    int quantity;
    float price;
    printf("Enter item name: ");
    scanf("%s", item_name);
    for (int i = 0; items[i].name[0] != '\0'; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            printf("Enter new item quantity: ");
            scanf("%d", &quantity);
            printf("Enter new item price: ");
            scanf("%f", &price);
            items[i].quantity = quantity;
            items[i].price = price;
            break;
        }
    }
}

void delete_item() {
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);
    for (int i = 0; items[i].name[0] != '\0'; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            items[i].name[0] = '\0';
            items[i].quantity = 0;
            items[i].price = 0.0f;
            break;
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the C Medical Store Management System!\n");
    printf("Please select an option:\n");
    printf("1. Display Items\n");
    printf("2. Add Item\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
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
            printf("Invalid input.\n");
    }

    return 0;
}