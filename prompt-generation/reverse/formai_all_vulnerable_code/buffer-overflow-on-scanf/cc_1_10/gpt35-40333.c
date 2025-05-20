//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int menuOption;
    int quantity;
    float total = 0.0;

    while(1){
        printf("\nWelcome to our Cafe Billing System!\n");
        printf("1. Coffee - $1.50\n");
        printf("2. Tea - $1.00\n");
        printf("3. Sandwich - $3.50\n");
        printf("4. Cake - $2.50\n");
        printf("5. Exit\n");

        printf("Please enter your menu option: ");
        scanf("%d", &menuOption);

        if (menuOption == 5){  // Exit option
            break;
        }

        printf("Please enter quantity: ");
        scanf("%d", &quantity);

        switch (menuOption){
            case 1:
                total += quantity * 1.5;
                break;
            case 2:
                total += quantity * 1.0;
                break;
            case 3:
                total += quantity * 3.5;
                break;
            case 4:
                total += quantity * 2.5;
                break;
            default:
                printf("Invalid menu option!\n");
                break;
        }

        printf("Current total: $%.2f\n", total);
    }

    printf("Thank you for using our Cafe Billing System!\n");
    printf("Your total bill is: $%.2f\n", total);

    return 0;
}