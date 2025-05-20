//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the conversion factor for different units
#define KM_TO_MILE 0.621371
#define LIT_TO_QUART 4
#define LITER_TO_GALLON 4.546

// Function to convert units
void convert_units(double value, char from_unit, char to_unit)
{
    switch (from_unit)
    {
        case 'k':
            value *= KM_TO_MILE;
            to_unit = 'm';
            break;
        case 'l':
            value *= LIT_TO_QUART;
            to_unit = 'q';
            break;
        case 'L':
            value *= LITER_TO_GALLON;
            to_unit = 'g';
            break;
    }

    switch (to_unit)
    {
        case 'm':
            printf("%f miles\n", value);
            break;
        case 'q':
            printf("%f quarts\n", value);
            break;
        case 'g':
            printf("%f gallons\n", value);
            break;
    }
}

int main()
{
    double value;
    char from_unit, to_unit;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit: ");
    scanf(" %c", &from_unit);

    printf("Enter the to unit: ");
    scanf(" %c", &to_unit);

    convert_units(value, from_unit, to_unit);

    return 0;
}