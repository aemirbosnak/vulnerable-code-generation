//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main()
{
    float f_in, f_out;
    char unit_in, unit_out;

    printf("Enter the unit you want to convert from (kg, g, lb, t): ");
    scanf("%c", &unit_in);

    printf("Enter the mass you want to convert: ");
    scanf("%f", &f_in);

    printf("Enter the unit you want to convert to (kg, g, lb, t): ");
    scanf("%c", &unit_out);

    switch (unit_in)
    {
        case 'k':
            switch (unit_out)
            {
                case 'g':
                    f_out = f_in * 1000;
                    break;
                case 'lb':
                    f_out = f_in * 2.20462;
                    break;
                case 't':
                    f_out = f_in * 1000000;
                    break;
            }
            break;
        case 'g':
            switch (unit_out)
            {
                case 'k':
                    f_out = f_in / 1000;
                    break;
                case 'lb':
                    f_out = f_in * 2.20462 / 1000;
                    break;
                case 't':
                    f_out = f_in * 1000000 / 1000;
                    break;
            }
            break;
        case 'lb':
            switch (unit_out)
            {
                case 'k':
                    f_out = f_in * 1000 / 2.20462;
                    break;
                case 'g':
                    f_out = f_in * 1000 / 2.20462;
                    break;
                case 't':
                    f_out = f_in * 1000000 / 2.20462;
                    break;
            }
            break;
        case 't':
            switch (unit_out)
            {
                case 'k':
                    f_out = f_in * 1000000 / 1000000;
                    break;
                case 'g':
                    f_out = f_in * 1000000 / 1000000;
                    break;
                case 'lb':
                    f_out = f_in * 1000000 / 2.20462;
                    break;
            }
            break;
    }

    printf("The mass is converted to %.2f %s.\n", f_out, unit_out);

    return 0;
}