//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

int main()
{
    char choice;
    double temperature;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please select an option:\n");
    printf("A. Celsius to Fahrenheit\n");
    printf("B. Fahrenheit to Celsius\n");
    scanf(" %c", &choice);

    if(choice == 'A' || choice == 'a')
    {
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &temperature);
        printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
    }
    else if(choice == 'B' || choice == 'b')
    {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%lf", &temperature);
        printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
    }
    else
    {
        printf("Invalid option selected.\n");
    }

    return 0;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius)
{
    double fahrenheit;

    fahrenheit = (celsius * 9.0) / 5.0 + 32.0;

    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit)
{
    double celsius;

    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;

    return celsius;
}