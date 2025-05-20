//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: energetic
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

void add_item() {
    Item item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter item price: ");
    scanf("%f", &item.price);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] == '\0') {
            items[i] = item;
            break;
        }
    }
}

void update_item(char *name) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new item price: ");
            scanf("%f", &items[i].price);
            break;
        }
    }
}

void remove_item(char *name) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].name[0] = '\0';
            break;
        }
    }
}

void list_items() {
    for (int i = 0; items[i].name[0] != '\0'; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    add_item();
    add_item();
    update_item("Item 1");
    remove_item("Item 2");
    list_items();

    return 0;
}