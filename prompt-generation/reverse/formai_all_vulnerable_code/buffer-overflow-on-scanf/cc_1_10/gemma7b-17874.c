//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ConverTION_TEMPERATURE 500

typedef struct Conversion
{
    double current_temperature;
    double target_temperature;
    double conversion_factor;
    char conversion_unit;
} Conversion;

void calculate_conversion_factor(Conversion *conversion)
{
    switch (conversion->conversion_unit)
    {
        case 'C':
            conversion->conversion_factor = 1.0;
            break;
        case 'F':
            conversion->conversion_factor = (1.8 * conversion->current_temperature) + 32.0;
            break;
        case 'K':
            conversion->conversion_factor = conversion->current_temperature + 273.15;
            break;
        default:
            printf("Error: Invalid conversion unit.\n");
            exit(1);
    }
}

void convert_temperature(Conversion *conversion)
{
    conversion->target_temperature = conversion->current_temperature * conversion->conversion_factor;
}

int main()
{
    Conversion conversion;

    // Get the current temperature.
    printf("Enter the current temperature: ");
    scanf("%lf", &conversion.current_temperature);

    // Get the target temperature unit.
    printf("Enter the target temperature unit (C, F, K): ");
    scanf("%c", &conversion.conversion_unit);

    // Calculate the conversion factor.
    calculate_conversion_factor(&conversion);

    // Convert the temperature.
    convert_temperature(&conversion);

    // Get the target temperature.
    printf("The target temperature is: %.2lf %c.\n", conversion.target_temperature, conversion.conversion_unit);

    return 0;
}