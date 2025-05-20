//FormAI DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>

int main()
{
    int option = 0;
    double value = 0;
    double result = 0;

    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*        Welcome to the Unit Converter       *\n");
    printf("*                                           *\n");
    printf("*********************************************\n\n");

    printf("Please select the type of conversion:\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Pounds to Kilograms\n");

    printf("Option: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            printf("Enter the distance in kilometers: ");
            scanf("%lf", &value);

            result = value * 0.621371;

            printf("%.2lf kilometers is equal to %.2lf miles.\n", value, result);
            break;

        case 2:
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &value);

            result = (value * 1.8) + 32;

            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", value, result);
            break;

        case 3:
            printf("Enter the weight in pounds: ");
            scanf("%lf", &value);

            result = value * 0.453592;

            printf("%.2lf pounds is equal to %.2lf kilograms.\n", value, result);
            break;

        default:
            printf("Invalid option.\n");
            break;
    }

    return 0;
}