//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to print temperature in Celsius and Fahrenheit
void printTemperature(float temperature, int scale) {
    if (scale == 1) {
        printf("%.2f degrees Celsius\n", temperature);
    } else if (scale == 2) {
        printf("%.2f degrees Fahrenheit\n", temperature);
    } else {
        printf("Invalid scale\n");
    }
}

// Function to get temperature from user
float getTemperature() {
    float temperature;
    printf("Enter temperature: ");
    scanf("%f", &temperature);
    return temperature;
}

// Function to get scale from user
int getScale() {
    int scale;
    printf("Enter scale (1 for Celsius, 2 for Fahrenheit): ");
    scanf("%d", &scale);
    return scale;
}

int main() {
    float temperature;
    int scale;

    // Get temperature and scale from user
    temperature = getTemperature();
    scale = getScale();

    // Convert temperature to Celsius and Fahrenheit
    float celsius = celsiusToFahrenheit(temperature);
    float fahrenheit = fahrenheitToCelsius(temperature);

    // Print temperature in Celsius and Fahrenheit
    printTemperature(celsius, 1);
    printTemperature(fahrenheit, 2);

    return 0;
}