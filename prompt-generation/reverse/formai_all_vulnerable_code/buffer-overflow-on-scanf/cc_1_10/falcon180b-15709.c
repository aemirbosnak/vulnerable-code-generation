//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: energetic
#include <stdio.h>

#define CELSIUS 0
#define FAHRENHEIT 1

// Function to convert temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius)
{
    return (celsius * (9.0/5.0)) + 32.0;
}

// Function to convert temperature from Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit)
{
    return (fahrenheit - 32.0) * (5.0/9.0);
}

int main()
{
    int choice;
    float temperature;

    // Display menu
    printf("Temperature Converter Menu\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");

    // Get user choice
    scanf("%d", &choice);

    // Convert temperature based on user choice
    switch(choice)
    {
        case CELSIUS:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));
            break;

        case FAHRENHEIT:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, fahrenheitToCelsius(temperature));
            break;

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}