//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Struct to store unit details
typedef struct {
    char name[20];
    float conversion_factor;
} Unit;

// Array of units
Unit units[] = {{"Centimeter", 0.01f}, {"Meter", 1.0f}, {"Kilometer", 1000.0f},
               {"Millimeter", 0.001f}, {"Inch", 0.0254f}, {"Foot", 0.3048f},
               {"Yard", 0.9144f}, {"Mile", 1609.34f}, {"Gallon", 0.0264172},
               {"Liter", 0.001056688}, {"Ounce", 0.035274}, {"Pound", 2.20462}};

int main() {
    char input_unit[20], target_unit[20];
    float value, conversion_factor, result;
    int i;

    printf("\n======= WELCOME TO THE UNIT CONVERTER =======\n\n");
    printf("Enter the value you want to convert: ");
    scanf("%f", &value);
    printf("Enter the unit of the value: ");
    scanf("%s", input_unit);

    // Convert input unit to lowercase
    for (i = 0; input_unit[i]; i++) {
        input_unit[i] = tolower(input_unit[i]);
    }

    // Search for input unit in the array
    for (i = 0; i < 10; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            conversion_factor = units[i].conversion_factor;
            break;
        }
    }

    if (i == 10) {
        printf("Invalid input unit.\n");
        return 1;
    }

    printf("Enter the target unit: ");
    scanf("%s", target_unit);

    // Convert target unit to lowercase
    for (i = 0; target_unit[i]; i++) {
        target_unit[i] = tolower(target_unit[i]);
    }

    // Search for target unit in the array
    for (i = 0; i < 10; i++) {
        if (strcmp(target_unit, units[i].name) == 0) {
            result = value * units[i].conversion_factor / conversion_factor;
            printf("The equivalent %s of %.2f %s is %.2f %s\n", units[i].name, value, input_unit, result, units[i].name);
            return 0;
        }
    }

    printf("Invalid target unit.\n");
    return 1;
}