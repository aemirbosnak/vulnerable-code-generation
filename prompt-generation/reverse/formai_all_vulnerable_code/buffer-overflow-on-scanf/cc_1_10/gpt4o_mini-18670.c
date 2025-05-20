//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("******************************\n");
    printf("*   Temperature Converter     *\n");
    printf("******************************\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
    printf("Please select an option: ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

int main() {
    int choice;
    float temperature, convertedTemperature;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, convertedTemperature);
                break;
            
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToKelvin(temperature);
                printf("%.2f Celsius is %.2f Kelvin\n", temperature, convertedTemperature);
                break;
                
            case 4:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &temperature);
                convertedTemperature = kelvinToCelsius(temperature);
                printf("%.2f Kelvin is %.2f Celsius\n", temperature, convertedTemperature);
                break;
                
            case 5:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToKelvin(temperature);
                printf("%.2f Fahrenheit is %.2f Kelvin\n", temperature, convertedTemperature);
                break;

            case 6:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &temperature);
                convertedTemperature = kelvinToFahrenheit(temperature);
                printf("%.2f Kelvin is %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
                
            case 0:
                printf("Exiting the Temperature Converter. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        printf("\n"); // Extra new line for better readability
    } while (choice != 0);

    return 0;
}