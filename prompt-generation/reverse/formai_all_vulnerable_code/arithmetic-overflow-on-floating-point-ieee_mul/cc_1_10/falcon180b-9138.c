//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Function to get user input for temperature and unit
float get_temperature(char* unit) {
    float temperature = 0;
    printf("Enter temperature: ");
    scanf("%f", &temperature);
    printf("Enter unit (C or F): ");
    scanf(" %c", &unit);
    return temperature;
}

// Function to convert temperature and display result
void convert_temperature(float temperature, char unit) {
    if (unit == 'C' || unit == 'c') {
        float fahrenheit = celsius_to_fahrenheit(temperature);
        printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, fahrenheit);
    } else if (unit == 'F' || unit == 'f') {
        float celsius = fahrenheit_to_celsius(temperature);
        printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, celsius);
    } else {
        printf("Invalid unit entered.\n");
    }
}

int main() {
    float temperature;
    char unit;

    // Get temperature and unit from user
    temperature = get_temperature(&unit);

    // Convert temperature and display result
    convert_temperature(temperature, unit);

    return 0;
}