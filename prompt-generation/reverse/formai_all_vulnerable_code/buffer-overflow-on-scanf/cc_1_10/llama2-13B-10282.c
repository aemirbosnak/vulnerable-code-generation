//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_UNITS 10

// Structure to hold unit conversions
typedef struct {
    char name[20];  // Unit name
    double factor;   // Conversion factor
} unit_conversion_t;

// Array to hold unit conversions
unit_conversion_t conversions[MAX_UNITS] = {
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 1.609344},
    {"inch", 0.0254},
    {"pound", 0.453592},
    {"ounce", 0.0283495},
    {"gallon", 0.264172},
    {"fluid_ounce", 0.0236588},
    {"temperature", 0.000001},
    {"weight", 0.0625}
};

// Function to convert between units
double convert_unit(char *from_unit, char *to_unit, double value) {
    int i = 0;
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(conversions[i].name, from_unit) == 0) {
            break;
        }
    }
    if (i == MAX_UNITS) {
        printf("Error: Unknown unit %s\n", from_unit);
        return -1;
    }
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(conversions[i].name, to_unit) == 0) {
            break;
        }
    }
    if (i == MAX_UNITS) {
        printf("Error: Unknown unit %s\n", to_unit);
        return -1;
    }
    return value * conversions[i].factor;
}

int main() {
    char from_unit[20];
    char to_unit[20];
    double value;

    printf("Enter a value to convert (e.g. 5 foot): ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert from (e.g. foot): ");
    scanf("%19s", from_unit);

    printf("Enter the unit you want to convert to (e.g. yard): ");
    scanf("%19s", to_unit);

    double converted_value = convert_unit(from_unit, to_unit, value);

    printf("The value in unit %s is %lf\n", to_unit, converted_value);

    return 0;
}