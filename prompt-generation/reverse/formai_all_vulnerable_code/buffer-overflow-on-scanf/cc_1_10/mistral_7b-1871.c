//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struct to define unit types and their conversion factors
typedef struct {
    char name[20];
    double factor;
} Unit;

// Array of units with their respective conversion factors
Unit units[] = {
    {"Meters", 0.001},
    {"Kilometers", 1000.0},
    {"Centimeters", 0.01},
    {"Miles", 1609.34},
    {"Feet", 0.3048},
    {"Inches", 0.0254},
    {"Grams", 0.001},
    {"Kilograms", 1000.0},
    {"Ounces", 0.035274},
    {"Pounds", 0.453592},
    {"Kilograms per square meter", 1.0},
    {"Pascals", 1.0}
};

// Function to find unit in the array based on given name
int findUnitIndex(char* unitName) {
    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (strcmp(units[i].name, unitName) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to convert value from source unit to target unit
double convertValue(double value, char* sourceUnit, char* targetUnit) {
    int sourceIndex = findUnitIndex(sourceUnit);
    int targetIndex = findUnitIndex(targetUnit);

    if (sourceIndex == -1 || targetIndex == -1) {
        printf("Invalid units!\n");
        exit(1);
    }

    double result = value * (units[targetIndex].factor / units[sourceIndex].factor);
    return result;
}

int main() {
    double length, mass, pressure;
    char sourceUnit[20], targetUnit[20];

    printf("Enter the length value: ");
    scanf("%lf", &length);
    printf("Enter the source unit: ");
    scanf("%s", sourceUnit);
    printf("Enter the target unit: ");
    scanf("%s", targetUnit);

    printf("\nLength conversion result: %.6f %s\n", convertValue(length, sourceUnit, targetUnit), targetUnit);

    printf("\nEnter the mass value: ");
    scanf("%lf", &mass);
    printf("Enter the source unit: ");
    scanf("%s", sourceUnit);
    printf("Enter the target unit: ");
    scanf("%s", targetUnit);

    printf("\nMass conversion result: %.6f %s\n", convertValue(mass, sourceUnit, targetUnit), targetUnit);

    printf("\nEnter the pressure value: ");
    scanf("%lf", &pressure);
    printf("Enter the source unit: ");
    scanf("%s", sourceUnit);
    printf("Enter the target unit: ");
    scanf("%s", targetUnit);

    printf("\nPressure conversion result: %.6f %s\n", convertValue(pressure, sourceUnit, targetUnit), targetUnit);

    return 0;
}