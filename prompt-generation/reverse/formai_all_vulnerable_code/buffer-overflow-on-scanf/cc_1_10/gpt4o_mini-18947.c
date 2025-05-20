//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("***********************\n");
    printf("*      Unit Converter  *\n");
    printf("***********************\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Area Converter\n");
    printf("5. Volume Converter\n");
    printf("6. Exit\n");
    printf("Please select an option (1-6): ");
}

double convertLength(double value, int fromUnit, int toUnit) {
    double conversionTable[3][3] = {
        {1.0, 100.0, 39.37},   // Meters to meters, centimeters, inches
        {0.01, 1.0, 0.393701}, // Centimeters to meters, centimeters, inches
        {0.0254, 2.54, 1.0}    // Inches to meters, centimeters, inches
    };
    return value * conversionTable[fromUnit][toUnit];
}

double convertWeight(double value, int fromUnit, int toUnit) {
    double conversionTable[3][3] = {
        {1.0, 1000.0, 35.274}, // Kilograms to kg, grams, ounces
        {0.001, 1.0, 0.035274}, // Grams to kg, grams, ounces
        {0.0283495, 28.3495, 1.0} // Ounces to kg, grams, ounces
    };
    return value * conversionTable[fromUnit][toUnit];
}

double convertTemperature(double value, int fromUnit, int toUnit) {
    if (fromUnit == toUnit) {
        return value; // No conversion needed
    }
    
    if (fromUnit == 0) { // Celsius to other
        return (toUnit == 1) ? (value * 9.0/5.0 + 32) : (value + 273.15); // -> Fahrenheit or Kelvin
    } else if (fromUnit == 1) { // Fahrenheit to other
        return (toUnit == 0) ? ((value - 32) * 5.0/9.0) : ((value - 32) * 5.0/9.0 + 273.15); // -> Celsius or Kelvin
    } else { // Kelvin to other
        return (toUnit == 0) ? (value - 273.15) : ((value - 273.15) * 9.0/5.0 + 32); // -> Celsius or Fahrenheit
    }
}

double convertArea(double value, int fromUnit, int toUnit) {
    double conversionTable[3][3] = {
        {1.0, 10000.0, 0.000247}, // Square meters to m^2, ha, acres
        {0.0001, 1.0, 0.0000247105}, // Hectares to m^2, ha, acres
        {4046.86, 404686, 1.0} // Acres to m^2, ha, acres
    };
    return value * conversionTable[fromUnit][toUnit];
}

double convertVolume(double value, int fromUnit, int toUnit) {
    double conversionTable[3][3] = {
        {1.0, 1000.0, 35.3147}, // Cubic meters to m^3, liters, cubic feet
        {0.001, 1.0, 0.0353147}, // Liters to m^3, liters, cubic feet
        {0.0283168, 28.3168, 1.0} // Cubic feet to m^3, liters, cubic feet
    };
    return value * conversionTable[fromUnit][toUnit];
}

int main() {
    int option, fromUnit, toUnit;
    double value;
    
    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        if (option == 6) {
            printf("Exiting the program.\n");
            break;
        }

        switch (option) {
            case 1: // Length
                printf("Enter length value: ");
                scanf("%lf", &value);
                printf("Select fromUnit (0: M, 1: CM, 2: INCH): ");
                scanf("%d", &fromUnit);
                printf("Select toUnit (0: M, 1: CM, 2: INCH): ");
                scanf("%d", &toUnit);
                printf("Converted length: %.4f\n", convertLength(value, fromUnit, toUnit));
                break;

            case 2: // Weight
                printf("Enter weight value: ");
                scanf("%lf", &value);
                printf("Select fromUnit (0: KG, 1: G, 2: OZ): ");
                scanf("%d", &fromUnit);
                printf("Select toUnit (0: KG, 1: G, 2: OZ): ");
                scanf("%d", &toUnit);
                printf("Converted weight: %.4f\n", convertWeight(value, fromUnit, toUnit));
                break;

            case 3: // Temperature
                printf("Enter temperature value: ");
                scanf("%lf", &value);
                printf("Select fromUnit (0: C, 1: F, 2: K): ");
                scanf("%d", &fromUnit);
                printf("Select toUnit (0: C, 1: F, 2: K): ");
                scanf("%d", &toUnit);
                printf("Converted temperature: %.4f\n", convertTemperature(value, fromUnit, toUnit));
                break;

            case 4: // Area
                printf("Enter area value: ");
                scanf("%lf", &value);
                printf("Select fromUnit (0: M2, 1: HA, 2: ACRE): ");
                scanf("%d", &fromUnit);
                printf("Select toUnit (0: M2, 1: HA, 2: ACRE): ");
                scanf("%d", &toUnit);
                printf("Converted area: %.4f\n", convertArea(value, fromUnit, toUnit));
                break;

            case 5: // Volume
                printf("Enter volume value: ");
                scanf("%lf", &value);
                printf("Select fromUnit (0: M3, 1: L, 2: CFT): ");
                scanf("%d", &fromUnit);
                printf("Select toUnit (0: M3, 1: L, 2: CFT): ");
                scanf("%d", &toUnit);
                printf("Converted volume: %.4f\n", convertVolume(value, fromUnit, toUnit));
                break;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    return 0;
}