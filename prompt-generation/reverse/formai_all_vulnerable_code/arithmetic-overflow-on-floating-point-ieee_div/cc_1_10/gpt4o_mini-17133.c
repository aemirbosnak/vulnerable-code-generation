//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>

void displayMenu();
void convertLength();
void convertTemperature();
void convertWeight();
double lengthConverter(double value, int fromUnit, int toUnit);
double temperatureConverter(double value, int fromUnit, int toUnit);
double weightConverter(double value, int fromUnit, int toUnit);

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4, or 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertTemperature();
                break;
            case 3:
                convertWeight();
                break;
            case 0:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\nUnit Converter\n");
    printf("1. Length Conversion\n");
    printf("2. Temperature Conversion\n");
    printf("3. Weight Conversion\n");
    printf("0. Exit\n");
}

void convertLength() {
    double value;
    int fromUnit, toUnit;

    printf("Length unit conversion:\n");
    printf("Select a unit to convert from:\n");
    printf("1. Meters\n");
    printf("2. Kilometers\n");
    printf("3. Miles\n");
    printf("4. Feet\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &fromUnit);

    printf("Select a unit to convert to:\n");
    printf("1. Meters\n");
    printf("2. Kilometers\n");
    printf("3. Miles\n");
    printf("4. Feet\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &toUnit);

    printf("Enter the value in chosen unit: ");
    scanf("%lf", &value);

    double result = lengthConverter(value, fromUnit, toUnit);
    printf("Converted value: %.2lf\n", result);
}

double lengthConverter(double value, int fromUnit, int toUnit) {
    const double conversionFactors[4] = {1.0, 1000.0, 1609.34, 0.3048}; // Meters, Kilometers, Miles, Feet
    double meters = value * conversionFactors[fromUnit - 1];
    return meters / conversionFactors[toUnit - 1];
}

void convertTemperature() {
    double value;
    int fromUnit, toUnit;

    printf("Temperature unit conversion:\n");
    printf("Select a unit to convert from:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &fromUnit);

    printf("Select a unit to convert to:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &toUnit);

    printf("Enter the value in chosen unit: ");
    scanf("%lf", &value);

    double result = temperatureConverter(value, fromUnit, toUnit);
    printf("Converted value: %.2lf\n", result);
}

double temperatureConverter(double value, int fromUnit, int toUnit) {
    double celsius;

    if (fromUnit == 1) {
        celsius = value; // Celsius
    } else if (fromUnit == 2) {
        celsius = (value - 32) * 5 / 9; // Fahrenheit to Celsius
    } else {
        celsius = value - 273.15; // Kelvin to Celsius
    }

    if (toUnit == 1) {
        return celsius; // Celsius
    } else if (toUnit == 2) {
        return celsius * 9 / 5 + 32; // Celsius to Fahrenheit
    } else {
        return celsius + 273.15; // Celsius to Kelvin
    }
}

void convertWeight() {
    double value;
    int fromUnit, toUnit;

    printf("Weight unit conversion:\n");
    printf("Select a unit to convert from:\n");
    printf("1. Grams\n");
    printf("2. Kilograms\n");
    printf("3. Pounds\n");
    printf("4. Ounces\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &fromUnit);

    printf("Select a unit to convert to:\n");
    printf("1. Grams\n");
    printf("2. Kilograms\n");
    printf("3. Pounds\n");
    printf("4. Ounces\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &toUnit);

    printf("Enter the value in chosen unit: ");
    scanf("%lf", &value);

    double result = weightConverter(value, fromUnit, toUnit);
    printf("Converted value: %.2lf\n", result);
}

double weightConverter(double value, int fromUnit, int toUnit) {
    const double conversionFactors[4] = {1.0, 1000.0, 453.592, 28.3495}; // Grams, Kilograms, Pounds, Ounces
    double grams = value * conversionFactors[fromUnit - 1];
    return grams / conversionFactors[toUnit - 1];
}