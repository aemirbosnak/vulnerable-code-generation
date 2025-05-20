//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>

int main() {
    int coffee_price = 5;
    int tea_price = 3;
    int sandwich_price = 7;
    int quantity;
    char choice;
    int total_amount = 0;

    printf("Welcome to the Retro Cafe!\n");

    do {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Coffee - $%d\n", coffee_price);
        printf("2. Tea - $%d\n", tea_price);
        printf("3. Sandwich - $%d\n", sandwich_price);
        printf("4. Quit\n");

        // Get the user's choice
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        // Get the quantity
        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        // Calculate the total price
        switch (choice) {
            case '1':
                total_amount += quantity * coffee_price;
                break;
            case '2':
                total_amount += quantity * tea_price;
                break;
            case '3':
                total_amount += quantity * sandwich_price;
                break;
            case '4':
                printf("Thank you for visiting the Retro Cafe!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    } while (choice != '4');

    // Display the total bill
    printf("\nTotal amount: $%d\n", total_amount);

    return 0;
}