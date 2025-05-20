//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 20

typedef struct {
    char name[20];
    double factor;
    char from[20];
} Unit;

int main() {
    Unit units[MAX_UNITS];
    int numUnits = 0;
    char input[100];
    char inputUnit[20];
    char outputUnit[20];
    double value, result;

    printf("Welcome to the Unit Converter!\n\n");

    // Initialize units
    strcpy(units[numUnits].name, "Meters");
    units[numUnits].factor = 1.0;
    strcpy(units[numUnits].from, "m");
    numUnits++;

    strcpy(units[numUnits].name, "Kilometers");
    units[numUnits].factor = 1000.0;
    strcpy(units[numUnits].from, "km");
    numUnits++;

    strcpy(units[numUnits].name, "Feet");
    units[numUnits].factor = 0.3048;
    strcpy(units[numUnits].from, "ft");
    numUnits++;

    strcpy(units[numUnits].name, "Inches");
    units[numUnits].factor = 0.0254;
    strcpy(units[numUnits].from, "in");
    numUnits++;

    strcpy(units[numUnits].name, "Yards");
    units[numUnits].factor = 0.9144;
    strcpy(units[numUnits].from, "yd");
    numUnits++;

    strcpy(units[numUnits].name, "Miles");
    units[numUnits].factor = 160934.4;
    strcpy(units[numUnits].from, "mi");
    numUnits++;

    strcpy(units[numUnits].name, "Liters");
    units[numUnits].factor = 1.0;
    strcpy(units[numUnits].from, "L");
    numUnits++;

    strcpy(units[numUnits].name, "Gallons");
    units[numUnits].factor = 3.78541;
    strcpy(units[numUnits].from, "gal");
    numUnits++;

    strcpy(units[numUnits].name, "Kilograms");
    units[numUnits].factor = 1.0;
    strcpy(units[numUnits].from, "kg");
    numUnits++;

    strcpy(units[numUnits].name, "Pounds");
    units[numUnits].factor = 0.453592;
    strcpy(units[numUnits].from, "lb");
    numUnits++;

    strcpy(units[numUnits].name, "Ounces");
    units[numUnits].factor = 0.0283495;
    strcpy(units[numUnits].from, "oz");
    numUnits++;

    strcpy(units[numUnits].name, "Celsius");
    units[numUnits].factor = 1.0;
    strcpy(units[numUnits].from, "°C");
    numUnits++;

    strcpy(units[numUnits].name, "Fahrenheit");
    units[numUnits].factor = 1.8;
    strcpy(units[numUnits].from, "°F");
    numUnits++;

    printf("\nEnter the value to convert: ");
    scanf("%s", input);

    printf("\nEnter the unit of the value: ");
    scanf("%s", inputUnit);

    printf("\nEnter the unit to convert to: ");
    scanf("%s", outputUnit);

    for (int i = 0; i < numUnits; i++) {
        if (strcmp(inputUnit, units[i].from) == 0) {
            printf("\n%s = %.2f %s", input, value, units[i].name);
            return 0;
        }
    }

    // Conversion not found
    printf("\nConversion not found.\n");

    return 0;
}