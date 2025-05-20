//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
   
    int menuOption; // variable to store user's menu option choice
    int quantity;   // variable to store the quantity of items
    float price;    // variable to store the price of each item
    
    // welcome message
    printf("\nWelcome to Happy Cafe Billing System!\n");
    printf("What would you like to order today?\n\n");
    
    // display menu
    printf("1. Caramel Macchiato - Php 120.00\n");
    printf("2. Strawberry Frappuccino - Php 150.00\n");
    printf("3. Blueberry Cheesecake - Php 180.00\n");
    printf("4. Chocolate Brownie - Php 130.00\n");
    
    // prompt user to enter menu option
    printf("\nPlease enter the menu option number: ");
    scanf("%d", &menuOption);
    
    // switch case to determine the item price based on the user's menu option
    switch (menuOption) {
        case 1:
            price = 120.00;
            printf("\nYou have selected Caramel Macchiato.\n");
            break;
        case 2:
            price = 150.00;
            printf("\nYou have selected Strawberry Frappuccino.\n");
            break;
        case 3:
            price = 180.00;
            printf("\nYou have selected Blueberry Cheesecake.\n");
            break;
        case 4:
            price = 130.00;
            printf("\nYou have selected Chocolate Brownie.\n");
            break;
        default:
            printf("\nInvalid menu option selected.\n");
            return 0;
    }
    
    // ask user to enter quantity
    printf("Please enter the quantity: ");
    scanf("%d", &quantity);
    
    // calculate subtotal and display it to user
    float subtotal = price * quantity;
    printf("\nThe subtotal is Php %.2f\n", subtotal);
    
    // calculate and display the VAT of 12% and the total amount due
    float vat = subtotal * 0.12;
    float total = subtotal + vat;
    
    printf("12%% VAT: Php %.2f\n", vat);
    printf("Total amount due: Php %.2f\n", total);
    
    // thank you message
    printf("\nThank you for ordering at Happy Cafe! We hope to see you again soon!\n");
    
    return 0;
}