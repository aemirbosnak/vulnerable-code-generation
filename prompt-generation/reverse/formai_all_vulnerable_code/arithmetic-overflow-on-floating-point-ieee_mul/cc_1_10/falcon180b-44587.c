//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

int main() {
    char choice;
    float temperature, convertedTemperature;

    do {
        // Menu options
        printf("Temperature Converter\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        // Convert temperature based on user choice
        switch(choice) {
            case '1':
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%f Celsius is equal to %f Fahrenheit.\n", temperature, convertedTemperature);
                break;
            case '2':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%f Fahrenheit is equal to %f Celsius.\n", temperature, convertedTemperature);
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '3');

    return 0;
}