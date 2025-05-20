//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);

int main()
{
    float temperature, converted_temp;
    char choice;

    // Get user input for temperature and unit of measurement
    printf("Enter temperature: ");
    scanf("%f", &temperature);

    printf("Enter unit of measurement (C for Celsius or F for Fahrenheit): ");
    scanf(" %c", &choice);

    // Convert temperature based on user input
    if (choice == 'C' || choice == 'c')
    {
        converted_temp = fahrenheit_to_celsius(temperature);
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, converted_temp);
    }
    else if (choice == 'F' || choice == 'f')
    {
        converted_temp = celsius_to_fahrenheit(temperature);
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, converted_temp);
    }
    else
    {
        printf("Invalid unit of measurement.\n");
    }

    return 0;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius)
{
    float fahrenheit;

    // Formula: (°C × 9/5) + 32 = °F
    fahrenheit = (celsius * 9/5) + 32;

    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit)
{
    float celsius;

    // Formula: (°F - 32) × 5/9 = °C
    celsius = (fahrenheit - 32) * 5/9;

    return celsius;
}