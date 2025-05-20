//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define constants for menu prices
#define COFFEE_PRICE 2.00
#define TEA_PRICE 1.50
#define PASTRY_PRICE 3.00
#define SANDWICH_PRICE 4.50

int main() {
    int option, quantity;
    float subtotal = 0.00, tax = 0.00, total = 0.00;
    
    printf("Welcome to Grateful Cafe!\n");
    printf("Here is our menu:\n");
    printf("1. Coffee ($%.2f)\n", COFFEE_PRICE);
    printf("2. Tea ($%.2f)\n", TEA_PRICE);
    printf("3. Pastry ($%.2f)\n", PASTRY_PRICE);
    printf("4. Sandwich ($%.2f)\n", SANDWICH_PRICE);
    
    printf("Enter the number of the item you would like to order (or 0 to exit): ");
    scanf("%d", &option);
    
    while (option != 0) {
        switch(option) {
            case 1:
                printf("How many coffees would you like to order? ");
                scanf("%d", &quantity);
                subtotal += COFFEE_PRICE * quantity;
                break;
            case 2:
                printf("How many teas would you like to order? ");
                scanf("%d", &quantity);
                subtotal += TEA_PRICE * quantity;
                break;
            case 3:
                printf("How many pastries would you like to order? ");
                scanf("%d", &quantity);
                subtotal += PASTRY_PRICE * quantity;
                break;
            case 4:
                printf("How many sandwiches would you like to order? ");
                scanf("%d", &quantity);
                subtotal += SANDWICH_PRICE * quantity;
                break;
            default:
                printf("Invalid option. Please select a valid option.\n");
                break;
        }
        
        // Ask for another order or end the loop
        printf("Enter the number of the item you would like to order (or 0 to exit): ");
        scanf("%d", &option);
    }
    
    // Calculate tax and total
    tax = subtotal * 0.08;
    total = subtotal + tax;
    
    // Print receipt
    printf("\n\n\n");
    printf("*********************************************\n");
    printf("************| THANK YOU! |********************\n");
    printf("*********************************************\n");
    printf("================= RECEIPT ====================\n");
    printf("==============================================\n");
    printf("\n");
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Tax (8%%): $%.2f\n", tax);
    printf("Total: $%.2f\n", total);
    printf("\n");
    printf("==============================================\n");
    printf("==============================================\n");
    
    return 0;
}