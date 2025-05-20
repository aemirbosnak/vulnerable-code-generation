//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_CONVERSIONS 5

// Declare a struct to store the units and their conversions
struct unit {
    char name[20];
    double conversion[MAX_CONVERSIONS];
};

// Declare an array to store the units
struct unit units[MAX_UNITS] = {
    {"meter", {1, 100, 1000, 1000000, 1000000000}}, // meters
    {"centimeter", {0.01, 1, 10, 100, 1000}}, // centimeters
    {"kilometer", {1000, 1, 0.01, 0.001, 0.000001}}, // kilometers
    {" millimeter", {0.001, 0.01, 1, 10, 100}}, // millimeters
    {"inch", {0.0254, 1, 2.54, 25.4, 254}} // inches
};

// Declare a function to convert between units
void convert(struct unit *u, double value) {
    int i;
    for (i = 0; i < MAX_CONVERSIONS; i++) {
        if (u->conversion[i] == 0) break;
        if (value >= u->conversion[i]) {
            value = value / u->conversion[i];
            break;
        }
    }
    if (i == MAX_CONVERSIONS) {
        printf("Error: cannot convert %f to %s\n", value, u->name);
        return;
    }
    printf("%.2f %s = %f %s\n", value, u->name, value * u->conversion[i], u->name);
}

int main() {
    double value;
    char unit[20];

    // Example usage
    printf("Enter a value in meters: ");
    scanf("%lf", &value);
    printf("Enter the desired unit: ");
    scanf(" %19s", unit);

    // Convert the value to the desired unit
    struct unit *u = &units[0];
    if (strcmp(unit, "meter") == 0) {
        convert(u, value);
    } else if (strcmp(unit, "centimeter") == 0) {
        convert(&units[1], value * 100);
    } else if (strcmp(unit, "kilometer") == 0) {
        convert(&units[2], value * 1000);
    } else if (strcmp(unit, "millimeter") == 0) {
        convert(&units[3], value * 1000);
    } else if (strcmp(unit, "inch") == 0) {
        convert(&units[4], value * 2.54);
    } else {
        printf("Invalid unit\n");
        return 1;
    }

    return 0;
}