//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// function to calculate the total amount based on customer's order
float calculateTotal(int quantity, float pricePerItem) {
    return quantity * pricePerItem;
}

int main()
{
    int menuChoice, quantity;
    float pricePerItem, totalAmount = 0;
    
    printf("Welcome to the C Cafe!\n");
    printf("Please select from our menu:\n");
    printf("1. Coffee - $3.50\n");
    printf("2. Tea - $2.50\n");
    printf("3. Sandwich - $5.00\n");
    printf("4. Cake - $4.00\n");
    
    // loop to keep customers adding orders
    while(1) {
        printf("Enter menu choice (0 to exit): ");
        scanf("%d", &menuChoice);
        
        switch(menuChoice) {
            case 0:
                printf("Thank you for visiting the C Cafe! Your total bill is $%.2f\n", totalAmount);
                exit(0);
            case 1:
                printf("How many coffees would you like to order? ");
                scanf("%d", &quantity);
                pricePerItem = 3.50;
                totalAmount += calculateTotal(quantity, pricePerItem);
                printf("Added %d coffees to your bill. Your total amount is now $%.2f\n", quantity, totalAmount);
                break;
            case 2:
                printf("How many teas would you like to order? ");
                scanf("%d", &quantity);
                pricePerItem = 2.50;
                totalAmount += calculateTotal(quantity, pricePerItem);
                printf("Added %d teas to your bill. Your total amount is now $%.2f\n", quantity, totalAmount);
                break;
            case 3:
                printf("How many sandwiches would you like to order? ");
                scanf("%d", &quantity);
                pricePerItem = 5.00;
                totalAmount += calculateTotal(quantity, pricePerItem);
                printf("Added %d sandwiches to your bill. Your total amount is now $%.2f\n", quantity, totalAmount);
                break;
            case 4:
                printf("How many cakes would you like to order? ");
                scanf("%d", &quantity);
                pricePerItem = 4.00;
                totalAmount += calculateTotal(quantity, pricePerItem);
                printf("Added %d cakes to your bill. Your total amount is now $%.2f\n", quantity, totalAmount);
                break;
            default:
                printf("Invalid menu choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}