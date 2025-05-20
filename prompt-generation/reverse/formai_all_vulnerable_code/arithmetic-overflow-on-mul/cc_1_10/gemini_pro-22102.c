//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <string.h>

// Define item structure
struct Item {
    char name[50];
    int price;
    int quantity;
};

// Define order structure
struct Order {
    int table_number;
    struct Item items[10];
    int num_items;
    int total_amount;
};

// Function to add item to order
void add_item(struct Order *order, struct Item item) {
    order->items[order->num_items] = item;
    order->num_items++;
}

// Function to calculate total amount of order
int calculate_total(struct Order order) {
    int total = 0;
    for (int i = 0; i < order.num_items; i++) {
        total += order.items[i].price * order.items[i].quantity;
    }
    return total;
}

// Function to print order
void print_order(struct Order order) {
    printf("Table Number: %d\n", order.table_number);
    printf("---------------------------------------\n");
    printf("Item Name                Price    Quantity       Amount\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < order.num_items; i++) {
        printf("%-20s    %6d    %8d    %8d\n", order.items[i].name, order.items[i].price, order.items[i].quantity, order.items[i].price * order.items[i].quantity);
    }
    printf("---------------------------------------\n");
    printf("Total Amount: %d\n", order.total_amount);
}

// Main function
int main() {
    // Create an order
    struct Order order;
    order.table_number = 1;
    order.num_items = 0;
    order.total_amount = 0;

    // Add items to the order
    struct Item item1;
    strcpy(item1.name, "Pizza");
    item1.price = 100;
    item1.quantity = 1;
    add_item(&order, item1);

    struct Item item2;
    strcpy(item2.name, "Burger");
    item2.price = 75;
    item2.quantity = 2;
    add_item(&order, item2);

    struct Item item3;
    strcpy(item3.name, "Fries");
    item3.price = 25;
    item3.quantity = 3;
    add_item(&order, item3);

    // Calculate total amount
    order.total_amount = calculate_total(order);

    // Print the order
    print_order(order);

    return 0;
}