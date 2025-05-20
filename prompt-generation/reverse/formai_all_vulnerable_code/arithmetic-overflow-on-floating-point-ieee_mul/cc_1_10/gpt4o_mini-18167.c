//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: authentic
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
    float temperature, convertedTemp;

    while(1) {
        displayMenu();
        
        // Read user choice
        printf("Enter your choice (1-6, any other number to exit): ");
        scanf("%d", &choice);

        // Exit if choice is not in range
        if (choice < 1 || choice > 6) {
            printf("Exiting the program. Thank you!\n");
            break;
        }

        // Input temperature from user
        printf("Enter the temperature to convert: ");
        scanf("%f", &temperature);

        // Performing conversion based on user choice
        switch(choice) {
            case 1:
                convertedTemp = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit.\n", temperature, convertedTemp);
                break;
            case 2:
                convertedTemp = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius.\n", temperature, convertedTemp);
                break;
            case 3:
                convertedTemp = celsiusToKelvin(temperature);
                printf("%.2f Celsius is %.2f Kelvin.\n", temperature, convertedTemp);
                break;
            case 4:
                convertedTemp = kelvinToCelsius(temperature);
                printf("%.2f Kelvin is %.2f Celsius.\n", temperature, convertedTemp);
                break;
            case 5:
                convertedTemp = fahrenheitToKelvin(temperature);
                printf("%.2f Fahrenheit is %.2f Kelvin.\n", temperature, convertedTemp);
                break;
            case 6:
                convertedTemp = kelvinToFahrenheit(temperature);
                printf("%.2f Kelvin is %.2f Fahrenheit.\n", temperature, convertedTemp);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

// Function to display the conversion menu
void displayMenu() {
    printf("\n=== Temperature Converter ===\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("==============================\n");
}

// Conversion functions
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