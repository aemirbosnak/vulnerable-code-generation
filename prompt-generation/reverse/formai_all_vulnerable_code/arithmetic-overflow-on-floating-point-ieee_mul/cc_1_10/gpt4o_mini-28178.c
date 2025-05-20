//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\nTemperature Converter Menu:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Celsius to Kelvin\n");
    printf("3. Convert Fahrenheit to Celsius\n");
    printf("4. Convert Fahrenheit to Kelvin\n");
    printf("5. Convert Kelvin to Celsius\n");
    printf("6. Convert Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("Choose an option (1-7): ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheitToCelsius(fahrenheit) + 273.15);
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvinToCelsius(kelvin) * 9/5) + 32;
}

int main() {
    int choice;
    float temperature, convertedTemperature;
    char buffer[50];

    while (1) {
        displayMenu();
        fgets(buffer, sizeof(buffer), stdin);
        choice = atoi(buffer);

        if (choice < 1 || choice > 7) {
            printf("Invalid option. Please try again.\n");
            continue;
        }

        if (choice == 7) {
            printf("Exiting the Temperature Converter. Goodbye!\n");
            break;
        }

        printf("Enter the temperature value: ");
        fgets(buffer, sizeof(buffer), stdin);
        temperature = atof(buffer);

        switch (choice) {
            case 1:
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            case 2:
                convertedTemperature = celsiusToKelvin(temperature);
                printf("%.2f Celsius = %.2f Kelvin\n", temperature, convertedTemperature);
                break;
            case 3:
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 4:
                convertedTemperature = fahrenheitToKelvin(temperature);
                printf("%.2f Fahrenheit = %.2f Kelvin\n", temperature, convertedTemperature);
                break;
            case 5:
                convertedTemperature = kelvinToCelsius(temperature);
                printf("%.2f Kelvin = %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 6:
                convertedTemperature = kelvinToFahrenheit(temperature);
                printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            default:
                printf("Unexpected error! Please restart the program.\n");
        }
    }

    return 0;
}