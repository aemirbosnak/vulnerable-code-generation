//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float total_bill = 0;

    printf("Welcome to Cafe X!\n\n");

    printf("MENU:\n");
    printf("1. Coffee         $2.50\n");
    printf("2. Tea            $2.00\n");
    printf("3. Croissant      $3.00\n");
    printf("4. Bagel          $2.50\n\n");

    printf("Please enter the number of the item you would like to order (1-4) or 0 to calculate your total bill: ");

    int input;
    scanf("%d", &input);

    while (input != 0)
    {
        switch (input)
        {
            case 1:
                total_bill += 2.50;
                printf("Coffee added.\n");
                break;

            case 2:
                total_bill += 2.00;
                printf("Tea added.\n");
                break;

            case 3:
                total_bill += 3.00;
                printf("Croissant added.\n");
                break;

            case 4:
                total_bill += 2.50;
                printf("Bagel added.\n");
                break;

            default:
                printf("Invalid input. Please enter a number between 1-4 or 0 to calculate your total bill.\n");
                break;
        }

        printf("Please enter the number of the item you would like to order (1-4) or 0 to calculate your total bill: ");
        scanf("%d", &input);
    }

    printf("\nYour total bill comes to: $%.2f\n\n", total_bill);

    return 0;
}