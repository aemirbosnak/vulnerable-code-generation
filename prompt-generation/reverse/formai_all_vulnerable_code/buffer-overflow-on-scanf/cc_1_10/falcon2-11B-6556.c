//Falcon2-11B DATASET v1.0 Category: Temperature Converter ; Style: immersive
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit + 459.67) * 0.5;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
    return (kelvin * 9.0 / 5.0) + 459.67;
}

int main() {
    float celsius, fahrenheit, kelvin;
    
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);
    
    printf("Enter the target temperature unit: (F for Fahrenheit, K for Kelvin)\n");
    char unit;
    scanf(" %c", &unit);
    
    switch (unit) {
        case 'F':
            fahrenheit = celsiusToFahrenheit(celsius);
            printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
            break;
        case 'K':
            kelvin = celsiusToKelvin(celsius);
            printf("Temperature in Kelvin: %.2f\n", kelvin);
            break;
        default:
            printf("Invalid unit\n");
            break;
    }
    
    return 0;
}