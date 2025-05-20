//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

double convert_temp(double temp, char unit, char target_unit)
{
    switch (unit)
    {
        case 'C':
            switch (target_unit)
            {
                case 'F':
                    return (temp * 1.8) + 32;
                case 'K':
                    return temp + 273.15;
            }
            break;
        case 'F':
            switch (target_unit)
            {
                case 'C':
                    return (temp - 32) * 5 / 9;
                case 'K':
                    return (temp - 32) * 5 / 9 + 273.15;
            }
            break;
        case 'K':
            switch (target_unit)
            {
                case 'C':
                    return temp - 273.15;
                case 'F':
                    return (temp - 273.15) * 9 / 5 + 32;
            }
            break;
    }

    return -1;
}

int main()
{
    double temp;
    char unit, target_unit;

    printf("Enter the temperature: ");
    scanf("%lf", &temp);

    printf("Enter the unit of the temperature (C, F, K): ");
    scanf(" %c", &unit);

    printf("Enter the target unit of the temperature (C, F, K): ");
    scanf(" %c", &target_unit);

    double converted_temp = convert_temp(temp, unit, target_unit);

    if (converted_temp != -1)
    {
        printf("The converted temperature is: %.2lf %s", converted_temp, target_unit);
    }
    else
    {
        printf("Error converting the temperature.");
    }

    return 0;
}