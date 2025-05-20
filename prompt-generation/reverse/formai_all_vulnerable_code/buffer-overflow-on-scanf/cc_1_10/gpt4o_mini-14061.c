//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    LENGTH,
    TEMPERATURE,
    WEIGHT,
    UNKNOWN
} UnitType;

void displayMenu() {
    printf("Unit Converter\n");
    printf("=================\n");
    printf("1. Length (meters, kilometers, miles)\n");
    printf("2. Temperature (Celsius, Fahrenheit)\n");
    printf("3. Weight (grams, kilograms, pounds)\n");
    printf("0. Exit\n");
    printf("Select a unit type to convert: ");
}

void lengthConverter() {
    printf("Length Converter\n");
    printf("Available units: 1. Meters 2. Kilometers 3. Miles\n");
    double value;
    int fromUnit, toUnit;
    
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    
    printf("Choose from: 1. Meters 2. Kilometers 3. Miles: ");
    scanf("%d", &fromUnit);
    
    printf("Choose to convert to: 1. Meters 2. Kilometers 3. Miles: ");
    scanf("%d", &toUnit);
    
    double convertedValue = value;
    // Convert from selected unit to meters
    switch(fromUnit) {
        case 1: // Meters
            break;
        case 2: // Kilometers
            convertedValue = value * 1000;
            break;
        case 3: // Miles
            convertedValue = value * 1609.34;
            break;
        default:
            printf("Invalid unit selected.\n");
            return;
    }

    // Convert from meters to the target unit
    switch(toUnit) {
        case 1: // Meters
            break;
        case 2: // Kilometers
            convertedValue /= 1000;
            break;
        case 3: // Miles
            convertedValue /= 1609.34;
            break;
        default:
            printf("Invalid unit selected.\n");
            return;
    }
    printf("Converted value: %.2f\n", convertedValue);
}

void temperatureConverter() {
    printf("Temperature Converter\n");
    printf("Available units: 1. Celsius 2. Fahrenheit\n");
    double value;
    int fromUnit, toUnit;
    
    printf("Enter the temperature value to convert: ");
    scanf("%lf", &value);
    
    printf("Choose from: 1. Celsius 2. Fahrenheit: ");
    scanf("%d", &fromUnit);
    
    printf("Choose to convert to: 1. Celsius 2. Fahrenheit: ");
    scanf("%d", &toUnit);
    
    double convertedValue = value;
    // Convert from selected unit to Celsius
    switch(fromUnit) {
        case 1: // Celsius
            break;
        case 2: // Fahrenheit
            convertedValue = (value - 32) * 5.0 / 9.0;
            break;
        default:
            printf("Invalid unit selected.\n");
            return;
    }

    // Convert from Celsius to the target unit
    switch(toUnit) {
        case 1: // Celsius
            break;
        case 2: // Fahrenheit
            convertedValue = (convertedValue * 9.0 / 5.0) + 32;
            break;
        default:
            printf("Invalid unit selected.\n");
            return;
    }
    printf("Converted temperature: %.2f\n", convertedValue);
}

void weightConverter() {
    printf("Weight Converter\n");
    printf("Available units: 1. Grams 2. Kilograms 3. Pounds\n");
    double value;
    int fromUnit, toUnit;
    
    printf("Enter the weight value to convert: ");
    scanf("%lf", &value);
    
    printf("Choose from: 1. Grams 2. Kilograms 3. Pounds: ");
    scanf("%d", &fromUnit);
    
    printf("Choose to convert to: 1. Grams 2. Kilograms 3. Pounds: ");
    scanf("%d", &toUnit);
    
    double convertedValue = value;
    // Convert from selected unit to grams
    switch(fromUnit) {
        case 1: // Grams
            break;
        case 2: // Kilograms
            convertedValue = value * 1000;
            break;
        case 3: // Pounds
            convertedValue = value * 453.592;
            break;
        default:
            printf("Invalid unit selected.\n");
            return;
    }

    // Convert from grams to the target unit
    switch(toUnit) {
        case 1: // Grams
            break;
        case 2: // Kilograms
            convertedValue /= 1000;
            break;
        case 3: // Pounds
            convertedValue /= 453.592;
            break;
        default:
            printf("Invalid unit selected.\n");
            return;
    }
    printf("Converted weight: %.2f\n", convertedValue);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Exiting the unit converter. Goodbye!\n");
            break;
        }
        
        switch (choice) {
            case 1:
                lengthConverter();
                break;
            case 2:
                temperatureConverter();
                break;
            case 3:
                weightConverter();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}