//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define constants for the conversion factors
#define KELVIN_TO_CELSIUS 273.15
#define CELSIUS_TO_FAHRENHEIT 1.8
#define FAHRENHEIT_TO_KELVIN 459.67

// Define a struct to represent a temperature
typedef struct {
    float value;
    char units;
} temperature;

// Function to convert a temperature to Celsius
temperature to_celsius(temperature temp) {
    temperature result;

    switch (temp.units) {
        case 'K':
            result.value = temp.value - KELVIN_TO_CELSIUS;
            result.units = 'C';
            break;
        case 'F':
            result.value = (temp.value - 32) * (5 / 9);
            result.units = 'C';
            break;
        default:
            result.value = temp.value;
            result.units = temp.units;
    }

    return result;
}

// Function to convert a temperature to Fahrenheit
temperature to_fahrenheit(temperature temp) {
    temperature result;

    switch (temp.units) {
        case 'K':
            result.value = (temp.value - KELVIN_TO_CELSIUS) * (9 / 5) + 32;
            result.units = 'F';
            break;
        case 'C':
            result.value = temp.value * (9 / 5) + 32;
            result.units = 'F';
            break;
        default:
            result.value = temp.value;
            result.units = temp.units;
    }

    return result;
}

// Function to convert a temperature to Kelvin
temperature to_kelvin(temperature temp) {
    temperature result;

    switch (temp.units) {
        case 'C':
            result.value = temp.value + KELVIN_TO_CELSIUS;
            result.units = 'K';
            break;
        case 'F':
            result.value = (temp.value + 459.67) * (5 / 9);
            result.units = 'K';
            break;
        default:
            result.value = temp.value;
            result.units = temp.units;
    }

    return result;
}

int main() {
    temperature temp;

    // Get input temperature from user
    printf("Enter temperature: ");
    scanf("%f %c", &temp.value, &temp.units);

    // Convert temperature to Celsius
    temperature celsius = to_celsius(temp);
    printf("Celsius: %f %c\n", celsius.value, celsius.units);

    // Convert temperature to Fahrenheit
    temperature fahrenheit = to_fahrenheit(temp);
    printf("Fahrenheit: %f %c\n", fahrenheit.value, fahrenheit.units);

    // Convert temperature to Kelvin
    temperature kelvin = to_kelvin(temp);
    printf("Kelvin: %f %c\n", kelvin.value, kelvin.units);

    return 0;
}