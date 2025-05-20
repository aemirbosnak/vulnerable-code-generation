//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice, quantity, bill = 0;
    char item[15];

    printf("   ************************************************************\n");
    printf("   *                                                          *\n");
    printf("   *                       C CAFE BILLING SYSTEM               *\n");
    printf("   *                                                          *\n");
    printf("   ************************************************************\n");
    printf("\nWelcome to C Cafe! Here's our menu:\n");
    printf("\n\t1. Coffee - $3\n\t2. Tea - $2\n\t3. Sandwich - $5\n\t4. Burger - $8\n");

    while(1) {
        printf("\nEnter item number: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                strcpy(item, "Coffee");
                bill += 3;
                break;

            case 2:
                strcpy(item, "Tea");
                bill += 2;
                break;

            case 3:
                strcpy(item, "Sandwich");
                bill += 5;
                break;

            case 4:
                strcpy(item, "Burger");
                bill += 8;
                break;

            default:
                printf("\nSorry, invalid choice! Try again.\n");
                continue;
        }

        printf("\nEnter quantity: ");
        scanf("%d", &quantity);

        if(quantity < 1)
        {
            printf("\nInvalid quantity input! Try again.\n");
            continue;
        }

        printf("%s x %d = $%d\n", item, quantity, (bill * quantity));

        char c;
        printf("\nDo you want to order more items? (y/n): ");
        scanf(" %c", &c);

        if(c == 'n' || c == 'N')
        {
            printf("\nYour total bill is $%d. Thanks for ordering from C Cafe!\n", bill);
            break;
        }
    }

    return 0;
}