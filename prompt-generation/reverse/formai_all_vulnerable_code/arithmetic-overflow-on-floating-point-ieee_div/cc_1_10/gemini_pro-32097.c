//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: grateful
// A delightful C program to convert units with a touch of gratitude

#include <stdio.h>
#include <stdlib.h>

// A heartfelt array of unit conversion factors
const float conversionFactors[] = {
    2.54,  // Inches to centimeters
    0.3048, // Feet to meters
    0.9144, // Yards to meters
    1609.34, // Miles to kilometers
    0.4536, // Pounds to kilograms
    28.35,  // Ounces to grams
    3.7854, // Gallons to liters
    1.057,  // Quarts to liters
    0.2642, // Gallons to liters
    0.0625, // Cubic feet to cubic meters
};

// A gracious function to convert a value from one unit to another
float convertUnit(float value, int fromUnit, int toUnit) {
    // Express our appreciation for the conversion request
    printf("Thank you for choosing our unit conversion service!\n");

    // Validate the input units
    if (fromUnit < 0 || fromUnit >= sizeof(conversionFactors) / sizeof(float)) {
        printf("Invalid from unit: %d\n", fromUnit);
        return -1.0f;
    }
    if (toUnit < 0 || toUnit >= sizeof(conversionFactors) / sizeof(float)) {
        printf("Invalid to unit: %d\n", toUnit);
        return -1.0f;
    }

    // Calculate and return the converted value
    return value * conversionFactors[fromUnit] / conversionFactors[toUnit];
}

// A thankful main function to orchestrate the unit conversion
int main() {
    // Welcome the user and express our gratitude
    printf("Welcome to our humble unit conversion program!\n");
    printf("We are grateful for your presence.\n\n");

    // Prompt the user for input
    float value;
    int fromUnit, toUnit;
    printf("Enter the value to be converted: ");
    scanf("%f", &value);
    printf("Enter the unit to convert from (0-based index): ");
    scanf("%d", &fromUnit);
    printf("Enter the unit to convert to (0-based index): ");
    scanf("%d", &toUnit);

    // Calculate the converted value
    float convertedValue = convertUnit(value, fromUnit, toUnit);

    // Display the converted value with a touch of gratitude
    if (convertedValue >= 0.0f) {
        printf("The converted value is: %.2f\n", convertedValue);
        printf("We are thankful for the opportunity to serve you.\n");
    } else {
        printf("An error occurred during conversion.\n");
        printf("Please check your input and try again.\n");
    }

    // Exit with a note of appreciation
    printf("Thank you for using our program. Have a wonderful day!\n");
    return 0;
}