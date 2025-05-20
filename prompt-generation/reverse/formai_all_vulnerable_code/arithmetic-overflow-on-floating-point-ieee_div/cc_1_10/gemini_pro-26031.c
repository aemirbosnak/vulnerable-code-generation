//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Structure to store conversion factors
typedef struct {
    double from_base;
    double to_base;
} conversion_factor;

// Array of conversion factors
conversion_factor factors[] = {
    {1.0, 1000.0}, // meters to kilometers
    {1.0, 2.54}, // centimeters to inches
    {1.0, 0.621371}, // miles to kilometers
    {1.0, 3.28084}, // feet to meters
    {1.0, 2.20462}, // pounds to kilograms
    {1.0, 3785.41}, // liters to gallons
    {1.0, 231.0}, // cubic inches to cubic centimeters
};

// Function to convert a value from one unit to another
double convert(double value, conversion_factor factor) {
    return value * factor.to_base / factor.from_base;
}

// Function to print a list of conversion factors
void print_factors() {
    printf("Available conversion factors:\n");
    for (int i = 0; i < sizeof(factors) / sizeof(conversion_factor); i++) {
        printf("%f %s to %f %s\n", factors[i].from_base, "meters", factors[i].to_base, "kilometers");
    }
}

// Main function
int main() {
    // Print a list of conversion factors
    print_factors();

    // Get the user's input
    double value;
    char from_unit[20];
    char to_unit[20];
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);
    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    // Find the conversion factor
    conversion_factor factor;
    for (int i = 0; i < sizeof(factors) / sizeof(conversion_factor); i++) {
        if (strcmp(from_unit, "meters") == 0 && strcmp(to_unit, "kilometers") == 0) {
            factor = factors[i];
            break;
        }
    }

    // Convert the value
    double converted_value = convert(value, factor);

    // Print the result
    printf("%f %s is equal to %f %s\n", value, from_unit, converted_value, to_unit);

    return 0;
}