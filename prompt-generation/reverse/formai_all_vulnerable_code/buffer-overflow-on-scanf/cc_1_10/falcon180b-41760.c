//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to get user input for temperature and unit
float get_temperature_input() {
    float temperature;
    char unit;

    printf("Enter temperature: ");
    scanf("%f", &temperature);

    printf("Enter unit (C for Celsius, F for Fahrenheit): ");
    scanf(" %c", &unit);

    return temperature;
}

// Function to convert temperature and display result
void convert_temperature(float temperature, char unit) {
    float converted_temperature;

    if (unit == 'C' || unit == 'c') {
        converted_temperature = celsius_to_fahrenheit(temperature);
        printf("%.2f %c = %.2f %c\n", temperature, unit, converted_temperature, 'F');
    } else if (unit == 'F' || unit == 'f') {
        converted_temperature = fahrenheit_to_celsius(temperature);
        printf("%.2f %c = %.2f %c\n", temperature, unit, converted_temperature, 'C');
    } else {
        printf("Invalid unit.\n");
    }
}

int main() {
    float temperature;

    while (1) {
        temperature = get_temperature_input();
        convert_temperature(temperature, temperature < -273.15? 'K' : 'C');
    }

    return 0;
}