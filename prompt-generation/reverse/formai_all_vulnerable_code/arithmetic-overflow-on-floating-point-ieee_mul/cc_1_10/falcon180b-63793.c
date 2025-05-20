//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to get temperature input from user
float get_temperature_input() {
    float temperature;
    printf("Enter temperature: ");
    scanf("%f", &temperature);
    return temperature;
}

// Function to get temperature unit input from user
char get_temperature_unit_input() {
    char unit;
    printf("Enter temperature unit (C/F): ");
    scanf(" %c", &unit);
    return unit;
}

// Function to display temperature with unit
void display_temperature(float temperature, char unit) {
    if (unit == 'C' || unit == 'c') {
        printf("%.2f degrees Celsius\n", temperature);
    } else if (unit == 'F' || unit == 'f') {
        printf("%.2f degrees Fahrenheit\n", temperature);
    } else {
        printf("Invalid temperature unit\n");
    }
}

int main() {
    float temperature;
    char unit;

    // Get temperature input from user
    temperature = get_temperature_input();

    // Get temperature unit input from user
    unit = get_temperature_unit_input();

    // Convert temperature to Celsius or Fahrenheit
    if (unit == 'C' || unit == 'c') {
        // Convert Celsius to Fahrenheit
        float fahrenheit = celsius_to_fahrenheit(temperature);
        printf("Temperature in Celsius: %.2f degrees Celsius\n", temperature);
        printf("Temperature in Fahrenheit: %.2f degrees Fahrenheit\n", fahrenheit);
    } else if (unit == 'F' || unit == 'f') {
        // Convert Fahrenheit to Celsius
        float celsius = fahrenheit_to_celsius(temperature);
        printf("Temperature in Fahrenheit: %.2f degrees Fahrenheit\n", temperature);
        printf("Temperature in Celsius: %.2f degrees Celsius\n", celsius);
    } else {
        printf("Invalid temperature unit\n");
    }

    return 0;
}