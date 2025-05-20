//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
typedef struct {
    char name[50];
    float price;
} Menu;

Menu menu[] = {
    {"Espresso", 2.50},
    {"Cappuccino", 3.00},
    {"Latte", 3.50},
    {"Americano", 2.00},
    {"Mocha", 4.00},
    {"Tea", 1.50},
    {"Hot Chocolate", 2.00},
    {"Pastry", 2.50},
    {"Muffin", 3.00},
    {"Scone", 2.00},
};

// Define the customer's order
typedef struct {
    char name[50];
    int quantity;
    Menu *item;
} Order;

// Get the customer's name
void get_customer_name(char *name) {
    printf("What is your name? ");
    scanf("%s", name);
}

// Get the customer's order
void get_customer_order(Order *order) {
    int choice;
    printf("What would you like to order?\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s ($%.2f)\n", i + 1, menu[i].name, menu[i].price);
    }
    scanf("%d", &choice);
    order->item = &menu[choice - 1];
    printf("How many would you like? ");
    scanf("%d", &order->quantity);
}

// Calculate the total bill
float calculate_bill(Order *order) {
    float total = order->item->price * order->quantity;
    return total;
}

// Print the receipt
void print_receipt(Order *order, float total) {
    printf("-------------------------------------\n");
    printf("Customer Name: %s\n", order->name);
    printf("Item Ordered: %s\n", order->item->name);
    printf("Quantity: %d\n", order->quantity);
    printf("Total: $%.2f\n", total);
    printf("-------------------------------------\n");
}

// Main function
int main() {
    // Get the customer's name
    char customer_name[50];
    get_customer_name(customer_name);

    // Get the customer's order
    Order order;
    get_customer_order(&order);

    // Calculate the total bill
    float total = calculate_bill(&order);

    // Print the receipt
    print_receipt(&order, total);

    return 0;
}