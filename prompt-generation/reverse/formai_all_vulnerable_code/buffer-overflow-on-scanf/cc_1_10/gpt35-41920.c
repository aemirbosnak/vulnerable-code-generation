//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a price for each item
#define PRICE_COFFEE 50
#define PRICE_TEA 30
#define PRICE_SANDWICH 100
#define PRICE_PASTRY 70

// Define the maximum quantity that can be ordered
#define MAX_QUANTITY 10

int main() {
    int price[4] = {PRICE_COFFEE, PRICE_TEA, PRICE_SANDWICH, PRICE_PASTRY}; // Store the price for each item
    int quantity[4] = {0,0,0,0}; // Store the quantity of each item ordered
    int option; // Store the option selected by the user in the menu
    int total = 0; // Store the total bill
    char choice; // Store the choice for whether to continue ordering or not

    printf("\n\n\t\t*** Welcome to the Curious Cafe ***\n\n");

    do {
        printf("\t\tMenu:\n");
        printf("1. Coffee - Rs. %d\n", PRICE_COFFEE);
        printf("2. Tea - Rs. %d\n", PRICE_TEA);
        printf("3. Sandwich - Rs. %d\n", PRICE_SANDWICH);
        printf("4. Pastry - Rs. %d\n", PRICE_PASTRY);
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        if (option == 5) { // If the user wants to exit, exit the program
            printf("\n\t\tThank you for visiting the Curious Cafe!");
            exit(0);
        } else if (option < 1 || option > 4) { // If the user enters an invalid option, continue ordering
            printf("\n\t\tInvalid option!\n");
            continue;
        }

        // Ask the user for the quantity of the selected item
        printf("\n\t\tEnter the quantity (max %d): ", MAX_QUANTITY);
        scanf("%d", &quantity[option-1]);

        // Calculate the bill for the selected item
        int bill = price[option-1] * quantity[option-1];
        total += bill;

        printf("\n\t\tTotal bill: Rs. %d\n", total); // Display the current total bill

        // Ask the user if they want to continue ordering
        printf("\n\t\tDo you want to order more items (y/n)? ");
        scanf("%s", &choice);

    } while (choice == 'y' || choice == 'Y'); // Continue ordering as long as the user wants to

    // Display the final bill and exit the program
    printf("\n\t\tYour total bill is: Rs. %d", total);
    printf("\n\t\tThank you for visiting the Curious Cafe!");
    return 0;
}