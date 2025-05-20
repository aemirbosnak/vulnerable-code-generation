//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

// Define the conversion function
double convert_units(double value, int from_unit, int to_unit)
{
    switch (from_unit)
    {
        case 0: // Meters
            switch (to_unit)
            {
                case 1: // Kilometers
                    return value * 1000;
                case 2: // Centimeters
                    return value * 100;
                case 3: // Millimeters
                    return value * 1000;
            }
            break;

        case 1: // Kilometers
            switch (to_unit)
            {
                case 0: // Meters
                    return value * 0.001;
                case 2: // Centimeters
                    return value * 1000;
                case 3: // Millimeters
                    return value * 1000;
            }
            break;

        case 2: // Centimeters
            switch (to_unit)
            {
                case 0: // Meters
                    return value * 0.01;
                case 1: // Kilometers
                    return value * 0.001;
                case 3: // Millimeters
                    return value * 10;
            }
            break;

        case 3: // Millimeters
            switch (to_unit)
            {
                case 0: // Meters
                    return value * 0.001;
                case 1: // Kilometers
                    return value * 0.001;
                case 2: // Centimeters
                    return value * 0.1;
            }
            break;
    }

    return -1; // Error
}

int main()
{
    double value;
    int from_unit, to_unit;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit (0 for meters, 1 for kilometers, 2 for centimeters, 3 for millimeters): ");
    scanf("%d", &from_unit);

    printf("Enter the to unit (0 for meters, 1 for kilometers, 2 for centimeters, 3 for millimeters): ");
    scanf("%d", &to_unit);

    double converted_value = convert_units(value, from_unit, to_unit);

    if (converted_value != -1)
    {
        printf("The converted value is: %.2lf", converted_value);
    }
    else
    {
        printf("Error!");
    }

    return 0;
}