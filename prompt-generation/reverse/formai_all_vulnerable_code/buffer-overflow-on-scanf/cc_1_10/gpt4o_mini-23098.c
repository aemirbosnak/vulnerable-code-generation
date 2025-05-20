//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10

typedef struct {
    char name[30];
    double conversionFactor;
} Unit;

typedef enum {
    LENGTH,
    WEIGHT,
    TEMPERATURE,
    VOLUME
} UnitType;

Unit lengthUnits[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"centimeter", 0.01},
    {"millimeter", 0.001},
    {"mile", 1609.34},
    {"yard", 0.9144},
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"nautical mile", 1852.0},
    {"decimeter", 0.1}
};

Unit weightUnits[MAX_UNITS] = {
    {"kilogram", 1.0},
    {"gram", 0.001},
    {"pound", 0.453592},
    {"ounce", 0.0283495},
    {"stone", 6.35029},
    {"tonne", 1000.0},
    {"metric ton", 1000.0},
    {"milligram", 0.000001},
    {"carat", 0.0002},
    {"slug", 14.5939}
};

Unit temperatureUnits[MAX_UNITS] = {
    {"celsius", 1.0},
    {"fahrenheit", 0.555556},
    {"kelvin", 1.0}
};

Unit volumeUnits[MAX_UNITS] = {
    {"liter", 1.0},
    {"milliliter", 0.001},
    {"gallon", 3.78541},
    {"quart", 0.946353},
    {"pint", 0.473176},
    {"cup", 0.236588},
    {"fluid ounce", 0.0295735},
    {"tablespoon", 0.0147868},
    {"teaspoon", 0.00492892},
    {"cubic meter", 1000.0}
};

double convert_units(double value, Unit fromUnit, Unit toUnit, UnitType type) {
    if (type == TEMPERATURE) {
        if (strcmp(fromUnit.name, "celsius") == 0 && strcmp(toUnit.name, "fahrenheit") == 0) {
            return (value * 9.0 / 5.0) + 32.0;
        } else if (strcmp(fromUnit.name, "fahrenheit") == 0 && strcmp(toUnit.name, "celsius") == 0) {
            return (value - 32.0) * 5.0 / 9.0;
        } else if (strcmp(fromUnit.name, "celsius") == 0 && strcmp(toUnit.name, "kelvin") == 0) {
            return value + 273.15;
        } else if (strcmp(fromUnit.name, "kelvin") == 0 && strcmp(toUnit.name, "celsius") == 0) {
            return value - 273.15;
        } else {
            return value; // Keep the values same if they are in the same scale
        }
    }
    return value * (toUnit.conversionFactor / fromUnit.conversionFactor);
}

void display_units(Unit units[], int count, char *unitType) {
    printf("Available %s Units:\n", unitType);
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
}

int main() {
    int choice, fromUnitIndex, toUnitIndex;
    double value;
    UnitType type;

    printf("Welcome to the Unit Converter!\n");
    printf("Select a unit type to convert:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Volume\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            type = LENGTH;
            display_units(lengthUnits, MAX_UNITS, "Length");
            break;
        case 2:
            type = WEIGHT;
            display_units(weightUnits, MAX_UNITS, "Weight");
            break;
        case 3:
            type = TEMPERATURE;
            display_units(temperatureUnits, 3, "Temperature");
            break;
        case 4:
            type = VOLUME;
            display_units(volumeUnits, MAX_UNITS, "Volume");
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("Select the unit you want to convert from (1-%d): ", MAX_UNITS);
    scanf("%d", &fromUnitIndex);
    printf("Select the unit you want to convert to (1-%d): ", MAX_UNITS);
    scanf("%d", &toUnitIndex);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    Unit fromUnit, toUnit;
    
    switch (type) {
        case LENGTH:
            fromUnit = lengthUnits[fromUnitIndex - 1];
            toUnit = lengthUnits[toUnitIndex - 1];
            break;
        case WEIGHT:
            fromUnit = weightUnits[fromUnitIndex - 1];
            toUnit = weightUnits[toUnitIndex - 1];
            break;
        case TEMPERATURE:
            fromUnit = temperatureUnits[fromUnitIndex - 1];
            toUnit = temperatureUnits[toUnitIndex - 1];
            break;
        case VOLUME:
            fromUnit = volumeUnits[fromUnitIndex - 1];
            toUnit = volumeUnits[toUnitIndex - 1];
            break;
        default:
            printf("Invalid unit type!\n");
            return 1;
    }

    double result = convert_units(value, fromUnit, toUnit, type);
    printf("Converted value: %.5f %s\n", result, toUnit.name);
    
    return 0;
}