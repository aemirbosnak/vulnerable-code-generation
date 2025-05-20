//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

int main()
{
    float f_value;
    int i_value;
    char c_value;

    printf("Welcome to the Ultimate Conversion Wizardry!\n");
    printf("Please select your preferred conversion method:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Meters to Yards\n");
    printf("4. Liters to Gallons\n");

    scanf("%d", &i_value);

    switch (i_value)
    {
        case 1:
            printf("Enter the Fahrenheit value: ");
            scanf("%f", &f_value);
            i_value = (int)round((f_value - 32) * 5 / 9);
            printf("The Celsius value is: %d\n", i_value);
            break;
        case 2:
            printf("Enter the kilogram value: ");
            scanf("%f", &f_value);
            i_value = (int)round(f_value * 2.2046);
            printf("The pound value is: %d\n", i_value);
            break;
        case 3:
            printf("Enter the meter value: ");
            scanf("%f", &f_value);
            i_value = (int)round(f_value * 1.0936);
            printf("The yard value is: %d\n", i_value);
            break;
        case 4:
            printf("Enter the liter value: ");
            scanf("%f", &f_value);
            i_value = (int)round(f_value * 1.05669);
            printf("The gallon value is: %d\n", i_value);
            break;
        default:
            printf("Invalid selection. Please try again.\n");
    }

    return 0;
}