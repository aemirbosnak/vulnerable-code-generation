//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

int main()
{
    char choice;
    double temperature;

    printf("Welcome to the Retro Temperature Converter!\n");
    printf("Please enter your temperature (C for Celsius, F for Fahrenheit): ");
    scanf("%c", &choice);

    switch(choice)
    {
        case 'C':
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, celsius_to_fahrenheit(temperature));
            break;

        case 'F':
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, fahrenheit_to_celsius(temperature));
            break;

        default:
            printf("Invalid input. Please enter C or F.\n");
    }

    return 0;
}

// Converts Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius)
{
    double fahrenheit;

    fahrenheit = (celsius * 9/5) + 32;

    return fahrenheit;
}

// Converts Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit)
{
    double celsius;

    celsius = (fahrenheit - 32) * 5/9;

    return celsius;
}