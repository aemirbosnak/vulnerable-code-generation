//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
int celsiusToFahrenheit(int celsius) {
    int fahrenheit = (celsius * 9) / 5 + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
int fahrenheitToCelsius(int fahrenheit) {
    int celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

// Function to get user input for temperature and temperature scale
int getTemperatureInput(int *temperature, char *scale) {
    printf("Enter temperature: ");
    scanf("%d", temperature);
    printf("Enter temperature scale (C for Celsius, F for Fahrenheit): ");
    scanf(" %c", scale);
    return 0;
}

// Function to display temperature conversion result
void displayTemperatureResult(int temperature, char scale, int result) {
    if (scale == 'C' || scale == 'c') {
        printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", temperature, result);
    } else if (scale == 'F' || scale == 'f') {
        printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", temperature, result);
    }
}

int main() {
    int temperature;
    char scale;
    int result;

    // Get user input for temperature and temperature scale
    getTemperatureInput(&temperature, &scale);

    // Convert temperature based on user input scale
    if (scale == 'C' || scale == 'c') {
        result = fahrenheitToCelsius(temperature);
    } else if (scale == 'F' || scale == 'f') {
        result = celsiusToFahrenheit(temperature);
    }

    // Display temperature conversion result
    displayTemperatureResult(temperature, scale, result);

    return 0;
}