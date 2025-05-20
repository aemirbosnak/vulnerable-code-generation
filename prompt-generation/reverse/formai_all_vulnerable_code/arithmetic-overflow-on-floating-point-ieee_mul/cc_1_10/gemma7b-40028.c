//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

#define MAX_CONVERT_TEMP 500

int main()
{
    float f_temp, c_temp, k_temp;
    char unit;

    // Display welcome message
    printf("Welcome to the Temperature Converter!\n");

    // Get the input temperature and unit
    printf("Enter the temperature: ");
    scanf("%f", &f_temp);

    printf("Enter the unit (C/F/K): ");
    scanf(" %c", &unit);

    // Convert the temperature
    switch (unit)
    {
        case 'C':
            c_temp = f_temp;
            break;
        case 'F':
            c_temp = (f_temp - 32) * 5 / 9;
            break;
        case 'K':
            c_temp = f_temp + 273.15;
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    // Display the converted temperature
    printf("The converted temperature is: %.2f %s.\n", c_temp, unit);

    // Convert the temperature to Kelvin
    k_temp = c_temp + 273.15;

    // Display the converted temperature in Kelvin
    printf("The converted temperature in Kelvin is: %.2f K.\n", k_temp);

    // Check if the converted temperature exceeds the maximum limit
    if (c_temp > MAX_CONVERT_TEMP)
    {
        printf("Warning: The converted temperature exceeds the maximum limit of %d degrees.", MAX_CONVERT_TEMP);
    }

    return 0;
}