//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0, menu_choice, quantity;
    float cost = 0, total_cost = 0, tax = 0, final_cost = 0;

    printf("\nWelcome to the C Cafe, where everything is brewed to perfection!\n\n");

    do {
        printf("Please make a selection from our menu:\n");
        printf("1. Coffee\t\t$3.50\n");
        printf("2. Tea\t\t\t$2.50\n");
        printf("3. Hot Chocolate\t$4.00\n");
        printf("4. Muffin\t\t$2.00\n");
        printf("5. Bagel\t\t$1.50\n");
        printf("6. Exit\n");

        printf("\nEnter the number of your choice: ");
        scanf("%d", &menu_choice);

        switch(menu_choice) {
            case 1:
                printf("\nHow many cups would you like? ");
                scanf("%d", &quantity);
                cost = quantity * 3.50;
                total_cost += cost;
                printf("Your total cost is: $%.2f\n", total_cost);
                break;

            case 2:
                printf("\nHow many cups would you like? ");
                scanf("%d", &quantity);
                cost = quantity * 2.50;
                total_cost += cost;
                printf("Your total cost is: $%.2f\n", total_cost);
                break;

            case 3:
                printf("\nHow many cups would you like? ");
                scanf("%d", &quantity);
                cost = quantity * 4.00;
                total_cost += cost;
                printf("Your total cost is: $%.2f\n", total_cost);
                break;

            case 4:
                printf("\nHow many muffins would you like? ");
                scanf("%d", &quantity);
                cost = quantity * 2.00;
                total_cost += cost;
                printf("Your total cost is: $%.2f\n", total_cost);
                break;

            case 5:
                printf("\nHow many bagels would you like? ");
                scanf("%d", &quantity);
                cost = quantity * 1.50;
                total_cost += cost;
                printf("Your total cost is: $%.2f\n", total_cost);
                break;

            case 6:
                printf("\nThank you for visiting the C Cafe! Your total bill is: $%.2f\n", total_cost);
                tax = total_cost * 0.08;
                final_cost = total_cost + tax;
                printf("With tax included, your final bill is: $%.2f\n", final_cost);
                break;

            default:
                printf("\nInvalid choice, please try again.\n");


        }

        i++;

    } while (menu_choice != 6);

    return 0;
}