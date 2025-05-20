//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME 50
#define MAX_PRICE 10

struct item {
    char name[MAX_NAME];
    float price;
};

struct order {
    int num_items;
    struct item items[MAX_ITEMS];
};

void add_item(struct item items[], int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[*num_items].price);
    (*num_items)++;
}

void display_items(struct item items[], int num_items) {
    printf("\nItems:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - %.2f\n", items[i].name, items[i].price);
    }
}

void add_order(struct order *order) {
    printf("\nEnter number of items in the order: ");
    scanf("%d", &order->num_items);
    for (int i = 0; i < order->num_items; i++) {
        printf("Enter item name: ");
        scanf("%s", order->items[i].name);
        printf("Enter item price: ");
        scanf("%f", &order->items[i].price);
    }
}

void display_order(struct order order) {
    printf("\nOrder:\n");
    printf("Number of items: %d\n", order.num_items);
    for (int i = 0; i < order.num_items; i++) {
        printf("%s - %.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total price: %.2f\n", order.items[0].price * order.num_items);
}

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;

    add_item(items, &num_items);
    add_item(items, &num_items);
    add_item(items, &num_items);

    display_items(items, num_items);

    struct order order;
    add_order(&order);

    display_order(order);

    return 0;
}