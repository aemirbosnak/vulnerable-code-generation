//FormAI DATASET v1.0 Category: Unit converter ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

// Function prototypes
float toMeters(float value, char fromUnit);
float toKelvin(float value, char fromUnit);
float toKilograms(float value, char fromUnit);
void printError();

int main() {
    // User input variables
    float input;
    char fromUnit, toUnit;

    // Print program header
    printf("=== INVASIVE UNIT CONVERTER ===\n\n");

    // Ask for input values
    printf("Enter the value you want to convert: ");
    scanf("%f", &input);
    printf("Enter the unit you want to convert from: ");
    scanf(" %c", &fromUnit);
    printf("Enter the unit you want to convert to: ");
    scanf(" %c", &toUnit);

    printf("\nResult: ");

    // Convert distance units
    if (fromUnit == 'm' && toUnit == 'f') {
        printf("%.2f feet", toMeters(input, fromUnit) * 3.28084);
    } else if (fromUnit == 'f' && toUnit == 'm') {
        printf("%.2f meters", toMeters(input, fromUnit));
    } else if (fromUnit == 'm' && toUnit == 'i') {
        printf("%.2f inches", toMeters(input, fromUnit) * 39.3701);
    } else if (fromUnit == 'i' && toUnit == 'm') {
        printf("%.2f meters", toMeters(input, fromUnit));
    }

    // Convert temperature units
    else if (fromUnit == 'c' && toUnit == 'f') {
        printf("%.2f degrees Fahrenheit", (input * 1.8) + 32);
    } else if (fromUnit == 'f' && toUnit == 'c') {
        printf("%.2f degrees Celsius", (input - 32) / 1.8);
    } else if (fromUnit == 'c' && toUnit == 'k') {
        printf("%.2f Kelvin", toKelvin(input, fromUnit));
    } else if (fromUnit == 'k' && toUnit == 'c') {
        printf("%.2f degrees Celsius", toKelvin(input, fromUnit) - 273.15);
    }

    // Convert weight units
    else if (fromUnit == 'k' && toUnit == 'p') {
        printf("%.2f pounds", toKilograms(input, fromUnit) * 2.20462);
    } else if (fromUnit == 'p' && toUnit == 'k') {
        printf("%.2f Kilograms", toKilograms(input, fromUnit));
    } else {
        // Invalid unit input error
        printError();
        return 1;
    }

    printf("\n\n");
    return 0;
}

// Convert distance units to meters
float toMeters(float value, char fromUnit) {
    switch(fromUnit) {
        case 'm':
            return value;
        case 'f':
            return value / 3.28084;
        case 'i':
            return value / 39.3701;
        default:
            // Invalid distance unit error
            printError();
            exit(1);
    }
}

// Convert temperature units to Kelvin
float toKelvin(float value, char fromUnit) {
    switch(fromUnit) {
        case 'c':
            return value + 273.15;
        case 'f':
            return (value + 459.67) * 5/9;
        case 'k':
            return value;
        default:
            // Invalid temperature unit error
            printError();
            exit(1);
    }
}

// Convert weight units to Kilograms
float toKilograms(float value, char fromUnit) {
    switch(fromUnit) {
        case 'k':
            return value;
        case 'p':
            return value / 2.20462;
        default:
            // Invalid weight unit error
            printError();
            exit(1);
    }
}

// Print error message
void printError() {
    printf("\nERROR: Invalid unit input!\n");
}