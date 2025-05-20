//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

// Define the structure for each item
typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_PRICE_LEN];
    float price;
} Item;

// Define the structure for the order
typedef struct {
    int num_items;
    Item items[MAX_ITEMS];
} Order;

// Function to add an item to the order
void add_item(Order* order) {
    printf("Enter the name of the item: ");
    scanf("%s", order->items[order->num_items].name);
    printf("Enter the description of the item: ");
    scanf("%s", order->items[order->num_items].description);
    printf("Enter the price of the item: ");
    scanf("%f", &order->items[order->num_items].price);
    order->num_items++;
}

// Function to display the order
void display_order(Order* order) {
    printf("Order details:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("Item %d:\n", i+1);
        printf("Name: %s\n", order->items[i].name);
        printf("Description: %s\n", order->items[i].description);
        printf("Price: $%.2f\n\n", order->items[i].price);
    }
}

// Function to calculate the total price of the order
float calculate_total(Order* order) {
    float total = 0.0;
    for (int i = 0; i < order->num_items; i++) {
        total += order->items[i].price;
    }
    return total;
}

int main() {
    // Create an order object
    Order order;
    order.num_items = 0;

    // Add items to the order
    add_item(&order);
    add_item(&order);
    add_item(&order);

    // Display the order
    display_order(&order);

    // Calculate the total price of the order
    float total = calculate_total(&order);

    // Display the total price
    printf("Total price: $%.2f\n", total);

    return 0;
}