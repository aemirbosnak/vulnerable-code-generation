//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: immersive
#include <stdio.h>
#include <math.h>

int main()
{
    float f_value;
    int unit_from, unit_to;

    printf("Enter the value you want to convert: ");
    scanf("%f", &f_value);

    printf("Enter the unit you want to convert from (e.g. km, kg, etc.): ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to (e.g. km, kg, etc.): ");
    scanf("%d", &unit_to);

    switch (unit_from)
    {
        case 1: // km
            switch (unit_to)
            {
                case 2: // m
                    f_value *= 1000;
                    break;
                case 3: // cm
                    f_value *= 1000000;
                    break;
            }
            break;
        case 2: // m
            switch (unit_to)
            {
                case 1: // km
                    f_value /= 1000;
                    break;
                case 3: // cm
                    f_value *= 1000;
                    break;
            }
            break;
        case 3: // cm
            switch (unit_to)
            {
                case 1: // km
                    f_value /= 1000000;
                    break;
                case 2: // m
                    f_value /= 1000;
                    break;
            }
            break;
    }

    printf("The converted value is: %.2f %s", f_value, unit_to);

    return 0;
}