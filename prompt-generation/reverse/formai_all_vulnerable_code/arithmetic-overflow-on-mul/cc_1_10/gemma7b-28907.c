//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>

void protected_temperature_converter(int choice)
{
    int temperature, unit, converted_temperature;
    char unit_symbol;

    printf("Enter the temperature: ");
    scanf("%d", &temperature);

    printf("Enter the unit of temperature (C, F, K): ");
    scanf(" %c", &unit_symbol);

    switch (choice)
    {
        case 1:
            converted_temperature = (temperature - 32) * 5 / 9 + 273;
            unit_symbol = 'F';
            break;
        case 2:
            converted_temperature = (temperature * 9 / 5) + 32;
            unit_symbol = 'F';
            break;
        case 3:
            converted_temperature = temperature + 273;
            unit_symbol = 'K';
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    printf("Converted temperature: %.2f %c\n", converted_temperature, unit_symbol);
}

int main()
{
    int choice;

    printf("Enter the number of the conversion you want to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");

    scanf("%d", &choice);

    protected_temperature_converter(choice);

    return 0;
}