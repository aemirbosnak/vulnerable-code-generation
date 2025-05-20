//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MenuItem {
    char name[20];
    float price;
    int quantity;
} MenuItem;

MenuItem menu[] = {
    {"Coffee", 2.50, 10},
    {"Tea", 3.00, 8},
    {"Juice", 2.00, 12},
    {"Soda", 2.25, 9}
};

int main() {
    int i, order_num = 0, total_price = 0;
    char order[20];

    printf("Welcome to the C Cafe!\n");

    // Loop to take customer's order
    while (1) {
        printf("Please enter your order (or 'q' to quit): ");
        scanf("%s", order);

        // Check if customer wants to quit
        if (strcmp(order, "q") == 0) {
            break;
        }

        // Find item in menu
        for (i = 0; i < 4; i++) {
            if (strcmp(order, menu[i].name) == 0) {
                // Add item to order
                order_num++;
                total_price += menu[i].price * menu[i].quantity;
                break;
            }
        }

        // If item not found, error message
        if (i == 4) {
            printf("Error: item not found.\n");
        }
    }

    // Calculate total price and print receipt
    printf("Your order:\n");
    for (i = 0; i < order_num; i++) {
        printf("%s - %d units at %.2f\n", menu[i].name, menu[i].quantity, menu[i].price);
    }

    printf("Total price: $%.2f\n", total_price);
    printf("Thank you for your visit to the C Cafe!\n");

    return 0;
}