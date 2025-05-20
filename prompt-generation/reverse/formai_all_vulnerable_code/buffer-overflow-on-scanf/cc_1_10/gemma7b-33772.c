//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float usd, euro, pound;
    char choice;

    printf("Enter the currency you want to convert from: (USD, EUR, GBP)\n");
    scanf("%c", &choice);

    printf("Enter the amount you want to convert: ");
    scanf("%f", &usd);

    switch (choice)
    {
        case 'u':
            euro = usd * 0.99;
            pound = usd * 0.84;
            break;
        case 'e':
            usd = euro * 1.01;
            pound = euro * 0.89;
            break;
        case 'p':
            usd = pound * 1.16;
            euro = pound * 1.06;
            break;
        default:
            printf("Invalid currency choice.\n");
            return 1;
    }

    printf("The converted amount is: ");
    switch (choice)
    {
        case 'u':
            printf("USD: %.2f\n", usd);
            printf("EUR: %.2f\n", euro);
            printf("GBP: %.2f\n", pound);
            break;
        case 'e':
            printf("USD: %.2f\n", usd);
            printf("EUR: %.2f\n", euro);
            printf("GBP: %.2f\n", pound);
            break;
        case 'p':
            printf("USD: %.2f\n", usd);
            printf("EUR: %.2f\n", euro);
            printf("GBP: %.2f\n", pound);
            break;
        default:
            printf("Invalid currency choice.\n");
            return 1;
    }

    return 0;
}