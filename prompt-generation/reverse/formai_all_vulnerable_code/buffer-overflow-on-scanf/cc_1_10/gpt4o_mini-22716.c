//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>

#define MAX_UNITS 10

// Enum for different types of units
typedef enum {
    LENGTH,
    WEIGHT,
    TEMPERATURE
} UnitType;

// Structure to hold information about a unit
typedef struct {
    char name[20];
    double conversionFactor; // Factor to convert to base unit
    UnitType type;
} Unit;

// Array of units
Unit units[MAX_UNITS];
int unitCount = 0;

// Function to add a new unit
void addUnit(char* name, double conversionFactor, UnitType type) {
    if (unitCount < MAX_UNITS) {
        snprintf(units[unitCount].name, sizeof(units[unitCount].name), "%s", name);
        units[unitCount].conversionFactor = conversionFactor;
        units[unitCount].type = type;
        unitCount++;
    } else {
        printf("Maximum number of units reached. Cannot add more.\n");
    }
}

// Function to display the available units
void displayUnits(UnitType type) {
    printf("Available units:\n");
    for (int i = 0; i < unitCount; i++) {
        if (units[i].type == type) {
            printf("%d. %s\n", i + 1, units[i].name);
        }
    }
}

// Function to convert value from one unit to another
double convert(double value, int fromUnit, int toUnit) {
    if (fromUnit < 0 || toUnit < 0 || fromUnit >= unitCount || toUnit >= unitCount) {
        printf("Invalid unit selection.\n");
        return -1;
    }
    // Convert value to base unit and then to target unit
    double baseValue = value * units[fromUnit].conversionFactor;
    return baseValue / units[toUnit].conversionFactor;
}

// Function to get user input for the conversion
void getInputAndConvert(UnitType type) {
    int fromUnit, toUnit;
    double value;

    displayUnits(type);
    printf("Select the unit you want to convert from (1-%d): ", unitCount);
    scanf("%d", &fromUnit);
    
    printf("Select the unit you want to convert to (1-%d): ", unitCount);
    scanf("%d", &toUnit);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    // Adjusting for 0-based index
    fromUnit--;
    toUnit--;

    double result = convert(value, fromUnit, toUnit);
    if (result != -1) {
        printf("Converted value: %.2f %s\n", result, units[toUnit].name);
    }
}

int main() {
    // Populate the unit conversions
    addUnit("meters", 1.0, LENGTH);
    addUnit("kilometers", 1000.0, LENGTH);
    addUnit("miles", 1609.34, LENGTH);
    addUnit("grams", 1.0, WEIGHT);
    addUnit("kilograms", 1000.0, WEIGHT);
    addUnit("pounds", 453.592, WEIGHT);
    addUnit("Celsius", 1.0, TEMPERATURE);
    addUnit("Fahrenheit", 0.555556, TEMPERATURE); // 5/9 in decimal
    addUnit("Kelvin", 1.0, TEMPERATURE);
    
    printf("Welcome to the Unit Converter! Choose a conversion type:\n");
    printf("1. Length\n2. Weight\n3. Temperature\n");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            getInputAndConvert(LENGTH);
            break;
        case 2:
            getInputAndConvert(WEIGHT);
            break;
        case 3:
            printf("Temperature conversions can be tricky. Let's convert:\n");
            getInputAndConvert(TEMPERATURE);
            break;
        default:
            printf("Invalid choice. Exiting.\n");
            break;
    }
    
    return 0;
}