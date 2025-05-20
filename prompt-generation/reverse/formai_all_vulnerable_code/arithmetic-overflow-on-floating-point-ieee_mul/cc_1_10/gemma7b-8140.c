//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a function to convert units of length
double convert_length(double value, char from_unit, char to_unit)
{
    double conversion_factor;

    switch (from_unit)
    {
        case 'm':
            conversion_factor = 1;
            break;
        case 'cm':
            conversion_factor = 10;
            break;
        case 'km':
            conversion_factor = 1000;
            break;
    }

    switch (to_unit)
    {
        case 'm':
            conversion_factor = 1;
            break;
        case 'cm':
            conversion_factor = 0.1;
            break;
        case 'km':
            conversion_factor = 0.001;
            break;
    }

    return value * conversion_factor;
}

int main()
{
    double value;
    char from_unit;
    char to_unit;

    printf("Enter the value:");
    scanf("%lf", &value);

    printf("Enter the from unit:");
    scanf(" %c", &from_unit);

    printf("Enter the to unit:");
    scanf(" %c", &to_unit);

    double converted_value = convert_length(value, from_unit, to_unit);

    printf("The converted value is: %.2lf %s", converted_value, to_unit);

    return 0;
}