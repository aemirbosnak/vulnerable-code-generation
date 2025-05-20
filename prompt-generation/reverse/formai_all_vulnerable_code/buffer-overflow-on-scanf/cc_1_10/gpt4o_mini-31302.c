//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>

// Function prototypes
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);

int main() {
    int choice;
    float temperature, convertedTemperature;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");

    while (1) {
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the Temperature Converter. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 7) {
            printf("Invalid choice! Please select a valid option.\n");
            continue;
        }

        printf("Enter the temperature: ");
        scanf("%f", &temperature);

        switch (choice) {
            case 1:
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            case 2:
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 3:
                convertedTemperature = celsiusToKelvin(temperature);
                printf("%.2f Celsius is %.2f Kelvin\n", temperature, convertedTemperature);
                break;
            case 4:
                convertedTemperature = kelvinToCelsius(temperature);
                printf("%.2f Kelvin is %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 5:
                convertedTemperature = fahrenheitToKelvin(temperature);
                printf("%.2f Fahrenheit is %.2f Kelvin\n", temperature, convertedTemperature);
                break;
            case 6:
                convertedTemperature = kelvinToFahrenheit(temperature);
                printf("%.2f Kelvin is %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
        }
    }

    return 0;
}

// Function definitions
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}