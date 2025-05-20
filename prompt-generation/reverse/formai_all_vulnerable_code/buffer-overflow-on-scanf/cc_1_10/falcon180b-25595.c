//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include<stdio.h>
#include<math.h>

int main()
{
    int choice;
    float temperature, converted;
    char unit;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter the temperature you want to convert:\n");
    scanf("%f", &temperature);

    printf("Please enter the unit of the temperature (C or F):\n");
    scanf(" %c", &unit);

    printf("Please enter the unit you want to convert to (C or F):\n");
    scanf(" %c", &unit);

    switch(unit)
    {
        case 'C':
            if(unit == 'F')
            {
                converted = (temperature - 32) * 5/9;
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, converted);
            }
            else
            {
                printf("Invalid conversion unit.\n");
            }
            break;

        case 'F':
            if(unit == 'C')
            {
                converted = (temperature * 9/5) + 32;
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, converted);
            }
            else
            {
                printf("Invalid conversion unit.\n");
            }
            break;

        default:
            printf("Invalid unit.\n");
    }

    return 0;
}