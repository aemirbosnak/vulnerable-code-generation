//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>

// Function prototypes
void displayMenu();
void lengthConverter();
void weightConverter();
void temperatureConverter();
double convertLength(double value, char unitFrom, char unitTo);
double convertWeight(double value, char unitFrom, char unitTo);
double convertTemperature(double value, char unitFrom, char unitTo);

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                lengthConverter();
                break;
            case 2: 
                weightConverter();
                break;
            case 3: 
                temperatureConverter();
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("=== Unit Converter ===\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Exit\n");
}

void lengthConverter() {
    double value;
    char unitFrom, unitTo;
    
    printf("Length Conversion:\n");
    printf("Enter value to convert: ");
    scanf("%lf", &value);
    printf("Convert from (m - meters, km - kilometers, ft - feet, in - inches): ");
    scanf(" %c", &unitFrom);
    printf("Convert to (m - meters, km - kilometers, ft - feet, in - inches): ");
    scanf(" %c", &unitTo);
    
    double result = convertLength(value, unitFrom, unitTo);
    printf("Converted value: %lf\n", result);
}

void weightConverter() {
    double value;
    char unitFrom, unitTo;
    
    printf("Weight Conversion:\n");
    printf("Enter value to convert: ");
    scanf("%lf", &value);
    printf("Convert from (kg - kilograms, g - grams, lb - pounds, oz - ounces): ");
    scanf(" %c", &unitFrom);
    printf("Convert to (kg - kilograms, g - grams, lb - pounds, oz - ounces): ");
    scanf(" %c", &unitTo);
    
    double result = convertWeight(value, unitFrom, unitTo);
    printf("Converted value: %lf\n", result);
}

void temperatureConverter() {
    double value;
    char unitFrom, unitTo;
    
    printf("Temperature Conversion:\n");
    printf("Enter value to convert: ");
    scanf("%lf", &value);
    printf("Convert from (C - Celsius, F - Fahrenheit, K - Kelvin): ");
    scanf(" %c", &unitFrom);
    printf("Convert to (C - Celsius, F - Fahrenheit, K - Kelvin): ");
    scanf(" %c", &unitTo);
    
    double result = convertTemperature(value, unitFrom, unitTo);
    printf("Converted value: %lf\n", result);
}

double convertLength(double value, char unitFrom, char unitTo) {
    if (unitFrom == 'm') {
        if (unitTo == 'km') return value / 1000;
        else if (unitTo == 'ft') return value * 3.28084;
        else if (unitTo == 'in') return value * 39.3701;
    } else if (unitFrom == 'km') {
        if (unitTo == 'm') return value * 1000;
        else if (unitTo == 'ft') return value * 3280.84;
        else if (unitTo == 'in') return value * 39370.1;
    } else if (unitFrom == 'ft') {
        if (unitTo == 'm') return value / 3.28084;
        else if (unitTo == 'km') return value / 3280.84;
        else if (unitTo == 'in') return value * 12;
    } else if (unitFrom == 'in') {
        if (unitTo == 'm') return value / 39.3701;
        else if (unitTo == 'km') return value / 39370.1;
        else if (unitTo == 'ft') return value / 12;
    }
    return value; // Return the same value if units are the same
}

double convertWeight(double value, char unitFrom, char unitTo) {
    if (unitFrom == 'kg') {
        if (unitTo == 'g') return value * 1000;
        else if (unitTo == 'lb') return value * 2.20462;
        else if (unitTo == 'oz') return value * 35.274;
    } else if (unitFrom == 'g') {
        if (unitTo == 'kg') return value / 1000;
        else if (unitTo == 'lb') return value / 453.592;
        else if (unitTo == 'oz') return value / 28.3495;
    } else if (unitFrom == 'lb') {
        if (unitTo == 'kg') return value / 2.20462;
        else if (unitTo == 'g') return value * 453.592;
        else if (unitTo == 'oz') return value * 16;
    } else if (unitFrom == 'oz') {
        if (unitTo == 'kg') return value / 35.274;
        else if (unitTo == 'g') return value * 28.3495;
        else if (unitTo == 'lb') return value / 16;
    }
    return value; // Return the same value if units are the same
}

double convertTemperature(double value, char unitFrom, char unitTo) {
    if (unitFrom == 'C') {
        if (unitTo == 'F') return (value * 9 / 5) + 32;
        else if (unitTo == 'K') return value + 273.15;
    } else if (unitFrom == 'F') {
        if (unitTo == 'C') return (value - 32) * 5 / 9;
        else if (unitTo == 'K') return (value - 32) * 5 / 9 + 273.15;
    } else if (unitFrom == 'K') {
        if (unitTo == 'C') return value - 273.15;
        else if (unitTo == 'F') return (value - 273.15) * 9 / 5 + 32;
    }
    return value; // Return the same value if units are the same
}