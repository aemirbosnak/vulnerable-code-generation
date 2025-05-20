//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
double convert_unit(double value, char from_unit, char to_unit);
char *unit_options(char unit);

int main() {
    double value;
    char from_unit, to_unit;

    // Get input from user
    printf("Enter a value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit of the value: ");
    scanf(" %c", &from_unit);
    printf("Enter the unit to convert to: ");
    scanf(" %c", &to_unit);

    // Convert the value and print the result
    double result = convert_unit(value, from_unit, to_unit);
    printf("%.2lf %c = %.2lf %c\n", value, from_unit, result, to_unit);

    return 0;
}

// Converts a value from one unit to another
double convert_unit(double value, char from_unit, char to_unit) {
    switch (from_unit) {
        case'm':
            switch (to_unit) {
                case 'k':
                    return value / 1000;
                case 'cm':
                    return value * 100;
                default:
                    return value;
            }
        case 'k':
            switch (to_unit) {
                case'm':
                    return value * 1000;
                case 'cm':
                    return value * 10000;
                default:
                    return value;
            }
        case 'cm':
            switch (to_unit) {
                case'm':
                    return value / 100;
                case 'k':
                    return value / 10000;
                default:
                    return value;
            }
        default:
            return value;
    }
}

// Displays unit options based on user input
char *unit_options(char unit) {
    switch (unit) {
        case'm':
            return "m, km";
        case 'k':
            return "m, cm";
        case 'cm':
            return "m, km";
        default:
            return "";
    }
}