//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct for a unit conversion
typedef struct {
    char name[20];  // Unit name
    double factor;   // Conversion factor
} unit_t;

// Define an array of unit conversions
unit_t conversions[] = {
    {"m", 1.0}, {"cm", 0.01}, {"mm", 0.001},
    {"ft", 0.3048}, {"in", 0.0254}, {"yd", 0.9144},
    {"kg", 0.001}, {"g", 0.000001}, {"oz", 0.0283168},
    {"lb", 0.45359237}, {"ton", 0.001},
    {"gal", 0.003785}, {"pt", 0.000625},
    {"fl oz", 0.0003785}
};

// Function to perform a unit conversion
double convert(double value, char from_unit[20], char to_unit[20]) {
    int i = 0;
    for (i = 0; i < sizeof(conversions) / sizeof(conversions[0]); i++) {
        if (strcmp(from_unit, conversions[i].name) == 0) {
            break;
        }
    }
    if (i == sizeof(conversions) / sizeof(conversions[0])) {
        printf("Invalid unit: %s\n", from_unit);
        return 0;
    }
    return value * conversions[i].factor;
}

int main() {
    char from_unit[20], to_unit[20];
    double value;

    // Example usage
    printf("Enter a value: ");
    scanf("%lf", &value);
    printf("From unit: ");
    fgets(from_unit, 20, stdin);
    printf("To unit: ");
    fgets(to_unit, 20, stdin);

    // Perform the conversion
    double converted_value = convert(value, from_unit, to_unit);
    printf("Converted value: %lf\n", converted_value);

    return 0;
}