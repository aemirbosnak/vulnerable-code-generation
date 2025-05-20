//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: minimalist
#include <stdio.h>

void displayMenu() {
    printf("Temperature Converter\n");
    printf("---------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("---------------------\n");
}

float celsiusToFahrenheit(float c) {
    return (c * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float f) {
    return (f - 32.0) * 5.0 / 9.0;
}

float celsiusToKelvin(float c) {
    return c + 273.15;
}

float kelvinToCelsius(float k) {
    return k - 273.15;
}

float fahrenheitToKelvin(float f) {
    return (f - 32.0) * 5.0 / 9.0 + 273.15;
}

float kelvinToFahrenheit(float k) {
    return (k - 273.15) * 9.0 / 5.0 + 32.0;
}

int main() {
    int choice;
    float temperature, convertedTemperature;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-7): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, please enter a number!\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        if (choice == 7) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter temperature: ");
        if (scanf("%f", &temperature) != 1) {
            printf("Invalid temperature input!\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            case 2:
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 3:
                convertedTemperature = celsiusToKelvin(temperature);
                printf("%.2f Celsius = %.2f Kelvin\n", temperature, convertedTemperature);
                break;
            case 4:
                convertedTemperature = kelvinToCelsius(temperature);
                printf("%.2f Kelvin = %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 5:
                convertedTemperature = fahrenheitToKelvin(temperature);
                printf("%.2f Fahrenheit = %.2f Kelvin\n", temperature, convertedTemperature);
                break;
            case 6:
                convertedTemperature = kelvinToFahrenheit(temperature);
                printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
        printf("\n");
    }
    
    return 0;
}