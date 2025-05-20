//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the conversion functions
double convert_length(double value, char from, char to);
double convert_mass(double value, char from, char to);
double convert_temperature(double value, char from, char to);

// Define the main function
int main() {
    // Get the input from the user
    double value;
    char from, to;
    printf("Enter the value to be converted: ");
    scanf("%lf", &value);
    printf("Enter the unit of the value (e.g., m, kg, C): ");
    scanf(" %c", &from);
    printf("Enter the unit to convert to (e.g., ft, lb, F): ");
    scanf(" %c", &to);

    // Convert the value
    double converted_value;
    switch (from) {
        case 'm':
            converted_value = convert_length(value, from, to);
            break;
        case 'kg':
            converted_value = convert_mass(value, from, to);
            break;
        case 'C':
            converted_value = convert_temperature(value, from, to);
            break;
        default:
            printf("Invalid unit of measurement.\n");
            return 1;
    }

    // Print the converted value
    printf("The converted value is: %.2f %c\n", converted_value, to);

    return 0;
}

// Define the conversion functions
double convert_length(double value, char from, char to) {
    switch (from) {
        case 'm':
            switch (to) {
                case 'ft':
                    return value * 3.281;
                case 'in':
                    return value * 39.37;
                default:
                    printf("Invalid unit of measurement.\n");
                    return -1;
            }
        case 'ft':
            switch (to) {
                case 'm':
                    return value / 3.281;
                case 'in':
                    return value * 12;
                default:
                    printf("Invalid unit of measurement.\n");
                    return -1;
            }
        case 'in':
            switch (to) {
                case 'm':
                    return value / 39.37;
                case 'ft':
                    return value / 12;
                default:
                    printf("Invalid unit of measurement.\n");
                    return -1;
            }
        default:
            printf("Invalid unit of measurement.\n");
            return -1;
    }
}

double convert_mass(double value, char from, char to) {
    switch (from) {
        case 'kg':
            switch (to) {
                case 'lb':
                    return value * 2.205;
                case 'oz':
                    return value * 35.274;
                default:
                    printf("Invalid unit of measurement.\n");
                    return -1;
            }
        case 'lb':
            switch (to) {
                case 'kg':
                    return value / 2.205;
                case 'oz':
                    return value * 16;
                default:
                    printf("Invalid unit of measurement.\n");
                    return -1;
            }
        case 'oz':
            switch (to) {
                case 'kg':
                    return value / 35.274;
                case 'lb':
                    return value / 16;
                default:
                    printf("Invalid unit of measurement.\n");
                    return -1;
            }
        default:
            printf("Invalid unit of measurement.\n");
            return -1;
    }
}

double convert_temperature(double value, char from, char to) {
    switch (from) {
        case 'C':
            switch (to) {
                case 'F':
                    return value * 1.8 + 32;
                case 'K':
                    return value + 273.15;
                default:
                    printf("Invalid unit of measurement.\n");
                    return -1;
            }
        case 'F':
            switch (to) {
                case 'C':
                    return (value - 32) / 1.8;
                case 'K':
                    return (value + 459.67) / 1.8;
                default:
                    printf("Invalid unit of measurement.\n");
                    return -1;
            }
        case 'K':
            switch (to) {
                case 'C':
                    return value - 273.15;
                case 'F':
                    return value * 1.8 - 459.67;
                default:
                    printf("Invalid unit of measurement.\n");
                    return -1;
            }
        default:
            printf("Invalid unit of measurement.\n");
            return -1;
    }
}