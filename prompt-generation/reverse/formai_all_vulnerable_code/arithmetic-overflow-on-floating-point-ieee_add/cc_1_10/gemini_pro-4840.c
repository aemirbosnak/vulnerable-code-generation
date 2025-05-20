//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of each item in the cafe menu
typedef struct Item {
    char name[50];
    float price;
} Item;

// Structure to store the details of each order placed by a customer
typedef struct Order {
    int order_id;
    char customer_name[50];
    int num_items;
    Item items[10];
    float total_price;
} Order;

// Array to store the menu items
Item menu[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Cake", 3.00},
    {"Sandwich", 4.00},
    {"Salad", 5.00}
};

// Function to display the menu
void display_menu() {
    printf("\nMenu:\n");
    printf("-------------------------------------------------------------------\n");
    printf("| Item Name | Price |\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("| %-10s | %-5.2f |\n", menu[i].name, menu[i].price);
    }
    printf("-------------------------------------------------------------------\n");
}

// Function to take the order from the customer
Order take_order() {
    Order order;

    // Get the customer's name
    printf("Enter your name: ");
    scanf(" %[^\n]", order.customer_name);

    // Get the number of items ordered
    printf("How many items would you like to order? ");
    scanf(" %d", &order.num_items);

    // Get the details of each item ordered
    for (int i = 0; i < order.num_items; i++) {
        printf("Enter the name of item %d: ", i + 1);
        scanf(" %s", order.items[i].name);

        printf("Enter the price of item %d: ", i + 1);
        scanf(" %f", &order.items[i].price);
    }

    // Calculate the total price of the order
    order.total_price = 0;
    for (int i = 0; i < order.num_items; i++) {
        order.total_price += order.items[i].price;
    }

    return order;
}

// Function to print the receipt
void print_receipt(Order order) {
    printf("\nReceipt:\n");
    printf("-------------------------------------------------------------------\n");
    printf("| Item Name | Price | Quantity |\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < order.num_items; i++) {
        printf("| %-10s | %-5.2f | %-7d |\n", order.items[i].name, order.items[i].price, 1);
    }
    printf("-------------------------------------------------------------------\n");
    printf("Total Price: %.2f\n", order.total_price);
    printf("-------------------------------------------------------------------\n");
}

// Main function
int main() {
    // Display the menu
    display_menu();

    // Take the order from the customer
    Order order = take_order();

    // Print the receipt
    print_receipt(order);

    return 0;
}