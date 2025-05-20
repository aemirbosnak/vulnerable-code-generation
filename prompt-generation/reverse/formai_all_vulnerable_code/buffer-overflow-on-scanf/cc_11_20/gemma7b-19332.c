//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char unit_from, unit_to;
    float temperature;

    // The remnants of a once great city
    printf("Welcome to the ruins of Old New York, where the heat still scorches the earth.\n");

    // Get the user's input
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    // Get the user's unit preference
    printf("Enter the unit you want to convert from (C, F, K): ");
    scanf(" %c", &unit_from);

    // Get the user's desired unit of conversion
    printf("Enter the unit you want to convert to (C, F, K): ");
    scanf(" %c", &unit_to);

    // Convert the temperature
    float converted_temperature;

    if (unit_from == 'C' && unit_to == 'F')
    {
        converted_temperature = (temperature * 1.8) + 32;
    }
    else if (unit_from == 'C' && unit_to == 'K')
    {
        converted_temperature = temperature + 273.15;
    }
    else if (unit_from == 'F' && unit_to == 'C')
    {
        converted_temperature = (temperature - 32) * 5 / 9;
    }
    else if (unit_from == 'F' && unit_to == 'K')
    {
        converted_temperature = (temperature - 32) * 5 / 9 + 273.15;
    }
    else if (unit_from == 'K' && unit_to == 'C')
    {
        converted_temperature = temperature - 273.15;
    }
    else if (unit_from == 'K' && unit_to == 'F')
    {
        converted_temperature = (temperature - 273.15) * 9 / 5 + 32;
    }

    // Display the converted temperature
    printf("The converted temperature is: %.2f %s.\n", converted_temperature, unit_to);

    // The remnants of a once great city
    printf("May the ruins of Old New York serve as a reminder to the fleeting nature of all things.\n");

    return;
}