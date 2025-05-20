//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <math.h>

void UnitConverter(float value, char unit_from, char unit_to)
{
    switch (unit_from)
    {
        case 'm':
            switch (unit_to)
            {
                case 'kg':
                    printf("%f kg = %f tons", value, value * 1000);
                    break;
                case 'g':
                    printf("%f g = %f mg", value, value * 1000);
                    break;
                case 't':
                    printf("%f t = %f tons", value, value * 1000);
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    printf("%f kg = %f m", value, value / 1000);
                    break;
                case 'g':
                    printf("%f kg = %f g", value, value * 1000);
                    break;
                case 't':
                    printf("%f kg = %f t", value, value / 1000);
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'm':
                    printf("%f g = %f m", value, value / 1000);
                    break;
                case 'kg':
                    printf("%f g = %f kg", value, value / 1000);
                    break;
                case 't':
                    printf("%f g = %f t", value, value / 1000);
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'm':
                    printf("%f t = %f m", value, value * 1000);
                    break;
                case 'kg':
                    printf("%f t = %f kg", value, value * 1000);
                    break;
                case 'g':
                    printf("%f t = %f g", value, value * 1000);
                    break;
            }
            break;
    }
}

int main()
{
    float value;
    char unit_from;
    char unit_to;

    printf("Enter the value:");
    scanf("%f", &value);

    printf("Enter the unit you are converting from:");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to:");
    scanf(" %c", &unit_to);

    UnitConverter(value, unit_from, unit_to);

    return 0;
}