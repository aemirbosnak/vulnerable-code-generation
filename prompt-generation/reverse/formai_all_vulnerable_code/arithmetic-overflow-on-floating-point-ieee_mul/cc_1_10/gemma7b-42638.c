//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: scalable
#include <stdio.h>
#include <math.h>

void convert_temperature(double temp, char unit)
{
    double conversion_factor = 1;
    switch (unit)
    {
        case 'F':
            conversion_factor = 1.8;
            break;
        case 'C':
            conversion_factor = 1;
            break;
        case 'K':
            conversion_factor = 1.8 + 273.15;
            break;
    }

    double converted_temp = temp * conversion_factor;

    switch (unit)
    {
        case 'F':
            printf("%lf degrees Fahrenheit is equal to %lf degrees Celsius.\n", temp, converted_temp);
            break;
        case 'C':
            printf("%lf degrees Celsius is equal to %lf degrees Fahrenheit.\n", temp, converted_temp);
            break;
        case 'K':
            printf("%lf degrees Kelvin is equal to %lf degrees Celsius.\n", temp, converted_temp - 273.15);
            break;
    }
}

int main()
{
    double temperature;
    char unit;

    printf("Enter the temperature: ");
    scanf("%lf", &temperature);

    printf("Enter the unit of temperature (F, C, K): ");
    scanf(" %c", &unit);

    convert_temperature(temperature, unit);

    return 0;
}