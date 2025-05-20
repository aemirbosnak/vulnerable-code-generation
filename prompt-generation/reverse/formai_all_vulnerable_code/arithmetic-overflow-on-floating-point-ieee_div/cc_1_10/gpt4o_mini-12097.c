//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void lengthConverter();
void weightConverter();
void temperatureConverter();
double convertLength(double value, int fromUnit, int toUnit);
double convertWeight(double value, int fromUnit, int toUnit);
double convertTemperature(double value, int fromUnit, int toUnit);

int main() {
    int choice;

    while(1) {
        displayMenu();
        printf("Enter your choice (1-4), or 0 to quit: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: lengthConverter(); break;
            case 2: weightConverter(); break;
            case 3: temperatureConverter(); break;
            case 0: printf("Exiting the converter. Goodbye!\n"); return 0;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\nUnit Converter\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("0. Exit\n");
}

void lengthConverter() {
    double value;
    int fromUnit, toUnit;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Length Units: 0) meters 1) kilometers 2) miles 3) yards\n");
    printf("Convert from (0-3): ");
    scanf("%d", &fromUnit);
    printf("Convert to (0-3): ");
    scanf("%d", &toUnit);
    double result = convertLength(value, fromUnit, toUnit);
    printf("Converted Value: %.2lf\n", result);
}

void weightConverter() {
    double value;
    int fromUnit, toUnit;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Weight Units: 0) grams 1) kilograms 2) pounds 3) ounces\n");
    printf("Convert from (0-3): ");
    scanf("%d", &fromUnit);
    printf("Convert to (0-3): ");
    scanf("%d", &toUnit);
    double result = convertWeight(value, fromUnit, toUnit);
    printf("Converted Value: %.2lf\n", result);
}

void temperatureConverter() {
    double value;
    int fromUnit, toUnit;
    printf("Enter the temperature value to convert: ");
    scanf("%lf", &value);
    printf("Temperature Units: 0) Celsius 1) Fahrenheit 2) Kelvin\n");
    printf("Convert from (0-2): ");
    scanf("%d", &fromUnit);
    printf("Convert to (0-2): ");
    scanf("%d", &toUnit);
    double result = convertTemperature(value, fromUnit, toUnit);
    printf("Converted Temperature: %.2lf\n", result);
}

double convertLength(double value, int fromUnit, int toUnit) {
    // Convert length units based on selected options
    double meters;

    // Convert to meters first
    switch(fromUnit) {
        case 0: meters = value; break; // meters
        case 1: meters = value * 1000; break; // kilometers
        case 2: meters = value * 1609.34; break; // miles
        case 3: meters = value * 0.9144; break; // yards
        default: meters = value; // default case
    }

    // Convert from meters to target unit
    switch(toUnit) {
        case 0: return meters; // meters
        case 1: return meters / 1000; // kilometers
        case 2: return meters / 1609.34; // miles
        case 3: return meters / 0.9144; // yards
        default: return meters; // default case
    }
}

double convertWeight(double value, int fromUnit, int toUnit) {
    // Convert weight units based on selected options
    double grams;

    // Convert to grams first
    switch(fromUnit) {
        case 0: grams = value; break; // grams
        case 1: grams = value * 1000; break; // kilograms
        case 2: grams = value * 453.592; break; // pounds
        case 3: grams = value * 28.3495; break; // ounces
        default: grams = value; // default case
    }

    // Convert from grams to target unit
    switch(toUnit) {
        case 0: return grams; // grams
        case 1: return grams / 1000; // kilograms
        case 2: return grams / 453.592; // pounds
        case 3: return grams / 28.3495; // ounces
        default: return grams; // default case
    }
}

double convertTemperature(double value, int fromUnit, int toUnit) {
    // Convert temperature units based on selected options
    double celsius;

    switch(fromUnit) {
        case 0: celsius = value; break; // Celsius
        case 1: celsius = (value - 32) * 5.0 / 9.0; break; // Fahrenheit
        case 2: celsius = value - 273.15; break; // Kelvin
        default: celsius = value; // default case
    }

    switch(toUnit) {
        case 0: return celsius; // Celsius
        case 1: return celsius * 9.0 / 5.0 + 32; // Fahrenheit
        case 2: return celsius + 273.15; // Kelvin
        default: return celsius; // default case
    }
}