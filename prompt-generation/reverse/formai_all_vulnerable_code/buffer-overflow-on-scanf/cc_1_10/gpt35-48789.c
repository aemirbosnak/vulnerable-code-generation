//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Initialize variables
    int choice, quantity, i = 0;
    float total = 0.0, price = 0.0;
    char item[20];

    printf("Welcome to Retro Cafe!\n");

    // Begin ordering process
    while (1)
    {
        printf("Please select an item:\n");
        printf("1. Coffee - $1.50\n");
        printf("2. Tea - $1.25\n");
        printf("3. Danish - $2.00\n");
        printf("4. Donut - $1.00\n");
        printf("5. Checkout\n");

        // Take user's order
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                strcpy(item, "Coffee");
                price = 1.50;
                break;
            case 2:
                strcpy(item, "Tea");
                price = 1.25;
                break;
            case 3:
                strcpy(item, "Danish");
                price = 2.00;
                break;
            case 4:
                strcpy(item, "Donut");
                price = 1.00;
                break;
            case 5:
                printf("\n=============================\n");
                printf("Coffee: %.2f\n", (float)total);
                printf("Tax:    %.2f\n", (float)total * 0.07);
                printf("Total:  %.2f\n", (float)total * 1.07);
                printf("=============================\n");
                printf("Thank you for shopping at Retro Cafe!\n");
                return 0;
            default:
                printf("Invalid option, please enter a valid option.\n");
                continue;
        }
        printf("How many %ss would you like to purchase?\n", item);
        scanf("%d", &quantity);

        // Add to total cost and output order
        total += price * quantity;
        printf("%d x %s added to cart.\n", quantity, item);
        printf("Current bill: $%.2f\n\n", total);
    }
    return 0;
}