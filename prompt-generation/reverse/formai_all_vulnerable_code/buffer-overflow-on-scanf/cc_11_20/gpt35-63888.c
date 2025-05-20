//FormAI DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Declaration of variables
    float value;
    char from;
    char to;
    float result;

    printf("Welcome to the C Unit converter!\n");

    //Accepting user input
    printf("\nEnter the value you want to convert: ");
    scanf("%f", &value);

    printf("\nWhich unit do you want to convert from? (C, F, K, M, KPH, MPH): ");
    scanf(" %c", &from);

    printf("\nWhich unit do you want to convert to? (C, F, K, M, KPH, MPH): ");
    scanf(" %c", &to);

    //Conversion using switch case
    switch(from)
    {
        case 'C':
            switch(to)
            {
                case 'F':
                    result = (value * 9/5) + 32;
                    printf("\n%.2f Celsius = %.2f Fahrenheit\n", value, result);
                    break;
                case 'K':
                    result = value + 273.15;
                    printf("\n%.2f Celsius = %.2f Kelvin\n", value, result);
                    break;
                default:
                    printf("\nConversion not supported\n");
            }
            break;
        case 'F':
            switch(to)
            {
                case 'C':
                    result = (value - 32) * 5/9;
                    printf("\n%.2f Fahrenheit = %.2f Celsius\n", value, result);
                    break;
                default:
                    printf("\nConversion not supported\n");
            }
            break;
        case 'K':
            switch(to)
            {
                case 'C':
                    result = value - 273.15;
                    printf("\n%.2f Kelvin = %.2f Celsius\n", value, result);
                    break;
                default:
                    printf("\nConversion not supported\n");
            }
            break;
        case 'M':
            switch(to)
            {
                case 'K':
                    result = value / 1000;
                    printf("\n%.2f Meters = %.2f Kilometers\n", value, result);
                    break;
                default:
                    printf("\nConversion not supported\n");
            }
            break;
        case 'KPH':
            switch(to)
            {
                case 'MPH':
                    result = value / 1.609;
                    printf("\n%.2f Kilometers per Hour = %.2f Miles per Hour\n", value, result);
                    break;
                default:
                    printf("\nConversion not supported\n");
            }
            break;
        case 'MPH':
            switch(to)
            {
                case 'KPH':
                    result = value * 1.609;
                    printf("\n%.2f Miles per Hour = %.2f Kilometers per Hour\n", value, result);
                    break;
                default:
                    printf("\nConversion not supported\n");
            }
            break;
        default:
            printf("\nConversion not supported\n");
    }

    printf("\nThank you for using our converter! Goodbye!\n");

    return 0;
}