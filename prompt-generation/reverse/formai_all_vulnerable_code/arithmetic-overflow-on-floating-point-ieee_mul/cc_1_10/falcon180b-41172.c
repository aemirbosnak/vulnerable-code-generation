//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>

#define UNIT_LENGTH 50

struct unit
{
    char name[UNIT_LENGTH];
    double factor;
};

struct unit units[] =
{
    {"m", 1 },
    {"km", 1000 },
    {"cm", 0.01 },
    {"mm", 0.001 },
    {"mi", 160934 },
    {"yd", 1.09361 },
    {"ft", 0.3048 },
    {"in", 0.0254 },
};

int unit_count = sizeof(units) / sizeof(units[0]); // Number of units

int main()
{
    setlocale(LC_ALL, ""); // Set locale to support non-ASCII characters

    char input[UNIT_LENGTH];
    char output_unit[UNIT_LENGTH];
    double value;
    int i;

    printf("Enter the value you want to convert: ");
    fgets(input, UNIT_LENGTH, stdin);
    value = atof(input); // Convert input to double

    printf("Enter the output unit: ");
    fgets(output_unit, UNIT_LENGTH, stdin);
    for (i = 0; i < unit_count; i++)
    {
        if (strcmp(output_unit, units[i].name) == 0)
        {
            break;
        }
    }
    if (i == unit_count)
    {
        printf("Invalid output unit\n");
        return 1;
    }

    printf("Converted value: %g %s = %g %s\n", value, output_unit, value * units[i].factor, units[i - 1].name);

    return 0;
}