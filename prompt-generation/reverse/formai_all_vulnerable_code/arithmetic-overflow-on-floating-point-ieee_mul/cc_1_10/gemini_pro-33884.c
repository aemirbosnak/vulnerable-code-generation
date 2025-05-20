//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the menu items and their prices
typedef struct Menu_Item {
    char name[50];
    float price;
} Menu_Item;

Menu_Item menu[] = {
    {"Coffee", 2.00},
    {"Tea", 1.50},
    {"Cake", 3.00},
    {"Cookie", 1.00},
    {"Soda", 1.50}
};

// Define the order struct to store the customer's order
typedef struct Order {
    Menu_Item item;
    int quantity;
} Order;

// Function to print the menu
void print_menu() {
    printf("Welcome to the Cafe!\n");
    printf("Here is our menu:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

// Function to take the customer's order
Order take_order() {
    Order order;

    // Get the item number the customer wants to order
    int item_number;
    printf("Enter the item number of the item you want to order: ");
    scanf("%d", &item_number);

    // Get the quantity of the item the customer wants to order
    int quantity;
    printf("Enter the quantity of the item you want to order: ");
    scanf("%d", &quantity);

    // Set the order's item and quantity
    order.item = menu[item_number - 1];
    order.quantity = quantity;

    return order;
}

// Function to calculate the total cost of the order
float calculate_total(Order order) {
    return order.item.price * order.quantity;
}

// Function to print the receipt
void print_receipt(Order order) {
    printf("Thank you for your order!\n");
    printf("Here is your receipt:\n");
    printf("Item: %s\n", order.item.name);
    printf("Quantity: %d\n", order.quantity);
    printf("Total: $%.2f\n", calculate_total(order));
    printf("\n");
}

// Main function
int main() {
    // Print the menu
    print_menu();

    // Take the customer's order
    Order order = take_order();

    // Calculate the total cost of the order
    float total = calculate_total(order);

    // Print the receipt
    print_receipt(order);

    return 0;
}