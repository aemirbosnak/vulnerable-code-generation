//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in an order
#define MAX_ITEMS 10

// Define the structure of an item
typedef struct item {
    char name[50];
    int quantity;
    float price;
} item;

// Define the structure of an order
typedef struct order {
    int num_items;
    item items[MAX_ITEMS];
} order;

// Define the structure of a table
typedef struct table {
    int table_number;
    order order;
} table;

// Define the structure of the cafe
typedef struct cafe {
    int num_tables;
    table tables[10];
} cafe;

// Create a new cafe
cafe create_cafe() {
    cafe cafe;
    cafe.num_tables = 0;
    return cafe;
}

// Add a new table to the cafe
void add_table(cafe *cafe, int table_number) {
    cafe->tables[cafe->num_tables].table_number = table_number;
    cafe->num_tables++;
}

// Add an item to an order
void add_item(order *order, char *name, int quantity, float price) {
    strcpy(order->items[order->num_items].name, name);
    order->items[order->num_items].quantity = quantity;
    order->items[order->num_items].price = price;
    order->num_items++;
}

// Calculate the total price of an order
float calculate_total(order *order) {
    float total = 0;
    for (int i = 0; i < order->num_items; i++) {
        total += order->items[i].quantity * order->items[i].price;
    }
    return total;
}

// Print the order
void print_order(order *order) {
    for (int i = 0; i < order->num_items; i++) {
        printf("%s x%d: $%.2f\n", order->items[i].name, order->items[i].quantity, order->items[i].price);
    }
}

// Main function
int main() {
    // Create a new cafe
    cafe cafe = create_cafe();

    // Add some tables to the cafe
    add_table(&cafe, 1);
    add_table(&cafe, 2);
    add_table(&cafe, 3);

    // Add some items to the order for table 1
    order order1 = cafe.tables[0].order;
    add_item(&order1, "Coffee", 1, 2.50);
    add_item(&order1, "Tea", 1, 1.50);
    add_item(&order1, "Cake", 1, 3.00);

    // Print the order for table 1
    printf("Order for table 1:\n");
    print_order(&order1);

    // Calculate the total price of the order for table 1
    float total1 = calculate_total(&order1);
    printf("Total: $%.2f\n", total1);

    return 0;
}