//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include <stdio.h>
#include <math.h>

#define PI 3.14159

// Function prototypes
double convert_celsius_to_fahrenheit(double celsius);
double convert_fahrenheit_to_celsius(double fahrenheit);

int main()
{
    double temperature, conversion_factor, converted_temperature;

    // Display welcome message
    printf("Welcome to the Temperature Converter!\n");

    // Get the temperature and conversion factor
    printf("Enter the temperature: ");
    scanf("%lf", &temperature);

    printf("Enter the conversion factor (1 for Fahrenheit, 2 for Celsius): ");
    scanf("%lf", &conversion_factor);

    // Convert the temperature
    if (conversion_factor == 1)
    {
        converted_temperature = convert_celsius_to_fahrenheit(temperature);
        printf("The converted temperature is: %.2lf Fahrenheit.\n", converted_temperature);
    }
    else if (conversion_factor == 2)
    {
        converted_temperature = convert_fahrenheit_to_celsius(temperature);
        printf("The converted temperature is: %.2lf Celsius.\n", converted_temperature);
    }
    else
    {
        printf("Invalid conversion factor.\n");
    }

    // Display farewell message
    printf("Thank you for using the Temperature Converter!\n");

    return 0;
}

// Function to convert Celsius to Fahrenheit
double convert_celsius_to_fahrenheit(double celsius)
{
    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double convert_fahrenheit_to_celsius(double fahrenheit)
{
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return celsius;
}