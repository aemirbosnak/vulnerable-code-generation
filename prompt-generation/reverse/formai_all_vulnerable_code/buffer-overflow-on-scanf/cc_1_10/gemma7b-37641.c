//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUMBER 100

typedef struct Item {
    char item_name[50];
    int item_quantity;
    float item_price;
} Item;

Item items[MAX_ITEM_NUMBER];

void add_item() {
    Item new_item;

    printf("Enter item name: ");
    scanf("%s", new_item.item_name);

    printf("Enter item quantity: ");
    scanf("%d", &new_item.item_quantity);

    printf("Enter item price: ");
    scanf("%f", &new_item.item_price);

    int i = 0;
    for (; items[i].item_name[0] != '\0'; i++) {}

    items[i] = new_item;
}

void update_item_quantity(char *item_name, int quantity) {
    for (int i = 0; items[i].item_name[0] != '\0'; i++) {
        if (strcmp(items[i].item_name, item_name) == 0) {
            items[i].item_quantity = quantity;
        }
    }
}

void print_items() {
    for (int i = 0; items[i].item_name[0] != '\0'; i++) {
        printf("%s: %d, $%.2f\n", items[i].item_name, items[i].item_quantity, items[i].item_price);
    }
}

int main() {
    add_item();
    add_item();
    add_item();

    update_item_quantity("Item 1", 10);

    print_items();

    return 0;
}