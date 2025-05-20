//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int main();
int get_input(double* value, char* unit);
double convert_temperature(double value, char from_unit, char to_unit);

// Celsius to Fahrenheit conversion formula
#define C_TO_F(c) ((c * 9.0 / 5.0) + 32.0)

// Fahrenheit to Celsius conversion formula
#define F_TO_C(f) ((f - 32.0) * 5.0 / 9.0)

int main() {
    double value;
    char from_unit, to_unit;

    // Get input from user
    if (get_input(&value, &from_unit) == 0) {
        return 1;
    }

    // Convert temperature
    double result = convert_temperature(value, from_unit, to_unit);

    // Print result
    printf("%.2f %c = %.2f %c\n", value, from_unit, result, to_unit);

    return 0;
}

int get_input(double* value, char* unit) {
    printf("Enter a temperature value followed by its unit (e.g. 25 C): ");
    scanf("%lf %c", value, unit);

    // Check for valid input
    if (*value <= 0) {
        printf("Invalid temperature value.\n");
        return 0;
    }

    // Convert unit to uppercase
    for (int i = 0; i < strlen(unit); i++) {
        unit[i] = toupper(unit[i]);
    }

    // Check for valid unit
    if (unit[0]!= 'C' && unit[0]!= 'F') {
        printf("Invalid temperature unit.\n");
        return 0;
    }

    return 1;
}

double convert_temperature(double value, char from_unit, char to_unit) {
    double result;

    // Celsius to Fahrenheit conversion
    if (from_unit == 'C' && to_unit == 'F') {
        result = C_TO_F(value);
    }
    // Fahrenheit to Celsius conversion
    else if (from_unit == 'F' && to_unit == 'C') {
        result = F_TO_C(value);
    }
    // Invalid conversion
    else {
        printf("Invalid temperature conversion.\n");
        return 0;
    }

    return result;
}