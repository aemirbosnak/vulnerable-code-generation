//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure definition for unit conversions
typedef struct {
    char name[50];
    float factor;
} Unit;

// Array of units and their conversion factors
Unit units[] = {
    {"Miles", 1609.34f},
    {"Kilometers", 0.001f},
    {"Pounds", 0.453592f},
    {"Kilograms", 2.20462f},
    {"Degrees Fahrenheit", 0.555555f},
    {"Degrees Celsius", 1.8f},
    {"Gallons", 3.785411f},
    {"Liters", 0.264172f}
};

// Function to find unit index by name
int findUnitIndex(char* name) {
    for (int i = 0; i < 8; i++) {
        if (strcmp(name, units[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to perform unit conversion
void convertUnits(char* fromUnit, char* toUnit, float value) {
    int fromIndex = findUnitIndex(fromUnit);
    int toIndex = findUnitIndex(toUnit);

    if (fromIndex == -1 || toIndex == -1) {
        printf("Error: Invalid units.\n");
        return;
    }

    float result = value * (units[toIndex].factor / units[fromIndex].factor);
    printf("%.2f %s is equal to %.2f %s\n", value, fromUnit, result, toUnit);
}

int main() {
    char fromUnit[50], toUnit[50];
    float value;

    printf("Enter the value to convert: ");
    scanf("%f", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", fromUnit);

    printf("Enter the unit to convert to: ");
    scanf("%s", toUnit);

    convertUnits(fromUnit, toUnit, value);

    return 0;
}