//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: scientific
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
    
    do {
        // Display the conversion menu
        displayMenu();
        
        // Get user choice
        printf("\nEnter your choice (1-5, 0 to exit): ");
        scanf("%d", &choice);

        // Process based on user choice
        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("Temperature in Fahrenheit: %.2f\n", convertedTemperature);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("Temperature in Celsius: %.2f\n", convertedTemperature);
                break;

            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToKelvin(temperature);
                printf("Temperature in Kelvin: %.2f\n", convertedTemperature);
                break;

            case 4:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &temperature);
                convertedTemperature = kelvinToCelsius(temperature);
                printf("Temperature in Celsius: %.2f\n", convertedTemperature);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
        
    } while (choice != 5);
    
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

// Function to display the conversion menu
void displayMenu() {
    printf("\nTemperature Conversion Menu:");
    printf("\n1. Celsius to Fahrenheit");
    printf("\n2. Fahrenheit to Celsius");
    printf("\n3. Celsius to Kelvin");
    printf("\n4. Kelvin to Celsius");
    printf("\n5. Exit");
}