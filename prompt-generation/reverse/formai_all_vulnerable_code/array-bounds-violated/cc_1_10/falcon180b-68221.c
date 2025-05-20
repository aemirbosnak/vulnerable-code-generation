//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Function to validate input string as a floating-point number
bool isFloat(const char *str) {
    for (int i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i]) && str[i]!= '.') {
            return false;
        }
    }
    return true;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    // Ask user for input
    char input[50];
    printf("Enter a temperature (C or F): ");
    fgets(input, sizeof(input), stdin);

    // Validate input
    char *endptr;
    float temp = strtof(input, &endptr);
    if (endptr == input ||!isFloat(input)) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert temperature
    char unit = toupper(input[strlen(input) - 1]);
    float convertedTemp;
    if (unit == 'C') {
        convertedTemp = celsiusToFahrenheit(temp);
        printf("%.2f C is %.2f F\n", temp, convertedTemp);
    } else if (unit == 'F') {
        convertedTemp = fahrenheitToCelsius(temp);
        printf("%.2f F is %.2f C\n", temp, convertedTemp);
    } else {
        printf("Invalid unit.\n");
        return 1;
    }

    return 0;
}