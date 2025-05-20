//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 6
#define MAX_QUANTITY_LEN 3

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
    float total;
} item_t;

typedef struct {
    int num_items;
    item_t items[MAX_ITEMS];
} order_t;

void init_order(order_t *order) {
    order->num_items = 0;
}

void add_item(order_t *order, char *name, char *price, int quantity) {
    if (order->num_items >= MAX_ITEMS) {
        printf("Error: Order is full.\n");
        return;
    }

    item_t *new_item = &order->items[order->num_items];
    strncpy(new_item->name, name, MAX_NAME_LEN);
    strncpy(new_item->price, price, MAX_PRICE_LEN);
    new_item->quantity = quantity;
    new_item->total = (float)quantity * atof(price);

    order->num_items++;
}

void print_order(order_t *order) {
    if (order->num_items == 0) {
        printf("Order is empty.\n");
        return;
    }

    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s - $%s x %d = $%.2f\n", order->items[i].name, order->items[i].price, order->items[i].quantity, order->items[i].total);
    }
}

void clear_order(order_t *order) {
    order->num_items = 0;
}

int main() {
    order_t order;
    init_order(&order);

    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;

    while (1) {
        printf("Enter item name: ");
        scanf("%s", name);

        printf("Enter item price: ");
        scanf("%s", price);

        printf("Enter item quantity: ");
        scanf("%d", &quantity);

        add_item(&order, name, price, quantity);
    }

    return 0;
}