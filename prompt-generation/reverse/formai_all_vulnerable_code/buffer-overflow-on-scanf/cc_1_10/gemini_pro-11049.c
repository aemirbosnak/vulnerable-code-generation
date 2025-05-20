//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Kelvin
double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Fahrenheit to Kelvin
double fahrenheit_to_kelvin(double fahrenheit) {
    return (fahrenheit + 459.67) * 5 / 9;
}

// Function to convert Kelvin to Fahrenheit
double kelvin_to_fahrenheit(double kelvin) {
    return (kelvin * 9 / 5) - 459.67;
}

// Function to print the conversion results
void print_conversion_results(double value, char *unit1, char *unit2, double converted_value) {
    printf("%.2f %s is equal to %.2f %s\n", value, unit1, converted_value, unit2);
}

int main(void) {
    // Get the temperature value and unit from the user
    double temperature;
    char unit[10];
    printf("Enter the temperature value: ");
    scanf("%lf", &temperature);
    printf("Enter the temperature unit (Celsius, Fahrenheit, or Kelvin): ");
    scanf("%s", unit);

    // Convert the temperature to all other units
    double converted_temperature;
    if (strcmp(unit, "Celsius") == 0) {
        converted_temperature = celsius_to_fahrenheit(temperature);
        print_conversion_results(temperature, "Celsius", "Fahrenheit", converted_temperature);

        converted_temperature = celsius_to_kelvin(temperature);
        print_conversion_results(temperature, "Celsius", "Kelvin", converted_temperature);
    } else if (strcmp(unit, "Fahrenheit") == 0) {
        converted_temperature = fahrenheit_to_celsius(temperature);
        print_conversion_results(temperature, "Fahrenheit", "Celsius", converted_temperature);

        converted_temperature = fahrenheit_to_kelvin(temperature);
        print_conversion_results(temperature, "Fahrenheit", "Kelvin", converted_temperature);
    } else if (strcmp(unit, "Kelvin") == 0) {
        converted_temperature = kelvin_to_celsius(temperature);
        print_conversion_results(temperature, "Kelvin", "Celsius", converted_temperature);

        converted_temperature = kelvin_to_fahrenheit(temperature);
        print_conversion_results(temperature, "Kelvin", "Fahrenheit", converted_temperature);
    } else {
        printf("Invalid temperature unit. Please enter 'Celsius', 'Fahrenheit', or 'Kelvin'.\n");
    }

    return 0;
}