//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to validate input
int validateInput(char *input) {
    if (strcmp(input, "c") == 0 || strcmp(input, "C") == 0) {
        return 1;
    } else if (strcmp(input, "f") == 0 || strcmp(input, "F") == 0) {
        return 2;
    } else {
        return 0;
    }
}

// Function to convert string to float
float stringToFloat(char *string) {
    float result = 0;
    int i = 0;
    int j = 0;
    while (string[i]!= '\0') {
        if (isdigit(string[i])) {
            result = result * 10 + (string[i] - '0');
            i++;
        } else {
            i++;
        }
    }
    return result;
}

int main() {
    char input[10];
    char choice;
    float temperature;
    float result;
    int validInput = 0;
    int choiceInt;

    // Prompt user for input
    printf("Enter temperature: ");
    scanf("%s", input);

    // Validate input
    while (validInput == 0) {
        printf("Enter unit of measurement (c/f): ");
        scanf("%s", input);
        choice = tolower(input[0]);
        validInput = validateInput(input);
        if (validInput == 0) {
            printf("Invalid input. Please enter c or f.\n");
        }
    }

    // Convert input to float
    temperature = stringToFloat(input);

    // Convert temperature
    if (choice == 'c' || choice == 'c') {
        result = celsiusToFahrenheit(temperature);
        printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, result);
    } else {
        result = fahrenheitToCelsius(temperature);
        printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, result);
    }

    return 0;
}