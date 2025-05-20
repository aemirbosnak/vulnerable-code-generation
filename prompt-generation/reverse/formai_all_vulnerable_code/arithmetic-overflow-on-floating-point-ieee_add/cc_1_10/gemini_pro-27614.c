//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    int num_items;
    Item *items;
    float total_price;
} Order;

Order *create_order() {
    Order *order = malloc(sizeof(Order));
    order->num_items = 0;
    order->items = NULL;
    order->total_price = 0.0;
    return order;
}

void destroy_order(Order *order) {
    if (order->items != NULL) {
        free(order->items);
    }
    free(order);
}

void add_item_to_order(Order *order, Item item) {
    order->num_items++;
    order->items = realloc(order->items, sizeof(Item) * order->num_items);
    order->items[order->num_items - 1] = item;
}

void print_order(Order *order) {
    printf("Order Summary:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s x%d @ $%.2f\n", order->items[i].name, order->items[i].quantity, order->items[i].price);
    }
    printf("Total: $%.2f\n", order->total_price);
}

int main() {
    Order *order = create_order();

    Item item1 = {"Latte", 2, 3.50};
    add_item_to_order(order, item1);

    Item item2 = {"Cappuccino", 1, 4.00};
    add_item_to_order(order, item2);

    Item item3 = {"Pastry", 1, 2.50};
    add_item_to_order(order, item3);

    order->total_price = 0.0;
    for (int i = 0; i < order->num_items; i++) {
        order->total_price += order->items[i].quantity * order->items[i].price;
    }

    print_order(order);

    destroy_order(order);

    return 0;
}