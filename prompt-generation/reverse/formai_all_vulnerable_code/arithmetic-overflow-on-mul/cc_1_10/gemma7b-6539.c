//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, temp, unit;
    float converted_temp;

    // Display menu options
    printf("Enter 1 for Fahrenheit to Celsius conversion.\n");
    printf("Enter 2 for Celsius to Fahrenheit conversion.\n");
    printf("Enter 3 for Kelvin to Fahrenheit conversion.\n");
    printf("Enter 4 for Fahrenheit to Kelvin conversion.\n");

    // Get user input
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Convert temperature based on user's choice
    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%d", &temp);
            unit = 1;
            converted_temp = (temp - 32) * 5 / 9;
            break;
        case 2:
            printf("Enter the temperature in Celsius: ");
            scanf("%d", &temp);
            unit = 2;
            converted_temp = (temp * 9 / 5) + 32;
            break;
        case 3:
            printf("Enter the temperature in Kelvin: ");
            scanf("%d", &temp);
            unit = 3;
            converted_temp = (temp - 273) * 1.8 + 32;
            break;
        case 4:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%d", &temp);
            unit = 4;
            converted_temp = (temp - 32) * 5 / 9 + 273;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    // Display the converted temperature
    printf("Converted temperature: %.2f %s.\n", converted_temp, unit);

    return 0;
}