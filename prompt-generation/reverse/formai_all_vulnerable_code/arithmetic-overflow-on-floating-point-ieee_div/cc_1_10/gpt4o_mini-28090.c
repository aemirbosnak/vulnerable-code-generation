//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void displayMenu();
void convertLength();
void convertWeight();
void convertTemperature();
double lengthConverter(double value, int fromUnit, int toUnit);
double weightConverter(double value, int fromUnit, int toUnit);
double temperatureConverter(double value, int fromUnit, int toUnit);

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-4) or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertTemperature();
                break;
            case 0:
                printf("Exiting the Unit Converter. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n--- Unit Converter ---\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("0. Exit\n");
}

void convertLength() {
    double value;
    int fromUnit, toUnit;

    printf("Enter value to convert (e.g., 10.5): ");
    scanf("%lf", &value);
    printf("Choose from unit (1: meters, 2: kilometers, 3: miles, 4: feet): ");
    scanf("%d", &fromUnit);
    printf("Choose to unit (1: meters, 2: kilometers, 3: miles, 4: feet): ");
    scanf("%d", &toUnit);

    double result = lengthConverter(value, fromUnit, toUnit);
    printf("Converted value: %.6f\n", result);
}

void convertWeight() {
    double value;
    int fromUnit, toUnit;

    printf("Enter value to convert (e.g., 70.5): ");
    scanf("%lf", &value);
    printf("Choose from unit (1: grams, 2: kilograms, 3: pounds, 4: ounces): ");
    scanf("%d", &fromUnit);
    printf("Choose to unit (1: grams, 2: kilograms, 3: pounds, 4: ounces): ");
    scanf("%d", &toUnit);

    double result = weightConverter(value, fromUnit, toUnit);
    printf("Converted value: %.6f\n", result);
}

void convertTemperature() {
    double value;
    int fromUnit, toUnit;

    printf("Enter value to convert (e.g., 32.0): ");
    scanf("%lf", &value);
    printf("Choose from unit (1: Celsius, 2: Fahrenheit, 3: Kelvin): ");
    scanf("%d", &fromUnit);
    printf("Choose to unit (1: Celsius, 2: Fahrenheit, 3: Kelvin): ");
    scanf("%d", &toUnit);

    double result = temperatureConverter(value, fromUnit, toUnit);
    printf("Converted value: %.6f\n", result);
}

double lengthConverter(double value, int fromUnit, int toUnit) {
    if (fromUnit == toUnit) return value;

    // Convert value to meters first
    switch (fromUnit) {
        case 1: // meters
            break;
        case 2: // kilometers
            value *= 1000;
            break;
        case 3: // miles
            value *= 1609.34;
            break;
        case 4: // feet
            value *= 0.3048;
            break;
        default:
            printf("Invalid fromUnit in lengthConverter.\n");
            return 0;
    }

    // Convert meters to the target unit:
    switch (toUnit) {
        case 1: // meters
            return value;
        case 2: // kilometers
            return value / 1000;
        case 3: // miles
            return value / 1609.34;
        case 4: // feet
            return value / 0.3048;
        default:
            printf("Invalid toUnit in lengthConverter.\n");
            return 0;
    }
}

double weightConverter(double value, int fromUnit, int toUnit) {
    if (fromUnit == toUnit) return value;

    // Convert value to grams first
    switch (fromUnit) {
        case 1: // grams
            break;
        case 2: // kilograms
            value *= 1000;
            break;
        case 3: // pounds
            value *= 453.592;
            break;
        case 4: // ounces
            value *= 28.3495;
            break;
        default:
            printf("Invalid fromUnit in weightConverter.\n");
            return 0;
    }

    // Convert grams to the target unit
    switch (toUnit) {
        case 1: // grams
            return value;
        case 2: // kilograms
            return value / 1000;
        case 3: // pounds
            return value / 453.592;
        case 4: // ounces
            return value / 28.3495;
        default:
            printf("Invalid toUnit in weightConverter.\n");
            return 0;
    }
}

double temperatureConverter(double value, int fromUnit, int toUnit) {
    if (fromUnit == toUnit) return value;

    // Convert value to Celsius first
    switch (fromUnit) {
        case 1: // Celsius
            break;
        case 2: // Fahrenheit
            value = (value - 32) * 5 / 9;
            break;
        case 3: // Kelvin
            value -= 273.15;
            break;
        default:
            printf("Invalid fromUnit in temperatureConverter.\n");
            return 0;
    }

    // Convert Celsius to the target unit
    switch (toUnit) {
        case 1: // Celsius
            return value;
        case 2: // Fahrenheit
            return (value * 9 / 5) + 32;
        case 3: // Kelvin
            return value + 273.15;
        default:
            printf("Invalid toUnit in temperatureConverter.\n");
            return 0;
    }
}