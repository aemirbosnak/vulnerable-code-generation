//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct item {
    char name[50];
    float price;
    int quantity;
};

struct order {
    struct item items[10];
    int num_items;
    float total;
};

void add_item(struct order *order, struct item *item) {
    order->items[order->num_items] = *item;
    order->num_items++;
    order->total += item->price * item->quantity;
}

void print_order(struct order *order) {
    printf("Order Summary:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s x %d @ %.2f = %.2f\n", order->items[i].name, order->items[i].quantity, order->items[i].price, order->items[i].price * order->items[i].quantity);
    }
    printf("Total: %.2f\n", order->total);
}

int main() {
    struct order order;
    order.num_items = 0;
    order.total = 0.0;

    struct item item1;
    strcpy(item1.name, "Coffee");
    item1.price = 2.50;
    item1.quantity = 2;
    add_item(&order, &item1);

    struct item item2;
    strcpy(item2.name, "Tea");
    item2.price = 1.50;
    item2.quantity = 1;
    add_item(&order, &item2);

    print_order(&order);

    return 0;
}