//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <math.h>

int main()
{
    float f_value;
    int unit_from, unit_to;
    float conversion_factor;

    // Get the value, unit from, and unit to
    printf("Enter the value: ");
    scanf("%f", &f_value);

    printf("Enter the unit you want to convert from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &unit_to);

    // Calculate the conversion factor
    switch (unit_from)
    {
        case 1:
            conversion_factor = 1;
            break;
        case 2:
            conversion_factor = 2.2;
            break;
        case 3:
            conversion_factor = 2.26;
            break;
        case 4:
            conversion_factor = 3.86;
            break;
        default:
            printf("Invalid unit from.\n");
            return 1;
    }

    switch (unit_to)
    {
        case 1:
            conversion_factor = 1;
            break;
        case 2:
            conversion_factor = 0.454;
            break;
        case 3:
            conversion_factor = 0.454;
            break;
        case 4:
            conversion_factor = 0.621;
            break;
        default:
            printf("Invalid unit to.\n");
            return 1;
    }

    // Convert the value
    float converted_value = f_value * conversion_factor;

    // Print the converted value
    printf("The converted value is: %.2f\n", converted_value);

    return 0;
}