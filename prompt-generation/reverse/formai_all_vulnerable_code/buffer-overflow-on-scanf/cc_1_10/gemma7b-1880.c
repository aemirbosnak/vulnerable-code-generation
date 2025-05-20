//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the conversion function
double convert_temp(double temp, char unit)
{
    double conversion_factor = 1;

    switch (unit)
    {
        case 'C':
            break;
        case 'F':
            conversion_factor = 1.8;
            temp = (temp - 32) * conversion_factor;
            break;
        case 'K':
            conversion_factor = 1.8;
            temp = temp + 273.15;
            break;
    }

    return temp;
}

int main()
{
    double temperature;
    char unit_from, unit_to;

    // Get the temperature, unit of origin, and unit of destination
    printf("Enter the temperature: ");
    scanf("%lf", &temperature);

    printf("Enter the unit of origin (C/F/K): ");
    scanf(" %c", &unit_from);

    printf("Enter the unit of destination (C/F/K): ");
    scanf(" %c", &unit_to);

    // Convert the temperature
    double converted_temperature = convert_temp(temperature, unit_from);

    // Convert the temperature to the specified unit
    converted_temperature = convert_temp(converted_temperature, unit_to);

    // Print the converted temperature
    printf("The converted temperature is: %.2lf %s", converted_temperature, unit_to);

    return 0;
}