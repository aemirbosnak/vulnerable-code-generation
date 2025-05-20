//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Cafe's billing system
int main(){
    printf("Welcome to the 221B Baker Street Cafe Billing System!\n");
    printf("Please enter your order below:\n\n");

    // Let's declare the variables
    int quantity, price, total_price = 0;
    char item[20];

    do{
        printf("Enter item name (or 'done' to calculate total): ");
        scanf("%s", item);

        if(strcmp(item, "done") == 0){
            break;
        }

        // The price per item
        printf("Enter price: ");
        scanf("%d", &price);

        // Number of items to order
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculate the total price
        total_price += price*quantity;

    } while(strcmp(item, "done") != 0);

    printf("\nCalculating bill...\n");

    printf("Item\t\tPrice\tQty\tTotal\n");
    printf("------------------------------------------\n");

    if(total_price == 0){
        printf("\nNo items ordered. Please visit again soon!\n");
    }
    else{
        printf("\n");
        printf("\tTotal payment amount:\t%d\n", total_price);
        printf("\tPayment accepted.\n");
        printf("\nThank you for dining with us. Please visit again soon!\n");
    }

    return 0;
}