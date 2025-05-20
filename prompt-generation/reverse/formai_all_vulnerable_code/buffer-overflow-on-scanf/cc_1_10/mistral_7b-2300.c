//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Enum for supported units
typedef enum Unit {
    INCH,
    CM,
    FT,
    M
} Unit;

// Struct for storing conversion factors and unit names
typedef struct Conversion {
    double factor;
    const char* name;
} Conversion;

// Array of supported conversions
const Conversion conversions[] = {
    {2.54, "centimeter"},
    {12.0, "inch"},
    {0.3048, "meter"},
    {3.28084, "foot"}
};

// Function to find conversion by name
const Conversion* find_conversion(const char* name) {
    for (const Conversion* conv = conversions; conv < conversions + sizeof(conversions) / sizeof(Conversion); conv++) {
        if (strcmp(conv->name, name) == 0) {
            return conv;
        }
    }
    return NULL;
}

// Function to perform the conversion
void convert(double value, const Conversion* from, const Conversion* to) {
    double result = value * (from->factor / to->factor);
    printf("To convert %.2f %s to %.2f %s, multiply by a conversion factor of %.2f:\n", value, from->name, result, to->name, from->factor / to->factor);
    printf("Therefore, %.2f %s is equal to %.2f %s.\n", value, from->name, result, to->name);
}

// Main function
int main() {
    char input_unit[32], output_unit[32];
    double input_value;

    printf("Enter the value to be converted: ");
    scanf("%lf", &input_value);

    printf("Enter the unit of the input value: ");
    scanf("%s", input_unit);

    const Conversion* from = find_conversion(input_unit);
    if (from == NULL) {
        printf("Invalid input unit '%s'. Please try again.\n", input_unit);
        return 1;
    }

    printf("Enter the unit of the output value: ");
    scanf("%s", output_unit);

    const Conversion* to = find_conversion(output_unit);
    if (to == NULL) {
        printf("Invalid output unit '%s'. Please try again.\n", output_unit);
        return 1;
    }

    convert(input_value, from, to);

    return 0;
}