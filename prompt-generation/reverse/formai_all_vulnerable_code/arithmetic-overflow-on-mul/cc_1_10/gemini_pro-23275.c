//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Item structure
struct Item {
    char name[50];
    int price;
    int quantity;
};

// Order structure
struct Order {
    struct Item items[100];
    int num_items;
    int total_price;
};

// Function to create an item
struct Item create_item(char *name, int price, int quantity) {
    struct Item item;
    strcpy(item.name, name);
    item.price = price;
    item.quantity = quantity;
    return item;
}

// Function to add an item to an order
void add_item_to_order(struct Order *order, struct Item item) {
    order->items[order->num_items] = item;
    order->num_items++;
    order->total_price += item.price * item.quantity;
}

// Function to print an order
void print_order(struct Order order) {
    printf("Order:\n");
    for (int i = 0; i < order.num_items; i++) {
        printf("%s x%d: $%d\n", order.items[i].name, order.items[i].quantity, order.items[i].price * order.items[i].quantity);
    }
    printf("Total: $%d\n", order.total_price);
}

int main() {
    // Create an order
    struct Order order;
    order.num_items = 0;
    order.total_price = 0;

    // Add items to the order
    add_item_to_order(&order, create_item("Coffee", 2, 1));
    add_item_to_order(&order, create_item("Tea", 3, 2));
    add_item_to_order(&order, create_item("Cake", 5, 1));

    // Print the order
    print_order(order);

    return 0;
}