//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: complete
#include <stdio.h>

// Function prototypes
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
void displayMenu();

int main() {
    int choice;
    float temperature, convertedTemperature;

    while (1) {
        displayMenu();
        printf("Select a conversion option (1-5, or 0 to exit): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

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
                printf("This option is currently under development. Please check back later.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to display menu options
void displayMenu() {
    printf("====== Temperature Converter ======\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Celsius to Kelvin\n");
    printf("4. Convert Kelvin to Celsius\n");
    printf("5. Other conversions (under development)\n");
    printf("0. Exit\n");
    printf("===================================\n");
}