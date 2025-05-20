//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice, item, quantity, price, total = 0;
    char name[20];
    printf("Welcome to our Happy Cafe!\n");
    printf("---------------------------\n");
    printf("Here is our menu:\n");
    printf("1. Coffee\t\t$2\n");
    printf("2. Tea\t\t\t$1.5\n");
    printf("3. Sandwich\t\t$5\n");
    printf("---------------------------\n");

    do {
        printf("\nWhat would you like to order? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many cups of coffee do you want? ");
                scanf("%d", &quantity);
                price = 2;
                total += price * quantity;
                strcpy(name, "Coffee");
                break;
            case 2:
                printf("How many cups of tea do you want? ");
                scanf("%d", &quantity);
                price = 1.5;
                total += price * quantity;
                strcpy(name, "Tea");
                break;
            case 3:
                printf("How many sandwiches do you want? ");
                scanf("%d", &quantity);
                price = 5;
                total += price * quantity;
                strcpy(name, "Sandwich");
                break;
            default:
                printf("Invalid choice.\n");
                continue;
        }

        printf("%s added to your order. Anything else? (1 for yes, 0 for no) ", name);
        scanf("%d", &item);

    } while (item != 0);

    printf("\nYour total bill is $%d.\n", total);
    printf("Thank you for visiting our Happy Cafe, have a nice day!");

    return 0;
}