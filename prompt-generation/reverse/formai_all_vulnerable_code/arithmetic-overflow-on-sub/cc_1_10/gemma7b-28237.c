//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
int celsius_to_fahrenheit(int celsius)
{
    int fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
int fahrenheit_to_celsius(int fahrenheit)
{
    int celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

int main()
{
    int choice, celsius, fahrenheit;

    // Display menu options
    printf("Choose an option:");
    printf("\n1. Convert Celsius to Fahrenheit");
    printf("\n2. Convert Fahrenheit to Celsius");

    // Get user input
    scanf("%d", &choice);

    // Switch case to handle user input
    switch (choice)
    {
        case 1:
            printf("Enter the Celsius temperature:");
            scanf("%d", &celsius);
            fahrenheit = celsius_to_fahrenheit(celsius);
            printf("The Fahrenheit temperature is: %d", fahrenheit);
            break;

        case 2:
            printf("Enter the Fahrenheit temperature:");
            scanf("%d", &fahrenheit);
            celsius = fahrenheit_to_celsius(fahrenheit);
            printf("The Celsius temperature is: %d", celsius);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}