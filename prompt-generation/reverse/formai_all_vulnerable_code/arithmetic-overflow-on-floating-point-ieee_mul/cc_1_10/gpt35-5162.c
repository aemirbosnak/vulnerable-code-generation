//FormAI DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float kelvin_to_celsius(float kelvin);
float celsius_to_kelvin(float celsius);

int main()
{
    int choice;
    float value, result;
    printf("Welcome to the C Unit Converter\n");
    printf("Please select the conversion that you want to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("Your choice (1-4): ");
    scanf("%d", &choice);
    printf("Enter the value you want to convert: ");
    scanf("%f", &value);
    switch (choice)
    {
        case 1:
            result = celsius_to_fahrenheit(value);
            printf("%.2f Celsius is %.2f Fahrenheit\n", value, result);
            break;
        case 2:
            result = fahrenheit_to_celsius(value);
            printf("%.2f Fahrenheit is %.2f Celsius\n", value, result);
            break;
        case 3:
            result = kelvin_to_celsius(value);
            printf("%.2f Kelvin is %.2f Celsius\n", value, result);
            break;
        case 4:
            result = celsius_to_kelvin(value);
            printf("%.2f Celsius is %.2f Kelvin\n", value, result);
            break;
        default:
            printf("Invalid choice, please select a number between 1 and 4\n");
            return 1;
    }
    return 0;
}

/* Function to convert celsius to fahrenheit */
float celsius_to_fahrenheit(float celsius)
{
    return (celsius * 9/5) + 32;
}

/* Function to convert fahrenheit to celsius */
float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32) * 5/9;
}

/* Function to convert kelvin to celsius */
float kelvin_to_celsius(float kelvin)
{
    return kelvin - 273.15;
}

/* Function to convert celsius to kelvin */
float celsius_to_kelvin(float celsius)
{
    return celsius + 273.15;
}