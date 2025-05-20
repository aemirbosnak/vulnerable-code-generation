//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
char menu[][20] = {"Coffee", "Tea", "Soda", "Water", "Cake", "Cookie"};
float prices[] = {1.50, 1.25, 1.00, 0.50, 2.00, 1.00};

// Define the function to print the menu
void print_menu() {
    printf("Menu:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i], prices[i]);
    }
}

// Define the function to get the user's order
int get_order() {
    int order;
    printf("Enter the number of the item you would like to order: ");
    scanf("%d", &order);
    return order;
}

// Define the function to calculate the total bill
float calculate_bill(int order, int quantity) {
    float total = prices[order - 1] * quantity;
    return total;
}

// Define the function to print the receipt
void print_receipt(int order, int quantity, float total) {
    printf("Receipt:\n");
    printf("Item: %s\n", menu[order - 1]);
    printf("Quantity: %d\n", quantity);
    printf("Total: $%.2f\n", total);
}

// Define the main function
int main() {
    // Print the menu
    print_menu();

    // Get the user's order
    int order = get_order();

    // Get the quantity of the item ordered
    int quantity;
    printf("Enter the quantity of the item you would like to order: ");
    scanf("%d", &quantity);

    // Calculate the total bill
    float total = calculate_bill(order, quantity);

    // Print the receipt
    print_receipt(order, quantity, total);

    return 0;
}