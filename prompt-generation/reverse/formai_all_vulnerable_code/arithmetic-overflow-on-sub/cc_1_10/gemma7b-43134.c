//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, temperature, unit;
    char symbol;

    printf("Welcome to the Curious Temperature Converter!\n");

    printf("Please select an option:\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Convert Kelvin to Celsius\n");
    printf("4. Convert Kelvin to Fahrenheit\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Fahrenheit:");
            scanf("%d", &temperature);
            unit = 5;
            symbol = 'C';
            break;
        case 2:
            printf("Enter the temperature in Celsius:");
            scanf("%d", &temperature);
            unit = 9;
            symbol = 'F';
            break;
        case 3:
            printf("Enter the temperature in Kelvin:");
            scanf("%d", &temperature);
            unit = 273;
            symbol = 'C';
            break;
        case 4:
            printf("Enter the temperature in Kelvin:");
            scanf("%d", &temperature);
            unit = 459.67 + temperature * 1.8;
            symbol = 'F';
            break;
        default:
            printf("Invalid choice.\n");
            exit(1);
    }

    temperature = (temperature - unit) * 2.0;
    printf("The temperature in %c is: %.2f\n", symbol, temperature);

    return 0;
}