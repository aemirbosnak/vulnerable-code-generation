//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: single-threaded
#include <stdio.h>

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float fahrenheitToKelvin(float fahrenheit) {
    float celsius = fahrenheitToCelsius(fahrenheit);
    return celsiusToKelvin(celsius);
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    float celsius = kelvinToCelsius(kelvin);
    return celsiusToFahrenheit(celsius);
}

void showMenu() {
    printf("\nTemperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("Select an option (1-7): ");
}

void temperatureConversion() {
    int choice;
    float value, result;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 7) {
            printf("Invalid choice. Please select a valid option.\n");
            continue;
        }

        printf("Enter the temperature value: ");
        scanf("%f", &value);

        switch (choice) {
            case 1:
                result = celsiusToFahrenheit(value);
                printf("%.2f Celsius = %.2f Fahrenheit\n", value, result);
                break;
            case 2:
                result = celsiusToKelvin(value);
                printf("%.2f Celsius = %.2f Kelvin\n", value, result);
                break;
            case 3:
                result = fahrenheitToCelsius(value);
                printf("%.2f Fahrenheit = %.2f Celsius\n", value, result);
                break;
            case 4:
                result = fahrenheitToKelvin(value);
                printf("%.2f Fahrenheit = %.2f Kelvin\n", value, result);
                break;
            case 5:
                result = kelvinToCelsius(value);
                printf("%.2f Kelvin = %.2f Celsius\n", value, result);
                break;
            case 6:
                result = kelvinToFahrenheit(value);
                printf("%.2f Kelvin = %.2f Fahrenheit\n", value, result);
                break;
            default:
                printf("This should never happen!\n");
                break;
        }
    }
}

int main() {
    printf("Welcome to the Temperature Converter!\n\n");
    temperatureConversion();
    return 0;
}