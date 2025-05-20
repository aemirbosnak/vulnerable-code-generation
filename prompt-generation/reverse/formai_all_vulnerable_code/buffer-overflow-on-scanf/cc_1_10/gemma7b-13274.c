//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice;
    float temperature, conversion_factor, result;

    // Display menu options
    printf("Enter 1 for Fahrenheit to Celsius conversion.\n");
    printf("Enter 2 for Celsius to Fahrenheit conversion.\n");
    printf("Enter 3 for Kelvin to Celsius conversion.\n");
    printf("Enter 4 for Celsius to Kelvin conversion.\n");

    // Get user input
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Calculate conversion factor based on user's choice
    switch (choice)
    {
        case 1:
            conversion_factor = (5.0 / 9.0) * 100;
            break;
        case 2:
            conversion_factor = 1.8 * temperature + 32;
            break;
        case 3:
            conversion_factor = temperature - 273.15;
            break;
        case 4:
            conversion_factor = (temperature - 273.15) * 1.8 + 32;
            break;
        default:
            printf("Invalid choice.\n");
            exit(1);
    }

    // Get the temperature to be converted
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    // Convert the temperature
    result = temperature * conversion_factor;

    // Display the converted temperature
    printf("The converted temperature is: %.2f\n", result);

    return 0;
}