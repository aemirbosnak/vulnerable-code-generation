//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Defining constants for menu items with their prices
#define COFFEE_PRICE  50
#define TEA_PRICE     40
#define SANDWICH_PRICE 70
#define BURGER_PRICE  120
#define PIZZA_PRICE   150

// Defining constants for taxes and discounts
#define TAX_RATE 0.1
#define DISCOUNT_RATE 0.05

// Struct to hold the details of an order
typedef struct {
    char name[20];
    int quantity;
    int price;
} Order;

int main() {
    // Initializing the orders array with 100 empty orders
    Order orders[100] = {0};

    // Initializing variables for total items, total sale, and total profit
    int totalItems = 0;
    int totalSale = 0;
    int totalProfit = 0;

    // Printing out the welcome message for the cafe
    printf("*** Welcome to Cafe Post-Apocalypse ***\n");
    printf("*** We serve Coffee, Tea, Sandwiches, Burgers, and Pizzas ***\n");

    // Loop for taking orders
    while (true) {
        char input[50];
        printf("\nWhat would you like to order? (Type 'Exit' to exit)\n");
        scanf("%[^\n]s", input);
        getchar(); // To consume the newline character

        // If the user chooses to exit, break out of the loop
        if (strcmp(input, "Exit") == 0) {
            break;
        }

        // Getting the quantity of the item to be ordered
        int quantity;
        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        // Initializing a new order with the name, quantity, and price
        Order order;
        strcpy(order.name, input);
        order.quantity = quantity;
        if (strcmp(order.name, "Coffee") == 0) {
            order.price = COFFEE_PRICE;
        } else if (strcmp(order.name, "Tea") == 0) {
            order.price = TEA_PRICE;
        } else if (strcmp(order.name, "Sandwich") == 0) {
            order.price = SANDWICH_PRICE;
        } else if (strcmp(order.name, "Burger") == 0) {
            order.price = BURGER_PRICE;
        } else if (strcmp(order.name, "Pizza") == 0) {
            order.price = PIZZA_PRICE;
        } else { // If an invalid item is ordered, go back to the start of the loop
            printf("Invalid item\n");
            continue;
        }

        // Adding the order to the orders array and updating the total items and total sale
        orders[totalItems] = order;
        totalItems++;
        totalSale += (order.price * order.quantity);
        
        // Printing out the order details
        printf("%d %s(s) added to the order\n", quantity, order.name);
        printf("%s - Price: %d, Quantity: %d\n", order.name, order.price, order.quantity);
    }

    // Print out the final bill and calculate the total profit after applying taxes and discounts
    printf("\n\n*** Bill ***\n");
    printf("Total items: %d\n", totalItems);
    printf("Total sale: %d\n", totalSale);
    float tax = totalSale * TAX_RATE;
    printf("Tax: %.2f\n", tax);
    printf("Discount: %.2f\n", totalSale * DISCOUNT_RATE);
    totalProfit = (int)(totalSale + tax - totalSale * DISCOUNT_RATE);
    printf("Total profit: %d\n", totalProfit);

    return 0;
}