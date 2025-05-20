//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Forward declarations
double convert_length(double length, char from_unit, char to_unit);
double convert_mass(double mass, char from_unit, char to_unit);
double convert_temperature(double temp, char from_unit, char to_unit);

// Main function
int main() {
    // Declare variables
    double value;
    char from_unit, to_unit;

    // Get user input
    printf("Welcome to the Unit Converter 3000!\n");
    printf("What do you want to convert? ");
    scanf(" %c", &value);
    printf("From which unit? ");
    scanf(" %c", &from_unit);
    printf("To which unit? ");
    scanf(" %c", &to_unit);

    // Convert the value
    double result;
    switch (from_unit) {
        case 'm':
            result = convert_length(value, 'm', to_unit);
            break;
        case 'c':
            result = convert_length(value, 'c', to_unit);
            break;
        case 'f':
            result = convert_length(value, 'f', to_unit);
            break;
        case 'g':
            result = convert_mass(value, 'g', to_unit);
            break;
        case 'k':
            result = convert_mass(value, 'k', to_unit);
            break;
        case 'l':
            result = convert_mass(value, 'l', to_unit);
            break;
        case 'C':
            result = convert_temperature(value, 'C', to_unit);
            break;
        case 'F':
            result = convert_temperature(value, 'F', to_unit);
            break;
        case 'K':
            result = convert_temperature(value, 'K', to_unit);
            break;
        default:
            printf("Invalid unit. Please try again.\n");
            return 1;
    }

    // Print the result
    printf("The converted value is: %.2f %c\n", result, to_unit);

    return 0;
}

// Convert length
double convert_length(double length, char from_unit, char to_unit) {
    double result;
    switch (from_unit) {
        case 'm':
            switch (to_unit) {
                case 'c':
                    result = length * 100;
                    break;
                case 'f':
                    result = length * 3.28084;
                    break;
                default:
                    printf("Invalid unit. Please try again.\n");
                    return -1;
            }
            break;
        case 'c':
            switch (to_unit) {
                case 'm':
                    result = length / 100;
                    break;
                case 'f':
                    result = length * 0.393701;
                    break;
                default:
                    printf("Invalid unit. Please try again.\n");
                    return -1;
            }
            break;
        case 'f':
            switch (to_unit) {
                case 'm':
                    result = length / 3.28084;
                    break;
                case 'c':
                    result = length * 2.54;
                    break;
                default:
                    printf("Invalid unit. Please try again.\n");
                    return -1;
            }
            break;
        default:
            printf("Invalid unit. Please try again.\n");
            return -1;
    }
    return result;
}

// Convert mass
double convert_mass(double mass, char from_unit, char to_unit) {
    double result;
    switch (from_unit) {
        case 'g':
            switch (to_unit) {
                case 'k':
                    result = mass * 1000;
                    break;
                case 'l':
                    result = mass * 0.453592;
                    break;
                default:
                    printf("Invalid unit. Please try again.\n");
                    return -1;
            }
            break;
        case 'k':
            switch (to_unit) {
                case 'g':
                    result = mass / 1000;
                    break;
                case 'l':
                    result = mass * 2.20462;
                    break;
                default:
                    printf("Invalid unit. Please try again.\n");
                    return -1;
            }
            break;
        case 'l':
            switch (to_unit) {
                case 'g':
                    result = mass / 0.453592;
                    break;
                case 'k':
                    result = mass / 2.20462;
                    break;
                default:
                    printf("Invalid unit. Please try again.\n");
                    return -1;
            }
            break;
        default:
            printf("Invalid unit. Please try again.\n");
            return -1;
    }
    return result;
}

// Convert temperature
double convert_temperature(double temp, char from_unit, char to_unit) {
    double result;
    switch (from_unit) {
        case 'C':
            switch (to_unit) {
                case 'F':
                    result = temp * 1.8 + 32;
                    break;
                case 'K':
                    result = temp + 273.15;
                    break;
                default:
                    printf("Invalid unit. Please try again.\n");
                    return -1;
            }
            break;
        case 'F':
            switch (to_unit) {
                case 'C':
                    result = (temp - 32) / 1.8;
                    break;
                case 'K':
                    result = (temp + 459.67) / 1.8;
                    break;
                default:
                    printf("Invalid unit. Please try again.\n");
                    return -1;
            }
            break;
        case 'K':
            switch (to_unit) {
                case 'C':
                    result = temp - 273.15;
                    break;
                case 'F':
                    result = (temp * 1.8) - 459.67;
                    break;
                default:
                    printf("Invalid unit. Please try again.\n");
                    return -1;
            }
            break;
        default:
            printf("Invalid unit. Please try again.\n");
            return -1;
    }
    return result;
}