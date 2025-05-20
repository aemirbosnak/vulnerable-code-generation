//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cappuccino = 100, latte = 120, americano = 90, espresso = 80, frappe = 150, total = 0, quantity;

    printf("Welcome to Cafe X!\n\n");
    printf("MENU:\n");
    printf("1. Cappuccino - Php 100\n");
    printf("2. Latte - Php 120\n");
    printf("3. Americano - Php 90\n");
    printf("4. Espresso - Php 80\n");
    printf("5. Frappe - Php 150\n\n");

    // take order
    printf("What would you like to order?\n");
    printf("Enter 0 to exit.\n\n");

    while (1) {
        int choice;
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Selected: Cappuccino\n");
                printf("How many cups? ");
                scanf("%d", &quantity);
                total += cappuccino * quantity;
                printf("Added to cart!\n\n");
                break;
            case 2:
                printf("Selected: Latte\n");
                printf("How many cups? ");
                scanf("%d", &quantity);
                total += latte * quantity;
                printf("Added to cart!\n\n");
                break;
            case 3:
                printf("Selected: Americano\n");
                printf("How many cups? ");
                scanf("%d", &quantity);
                total += americano * quantity;
                printf("Added to cart!\n\n");
                break;
            case 4:
                printf("Selected: Espresso\n");
                printf("How many cups? ");
                scanf("%d", &quantity);
                total += espresso * quantity;
                printf("Added to cart!\n\n");
                break;
            case 5:
                printf("Selected: Frappe\n");
                printf("How many cups? ");
                scanf("%d", &quantity);
                total += frappe * quantity;
                printf("Added to cart!\n\n");
                break;
            default:
                printf("Invalid input!\n\n");
        }
    }

    // show total
    printf("Thank you for your order!\n");
    printf("Your total is: %d\n", total);

    return 0;
}