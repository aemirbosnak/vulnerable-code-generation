//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Claude Shannon
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

// Function to get user input for temperature and unit
float get_temperature_input(char *unit) {
    float temperature;
    printf("Enter temperature in %s: ", unit);
    scanf("%f", &temperature);
    return temperature;
}

// Function to display temperature conversion result
void display_result(float temperature, char *input_unit, char *output_unit) {
    float converted_temperature;
    if (strcmp(input_unit, "C") == 0) {
        converted_temperature = celsius_to_fahrenheit(temperature);
        printf("%.2f %s is %.2f %s\n", temperature, input_unit, converted_temperature, output_unit);
    }
    else if (strcmp(input_unit, "F") == 0) {
        converted_temperature = fahrenheit_to_celsius(temperature);
        printf("%.2f %s is %.2f %s\n", temperature, input_unit, converted_temperature, output_unit);
    }
    else {
        printf("Invalid input unit.\n");
    }
}

int main() {
    char input_unit, output_unit;
    float temperature;

    // Get user input for temperature and units
    printf("Enter temperature and units (C for Celsius, F for Fahrenheit): ");
    scanf("%c%c", &input_unit, &output_unit);

    // Convert temperature and display result
    temperature = get_temperature_input(input_unit);
    display_result(temperature, input_unit, output_unit);

    return 0;
}