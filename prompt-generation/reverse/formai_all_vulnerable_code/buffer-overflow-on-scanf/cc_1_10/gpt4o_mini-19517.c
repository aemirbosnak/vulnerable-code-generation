//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>

// Function declarations
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
    
    printf("Welcome to the Temperature Converter!\n");
    printf("This program allows you to convert temperatures between Celsius, Fahrenheit, and Kelvin.\n\n");

    do {
        displayMenu();
        printf("Enter your choice (1-5, or 0 to exit): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // clearing the input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit\n\n", temperature, convertedTemperature);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius\n\n", temperature, convertedTemperature);
                break;

            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToKelvin(temperature);
                printf("%.2f Celsius is %.2f Kelvin\n\n", temperature, convertedTemperature);
                break;

            case 4:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &temperature);
                convertedTemperature = kelvinToCelsius(temperature);
                printf("%.2f Kelvin is %.2f Celsius\n\n", temperature, convertedTemperature);
                break;

            case 5:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToKelvin(temperature);
                printf("%.2f Fahrenheit is %.2f Kelvin\n\n", temperature, convertedTemperature);
                break;

            case 0:
                printf("Exiting the program. Thank you for using the Temperature Converter!\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option from the menu.\n\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("Temperature Conversion Options:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Celsius to Kelvin\n");
    printf("4. Convert Kelvin to Celsius\n");
    printf("5. Convert Fahrenheit to Kelvin\n");
    printf("0. Exit Program\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}