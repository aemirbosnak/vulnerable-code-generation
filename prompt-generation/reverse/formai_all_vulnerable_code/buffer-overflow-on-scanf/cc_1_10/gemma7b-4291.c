//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 100

typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEM_NUM];

void display_menu() {
    printf("**Medical Store Management System**\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Update Quantity\n");
    printf("4. View Items\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void add_item() {
    Item new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);
    printf("Enter item price: ");
    scanf("%f", &new_item.price);

    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        if (items[i].name[0] == '\0') {
            items[i] = new_item;
            break;
        }
    }
}

void remove_item() {
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            items[i].name[0] = '\0';
            break;
        }
    }
}

void update_quantity() {
    char item_name[50];
    int new_quantity;
    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &new_quantity);
            items[i].quantity = new_quantity;
            break;
        }
    }
}

void view_items() {
    printf("Items:\n");
    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    int choice;

    display_menu();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            remove_item();
            break;
        case 3:
            update_quantity();
            break;
        case 4:
            view_items();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}