//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to get user input
float get_input(char *prompt) {
    float input = 0;
    printf("%s", prompt);
    if (scanf("%f", &input)!= 1) {
        printf("Invalid input. Please enter a number.\n");
        exit(1);
    }
    return input;
}

int main() {
    char input_type;
    float input_value;

    // Get user input type
    printf("Enter 'C' to convert Celsius to Fahrenheit or 'F' to convert Fahrenheit to Celsius: ");
    scanf(" %c", &input_type);

    // Get user input value
    input_value = get_input("Enter temperature: ");

    // Convert temperature
    float result;
    if (input_type == 'C' || input_type == 'c') {
        result = celsius_to_fahrenheit(input_value);
        printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", input_value, result);
    } else if (input_type == 'F' || input_type == 'f') {
        result = fahrenheit_to_celsius(input_value);
        printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", input_value, result);
    } else {
        printf("Invalid input type. Please enter 'C' or 'F'.\n");
        return 1;
    }

    return 0;
}