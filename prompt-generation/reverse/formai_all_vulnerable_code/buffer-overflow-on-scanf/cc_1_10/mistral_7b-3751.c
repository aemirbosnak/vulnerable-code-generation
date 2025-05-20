//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Struct to store unit conversions
typedef struct {
    const char* name;
    double conversion_factor;
} Unit;

// Array of supported units
Unit units[] = {
    {"Meter", 1.0},
    {"Kilometer", 1000.0},
    {"Centimeter", 0.01},
    {"Light-year", 9.461e+15},
    {"Astronomical unit", 1.496e+11},
    {"Parsec", 3.08568756e+16}
};

// Function to find unit index by name
int find_unit_index(const char* name) {
    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to convert units
void convert_units(const char* from_unit, double value, const char* to_unit) {
    int from_index = find_unit_index(from_unit);
    int to_index = find_unit_index(to_unit);

    if (from_index == -1 || to_index == -1) {
        printf("Invalid units.\n");
        return;
    }

    double result = value * units[from_index].conversion_factor / units[to_index].conversion_factor;
    printf("%.12lf %s is equal to %.12lf %s.\n", value, from_unit, result, to_unit);
}

int main() {
    char from_unit[10], to_unit[10];
    double value;

    printf("Welcome to the Galactic Length Converter 3000!\n");
    printf("Enter the value in meters: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert from (Meter, Kilometer, Centimeter): ");
    scanf("%s", from_unit);
    printf("Enter the unit you want to convert to (Light-year, Astronomical unit, Parsec): ");
    scanf("%s", to_unit);

    convert_units(from_unit, value, to_unit);

    return 0;
}