//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice;
    float temperature;
    char unit;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please select an option:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Fahrenheit:");
            scanf("%f", &temperature);
            unit = 'C';
            temperature = (temperature - 32) * 5 / 9;
            break;
        case 2:
            printf("Enter the temperature in Celsius:");
            scanf("%f", &temperature);
            unit = 'F';
            temperature = (temperature * 9 / 5) + 32;
            break;
        case 3:
            printf("Enter the temperature in Kelvin:");
            scanf("%f", &temperature);
            unit = 'C';
            temperature = temperature - 273.15;
            break;
        case 4:
            printf("Enter the temperature in Celsius:");
            scanf("%f", &temperature);
            unit = 'K';
            temperature = temperature + 273.15;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("The converted temperature is: %.2f %c.\n", temperature, unit);

    return 0;
}