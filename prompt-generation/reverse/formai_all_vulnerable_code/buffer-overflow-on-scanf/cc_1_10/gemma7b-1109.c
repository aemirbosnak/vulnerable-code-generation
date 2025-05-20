//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>
#include <math.h>

void UnitConverter(float value, int fromUnit, int toUnit)
{
    switch (fromUnit)
    {
        case 0:
            switch (toUnit)
            {
                case 1:
                    printf("%f is equal to %.2f units of mass in kilograms.", value, value * 1000);
                    break;
                case 2:
                    printf("%f is equal to %.2f units of mass in grams.", value, value * 1000);
                    break;
                case 3:
                    printf("%f is equal to %.2f units of mass in milligrams.", value, value * 1000);
                    break;
            }
            break;
        case 1:
            switch (toUnit)
            {
                case 0:
                    printf("%f is equal to %.2f units of mass in kilograms.", value, value / 1000);
                    break;
                case 2:
                    printf("%f is equal to %.2f units of mass in grams.", value, value / 1000 * 1000);
                    break;
                case 3:
                    printf("%f is equal to %.2f units of mass in milligrams.", value, value / 1000 * 1000 * 1000);
                    break;
            }
            break;
        case 2:
            switch (toUnit)
            {
                case 0:
                    printf("%f is equal to %.2f units of mass in kilograms.", value, value / 1000);
                    break;
                case 1:
                    printf("%f is equal to %.2f units of mass in grams.", value, value / 1000 * 1000);
                    break;
                case 3:
                    printf("%f is equal to %.2f units of mass in milligrams.", value, value / 1000 * 1000 * 1000);
                    break;
            }
            break;
        case 3:
            switch (toUnit)
            {
                case 0:
                    printf("%f is equal to %.2f units of mass in kilograms.", value, value / 1000);
                    break;
                case 1:
                    printf("%f is equal to %.2f units of mass in grams.", value, value / 1000 * 1000);
                    break;
                case 2:
                    printf("%f is equal to %.2f units of mass in milligrams.", value, value / 1000 * 1000 * 1000);
                    break;
            }
            break;
    }
}

int main()
{
    float value;
    int fromUnit, toUnit;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the unit you want to convert from (0-3): ");
    scanf("%d", &fromUnit);

    printf("Enter the unit you want to convert to (0-3): ");
    scanf("%d", &toUnit);

    UnitConverter(value, fromUnit, toUnit);

    return 0;
}