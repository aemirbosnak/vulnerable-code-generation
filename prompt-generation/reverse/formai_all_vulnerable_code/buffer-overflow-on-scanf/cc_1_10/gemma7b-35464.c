//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int a, b, c, d, e, f, g;
    char ch;

    printf("Welcome to the C Mortgage Calculator!\n");
    printf("Please enter the loan amount: ");
    scanf("%d", &a);

    printf("Please enter the interest rate (as a decimal): ");
    scanf("%f", &b);

    printf("Please enter the number of years: ");
    scanf("%d", &c);

    printf("Please select an option:\n");
    printf("1. Calculate monthly payment\n");
    printf("2. Calculate total interest\n");
    printf("3. Calculate total cost\n");

    scanf("%d", &d);

    switch (d)
    {
        case 1:
            e = a * (b / 100) * c;
            f = e / 12;
            printf("The monthly payment is $%d.\n", f);
            break;

        case 2:
            g = a * (b / 100) * c;
            printf("The total interest is $%d.\n", g);
            break;

        case 3:
            e = a * (b / 100) * c;
            f = e / 12;
            g = a * (b / 100) * c - f;
            printf("The total cost is $%d.\n", g);
            break;

        default:
            printf("Invalid input.\n");
    }

    return 0;
}