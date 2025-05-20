//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int option, quantity;
    float price, total = 0.0;
    char item[30];

    printf("\n-------------- C Cafe Billing System ------------------\n\n");

    printf("Item\t\t\tPrice\n\n");
    printf("Coffee\t\t\t3.99\n");
    printf("Tea\t\t\t2.99\n");
    printf("Sandwich\t\t5.99\n");
    printf("Burger\t\t\t7.99\n");
    printf("Pizza\t\t\t9.99\n\n");

    do {
        printf("Enter Option Number (1-5): ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                strcpy(item, "Coffee");
                price = 3.99;
                break;
            case 2:
                strcpy(item, "Tea");
                price = 2.99;
                break;
            case 3:
                strcpy(item, "Sandwich");
                price = 5.99;
                break;
            case 4:
                strcpy(item, "Burger");
                price = 7.99;
                break;
            case 5:
                strcpy(item, "Pizza");
                price = 9.99;
                break;
            default:
                printf("Invalid Option\n");
                continue;
        }

        printf("Enter Quantity: ");
        scanf("%d", &quantity);

        total += price * quantity;

        printf("\n%s\t\t\t%.2f x %d = %.2f\n", item, price, quantity, price*quantity);
        printf("Total: %.2f\n\n", total);

    } while(option != 0);

    printf("Thank You for using C Cafe Billing System!");

    return 0;
}