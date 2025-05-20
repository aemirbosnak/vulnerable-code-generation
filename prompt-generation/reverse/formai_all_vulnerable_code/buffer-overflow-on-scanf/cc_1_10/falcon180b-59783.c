//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the item structure
typedef struct {
    char name[50];
    float price;
} Item;

// Define the order structure
typedef struct {
    int num_items;
    Item items[MAX_ITEMS];
} Order;

// Function to add an item to the order
void add_item(Order* order, char* name, float price) {
    if (order->num_items >= MAX_ITEMS) {
        printf("Sorry, you can only order up to %d items.\n", MAX_ITEMS);
        return;
    }

    strncpy(order->items[order->num_items].name, name, 50);
    order->items[order->num_items].price = price;
    order->num_items++;
}

// Function to calculate the total cost of the order
float calculate_total(Order* order) {
    float total = 0;

    for (int i = 0; i < order->num_items; i++) {
        total += order->items[i].price;
    }

    return total;
}

// Function to print the order details
void print_order(Order* order) {
    printf("Order details:\n");

    for (int i = 0; i < order->num_items; i++) {
        printf("Item %d: %s - $%.2f\n", i+1, order->items[i].name, order->items[i].price);
    }

    printf("Total cost: $%.2f\n", calculate_total(order));
}

// Function to simulate a cafe ordering system
int main() {
    char item_name[50];
    float item_price;

    Order order = {0};

    while (1) {
        printf("Welcome to the Retro Cafe!\n");
        printf("Please enter the name of the item you would like to order: ");
        scanf("%s", item_name);

        printf("Please enter the price of the item: $");
        scanf("%f", &item_price);

        add_item(&order, item_name, item_price);

        printf("Would you like to order another item? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice!= 'y') {
            break;
        }
    }

    print_order(&order);

    return 0;
}