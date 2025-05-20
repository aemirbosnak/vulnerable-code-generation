//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// define the maximum number of items in the menu
#define MAX_ITEMS 100

// define the structure of a menu item
typedef struct {
    char name[50];
    double price;
} Item;

// define the structure of a customer order
typedef struct {
    char name[50];
    int num_items;
    Item items[MAX_ITEMS];
} Order;

// function to add an item to the order
void add_item(Order* order, char* name, double price) {
    int i;
    for (i = 0; i < order->num_items; i++) {
        if (strcmp(order->items[i].name, name) == 0) { // item already exists in the order
            order->items[i].price += price;
            return;
        }
    }
    strcpy(order->items[i].name, name);
    order->items[i].price = price;
    order->num_items++;
}

// function to calculate the total price of the order
double get_total(Order* order) {
    double total = 0.0;
    int i;
    for (i = 0; i < order->num_items; i++) {
        total += order->items[i].price;
    }
    return total;
}

// function to print the order details
void print_order(Order* order) {
    printf("Customer name: %s\n", order->name);
    printf("Number of items: %d\n", order->num_items);
    printf("Items:\n");
    int i;
    for (i = 0; i < order->num_items; i++) {
        printf("%s: $%.2f\n", order->items[i].name, order->items[i].price);
    }
    printf("Total price: $%.2f\n", get_total(order));
}

// main function
int main() {
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    // initialize the order
    Order order;
    strcpy(order.name, name);
    order.num_items = 0;

    // add items to the order
    add_item(&order, "Coffee", 2.50);
    add_item(&order, "Cake", 3.99);
    add_item(&order, "Sandwich", 4.99);

    // print the order details
    print_order(&order);

    return 0;
}