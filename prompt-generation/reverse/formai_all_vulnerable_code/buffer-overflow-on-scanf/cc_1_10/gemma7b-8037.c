//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEMS];

void add_item() {
    Item item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter item price: ");
    scanf("%lf", &item.price);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name == NULL) {
            items[i] = item;
            break;
        }
    }
}

void update_item(char name) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new item price: ");
            scanf("%lf", &items[i].price);
            break;
        }
    }
}

void list_items() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name != NULL) {
            printf("%s - %d - %.2lf\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    add_item();
    add_item();
    update_item("Item 1");
    list_items();

    return 0;
}