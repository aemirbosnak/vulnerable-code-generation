//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: random
/*
 * C Cafe Billing System Example Program
 *
 * This program is an example of a simple cafe billing system in C. It allows customers to order drinks and food, and then prints out a receipt with the total cost.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <string.h>

// Define the menu items
struct menu_item {
    char name[50];
    float price;
};

struct menu_item drinks[] = {
    {"Latte", 3.00},
    {"Cappuccino", 4.00},
    {"Mocha", 4.50},
    {"Coffee", 2.50},
    {"Tea", 2.00}
};

struct menu_item food[] = {
    {"Bagel", 3.00},
    {"Sandwich", 5.00},
    {"Salad", 6.00},
    {"Soup", 4.50},
    {"Pizza", 8.00}
};

int main() {
    // Declare variables
    int i, j, k;
    char drink_name[50], food_name[50];
    float drink_price, food_price, total_cost;

    // Print the menu
    printf("Welcome to our cafe!\n");
    printf("Our menu includes the following drinks:\n");
    for (i = 0; i < sizeof(drinks) / sizeof(drinks[0]); i++) {
        printf("%s - %.2f\n", drinks[i].name, drinks[i].price);
    }
    printf("Our menu includes the following food:\n");
    for (i = 0; i < sizeof(food) / sizeof(food[0]); i++) {
        printf("%s - %.2f\n", food[i].name, food[i].price);
    }

    // Get the customer's order
    printf("What would you like to order? (Drink or Food)\n");
    scanf("%s", drink_name);
    printf("What would you like to order? (Drink or Food)\n");
    scanf("%s", food_name);

    // Calculate the total cost
    for (i = 0; i < sizeof(drinks) / sizeof(drinks[0]); i++) {
        if (strcmp(drink_name, drinks[i].name) == 0) {
            drink_price = drinks[i].price;
            break;
        }
    }
    for (i = 0; i < sizeof(food) / sizeof(food[0]); i++) {
        if (strcmp(food_name, food[i].name) == 0) {
            food_price = food[i].price;
            break;
        }
    }
    total_cost = drink_price + food_price;

    // Print the receipt
    printf("Here is your receipt:\n");
    printf("Drink: %s - %.2f\n", drink_name, drink_price);
    printf("Food: %s - %.2f\n", food_name, food_price);
    printf("Total: %.2f\n", total_cost);

    return 0;
}