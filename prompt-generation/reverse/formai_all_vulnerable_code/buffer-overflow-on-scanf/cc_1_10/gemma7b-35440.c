//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: complex
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main()
{
    int choice, unit_from, unit_to;
    float value;

    // Display menu options
    printf("Select the unit you want to convert from:\n");
    printf("1. Meter\n");
    printf("2. Kilometer\n");
    printf("3. Mile\n");
    printf("4. Foot\n");

    // Get user input
    scanf("%d", &choice);

    // Convert the unit
    switch (choice)
    {
        case 1:
            unit_from = 1;
            unit_to = 2;
            break;
        case 2:
            unit_from = 2;
            unit_to = 3;
            break;
        case 3:
            unit_from = 3;
            unit_to = 4;
            break;
        case 4:
            unit_from = 4;
            unit_to = 1;
            break;
        default:
            printf("Invalid input\n");
            return 1;
    }

    // Get the value to be converted
    printf("Enter the value you want to convert: ");
    scanf("%f", &value);

    // Calculate the conversion factor
    float factor = 1;
    switch (unit_from)
    {
        case 1:
            factor = 1000;
            break;
        case 2:
            factor = 1000;
            break;
        case 3:
            factor = 1609.34;
            break;
        case 4:
            factor = 3.28084;
            break;
    }

    // Convert the value
    float converted_value = value * factor;

    // Display the converted value
    printf("The converted value is: %.2f %s\n", converted_value, unit_to);

    return 0;
}