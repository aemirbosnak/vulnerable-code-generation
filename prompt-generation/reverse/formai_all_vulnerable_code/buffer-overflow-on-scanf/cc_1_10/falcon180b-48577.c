//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 8
#define UNIT_NAMES "Length, Weight, Volume, Temperature, Time, Speed, Area, Power"

typedef struct {
    char name[20];
    double factor;
} unit;

unit units[NUM_UNITS] = {{"Meters", 1}, {"Kilograms", 1}, {"Liters", 1}, {"Kelvin", 1}, {"Seconds", 1}, {"Meters/Second", 1}, {"Square Meters", 1}, {"Watts", 1}};

int main() {
    char input[100];
    char fromUnit[20], toUnit[20];
    double value, result;
    int i, j;

    printf("Welcome to the Unit Converter!\n\n");
    printf("Please enter the unit you want to convert (e.g. Meters): ");
    scanf("%s", input);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            printf("You have selected %s.\n", input);
            break;
        }
    }

    printf("Please enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Please enter the unit you want to convert from: ");
    scanf("%s", fromUnit);

    printf("Please enter the unit you want to convert to: ");
    scanf("%s", toUnit);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(fromUnit, units[i].name) == 0) {
            for (j = 0; j < NUM_UNITS; j++) {
                if (strcmp(toUnit, units[j].name) == 0) {
                    result = value * units[i].factor / units[j].factor;
                    printf("%.2lf %s is equal to %.2lf %s.\n", value, fromUnit, result, toUnit);
                    break;
                }
            }
            break;
        }
    }

    return 0;
}