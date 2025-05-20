//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: recursive
#include <stdio.h>

// Function prototypes
void displayMenu();
void lengthConverter();
void weightConverter();
void temperatureConverter();
void convertUnits(int choice);
void performConversion(int type, double value, int fromUnit, int toUnit);
double convertLength(int fromUnit, int toUnit, double value);
double convertWeight(int fromUnit, int toUnit, double value);
double convertTemperature(int fromUnit, int toUnit, double value);
void promptForConversion();
void executeConversion(int type);

// Constants for length units
#define METERS 0
#define KILOMETERS 1
#define MILES 2
#define FEET 3

// Constants for weight units
#define GRAMS 0
#define KILOGRAMS 1
#define POUNDS 2

// Constants for temperature units
#define CELSIUS 0
#define FAHRENHEIT 1
#define KELVIN 2

int main() {
    printf("Welcome to the Unit Converter!\n");
    displayMenu();
    return 0;
}

void displayMenu() {
    int choice;

    printf("Choose a category for conversion:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    convertUnits(choice);
}

void convertUnits(int choice) {
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
            printf("Exiting the program. Goodbye!\n");
            return;
        default:
            printf("Invalid choice. Please try again.\n");
            promptForConversion();
            break;
    }
}

void lengthConverter() {
    double value;
    int fromUnit, toUnit;

    printf("Enter length value to convert: ");
    scanf("%lf", &value);
    printf("From:\n0. Meters\n1. Kilometers\n2. Miles\n3. Feet\n");
    printf("Select the unit you are converting from: ");
    scanf("%d", &fromUnit);
    printf("To:\n0. Meters\n1. Kilometers\n2. Miles\n3. Feet\n");
    printf("Select the unit you are converting to: ");
    scanf("%d", &toUnit);

    double result = convertLength(fromUnit, toUnit, value);
    printf("Converted length: %.2f\n", result);

    promptForConversion();
}

void weightConverter() {
    double value;
    int fromUnit, toUnit;

    printf("Enter weight value to convert: ");
    scanf("%lf", &value);
    printf("From:\n0. Grams\n1. Kilograms\n2. Pounds\n");
    printf("Select the unit you are converting from: ");
    scanf("%d", &fromUnit);
    printf("To:\n0. Grams\n1. Kilograms\n2. Pounds\n");
    printf("Select the unit you are converting to: ");
    scanf("%d", &toUnit);

    double result = convertWeight(fromUnit, toUnit, value);
    printf("Converted weight: %.2f\n", result);

    promptForConversion();
}

void temperatureConverter() {
    double value;
    int fromUnit, toUnit;

    printf("Enter temperature value to convert: ");
    scanf("%lf", &value);
    printf("From:\n0. Celsius\n1. Fahrenheit\n2. Kelvin\n");
    printf("Select the unit you are converting from: ");
    scanf("%d", &fromUnit);
    printf("To:\n0. Celsius\n1. Fahrenheit\n2. Kelvin\n");
    printf("Select the unit you are converting to: ");
    scanf("%d", &toUnit);

    double result = convertTemperature(fromUnit, toUnit, value);
    printf("Converted temperature: %.2f\n", result);

    promptForConversion();
}

double convertLength(int fromUnit, int toUnit, double value) {
    if (fromUnit == toUnit) return value; // No conversion needed
    // Conversion logic
    if (fromUnit == METERS) {
        switch (toUnit) {
            case KILOMETERS: return value / 1000.0;
            case MILES: return value / 1609.34;
            case FEET: return value * 3.28084;
        }
    } else if (fromUnit == KILOMETERS) {
        switch (toUnit) {
            case METERS: return value * 1000.0;
            case MILES: return value / 1.60934;
            case FEET: return value * 3280.84;
        }
    } else if (fromUnit == MILES) {
        switch (toUnit) {
            case METERS: return value * 1609.34;
            case KILOMETERS: return value * 1.60934;
            case FEET: return value * 5280.0;
        }
    } else if (fromUnit == FEET) {
        switch (toUnit) {
            case METERS: return value / 3.28084;
            case KILOMETERS: return value / 3280.84;
            case MILES: return value / 5280.0;
        }
    }
    return value; // Fallback for unhandled cases
}

double convertWeight(int fromUnit, int toUnit, double value) {
    if (fromUnit == toUnit) return value; // No conversion needed
    // Conversion logic
    if (fromUnit == GRAMS) {
        switch (toUnit) {
            case KILOGRAMS: return value / 1000.0;
            case POUNDS: return value / 453.592;
        }
    } else if (fromUnit == KILOGRAMS) {
        switch (toUnit) {
            case GRAMS: return value * 1000.0;
            case POUNDS: return value * 2.20462;
        }
    } else if (fromUnit == POUNDS) {
        switch (toUnit) {
            case GRAMS: return value * 453.592;
            case KILOGRAMS: return value / 2.20462;
        }
    }
    return value; // Fallback for unhandled cases
}

double convertTemperature(int fromUnit, int toUnit, double value) {
    if (fromUnit == toUnit) return value; // No conversion needed
    if (fromUnit == CELSIUS) {
        if (toUnit == FAHRENHEIT) return (value * 9.0 / 5.0) + 32.0;
        if (toUnit == KELVIN) return value + 273.15;
    } else if (fromUnit == FAHRENHEIT) {
        if (toUnit == CELSIUS) return (value - 32.0) * 5.0 / 9.0;
        if (toUnit == KELVIN) return (value - 32.0) * 5.0 / 9.0 + 273.15;
    } else if (fromUnit == KELVIN) {
        if (toUnit == CELSIUS) return value - 273.15;
        if (toUnit == FAHRENHEIT) return (value - 273.15) * 9.0 / 5.0 + 32.0;
    }
    return value; // Fallback for unhandled cases
}

void promptForConversion() {
    char choice;
    printf("Would you like to perform another conversion? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        displayMenu();
    } else {
        printf("Thank you for using the unit converter! Goodbye!\n");
    }
}