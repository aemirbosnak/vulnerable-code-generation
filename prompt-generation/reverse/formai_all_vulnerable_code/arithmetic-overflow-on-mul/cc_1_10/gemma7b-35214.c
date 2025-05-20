//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, temperature, unit_from, unit_to;

    printf("Welcome to the Crazy Temperature Converter!\n");
    printf("Please select an option:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Kelvin to Fahrenheit\n");
    printf("4. Fahrenheit to Kelvin\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Fahrenheit:");
            scanf("%d", &temperature);
            unit_from = 1;
            unit_to = 2;
            break;
        case 2:
            printf("Enter the temperature in Celsius:");
            scanf("%d", &temperature);
            unit_from = 2;
            unit_to = 1;
            break;
        case 3:
            printf("Enter the temperature in Kelvin:");
            scanf("%d", &temperature);
            unit_from = 3;
            unit_to = 1;
            break;
        case 4:
            printf("Enter the temperature in Fahrenheit:");
            scanf("%d", &temperature);
            unit_from = 1;
            unit_to = 3;
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    if (unit_from != unit_to)
    {
        temperature = convert_temperature(temperature, unit_from, unit_to);
        printf("The converted temperature is: %d %s.\n", temperature, unit_to);
    }
}

int convert_temperature(int temperature, int unit_from, int unit_to)
{
    switch (unit_from)
    {
        case 1:
            return (temperature - 32) * 5 / 9;
        case 2:
            return (temperature * 9 / 5) + 32;
        case 3:
            return temperature + 273.15;
        default:
            return -1;
    }
}