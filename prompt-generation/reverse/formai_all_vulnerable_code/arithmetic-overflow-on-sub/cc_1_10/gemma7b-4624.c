//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, temperature, unit_from, unit_to;
    float converted_temperature;

    // Display menu options
    printf("Select an option:\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Convert Kelvin to Celsius\n");
    printf("4. Convert Kelvin to Fahrenheit\n");

    // Get user input
    scanf("Enter your choice: ", &choice);

    // Calculate conversion factor based on user's choice
    switch (choice)
    {
        case 1:
            unit_from = 0;
            unit_to = 1;
            converted_temperature = (temperature - 32) * 5 / 9 + 0;
            break;
        case 2:
            unit_from = 1;
            unit_to = 0;
            converted_temperature = (temperature * 9 / 5) + 32;
            break;
        case 3:
            unit_from = 2;
            unit_to = 1;
            converted_temperature = temperature - 273.15;
            break;
        case 4:
            unit_from = 2;
            unit_to = 0;
            converted_temperature = (temperature + 273.15) * 9 / 5 + 32;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    // Display converted temperature
    printf("Converted temperature: %.2f %s\n", converted_temperature, unit_to);

    return 0;
}