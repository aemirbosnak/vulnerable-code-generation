//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);

int main()
{
    float celsius, fahrenheit;
    char choice;

    /* Temperature Conversion Loop */
    do
    {
        /* Display Menu */
        printf("\n Temperature Conversion Menu\n");
        printf("------------------------------------\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("------------------------------------\n");

        /* Get User Choice */
        scanf("%c", &choice);

        /* Validate User Choice */
        switch(choice)
        {
            case '1':
                /* Celsius to Fahrenheit Conversion */
                printf("\n Enter Temperature in Celsius: ");
                scanf("%f", &celsius);
                printf("\n Temperature in Fahrenheit: %.2f\n", celsiusToFahrenheit(celsius));
                break;

            case '2':
                /* Fahrenheit to Celsius Conversion */
                printf("\n Enter Temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                printf("\n Temperature in Celsius: %.2f\n", fahrenheitToCelsius(fahrenheit));
                break;

            case '3':
                /* Exit Program */
                printf("\n Exiting Temperature Conversion Program...\n");
                break;

            default:
                /* Invalid User Choice */
                printf("\n Invalid Choice! Please Try Again...\n");
                break;
        }

    } while(choice!= '3');

    return 0;
}

/* Celsius to Fahrenheit Conversion Function */
float celsiusToFahrenheit(float celsius)
{
    float fahrenheit;

    /* Conversion Formula: F = (C * 1.8) + 32 */
    fahrenheit = (celsius * 1.8) + 32;

    return fahrenheit;
}

/* Fahrenheit to Celsius Conversion Function */
float fahrenheitToCelsius(float fahrenheit)
{
    float celsius;

    /* Conversion Formula: C = (F - 32) / 1.8 */
    celsius = (fahrenheit - 32) / 1.8;

    return celsius;
}