//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: detailed
#include <stdio.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius)
{
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

int main()
{
    float temperature;
    char unit;
    char conversion_unit;

    // Get the temperature and unit
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    // Get the conversion unit
    printf("Enter the conversion unit (C/F): ");
    scanf(" %c", &unit);

    // Convert the temperature
    switch (unit)
    {
        case 'C':
            conversion_unit = 'F';
            temperature = celsius_to_fahrenheit(temperature);
            break;
        case 'F':
            conversion_unit = 'C';
            temperature = fahrenheit_to_celsius(temperature);
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    // Print the converted temperature
    printf("The converted temperature is: %.2f %c.\n", temperature, conversion_unit);

    return 0;
}