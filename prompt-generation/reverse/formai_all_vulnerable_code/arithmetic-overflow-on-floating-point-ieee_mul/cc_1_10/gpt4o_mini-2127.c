//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING_LEN 100
#define FAHRENHEIT 1
#define CELSIUS 2

/* Function Prototypes */
void displayWelcomeMessage();
void displayMenu();
double convertTemperature(double temperature, int fromUnit, int toUnit);
void getInput(double *temperature, int *fromUnit, int *toUnit);
void performConversion();
void displayConversionResult(double originalTemp, double convertedTemp, int fromUnit, int toUnit);

int main() {
    displayWelcomeMessage();
    performConversion();
    return 0;
}

void displayWelcomeMessage() {
    printf("========================================\n");
    printf("        Welcome to TempX Converter!    \n");
    printf("        The Temperature of Tomorrow!   \n");
    printf("========================================\n");
}

void displayMenu() {
    printf("Select the units for conversion:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("Please enter your choice (1 or 2): ");
}

double convertTemperature(double temperature, int fromUnit, int toUnit) {
    double convertedTemp = 0.0;
    
    if (fromUnit == CELSIUS && toUnit == FAHRENHEIT) {
        convertedTemp = (temperature * 9.0 / 5.0) + 32.0;
    } else if (fromUnit == FAHRENHEIT && toUnit == CELSIUS) {
        convertedTemp = (temperature - 32.0) * (5.0 / 9.0);
    } else {
        convertedTemp = temperature; // No conversion
    }
    
    return convertedTemp;
}

void getInput(double *temperature, int *fromUnit, int *toUnit) {
    printf("Enter the temperature value to convert: ");
    scanf("%lf", temperature);
    
    displayMenu();
    scanf("%d", fromUnit);
    
    printf("Now, choose the unit to convert to:\n");
    displayMenu();
    scanf("%d", toUnit);
}

void performConversion() {
    double originalTemp;
    int fromUnit, toUnit;
    
    getInput(&originalTemp, &fromUnit, &toUnit);

    // Check for valid input
    if ((fromUnit != CELSIUS && fromUnit != FAHRENHEIT) || 
        (toUnit != CELSIUS && toUnit != FAHRENHEIT)) {
        printf("Invalid unit selection. Please restart the program.\n");
        return;
    }

    double convertedTemp = convertTemperature(originalTemp, fromUnit, toUnit);
    displayConversionResult(originalTemp, convertedTemp, fromUnit, toUnit);
}

void displayConversionResult(double originalTemp, double convertedTemp, int fromUnit, int toUnit) {
    char *fromUnitStr = (fromUnit == CELSIUS) ? "Celsius" : "Fahrenheit";
    char *toUnitStr = (toUnit == CELSIUS) ? "Celsius" : "Fahrenheit";

    printf("========================================\n");
    printf("       Conversion Results                \n");
    printf("========================================\n");
    printf("Original Temperature: %.2lf %s\n", originalTemp, fromUnitStr);
    printf("Converted Temperature: %.2lf %s\n", convertedTemp, toUnitStr);
    printf("========================================\n");
    printf("Thank you for using TempX Converter!\n");
    printf("========================================\n");
}