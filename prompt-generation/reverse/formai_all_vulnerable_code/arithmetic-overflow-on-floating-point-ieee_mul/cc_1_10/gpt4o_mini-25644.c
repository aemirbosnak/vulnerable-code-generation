//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 100

// Function prototypes
void displayMenu();
float convertTemperature(float value, char fromUnit, char toUnit);
void inputTemperature(float *value, char *unit);
void outputResult(float result, char unit);

// Main function
int main() {
    float temperatureValue;
    char fromUnit, toUnit;

    printf("Welcome to the Temperature Converter!\n");
    
    inputTemperature(&temperatureValue, &fromUnit);
    displayMenu();
    
    toUnit = getchar();
    toUnit = tolower(toUnit); // Normalize to lowercase
    
    if (fromUnit == toUnit) {
        printf("The converted temperature is the same: %.2f %c\n", temperatureValue, toupper(fromUnit));
        return 0;
    }

    float convertedValue = convertTemperature(temperatureValue, fromUnit, toUnit);
    outputResult(convertedValue, toUnit);
    
    return 0;
}

// Function to display the conversion menu
void displayMenu() {
    printf("Select the output temperature unit:\n");
    printf("1. Celsius (C)\n");
    printf("2. Fahrenheit (F)\n");
    printf("3. Kelvin (K)\n");
    printf("Enter your choice (1, 2, or 3): ");
}

// Function to convert temperature
float convertTemperature(float value, char fromUnit, char toUnit) {
    float result;

    // Convert from fromUnit to Kelvin for simplicity
    switch(fromUnit) {
        case 'c':
            result = value + 273.15; // Celsius to Kelvin
            break;
        case 'f':
            result = (value - 32) * 5 / 9 + 273.15; // Fahrenheit to Kelvin
            break;
        case 'k':
            result = value; // Kelvin is the reference
            break;
        default:
            printf("Invalid input unit\n");
            exit(1);
    }

    // Convert from Kelvin to target unit
    switch(toUnit) {
        case 'c':
            result -= 273.15; // Kelvin to Celsius
            break;
        case 'f':
            result = (result - 273.15) * 9 / 5 + 32; // Kelvin to Fahrenheit
            break;
        case 'k':
            // already in Kelvin
            break;
        default:
            printf("Invalid output unit\n");
            exit(1);
    }

    return result;
}

// Function to input temperature and unit
void inputTemperature(float *value, char *unit) {
    char buffer[MAX_BUFFER];

    printf("Enter the temperature value: ");
    fgets(buffer, MAX_BUFFER, stdin);
    *value = atof(buffer); // Convert string to float

    printf("Enter the temperature unit (C/F/K): ");
    fgets(buffer, MAX_BUFFER, stdin);
    *unit = tolower(buffer[0]); // Normalize to lowercase
}

// Function to output the result
void outputResult(float result, char unit) {
    printf("The converted temperature is: %.2f %c\n", result, toupper(unit));
}