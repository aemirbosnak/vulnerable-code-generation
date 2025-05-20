//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

int main()
{
    int choice, unit_from, unit_to;
    float value;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Convert meters to feet\n");
    printf("4. Convert feet to meters\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &value);
            unit_from = 1;
            unit_to = 2;
            break;
        case 2:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &value);
            unit_from = 2;
            unit_to = 1;
            break;
        case 3:
            printf("Enter the distance in meters: ");
            scanf("%f", &value);
            unit_from = 3;
            unit_to = 4;
            break;
        case 4:
            printf("Enter the distance in feet: ");
            scanf("%f", &value);
            unit_from = 4;
            unit_to = 3;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    switch (unit_from)
    {
        case 1:
            value = (value - 32) * 5 / 9;
            break;
        case 2:
            value = (value * 9 / 5) + 32;
            break;
        case 3:
            value = value * 3.28084;
            break;
        case 4:
            value = value * 0.328084;
            break;
    }

    switch (unit_to)
    {
        case 1:
            printf("The temperature in Celsius is: %.2f\n", value);
            break;
        case 2:
            printf("The temperature in Fahrenheit is: %.2f\n", value);
            break;
        case 3:
            printf("The distance in feet is: %.2f\n", value);
            break;
        case 4:
            printf("The distance in meters is: %.2f\n", value);
            break;
    }

    return 0;
}