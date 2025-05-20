//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: innovative
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main()
{
    int choice, unit_from, unit_to;
    float temperature;

    // Display menu options
    printf("-------------------\n");
    printf("Temperature Converter\n");
    printf("-------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("-------------------\n");

    // Get user input
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Convert temperature units
    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &temperature);
            unit_from = 0;
            unit_to = 1;
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            unit_from = 1;
            unit_to = 0;
            break;
        case 3:
            printf("Enter the temperature in Kelvin: ");
            scanf("%f", &temperature);
            unit_from = 2;
            unit_to = 0;
            break;
        case 4:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &temperature);
            unit_from = 0;
            unit_to = 2;
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    // Calculate conversion factor
    float factor = 1;
    switch (unit_from)
    {
        case 0:
            factor = 1.8;
            break;
        case 1:
            factor = 0.555556;
            break;
        case 2:
            factor = 1;
            break;
    }

    // Convert temperature
    float converted_temperature = temperature * factor;

    // Display converted temperature
    printf("The converted temperature is: %.2f %s.\n", converted_temperature, unit_to);

    return 0;
}