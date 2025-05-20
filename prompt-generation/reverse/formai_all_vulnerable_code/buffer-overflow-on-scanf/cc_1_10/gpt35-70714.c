//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>

int main()
{
    float coffee_price = 2.50;
    float latte_price = 3.00;
    float muffin_price = 1.50;
    float sub_total = 0.00, tax = 0.00, total = 0.00;
    char option;
    int coffee_qty = 0, latte_qty = 0, muffin_qty = 0;

    printf("\n\tCafe Billing System\n\n");

    printf("Coffee - $%.2f\n", coffee_price);
    printf("Latte - $%.2f\n", latte_price);
    printf("Muffin - $%.2f\n\n", muffin_price);

    do {
        printf("Enter option (C/L/M) or E to exit: ");
        scanf(" %c", &option);

        if (option == 'C' || option == 'c') {
            printf("Enter quantity: ");
            scanf("%d", &coffee_qty);
            sub_total += coffee_qty * coffee_price;
        } else if (option == 'L' || option == 'l') {
            printf("Enter quantity: ");
            scanf("%d", &latte_qty);
            sub_total += latte_qty * latte_price;
        } else if (option == 'M' || option == 'm') {
            printf("Enter quantity: ");
            scanf("%d", &muffin_qty);
            sub_total += muffin_qty * muffin_price;
        } else {
            printf("Invalid option, try again.\n");
        }
    } while (option != 'E' && option != 'e');

    tax = sub_total * 0.1;
    total = sub_total + tax;

    printf("\n\n\tItems\tQty\tPrice\n");
    printf("-------------------------------------------\n");
    printf("\tCoffee\t%d\t%.2f\n", coffee_qty, coffee_price);
    printf("\tLatte\t%d\t%.2f\n", latte_qty, latte_price);
    printf("\tMuffin\t%d\t%.2f\n", muffin_qty, muffin_price);
    printf("-------------------------------------------\n");
    printf("\tSub Total\t%.2f\n", sub_total);
    printf("\tTax (10%%)\t%.2f\n", tax);
    printf("\tTotal\t\t%.2f\n\n", total);

    printf("Thank you for visiting, please come again!\n");

    return 0;
}