//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
/* This program is a cafe billing system that calculates the total bill of the customer */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int menuChoice, quantity, moreOrders;
    float totalBill = 0;

    /* Display the menu */
    printf("\nWelcome to Ada's Cafe!\n");
    printf("Here's our menu:\n\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $2.00\n");
    printf("3. Sandwich - $5.00\n");
    printf("4. Cake - $4.50\n");

    /* Take orders from the customer */
    do {
        printf("\nWhat would you like to order? (Enter the number): ");
        scanf("%d", &menuChoice);

        printf("How many would you like?: ");
        scanf("%d", &quantity);

        switch(menuChoice) {
            case 1:
                totalBill += (2.50 * quantity);
                break;
            case 2:
                totalBill += (2.00 * quantity);
                break;
            case 3:
                totalBill += (5.00 * quantity);
                break;
            case 4:
                totalBill += (4.50 * quantity);
                break;
            default:
                printf("Invalid choice!");
        }

        printf("Anything else? (1 for Yes / 0 for No): ");
        scanf("%d", &moreOrders);
        printf("\n");

    } while(moreOrders == 1);

    /* Display the total bill */
    printf("Your total bill is: $%.2f\n", totalBill);

    return 0;
}