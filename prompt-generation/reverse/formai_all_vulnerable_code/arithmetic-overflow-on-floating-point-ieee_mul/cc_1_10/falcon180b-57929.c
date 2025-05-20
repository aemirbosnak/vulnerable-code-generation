//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>

// Function to convert length from meters to feet
double metersToFeet(double meters) {
    return meters * 3.28084;
}

// Function to convert length from feet to meters
double feetToMeters(double feet) {
    return feet / 3.28084;
}

// Function to convert weight from kilograms to pounds
double kilogramsToPounds(double kilograms) {
    return kilograms * 2.20462;
}

// Function to convert weight from pounds to kilograms
double poundsToKilograms(double pounds) {
    return pounds / 2.20462;
}

// Function to convert temperature from Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return celsius * 1.8 + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    double length, weight, temperature;
    char unit;

    // Get user input for length, weight, and temperature
    printf("Enter length, weight, and temperature values:\n");
    scanf("%lf %c %lf %c %lf", &length, &unit, &weight, &unit, &temperature);

    // Convert length, weight, and temperature if necessary
    if (unit =='m') {
        length = feetToMeters(length);
    } else if (unit == 'f') {
        length = metersToFeet(length);
    }

    if (unit == 'k') {
        weight = poundsToKilograms(weight);
    } else if (unit == 'p') {
        weight = kilogramsToPounds(weight);
    }

    if (unit == 'c') {
        temperature = fahrenheitToCelsius(temperature);
    } else if (unit == 'f') {
        temperature = celsiusToFahrenheit(temperature);
    }

    // Print converted values
    printf("Length: %.2lf %c\n", length, unit);
    printf("Weight: %.2lf %c\n", weight, unit);
    printf("Temperature: %.2lf %c\n", temperature, unit);

    return 0;
}