//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include <stdio.h>

void displayMenu();
float convertCelsiusToFahrenheit(float celsius);
float convertFahrenheitToCelsius(float fahrenheit);
float convertCelsiusToKelvin(float celsius);
float convertKelvinToCelsius(float kelvin);
float convertFahrenheitToKelvin(float fahrenheit);
float convertKelvinToFahrenheit(float kelvin);

int main() {
    int choice;
    float temperature, convertedTemperature;

    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = convertCelsiusToFahrenheit(temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = convertFahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, convertedTemperature);
                break;
                
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = convertCelsiusToKelvin(temperature);
                printf("%.2f Celsius = %.2f Kelvin\n", temperature, convertedTemperature);
                break;

            case 4:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &temperature);
                convertedTemperature = convertKelvinToCelsius(temperature);
                printf("%.2f Kelvin = %.2f Celsius\n", temperature, convertedTemperature);
                break;

            case 5:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = convertFahrenheitToKelvin(temperature);
                printf("%.2f Fahrenheit = %.2f Kelvin\n", temperature, convertedTemperature);
                break;

            case 6:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &temperature);
                convertedTemperature = convertKelvinToFahrenheit(temperature);
                printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;

            case 7:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        printf("\n");
    } while (choice != 7);

    return 0;
}

void displayMenu() {
    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
}

float convertCelsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float convertFahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float convertCelsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float convertKelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float convertFahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

float convertKelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}