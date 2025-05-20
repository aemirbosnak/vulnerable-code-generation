//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: interoperable
#include <stdio.h>

struct item {
    char name[50];
    int quantity;
    float price;
};

struct order {
    int num_items;
    struct item items[10];
};

void add_item(struct order *order, struct item item) {
    order->items[order->num_items] = item;
    order->num_items++;
}

void print_order(struct order order) {
    printf("Order Summary:\n");
    for (int i = 0; i < order.num_items; i++) {
        printf("%s %d %.2f\n", order.items[i].name, order.items[i].quantity, order.items[i].price);
    }
}

float calculate_total(struct order order) {
    float total = 0;
    for (int i = 0; i < order.num_items; i++) {
        total += order.items[i].quantity * order.items[i].price;
    }
    return total;
}

int main() {
    struct order order;
    order.num_items = 0;

    // Add some items to the order
    struct item item1 = {"Coffee", 1, 2.50};
    add_item(&order, item1);

    struct item item2 = {"Tea", 2, 1.50};
    add_item(&order, item2);

    struct item item3 = {"Cake", 1, 3.00};
    add_item(&order, item3);

    // Print the order summary
    print_order(order);

    // Calculate the total amount
    float total = calculate_total(order);
    printf("Total: %.2f\n", total);

    return 0;
}