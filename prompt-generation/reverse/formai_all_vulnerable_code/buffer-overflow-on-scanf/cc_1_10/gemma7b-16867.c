//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT_NUMBER 1000

typedef struct UnitConverter
{
    char unit_from[20];
    char unit_to[20];
    double conversion_factor;
} UnitConverter;

UnitConverter unit_converters[] =
{
    {"kg", "g", 1000},
    {"L", "ml", 1000},
    {"km", "m", 1000},
    {"h", "min", 60},
    {"min", "s", 60}
};

int main()
{
    double amount;
    char from_unit[20];
    char to_unit[20];

    printf("Enter the amount: ");
    scanf("%lf", &amount);

    printf("Enter the unit you want to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", to_unit);

    for (int i = 0; i < sizeof(unit_converters) / sizeof(UnitConverter); i++)
    {
        if (strcmp(from_unit, unit_converters[i].unit_from) == 0 && strcmp(to_unit, unit_converters[i].unit_to) == 0)
        {
            double converted_amount = amount * unit_converters[i].conversion_factor;
            printf("The converted amount is: %.2lf %s\n", converted_amount, unit_converters[i].unit_to);
            break;
        }
    }

    if (strcmp(from_unit, to_unit) == 0)
    {
        printf("Error: the units are the same.\n");
    }
    else
    {
        printf("Error: the units are not supported.\n");
    }

    return 0;
}