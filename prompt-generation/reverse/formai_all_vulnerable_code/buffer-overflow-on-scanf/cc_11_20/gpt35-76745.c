//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j;
    char order[50]; // maximum order length is 50
    float price, VAT = 0.14, subTotal = 0, total = 0; // initial prices and VAT rate
    char menu[5][15] = {"Coffee", "Tea", "Sandwich", "Cake", "Burger"}; // menu items
    float prices[5] = {2.5, 1.5, 3.0, 2.0, 4.5}; // respective prices

    printf("Welcome to Cafe Billing System.\n\n");

    // display the menu
    printf("Menu\n");
    printf("----\n");
    for (i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i], prices[i]);
    }

    // take the order
    printf("\nWhat would you like to order (enter item number): ");
    scanf("%d", &i);
    while (i != 0) {
        // check if order is within range
        if (i < 1 || i > 5) {
            printf("\nInvalid order entered. Please try again.\n");
        }
        else {
            printf("\nOrdered Item: %s - $%.2f\n", menu[i-1], prices[i-1]);
            subTotal += prices[i-1];
        }
        printf("Enter another item number (enter 0 to finish): ");
        scanf("%d", &i);
    }
    printf("\n");

    // calculate VAT and total price
    VAT *= subTotal;
    total = subTotal + VAT;

    // print receipt
    printf("RECEIPT\n");
    printf("-------\n");
    for (i = 0; i < strlen(order); i++) {
        printf("%c", order[i]);
        if (order[i] == '\n') {
            printf("           $%.2f\n", prices[i]); // format price output
        }
    }
    printf("Subtotal:              $%.2f\n", subTotal);
    printf("VAT (14%%):             $%.2f\n", VAT);
    printf("Total:                 $%.2f\n", total);

    // pay now or later option
    printf("\nWould you like to pay now? (Y/N): ");
    scanf(" %c", &order);
    order[0] = toupper(order[0]);
    while (order[0] != 'Y' && order[0] != 'N') {
        printf("\nInvalid response. Please try again.\n");
        printf("\nWould you like to pay now? (Y/N): ");
        scanf(" %c", &order);
        order[0] = toupper(order[0]);
    }

    // paranoid message
    if (order[0] == 'Y') {
        printf("\nThanks for your payment. Here's your Change: ");
        for (j = 0; j < 1000000000; j++); // some random delay
        printf("$%.2f\n", total);
        for (j = 0; j < 1000000000; j++);
        printf("\nDon't tell anyone the amount you paid. They might steal it!\n");
    }
    else {
        printf("\nOkay, you can pay later. But remember, don't lose that receipt!\n");
    }

    return(0);
}