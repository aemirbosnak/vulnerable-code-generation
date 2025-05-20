//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>

// Function declarations
void showMenu();
void convertLength();
void convertWeight();
void convertTemperature();
double lengthConverter(double value, int fromUnit, int toUnit);
double weightConverter(double value, int fromUnit, int toUnit);
double temperatureConverter(double value, int fromUnit, int toUnit);

int main() {
    int choice;
    do {
        showMenu();
        printf("Please enter your choice (1-4): ");
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
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void showMenu() {
    printf("\n*** Unit Converter ***\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Exit\n");
}

void convertLength() {
    double value;
    int fromUnit, toUnit;

    printf("Enter the length value to convert: ");
    scanf("%lf", &value);
    printf("Select from unit (1: Meters, 2: Kilometers, 3: Miles, 4: Feet): ");
    scanf("%d", &fromUnit);
    printf("Select to unit (1: Meters, 2: Kilometers, 3: Miles, 4: Feet): ");
    scanf("%d", &toUnit);
    
    double result = lengthConverter(value, fromUnit, toUnit);
    printf("Converted length: %.2f\n", result);
}

void convertWeight() {
    double value;
    int fromUnit, toUnit;

    printf("Enter the weight value to convert: ");
    scanf("%lf", &value);
    printf("Select from unit (1: Grams, 2: Kilograms, 3: Pounds, 4: Ounces): ");
    scanf("%d", &fromUnit);
    printf("Select to unit (1: Grams, 2: Kilograms, 3: Pounds, 4: Ounces): ");
    scanf("%d", &toUnit);
    
    double result = weightConverter(value, fromUnit, toUnit);
    printf("Converted weight: %.2f\n", result);
}

void convertTemperature() {
    double value;
    int fromUnit, toUnit;

    printf("Enter the temperature value to convert: ");
    scanf("%lf", &value);
    printf("Select from unit (1: Celsius, 2: Fahrenheit, 3: Kelvin): ");
    scanf("%d", &fromUnit);
    printf("Select to unit (1: Celsius, 2: Fahrenheit, 3: Kelvin): ");
    scanf("%d", &toUnit);
    
    double result = temperatureConverter(value, fromUnit, toUnit);
    printf("Converted temperature: %.2f\n", result);
}

double lengthConverter(double value, int fromUnit, int toUnit) {
    // Length units: 1 - Meters, 2 - Kilometers, 3 - Miles, 4 - Feet
    // Convert fromUnit to meters
    if (fromUnit == 1) {
        // Meters
    } else if (fromUnit == 2) {
        value *= 1000; // Kilometers to Meters
    } else if (fromUnit == 3) {
        value *= 1609.34; // Miles to Meters
    } else if (fromUnit == 4) {
        value *= 0.3048; // Feet to Meters
    }

    // Convert from meters to toUnit
    if (toUnit == 1) {
        return value; // Meters
    } else if (toUnit == 2) {
        return value / 1000; // Meters to Kilometers
    } else if (toUnit == 3) {
        return value / 1609.34; // Meters to Miles
    } else if (toUnit == 4) {
        return value / 0.3048; // Meters to Feet
    }

    return 0; // Error case
}

double weightConverter(double value, int fromUnit, int toUnit) {
    // Weight units: 1 - Grams, 2 - Kilograms, 3 - Pounds, 4 - Ounces
    // Convert fromUnit to grams
    if (fromUnit == 1) {
        // Grams
    } else if (fromUnit == 2) {
        value *= 1000; // Kilograms to Grams
    } else if (fromUnit == 3) {
        value *= 453.592; // Pounds to Grams
    } else if (fromUnit == 4) {
        value *= 28.3495; // Ounces to Grams
    }

    // Convert from grams to toUnit
    if (toUnit == 1) {
        return value; // Grams
    } else if (toUnit == 2) {
        return value / 1000; // Grams to Kilograms
    } else if (toUnit == 3) {
        return value / 453.592; // Grams to Pounds
    } else if (toUnit == 4) {
        return value / 28.3495; // Grams to Ounces
    }

    return 0; // Error case
}

double temperatureConverter(double value, int fromUnit, int toUnit) {
    // Temperature units: 1 - Celsius, 2 - Fahrenheit, 3 - Kelvin
    if (fromUnit == 1) {
        // Celsius to other units
        if (toUnit == 2) {
            return value * 9.0 / 5.0 + 32; // Celsius to Fahrenheit
        } else if (toUnit == 3) {
            return value + 273.15; // Celsius to Kelvin
        }
    } else if (fromUnit == 2) {
        // Fahrenheit to Celsius
        if (toUnit == 1) {
            return (value - 32) * 5.0 / 9.0; // Fahrenheit to Celsius
        } else if (toUnit == 3) {
            return (value - 32) * 5.0 / 9.0 + 273.15; // Fahrenheit to Kelvin
        }
    } else if (fromUnit == 3) {
        // Kelvin to Celsius
        if (toUnit == 1) {
            return value - 273.15; // Kelvin to Celsius
        } else if (toUnit == 2) {
            return (value - 273.15) * 9.0 / 5.0 + 32; // Kelvin to Fahrenheit
        }
    }

    return 0; // Error case
}