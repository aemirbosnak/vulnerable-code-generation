//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include <stdio.h>

int main()
{
    int from_unit, to_unit, value;

    printf("Welcome to the Unit Converter!\n");
    printf("Please choose the unit you want to convert from:\n");
    printf("1. Liter\n");
    printf("2. Cubic Meter\n");
    printf("3. Cubic Centimeter\n");

    scanf("%d", &from_unit);

    printf("Please enter the value you want to convert:");
    scanf("%d", &value);

    printf("Please choose the unit you want to convert to:\n");
    printf("1. Liter\n");
    printf("2. Cubic Meter\n");
    printf("3. Cubic Centimeter\n");

    scanf("%d", &to_unit);

    switch (from_unit)
    {
        case 1:
            switch (to_unit)
            {
                case 1:
                    printf("The converted value is: %d liters.\n", value);
                    break;
                case 2:
                    printf("The converted value is: %f cubic meters.\n", (double)value / 1000);
                    break;
                case 3:
                    printf("The converted value is: %f cubic centimeters.\n", (double)value * 1000);
                    break;
            }
            break;
        case 2:
            switch (to_unit)
            {
                case 1:
                    printf("The converted value is: %d liters.\n", value * 1000);
                    break;
                case 2:
                    printf("The converted value is: %f cubic meters.\n", (double)value);
                    break;
                case 3:
                    printf("The converted value is: %f cubic centimeters.\n", (double)value * 1000);
                    break;
            }
            break;
        case 3:
            switch (to_unit)
            {
                case 1:
                    printf("The converted value is: %d liters.\n", value * 1000);
                    break;
                case 2:
                    printf("The converted value is: %f cubic meters.\n", (double)value / 1000);
                    break;
                case 3:
                    printf("The converted value is: %f cubic centimeters.\n", (double)value);
                    break;
            }
            break;
    }

    return 0;
}