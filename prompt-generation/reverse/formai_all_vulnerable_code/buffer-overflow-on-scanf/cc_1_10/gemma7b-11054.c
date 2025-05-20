//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    float usd, euro, pound, yen;

    printf("Enter the number of units you want to convert: ");
    scanf("%d", &num);

    printf("Enter the source currency (USD, EUR, GBP, Yen): ");
    char source_currency;
    scanf(" %c", &source_currency);

    printf("Enter the target currency (USD, EUR, GBP, Yen): ");
    char target_currency;
    scanf(" %c", &target_currency);

    switch (source_currency)
    {
        case 'USD':
            usd = num;
            euro = usd * 0.99;
            pound = usd * 0.84;
            yen = usd * 138.25;
            break;
        case 'EUR':
            euro = num;
            usd = euro * 1.01;
            pound = euro * 0.88;
            yen = euro * 138.25;
            break;
        case 'GBP':
            pound = num;
            usd = pound * 1.16;
            euro = pound * 1.11;
            yen = pound * 138.25;
            break;
        case 'Yen':
            yen = num;
            usd = yen * 0.0079;
            euro = yen * 0.0079;
            pound = yen * 0.0079;
            break;
    }

    switch (target_currency)
    {
        case 'USD':
            printf("The converted amount is: $%.2f", usd);
            break;
        case 'EUR':
            printf("The converted amount is: €%.2f", euro);
            break;
        case 'GBP':
            printf("The converted amount is: £%.2f", pound);
            break;
        case 'Yen':
            printf("The converted amount is: ¥%.2f", yen);
            break;
    }

    return 0;
}