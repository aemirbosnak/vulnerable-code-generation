//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>

// Define the menu items and their prices
#define COFFEE 1
#define TEA 2
#define JUICE 3
#define CAKE 4
#define COOKIE 5

int main() {
    int menu[5] = {0}; // Initialize the menu items to 0
    int num_items = 0; // Initialize the number of items to 0
    double bill_amount = 0.0; // Initialize the bill amount to 0

    // Print the menu
    printf("Welcome to the Cafe!\n");
    printf("Here's our menu:\n");
    printf("1. Coffee - $3.50\n");
    printf("2. Tea - $2.50\n");
    printf("3. Juice - $4.00\n");
    printf("4. Cake - $5.00\n");
    printf("5. Cookie - $2.00\n");

    // Get the customer's order
    printf("\nEnter the number of items you would like to order (max 5): ");
    scanf("%d", &num_items);

    // Validate the order
    if (num_items > 5) {
        printf("Sorry, we can only serve up to 5 items at a time.\n");
        return 0;
    }

    // Get the customer's order
    for (int i = 0; i < num_items; i++) {
        int item;
        printf("\nEnter the number of the item you would like to order (1-5): ");
        scanf("%d", &item);

        // Validate the order
        if (item < 1 || item > 5) {
            printf("Invalid item number.\n");
            return 0;
        }

        // Add the item to the order
        menu[item-1] = 1;
    }

    // Calculate the bill amount
    for (int i = 0; i < num_items; i++) {
        if (menu[i] == 1) {
            switch (i+1) {
                case 1:
                    bill_amount += 3.50;
                    break;
                case 2:
                    bill_amount += 2.50;
                    break;
                case 3:
                    bill_amount += 4.00;
                    break;
                case 4:
                    bill_amount += 5.00;
                    break;
                case 5:
                    bill_amount += 2.00;
                    break;
            }
        }
    }

    // Print the bill
    printf("\nYour bill amount is: $%.2f\n", bill_amount);

    return 0;
}