//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total bill based on quantity and price
float calculateBill(float quantity, float price) {
    return quantity * price;
}

int main() {
    int option, quantity, i;
    float price, totalBill = 0;

    // Menu for the cafe
    char *menu[] = {"Espresso", "Cappuccino", "Latte", "Mocha", "Hot Chocolate"};
    float prices[] = {2.50, 3.00, 3.50, 4.00, 2.75};

    printf("Welcome to the C Cafe!\n");

    // Loop to continue taking orders until user quits
    while (1) {
        printf("\nWhat would you like to order?\n");

        // Display the menu
        for (i = 0; i < 5; i++) {
            printf("%d. %s (%.2f)\n", i+1, menu[i], prices[i]);
        }

        printf("6. Quit\n");

        // Get user input for their order
        printf("Enter your choice: ");
        scanf("%d", &option);

        // If user chooses to quit, exit the program
        if (option == 6) {
            printf("Thank you for visiting the C Cafe!\n");
            break;
        }

        // Get user input for quantity of their order
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculate the bill for the user's order and add to totalBill
        price = prices[option-1];
        float bill = calculateBill(quantity, price);
        totalBill += bill;

        // Display the bill for the user's order
        printf("Your bill for %d %s is %.2f\n", quantity, menu[option-1], bill);
    }

    // Display the total bill for all orders
    printf("Total bill: %.2f", totalBill);

    return 0;
}