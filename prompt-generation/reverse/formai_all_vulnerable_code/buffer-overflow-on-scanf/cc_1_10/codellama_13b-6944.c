//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
/*
 * A unique C Cafe Billing System example program
 * by Dennis Ritchie
 */

#include <stdio.h>

int main() {
    // Define the prices of the menu items
    int coffee = 100;
    int tea = 80;
    int sandwich = 150;
    int milk = 50;
    int cake = 100;

    // Define the number of items ordered
    int num_coffee = 0;
    int num_tea = 0;
    int num_sandwich = 0;
    int num_milk = 0;
    int num_cake = 0;

    // Print the menu
    printf("Welcome to the Cafe Billing System!\n");
    printf("Menu:\n");
    printf("1. Coffee - $100\n");
    printf("2. Tea - $80\n");
    printf("3. Sandwich - $150\n");
    printf("4. Milk - $50\n");
    printf("5. Cake - $100\n");

    // Take orders
    while (1) {
        // Print the order options
        printf("Please select an item: ");

        // Take the order
        int choice;
        scanf("%d", &choice);

        // Check if the order is valid
        if (choice < 1 || choice > 5) {
            printf("Invalid order. Please try again.\n");
            continue;
        }

        // Update the number of items ordered
        switch (choice) {
            case 1:
                num_coffee++;
                break;
            case 2:
                num_tea++;
                break;
            case 3:
                num_sandwich++;
                break;
            case 4:
                num_milk++;
                break;
            case 5:
                num_cake++;
                break;
        }

        // Print the order summary
        printf("Order Summary:\n");
        printf("Coffee: %d\n", num_coffee);
        printf("Tea: %d\n", num_tea);
        printf("Sandwich: %d\n", num_sandwich);
        printf("Milk: %d\n", num_milk);
        printf("Cake: %d\n", num_cake);

        // Print the total cost
        int total_cost = coffee * num_coffee + tea * num_tea + sandwich * num_sandwich + milk * num_milk + cake * num_cake;
        printf("Total Cost: $%d\n", total_cost);

        // Ask for another order
        printf("Would you like to order again? (y/n): ");
        char another_order;
        scanf(" %c", &another_order);

        // Check if the user wants to quit
        if (another_order == 'n') {
            break;
        }
    }

    // Print the final order summary
    printf("Final Order Summary:\n");
    printf("Coffee: %d\n", num_coffee);
    printf("Tea: %d\n", num_tea);
    printf("Sandwich: %d\n", num_sandwich);
    printf("Milk: %d\n", num_milk);
    printf("Cake: %d\n", num_cake);

    // Print the final total cost
    int final_total_cost = coffee * num_coffee + tea * num_tea + sandwich * num_sandwich + milk * num_milk + cake * num_cake;
    printf("Final Total Cost: $%d\n", final_total_cost);

    return 0;
}