//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to get the user's input
float get_user_input(char *prompt) {
    float input;
    printf("%s", prompt);
    scanf("%f", &input);
    return input;
}

// Function to print the converted temperature
void print_converted_temperature(float converted_temperature, char *unit) {
    printf("The converted temperature is: %.2f %s\n", converted_temperature, unit);
}

int main() {
    // Get the user's input
    float temperature = get_user_input("Enter the temperature: ");
    char unit = get_user_input("Enter the unit (C/F): ");

    // Convert the temperature
    float converted_temperature;
    if (unit == 'C' || unit == 'c') {
        converted_temperature = celsius_to_fahrenheit(temperature);
    } else if (unit == 'F' || unit == 'f') {
        converted_temperature = fahrenheit_to_celsius(temperature);
    } else {
        printf("Invalid unit. Please enter C or F.\n");
        return 1;
    }

    // Print the converted temperature
    if (unit == 'C' || unit == 'c') {
        print_converted_temperature(converted_temperature, "Fahrenheit");
    } else if (unit == 'F' || unit == 'f') {
        print_converted_temperature(converted_temperature, "Celsius");
    }

    return 0;
}