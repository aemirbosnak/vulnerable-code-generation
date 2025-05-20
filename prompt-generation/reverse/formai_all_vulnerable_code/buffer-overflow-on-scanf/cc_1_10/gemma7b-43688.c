//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX];

void add_item() {
    Item item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter item price: ");
    scanf("%f", &item.price);

    for (int i = 0; i < MAX; i++) {
        if (items[i].name == NULL) {
            items[i] = item;
            break;
        }
    }
}

void update_item() {
    char name[20];
    printf("Enter item name: ");
    scanf("%s", name);

    for (int i = 0; i < MAX; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new item price: ");
            scanf("%f", &items[i].price);
            break;
        }
    }
}

void list_items() {
    for (int i = 0; i < MAX; i++) {
        if (items[i].name) {
            printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    int choice;

    printf("Enter 1 to add item, 2 to update item, 3 to list items: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            update_item();
            break;
        case 3:
            list_items();
            break;
        default:
            printf("Invalid input.");
    }

    return 0;
}