//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: genius
#include <stdio.h>

// Function prototypes
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);

int main() {
    int choice;
    float temperature, convertedTemperature;

    do {
        displayMenu();
        printf("Enter your choice (1-6 to convert, 0 to exit): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6) {
            printf("Enter the temperature to convert: ");
            scanf("%f", &temperature);
        }

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
            case 0:
                printf("Exiting the temperature converter. Stay warm and cool!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\nTemperature Converter Menu\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
}

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
    float celsius = fahrenheitToCelsius(fahrenheit);
    return celsiusToKelvin(celsius);
}

float kelvinToFahrenheit(float kelvin) {
    float celsius = kelvinToCelsius(kelvin);
    return celsiusToFahrenheit(celsius);
}