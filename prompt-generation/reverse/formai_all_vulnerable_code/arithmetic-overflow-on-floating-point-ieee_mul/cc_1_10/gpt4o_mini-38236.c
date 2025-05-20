//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>

void lengthConverter();
void weightConverter();
void temperatureConverter();
void volumeConverter();
void displayMenu();
float convertLength(float value, int fromUnit, int toUnit);
float convertWeight(float value, int fromUnit, int toUnit);
float convertTemperature(float value, int fromUnit, int toUnit);
float convertVolume(float value, int fromUnit, int toUnit);

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
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
                volumeConverter();
                break;
            case 5:
                printf("Exiting the converter. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n*** Unit Converter ***\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Volume Converter\n");
    printf("5. Exit\n");
}

void lengthConverter() {
    float value;
    int fromUnit, toUnit;
    printf("Length conversion:\n");
    printf("Enter length value: ");
    scanf("%f", &value);
    printf("Convert from:\n1. Meters\n2. Kilometers\n3. Feet\n4. Miles\n");
    scanf("%d", &fromUnit);
    printf("Convert to:\n1. Meters\n2. Kilometers\n3. Feet\n4. Miles\n");
    scanf("%d", &toUnit);
    float result = convertLength(value, fromUnit - 1, toUnit - 1);
    printf("Converted value: %.2f\n", result);
}

void weightConverter() {
    float value;
    int fromUnit, toUnit;
    printf("Weight conversion:\n");
    printf("Enter weight value: ");
    scanf("%f", &value);
    printf("Convert from:\n1. Kilograms\n2. Grams\n3. Pounds\n4. Ounces\n");
    scanf("%d", &fromUnit);
    printf("Convert to:\n1. Kilograms\n2. Grams\n3. Pounds\n4. Ounces\n");
    scanf("%d", &toUnit);
    float result = convertWeight(value, fromUnit - 1, toUnit - 1);
    printf("Converted value: %.2f\n", result);
}

void temperatureConverter() {
    float value;
    int fromUnit, toUnit;
    printf("Temperature conversion:\n");
    printf("Enter temperature value: ");
    scanf("%f", &value);
    printf("Convert from:\n1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    scanf("%d", &fromUnit);
    printf("Convert to:\n1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    scanf("%d", &toUnit);
    float result = convertTemperature(value, fromUnit - 1, toUnit - 1);
    printf("Converted value: %.2f\n", result);
}

void volumeConverter() {
    float value;
    int fromUnit, toUnit;
    printf("Volume conversion:\n");
    printf("Enter volume value: ");
    scanf("%f", &value);
    printf("Convert from:\n1. Liters\n2. Milliliters\n3. Gallons\n4. Cubic meters\n");
    scanf("%d", &fromUnit);
    printf("Convert to:\n1. Liters\n2. Milliliters\n3. Gallons\n4. Cubic meters\n");
    scanf("%d", &toUnit);
    float result = convertVolume(value, fromUnit - 1, toUnit - 1);
    printf("Converted value: %.2f\n", result);
}

float convertLength(float value, int fromUnit, int toUnit) {
    float meters;
    switch (fromUnit) {
        case 0: meters = value; break; // Meters
        case 1: meters = value * 1000; break; // Kilometers
        case 2: meters = value * 0.3048; break; // Feet
        case 3: meters = value * 1609.34; break; // Miles
        default: meters = value; break;
    }
    
    switch (toUnit) {
        case 0: return meters; // Meters
        case 1: return meters / 1000; // Kilometers
        case 2: return meters / 0.3048; // Feet
        case 3: return meters / 1609.34; // Miles
        default: return meters; break;
    }
}

float convertWeight(float value, int fromUnit, int toUnit) {
    float kilograms;
    switch (fromUnit) {
        case 0: kilograms = value; break; // Kilograms
        case 1: kilograms = value / 1000; break; // Grams
        case 2: kilograms = value * 0.453592; break; // Pounds
        case 3: kilograms = value * 0.0283495; break; // Ounces
        default: kilograms = value; break;
    }

    switch (toUnit) {
        case 0: return kilograms; // Kilograms
        case 1: return kilograms * 1000; // Grams
        case 2: return kilograms / 0.453592; // Pounds
        case 3: return kilograms / 0.0283495; // Ounces
        default: return kilograms; break;
    }
}

float convertTemperature(float value, int fromUnit, int toUnit) {
    float celsius;
    switch (fromUnit) {
        case 0: celsius = value; break; // Celsius
        case 1: celsius = (value - 32) * 5 / 9; break; // Fahrenheit
        case 2: celsius = value - 273.15; break; // Kelvin
        default: celsius = value; break;
    }

    switch (toUnit) {
        case 0: return celsius; // Celsius
        case 1: return celsius * 9/5 + 32; // Fahrenheit
        case 2: return celsius + 273.15; // Kelvin
        default: return celsius; break;
    }
}

float convertVolume(float value, int fromUnit, int toUnit) {
    float liters;
    switch (fromUnit) {
        case 0: liters = value; break; // Liters
        case 1: liters = value / 1000; break; // Milliliters
        case 2: liters = value * 3.78541; break; // Gallons
        case 3: liters = value * 1000; break; // Cubic meters
        default: liters = value; break;
    }

    switch (toUnit) {
        case 0: return liters; // Liters
        case 1: return liters * 1000; // Milliliters
        case 2: return liters / 3.78541; // Gallons
        case 3: return liters / 1000; // Cubic meters
        default: return liters; break;
    }
}