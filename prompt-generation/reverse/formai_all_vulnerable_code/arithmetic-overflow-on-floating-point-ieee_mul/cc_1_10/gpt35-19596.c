//FormAI DATASET v1.0 Category: Temperature Converter ; Style: safe
#include <stdio.h>

// Function declaration for conversion
float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToCelsius(float kelvin);
float kelvinToFahrenheit(float kelvin);

int main() {
    float temperatureCelsius, temperatureFahrenheit, temperatureKelvin;
    int choice;

    printf("---- Temperature Converter ----\n");

    while(1) {
        // Display menu
        printf("\nSelect your choice:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Celsius to Kelvin\n");
        printf("3. Fahrenheit to Celsius\n");
        printf("4. Fahrenheit to Kelvin\n");
        printf("5. Kelvin to Celsius\n");
        printf("6. Kelvin to Fahrenheit\n");
        printf("7. Exit\n");
        printf("\nEnter your choice number: ");
        scanf("%d", &choice);

        // Exit program if user selects the 'Exit' option
        if (choice == 7) {
            printf("\nExiting program...\n");
            break;
        }

        // Display input prompt
        printf("Enter temperature: ");
        scanf("%f", &temperatureCelsius);

        // Determine selected conversion and perform it
        switch (choice) {
            case 1:
                temperatureFahrenheit = celsiusToFahrenheit(temperatureCelsius);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperatureCelsius, temperatureFahrenheit);
                break;
            case 2:
                temperatureKelvin = celsiusToKelvin(temperatureCelsius);
                printf("%.2f Celsius = %.2f Kelvin\n", temperatureCelsius, temperatureKelvin);
                break;
            case 3:
                temperatureCelsius = fahrenheitToCelsius(temperatureCelsius);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperatureFahrenheit, temperatureCelsius);
                break;
            case 4:
                temperatureKelvin = fahrenheitToKelvin(temperatureCelsius);
                printf("%.2f Fahrenheit = %.2f Kelvin\n", temperatureFahrenheit, temperatureKelvin);
                break;
            case 5:
                temperatureCelsius = kelvinToCelsius(temperatureCelsius);
                printf("%.2f Kelvin = %.2f Celsius\n", temperatureKelvin, temperatureCelsius);
                break;
            case 6:
                temperatureFahrenheit = kelvinToFahrenheit(temperatureCelsius);
                printf("%.2f Kelvin = %.2f Fahrenheit\n", temperatureKelvin, temperatureFahrenheit);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit + 459.67) * 5 / 9;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
    return kelvin * 9 / 5 - 459.67;
}