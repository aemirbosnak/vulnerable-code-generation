//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct item {
    char name[32];
    int price;
    int quantity;
};

struct order {
    struct item items[100];
    int num_items;
    float total;
};

void add_item(struct order *order, struct item item) {
    order->items[order->num_items] = item;
    order->num_items++;
    order->total += item.price * item.quantity;
}

void print_order(struct order order) {
    printf("Order Summary:\n");
    for (int i = 0; i < order.num_items; i++) {
        struct item item = order.items[i];
        printf("%s x %d: $%.2f\n", item.name, item.quantity, item.price * item.quantity);
    }
    printf("Total: $%.2f\n", order.total);
}

int main() {
    struct order order;
    order.num_items = 0;
    order.total = 0.0;

    while (1) {
        printf("Enter item name (or q to quit): ");
        char name[32];
        scanf("%s", name);

        if (strcmp(name, "q") == 0) {
            break;
        }

        printf("Enter item price: ");
        int price;
        scanf("%d", &price);

        printf("Enter item quantity: ");
        int quantity;
        scanf("%d", &quantity);

        struct item item;
        strcpy(item.name, name);
        item.price = price;
        item.quantity = quantity;

        add_item(&order, item);
    }

    print_order(order);

    return 0;
}