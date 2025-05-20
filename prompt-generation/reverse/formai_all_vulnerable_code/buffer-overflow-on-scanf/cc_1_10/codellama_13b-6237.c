//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: retro
/*
 * C Cafe Billing System
 *
 * This program is a retro-style example of a basic billing system for a cafe.
 * It allows customers to order food and drinks, and prints a bill with the total cost.
 */

#include <stdio.h>
#include <string.h>

// Define the menu items
typedef struct {
    char name[32];
    float price;
} MenuItem;

MenuItem menu[] = {
    {"Coffee", 3.00},
    {"Tea", 2.50},
    {"Sandwich", 5.00},
    {"Salad", 4.50},
    {"Chips", 2.00},
    {"Soda", 2.50},
    {"Cake", 3.00},
    {"Ice Cream", 3.50}
};

int main() {
    int i, n;
    char name[32];
    float total = 0.0;

    // Print the menu
    printf("Welcome to our retro cafe!\n");
    printf("Our menu is as follows:\n\n");
    for (i = 0; i < sizeof(menu) / sizeof(MenuItem); i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }

    // Ask for customer name and order
    printf("\nWhat is your name? ");
    scanf("%s", name);
    printf("\nWhat would you like to order? (enter the number) ");
    scanf("%d", &n);

    // Calculate the total cost of the order
    total += menu[n - 1].price;

    // Print the bill
    printf("\nBill for %s:\n", name);
    printf("Item: %s\n", menu[n - 1].name);
    printf("Price: $%.2f\n", menu[n - 1].price);
    printf("Total: $%.2f\n", total);

    return 0;
}