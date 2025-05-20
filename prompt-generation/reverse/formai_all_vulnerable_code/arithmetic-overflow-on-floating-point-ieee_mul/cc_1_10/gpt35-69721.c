//FormAI DATASET v1.0 Category: Unit converter ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
double celciusToFahrenheit(double celcius);
double fahrenheitToCelcius(double fahrenheit);

int main()
{
    int choice;
    double valueToConvert;
    printf("\t~~~ UNIT CONVERTER ~~~\n\n");
    printf("Please select an option below: \n");
    printf("1. Celcius to Fahrenheit\n");
    printf("2. Fahrenheit to Celcius\n");
    printf("> ");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter Celcius value: ");
            scanf("%lf", &valueToConvert);

            printf("%.2lf C = %.2lf F\n", valueToConvert, celciusToFahrenheit(valueToConvert));
            break;
        case 2:
            printf("Enter Fahrenheit value: ");
            scanf("%lf", &valueToConvert);

            printf("%.2lf F = %.2lf C\n", valueToConvert, fahrenheitToCelcius(valueToConvert));
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

// Convert Celcius to Fahrenheit
double celciusToFahrenheit(double celcius)
{
    return (celcius * (9.0 / 5.0)) + 32.0;
}

// Convert Fahrenheit to Celcius
double fahrenheitToCelcius(double fahrenheit)
{
    return (fahrenheit - 32.0) * (5.0 / 9.0);
}