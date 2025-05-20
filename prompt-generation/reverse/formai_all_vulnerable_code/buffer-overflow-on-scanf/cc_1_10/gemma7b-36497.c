//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, c, t, f;
    float f_conv, t_conv, c_conv;
    char unit;

    printf("Enter the number of conversions: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the unit of the temperature: (C, F, T) ");
        scanf(" %c", &unit);

        printf("Enter the temperature: ");
        scanf("%d", &t);

        switch (unit)
        {
            case 'C':
                c_conv = t;
                f_conv = (c_conv * 1.8) + 32;
                t_conv = (c_conv * 5) / 9 + 273.15;
                break;
            case 'F':
                f_conv = t;
                c_conv = (f_conv - 32) * 5 / 9;
                t_conv = (f_conv - 32) * 5 / 9 + 273.15;
                break;
            case 'T':
                t_conv = t;
                c_conv = (t_conv - 273.15) * 9 / 5;
                f_conv = (t_conv - 273.15) * 9 / 5 + 32;
                break;
            default:
                printf("Invalid unit.\n");
                break;
        }

        printf("The converted temperature is: ");
        switch (unit)
        {
            case 'C':
                printf("%d degrees Celsius.\n", c_conv);
                break;
            case 'F':
                printf("%d degrees Fahrenheit.\n", f_conv);
                break;
            case 'T':
                printf("%d degrees Kelvin.\n", t_conv);
                break;
            default:
                printf("Invalid unit.\n");
                break;
        }
    }

    return 0;
}