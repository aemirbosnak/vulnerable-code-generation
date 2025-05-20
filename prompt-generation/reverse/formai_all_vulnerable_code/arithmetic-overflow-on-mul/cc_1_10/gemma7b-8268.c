//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void main()
{
    int choice, temperature, f_temp, c_temp;
    char unit;

    // Display menu options
    printf("Enter 1 for Fahrenheit to Celsius conversion.\n");
    printf("Enter 2 for Celsius to Fahrenheit conversion.\n");
    printf("Enter 3 for Kelvin to Celsius conversion.\n");

    // Get user input
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Convert temperature based on user choice
    switch (choice)
    {
        case 1:
            printf("Enter the Fahrenheit temperature: ");
            scanf("%d", &f_temp);
            c_temp = (f_temp - 32) * 5 / 9;
            printf("The Celsius temperature is: %.2f", c_temp);
            break;

        case 2:
            printf("Enter the Celsius temperature: ");
            scanf("%d", &c_temp);
            f_temp = (c_temp * 9 / 5) + 32;
            printf("The Fahrenheit temperature is: %.2f", f_temp);
            break;

        case 3:
            printf("Enter the Kelvin temperature: ");
            scanf("%d", &c_temp);
            f_temp = (c_temp * 1.8) + 32;
            printf("The Fahrenheit temperature is: %.2f", f_temp);
            break;

        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    // Get the unit of temperature
    printf("Enter the unit of temperature (F/C/K): ");
    scanf(" %c", &unit);

    // Display the converted temperature
    printf("The converted temperature is: %.2f %s", c_temp, unit);

    return;
}