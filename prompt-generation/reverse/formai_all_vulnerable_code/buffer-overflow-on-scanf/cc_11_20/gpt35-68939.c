//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for menu items
#define ITEM1 "Coffee (Regular)"
#define ITEM2 "Coffee (Espresso)"
#define ITEM3 "Muffin"
#define ITEM4 "Sandwich"

// Constants for menu prices
#define PRICE1 2.50
#define PRICE2 3.50
#define PRICE3 2.00
#define PRICE4 4.00

int main()
{
    // Variables to store user input and total price
    int choice, quantity;
    float totalPrice = 0.0;
    
    // Display menu options to user
    printf("Welcome to the C Cafe!\n");
    printf("------------------------------\n");
    printf("Menu:\n");
    printf("1. %s - %.2f\n", ITEM1, PRICE1);
    printf("2. %s - %.2f\n", ITEM2, PRICE2);
    printf("3. %s - %.2f\n", ITEM3, PRICE3);
    printf("4. %s - %.2f\n", ITEM4, PRICE4);
    printf("------------------------------\n");
    
    // Ask user for their order
    printf("Enter your order (1-4): ");
    scanf("%d", &choice);
    
    // Validate user input
    while (choice < 1 || choice > 4)
    {
        printf("Invalid input. Please enter a number between 1 and 4: ");
        scanf("%d", &choice);
    }
    
    // Ask user for the quantity of their order
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    
    // Calculate the total price of the order based on user's selection
    switch (choice)
    {
        case 1:
            totalPrice = PRICE1 * quantity;
            break;
        case 2:
            totalPrice = PRICE2 * quantity;
            break;
        case 3:
            totalPrice = PRICE3 * quantity;
            break;
        case 4:
            totalPrice = PRICE4 * quantity;
            break;
    }
    
    // Display the user's order and total price
    printf("------------------------------\n");
    printf("Your order: %d x ", quantity);
    switch (choice)
    {
        case 1:
            printf("%s", ITEM1);
            break;
        case 2:
            printf("%s", ITEM2);
            break;
        case 3:
            printf("%s", ITEM3);
            break;
        case 4:
            printf("%s", ITEM4);
            break;
    }
    printf(" = %.2f\n", totalPrice);
    
    return 0;
}