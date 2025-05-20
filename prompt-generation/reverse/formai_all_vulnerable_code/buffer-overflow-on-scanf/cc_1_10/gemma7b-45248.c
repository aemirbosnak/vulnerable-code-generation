//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT_NUM 100

typedef struct UnitConverter
{
    char unit_from[20];
    char unit_to[20];
    double conversion_factor;
} UnitConverter;

UnitConverter unit_converter_table[] = 
{
    {"kg", "g", 1000},
    {"L", "ml", 1000},
    {"m", "cm", 100},
    {"km", "km", 1},
    {"s", "min", 60},
    {"h", "day", 24}
};

int main()
{
    char unit_from[20];
    char unit_to[20];
    double quantity;
    double converted_quantity;
    int i;

    printf("Enter the unit you want to convert from: ");
    scanf("%s", unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit_to);

    printf("Enter the quantity you want to convert: ");
    scanf("%lf", &quantity);

    for (i = 0; i < MAX_CONVERT_NUM; i++)
    {
        if (strcmp(unit_converter_table[i].unit_from, unit_from) == 0 && strcmp(unit_converter_table[i].unit_to, unit_to) == 0)
        {
            converted_quantity = quantity * unit_converter_table[i].conversion_factor;
            break;
        }
    }

    if (i == MAX_CONVERT_NUM)
    {
        printf("Error: Unit conversion not found.\n");
        return 1;
    }

    printf("The converted quantity is: %.2lf %s.\n", converted_quantity, unit_to);

    return 0;
}