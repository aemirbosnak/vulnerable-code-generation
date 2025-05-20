//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT 10

int main()
{
    int unit_type, from_unit, to_unit;
    float value;
    char convert_type[MAX_CONVERT];

    printf("Enter the unit type you want to convert from (e.g. km, kg, etc.): ");
    scanf("%s", convert_type);

    printf("Enter the value you want to convert: ");
    scanf("%f", &value);

    printf("Enter the unit type you want to convert to (e.g. km, kg, etc.): ");
    scanf("%s", convert_type);

    unit_type = find_unit_type(convert_type);
    from_unit = find_unit_type(convert_type);
    to_unit = find_unit_type(convert_type);

    switch (unit_type)
    {
        case 0:
            switch (to_unit)
            {
                case 0:
                    printf("The converted value is: %.2f km.", value);
                    break;
                case 1:
                    printf("The converted value is: %.2f m.", value * 1000);
                    break;
                case 2:
                    printf("The converted value is: %.2f miles.", value * 1.613);
                    break;
            }
            break;
        case 1:
            switch (to_unit)
            {
                case 0:
                    printf("The converted value is: %.2f km.", value / 1000);
                    break;
                case 1:
                    printf("The converted value is: %.2f m.", value);
                    break;
                case 2:
                    printf("The converted value is: %.2f miles.", value * 1.613);
                    break;
            }
            break;
        case 2:
            switch (to_unit)
            {
                case 0:
                    printf("The converted value is: %.2f km.", value * 1.613);
                    break;
                case 1:
                    printf("The converted value is: %.2f m.", value * 1.613 * 1000);
                    break;
                case 2:
                    printf("The converted value is: %.2f miles.", value);
                    break;
            }
            break;
    }

    return 0;
}

int find_unit_type(char *unit_type)
{
    if (strcmp(unit_type, "km") == 0)
        return 0;
    else if (strcmp(unit_type, "m") == 0)
        return 1;
    else if (strcmp(unit_type, "miles") == 0)
        return 2;
    else
        return -1;
}