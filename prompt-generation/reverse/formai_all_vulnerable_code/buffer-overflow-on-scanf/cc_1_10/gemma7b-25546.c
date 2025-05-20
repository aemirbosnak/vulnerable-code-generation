//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

double unit_converter(char *unit_from, char *unit_to)
{
    double conversion_factor = 0;

    if (strcmp(unit_from, "kg") == 0 && strcmp(unit_to, "g") == 0)
    {
        conversion_factor = 1000;
    }
    else if (strcmp(unit_from, "g") == 0 && strcmp(unit_to, "kg") == 0)
    {
        conversion_factor = 0.001;
    }
    else if (strcmp(unit_from, "l") == 0 && strcmp(unit_to, "ml") == 0)
    {
        conversion_factor = 1000;
    }
    else if (strcmp(unit_from, "ml") == 0 && strcmp(unit_to, "l") == 0)
    {
        conversion_factor = 0.001;
    }
    else
    {
        printf("Error: Unit conversion not supported.\n");
        exit(1);
    }

    return conversion_factor;
}

int main()
{
    char unit_from[20];
    char unit_to[20];
    double mass;
    double conversion_factor;

    printf("Enter the unit you want to convert from: ");
    scanf("%s", unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit_to);

    printf("Enter the mass: ");
    scanf("%lf", &mass);

    conversion_factor = unit_converter(unit_from, unit_to);

    if (conversion_factor != 0)
    {
        double converted_mass = mass * conversion_factor;

        printf("The converted mass is: %.2lf %s.\n", converted_mass, unit_to);
    }

    return 0;
}