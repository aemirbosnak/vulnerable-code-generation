//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

int main() {
    float celsius, fahrenheit, kelvin;
    char choice;

    // Loop until user chooses to exit
    while (1) {
        // Display menu
        printf("Temperature Conversion Menu:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        // Perform conversion based on user choice
        switch (choice) {
            case '1':
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celsius);
                printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, celsiusToFahrenheit(celsius));
                break;
            case '2':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
                break;
            case '3':
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celsius);
                printf("%.2f Celsius = %.2f Kelvin\n", celsius, celsiusToKelvin(celsius));
                break;
            case '4':
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &kelvin);
                printf("%.2f Kelvin = %.2f Celsius\n", kelvin, kelvinToCelsius(kelvin));
                break;
            case '5':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}