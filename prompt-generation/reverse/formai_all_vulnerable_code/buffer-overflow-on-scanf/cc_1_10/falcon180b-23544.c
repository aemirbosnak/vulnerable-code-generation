//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    float celsius = kelvin - 273.15;
    return celsius;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

// Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
    float fahrenheit = (kelvin - 273.15) * 9/5 + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
    float kelvin = (fahrenheit + 459.67) * 5/9;
    return kelvin;
}

int main() {

    float celsius, fahrenheit, kelvin;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    printf("Celsius to Fahrenheit: %.2f\n", celsiusToFahrenheit(celsius));
    printf("Fahrenheit to Celsius: %.2f\n", fahrenheitToCelsius(celsius));
    printf("Celsius to Kelvin: %.2f\n", celsiusToKelvin(celsius));
    printf("Kelvin to Celsius: %.2f\n", kelvinToCelsius(celsius));
    printf("Kelvin to Fahrenheit: %.2f\n", kelvinToFahrenheit(celsius));
    printf("Fahrenheit to Kelvin: %.2f\n", fahrenheitToKelvin(celsius));

    return 0;
}