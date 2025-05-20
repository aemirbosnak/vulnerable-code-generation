//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void UnitConverter(void)
{
    int choice;
    float value;
    char unit_from, unit_to;

    printf("Enter 1 for Metric to Imperial or 2 for Imperial to Metric: ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the unit you are converting from: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you are converting to: ");
    scanf(" %c", &unit_to);

    switch (choice)
    {
        case 1:
            switch (unit_from)
            {
                case 'm':
                    switch (unit_to)
                    {
                        case 'kg':
                            printf("%f kg = %f tons", value, value * 1000);
                            break;
                        case 'g':
                            printf("%f g = %f lb", value, value * 0.0022046);
                            break;
                        case 'L':
                            printf("%f L = %f gallons", value, value * 1.05669);
                            break;
                        default:
                            printf("Invalid unit conversion");
                            break;
                    }
                    break;
                case 'kg':
                    switch (unit_to)
                    {
                        case 'm':
                            printf("%f kg = %f meters", value, value * 1000);
                            break;
                        case 'g':
                            printf("%f kg = %f grams", value, value * 1000000);
                            break;
                        case 'L':
                            printf("%f kg = %f liters", value, value * 1000);
                            break;
                        default:
                            printf("Invalid unit conversion");
                            break;
                    }
                    break;
                case 'L':
                    switch (unit_to)
                    {
                        case 'm':
                            printf("%f L = %f meters", value, value * 1000);
                            break;
                        case 'kg':
                            printf("%f L = %f kilograms", value, value * 1000);
                            break;
                        case 'g':
                            printf("%f L = %f grams", value, value * 1000000);
                            break;
                        default:
                            printf("Invalid unit conversion");
                            break;
                    }
                    break;
                default:
                    printf("Invalid unit conversion");
                    break;
            }
            break;
        case 2:
            switch (unit_from)
            {
                case 'kg':
                    switch (unit_to)
                    {
                        case 'm':
                            printf("%f kg = %f meters", value, value * 1000);
                            break;
                        case 'g':
                            printf("%f kg = %f grams", value, value * 1000000);
                            break;
                        case 'L':
                            printf("%f kg = %f liters", value, value * 1000);
                            break;
                        default:
                            printf("Invalid unit conversion");
                            break;
                    }
                    break;
                case 'g':
                    switch (unit_to)
                    {
                        case 'm':
                            printf("%f g = %f meters", value, value * 1000);
                            break;
                        case 'kg':
                            printf("%f g = %f kilograms", value, value * 0.001);
                            break;
                        case 'L':
                            printf("%f g = %f liters", value, value * 0.001);
                            break;
                        default:
                            printf("Invalid unit conversion");
                            break;
                    }
                    break;
                case 'L':
                    switch (unit_to)
                    {
                        case 'm':
                            printf("%f L = %f meters", value, value * 1000);
                            break;
                        case 'kg':
                            printf("%f L = %f kilograms", value, value * 1000);
                            break;
                        case 'g':
                            printf("%f L = %f grams", value, value * 1000000);
                            break;
                        default:
                            printf("Invalid unit conversion");
                            break;
                    }
                    break;
                default:
                    printf("Invalid unit conversion");
                    break;
            }
            break;
        default:
            printf("Invalid choice");
            break;
    }
}

int main(void)
{
    UnitConverter();

    return 0;
}