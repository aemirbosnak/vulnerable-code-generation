//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main()
{
    int choice, unit_from, unit_to;
    float value;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert meters to kilometers\n");
    printf("2. Convert liters to gallons\n");
    printf("3. Convert degrees Celsius to Fahrenheit\n");
    printf("4. Convert pounds to kilograms\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the value in meters:");
            scanf("%f", &value);
            unit_from = 1;
            unit_to = 2;
            break;
        case 2:
            printf("Enter the value in liters:");
            scanf("%f", &value);
            unit_from = 2;
            unit_to = 3;
            break;
        case 3:
            printf("Enter the value in degrees Celsius:");
            scanf("%f", &value);
            unit_from = 3;
            unit_to = 4;
            break;
        case 4:
            printf("Enter the value in pounds:");
            scanf("%f", &value);
            unit_from = 4;
            unit_to = 5;
            break;
        default:
            printf("Invalid option.\n");
            break;
    }

    switch (unit_to)
    {
        case 1:
            printf("The converted value is: %.2f kilometers.\n", value * 1000);
            break;
        case 2:
            printf("The converted value is: %.2f liters.\n", value * 1000);
            break;
        case 3:
            printf("The converted value is: %.2f degrees Fahrenheit.\n", (value * 1.8) + 32);
            break;
        case 4:
            printf("The converted value is: %.2f kilograms.\n", value * 2.2046);
            break;
        case 5:
            printf("The converted value is: %.2f pounds.\n", value * 0.45359);
            break;
        default:
            printf("Invalid unit conversion.\n");
            break;
    }

    return 0;
}