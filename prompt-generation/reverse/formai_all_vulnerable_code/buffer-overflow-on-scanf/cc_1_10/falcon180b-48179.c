//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>

#define FAHRENHEIT 0
#define CELSIUS 1

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to get user input for temperature type
int getTemperatureType() {
    int type;
    printf("Enter 0 for Celsius to Fahrenheit conversion and 1 for Fahrenheit to Celsius conversion: ");
    scanf("%d", &type);
    return type;
}

// Function to get user input for temperature value
float getTemperatureValue() {
    float value;
    printf("Enter the temperature value: ");
    scanf("%f", &value);
    return value;
}

// Function to display the converted temperature
void displayConvertedTemperature(float value, int type) {
    if (type == FAHRENHEIT) {
        printf("%.2f degrees Fahrenheit is equivalent to %.2f degrees Celsius.\n", value, celsiusToFahrenheit(value));
    } else {
        printf("%.2f degrees Celsius is equivalent to %.2f degrees Fahrenheit.\n", value, fahrenheitToCelsius(value));
    }
}

int main() {
    int type;
    float value;
    
    // Get user input for temperature type
    type = getTemperatureType();
    
    // Get user input for temperature value
    value = getTemperatureValue();
    
    // Convert and display the temperature
    displayConvertedTemperature(value, type);
    
    return 0;
}