//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: secure
// Cafe Billing System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for items in the cafe menu
typedef struct {
    char name[30];
    float price;
} menu_item;

// Structure for a customer order
typedef struct {
    menu_item* items[10];
    int num_items;
    float total_price;
} order;

// Function to add an item to an order
void add_item(order* o, menu_item* item) {
    o->items[o->num_items++] = item;
    o->total_price += item->price;
}

// Function to calculate the total price of an order
float calculate_total(order* o) {
    float total = 0;
    for (int i = 0; i < o->num_items; i++) {
        total += o->items[i]->price;
    }
    return total;
}

// Function to print a customer's order
void print_order(order* o) {
    printf("Customer Order:\n");
    for (int i = 0; i < o->num_items; i++) {
        printf("  %s: $%.2f\n", o->items[i]->name, o->items[i]->price);
    }
    printf("Total: $%.2f\n", o->total_price);
}

int main() {
    // Define the cafe menu
    menu_item menu[] = {
        {"Coffee", 3.50},
        {"Tea", 2.50},
        {"Cappuccino", 4.50},
        {"Latte", 4.00},
        {"Mocha", 5.00},
        {"Espresso", 3.00}
    };
    int num_menu_items = sizeof(menu) / sizeof(menu_item);

    // Create an order
    order o = {NULL, 0, 0};

    // Add items to the order
    add_item(&o, &menu[0]);
    add_item(&o, &menu[1]);
    add_item(&o, &menu[2]);

    // Calculate the total price of the order
    float total = calculate_total(&o);

    // Print the order
    print_order(&o);

    return 0;
}