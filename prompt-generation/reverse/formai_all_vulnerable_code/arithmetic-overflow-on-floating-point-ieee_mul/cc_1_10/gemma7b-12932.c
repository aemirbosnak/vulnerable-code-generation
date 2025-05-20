//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>
#include <math.h>

// Define a macro for converting units of length
#define UNIT_CONVERT(x, from, to) (x) * pow(10, from - to)

// Function to convert meters to kilometers
double meters_to_kilometers(double meters)
{
    return UNIT_CONVERT(meters, 2, 3);
}

// Function to convert liters to cubic meters
double liters_to_cubic_meters(double liters)
{
    return UNIT_CONVERT(liters, 3, 3);
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

    switch (from_unit)
    {
        case 'm':
            switch (to_unit)
            {
                case 'k':
                    printf("The converted value is: %.2lf kilometers.\n", meters_to_kilometers(value));
                    break;
                case 'c':
                    printf("The converted value is: %.2lf centimeters.\n", meters_to_kilometers(value) * 100);
                    break;
            }
            break;
        case 'l':
            switch (to_unit)
            {
                case 'm':
                    printf("The converted value is: %.2lf meters.\n", liters_to_cubic_meters(value));
                    break;
                case 'dm':
                    printf("The converted value is: %.2lf decimeters.\n", liters_to_cubic_meters(value) * 10);
                    break;
            }
            break;
    }

    return 0;
}