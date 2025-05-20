//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <math.h>

// Define the conversion factor for each unit
const int km_to_miles = 0.621371;
const int km_to_meters = 1000;
const int miles_to_km = 1.60934;
const int miles_to_meters = 1609.34;
const int meters_to_km = 0.001;
const int meters_to_miles = 0.000621371;

// Function to convert units
void convert_units(int unit_from, int unit_to, float value)
{
    switch (unit_from)
    {
        case 1: // kilometers
            switch (unit_to)
            {
                case 2: // miles
                    value *= km_to_miles;
                    break;
                case 3: // meters
                    value *= km_to_meters;
                    break;
            }
            break;
        case 2: // miles
            switch (unit_to)
            {
                case 1: // kilometers
                    value *= miles_to_km;
                    break;
                case 3: // meters
                    value *= miles_to_meters;
                    break;
            }
            break;
        case 3: // meters
            switch (unit_to)
            {
                case 1: // kilometers
                    value *= meters_to_km;
                    break;
                case 2: // miles
                    value *= meters_to_miles;
                    break;
            }
            break;
    }

    printf("The converted value is: %.2f", value);
}

int main()
{
    float value;
    int unit_from, unit_to;

    // Get the unit conversion parameters
    printf("Enter the unit you want to convert from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &unit_to);

    // Get the value to be converted
    printf("Enter the value to be converted: ");
    scanf("%f", &value);

    // Convert the units
    convert_units(unit_from, unit_to, value);

    return 0;
}