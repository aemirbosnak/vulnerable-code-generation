//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void convert_currency(double amount, char from_currency, char to_currency)
{
    double conversion_factor = 0;

    switch (from_currency)
    {
        case 'USD':
            switch (to_currency)
            {
                case 'EUR':
                    conversion_factor = 0.99;
                    break;
                case 'GBP':
                    conversion_factor = 0.84;
                    break;
                case 'JPY':
                    conversion_factor = 1.14;
                    break;
            }
            break;
        case 'EUR':
            switch (to_currency)
            {
                case 'USD':
                    conversion_factor = 1.01;
                    break;
                case 'GBP':
                    conversion_factor = 0.88;
                    break;
                case 'JPY':
                    conversion_factor = 1.22;
                    break;
            }
            break;
        case 'GBP':
            switch (to_currency)
            {
                case 'USD':
                    conversion_factor = 1.16;
                    break;
                case 'EUR':
                    conversion_factor = 1.11;
                    break;
                case 'JPY':
                    conversion_factor = 1.33;
                    break;
            }
            break;
        case 'JPY':
            switch (to_currency)
            {
                case 'USD':
                    conversion_factor = 0.89;
                    break;
                case 'EUR':
                    conversion_factor = 0.81;
                    break;
                case 'GBP':
                    conversion_factor = 0.74;
                    break;
            }
            break;
    }

    double converted_amount = amount * conversion_factor;

    printf("The converted amount is: %.2lf %s", converted_amount, to_currency);
}

int main()
{
    double amount;
    char from_currency;
    char to_currency;

    printf("Enter the amount:");
    scanf("%lf", &amount);

    printf("Enter the from currency:");
    scanf(" %c", &from_currency);

    printf("Enter the to currency:");
    scanf(" %c", &to_currency);

    convert_currency(amount, from_currency, to_currency);

    return 0;
}