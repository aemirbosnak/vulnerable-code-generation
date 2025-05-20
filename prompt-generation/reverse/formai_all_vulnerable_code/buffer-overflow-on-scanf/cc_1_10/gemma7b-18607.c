//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <math.h>

#define PI 3.14159

void unit_converter(double value, int unit_from, int unit_to)
{
    switch (unit_from)
    {
        case 0: // Meters
            switch (unit_to)
            {
                case 1: // Centimeters
                    printf("%f meters is equal to %f centimeters.\n", value, value * 100);
                    break;
                case 2: // Kilometers
                    printf("%f meters is equal to %f kilometers.\n", value, value / 1000);
                    break;
            }
            break;
        case 1: // Centimeters
            switch (unit_to)
            {
                case 0: // Meters
                    printf("%f centimeters is equal to %f meters.\n", value, value / 100);
                    break;
                case 2: // Kilometers
                    printf("%f centimeters is equal to %f kilometers.\n", value, value / 100000);
                    break;
            }
            break;
        case 2: // Kilometers
            switch (unit_to)
            {
                case 0: // Meters
                    printf("%f kilometers is equal to %f meters.\n", value, value * 1000);
                    break;
                case 1: // Centimeters
                    printf("%f kilometers is equal to %f centimeters.\n", value, value * 1000 * 100);
                    break;
            }
            break;
    }
}

int main()
{
    double value;
    int unit_from, unit_to;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &unit_to);

    unit_converter(value, unit_from, unit_to);

    return 0;
}