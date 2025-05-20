//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <math.h>

int main()
{
    float f_value, f_unit, f_result;
    char c_unit, c_result;

    printf("Welcome to the futuristic Unit Converter!\n");
    printf("Please enter the value you want to convert:");
    scanf("%f", &f_value);

    printf("Please enter the unit you want to convert from:");
    scanf(" %c", &c_unit);

    printf("Please enter the unit you want to convert to:");
    scanf(" %c", &c_result);

    switch (c_unit)
    {
        case 'm':
            switch (c_result)
            {
                case 'kg':
                    f_result = f_value * 1000;
                    break;
                case 'g':
                    f_result = f_value * 1000000;
                    break;
                case 't':
                    f_result = f_value * 1000000000;
                    break;
            }
            break;
        case 'kg':
            switch (c_result)
            {
                case 'm':
                    f_result = f_value / 1000;
                    break;
                case 'g':
                    f_result = f_value / 1000000;
                    break;
                case 't':
                    f_result = f_value / 1000000000;
                    break;
            }
            break;
        case 'g':
            switch (c_result)
            {
                case 'm':
                    f_result = f_value / 1000000;
                    break;
                case 'kg':
                    f_result = f_value / 1000000;
                    break;
                case 't':
                    f_result = f_value / 1000000000;
                    break;
            }
            break;
        case 't':
            switch (c_result)
            {
                case 'm':
                    f_result = f_value * 1000000;
                    break;
                case 'kg':
                    f_result = f_value * 1000000;
                    break;
                case 'g':
                    f_result = f_value * 1000000;
                    break;
            }
            break;
    }

    printf("The result is: %.2f %s", f_result, c_result);

    return 0;
}