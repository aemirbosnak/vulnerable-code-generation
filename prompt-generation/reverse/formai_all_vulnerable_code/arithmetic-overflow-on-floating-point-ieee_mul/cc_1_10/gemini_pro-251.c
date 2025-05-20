//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: brave
// Unit Converter with a Dash of Bravado!

#include <stdio.h>

// A global array of unit conversion factors
double conversion_factors[] = {
    1.0, // meters to meters
    0.3048, // meters to feet
    0.9144, // meters to yards
    1609.34, // meters to miles
    1000.0, // grams to grams
    0.035274, // grams to ounces
    2.20462, // grams to pounds
    3.78541, // liters to liters
    0.264172, // liters to gallons
    231.0 // cubic meters to cubic feet
};

// A global array of unit names
const char *unit_names[] = {
    "meters",
    "feet",
    "yards",
    "miles",
    "grams",
    "ounces",
    "pounds",
    "liters",
    "gallons",
    "cubic meters",
    "cubic feet"
};

// A type to represent a quantity
typedef struct {
    double value;
    int unit;
} quantity;

// Function to convert a quantity to another unit
quantity convert_quantity(quantity q, int target_unit) {
    q.value *= conversion_factors[q.unit * target_unit];
    q.unit = target_unit;
    return q;
}

// Function to print a quantity
void print_quantity(quantity q) {
    printf("%.2f %s\n", q.value, unit_names[q.unit]);
}

// Main function
int main() {
    // Declare a quantity
    quantity q;

    // Get the original value and unit from the user
    printf("Enter the original value: ");
    scanf("%lf", &q.value);
    printf("Enter the original unit (0-9): ");
    scanf("%d", &q.unit);

    // Validate the input
    if (q.unit < 0 || q.unit > 9) {
        printf("Invalid unit! Please enter a value between 0 and 9.\n");
        return -1;
    }

    // Get the target unit from the user
    printf("Enter the target unit (0-9): ");
    int target_unit;
    scanf("%d", &target_unit);

    // Validate the target unit
    if (target_unit < 0 || target_unit > 9) {
        printf("Invalid target unit! Please enter a value between 0 and 9.\n");
        return -1;
    }

    // Convert the quantity
    q = convert_quantity(q, target_unit);

    // Print the converted quantity
    printf("Converted value: ");
    print_quantity(q);

    // Exit with success
    return 0;
}