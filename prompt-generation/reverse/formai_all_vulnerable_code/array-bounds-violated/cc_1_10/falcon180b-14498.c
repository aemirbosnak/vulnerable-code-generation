//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if input is a valid number
int is_number(char *input) {
    while (*input) {
        if (!isdigit(*input)) {
            return 0;
        }
        input++;
    }
    return 1;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Main function
int main() {
    char input[100];
    double temperature, result;
    char unit;

    // Prompt user for input
    printf("Enter temperature (e.g. 25C or 77F): ");
    scanf("%s", input);

    // Check if input is a valid number
    if (!is_number(input)) {
        printf("Invalid input\n");
        return 1;
    }

    // Check if user entered Celsius or Fahrenheit
    if (tolower(input[strlen(input) - 1]) == 'c') {
        temperature = atof(input);
        result = celsius_to_fahrenheit(temperature);
        unit = 'F';
    } else if (tolower(input[strlen(input) - 1]) == 'f') {
        temperature = atof(input);
        result = fahrenheit_to_celsius(temperature);
        unit = 'C';
    } else {
        printf("Invalid unit\n");
        return 1;
    }

    // Print result
    printf("%.2f%c = %.2f%c\n", temperature, tolower(input[strlen(input) - 1]), result, unit);

    return 0;
}