//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Function to check if input is a number
int isNumber(char *str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Function to get input from user
float getInput(char *message) {
    float input;
    printf("%s", message);
    if (scanf("%f", &input) == 1) {
        return input;
    }
    else {
        printf("Invalid input. Please enter a number.\n");
        return 0;
    }
}

// Function to get unit of measurement from user
char getUnit() {
    char unit;
    printf("Enter the unit of measurement (C or F): ");
    scanf("%c", &unit);
    if (unit!= 'C' && unit!= 'F') {
        printf("Invalid unit of measurement. Please enter C or F.\n");
        exit(1);
    }
    return unit;
}

int main() {
    char unit;
    float input, result;

    // Get input and unit of measurement from user
    input = getInput("Enter the temperature: ");
    unit = getUnit();

    // Convert temperature based on unit of measurement
    if (unit == 'C') {
        result = celsiusToFahrenheit(input);
        printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", input, result);
    }
    else {
        result = fahrenheitToCelsius(input);
        printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", input, result);
    }

    return 0;
}