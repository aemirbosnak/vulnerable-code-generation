//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the unit conversion functions
double convert_length(double value, char from, char to) {
    if (from == 'm' && to == 'cm') {
        return value * 100;
    } else if (from == 'cm' && to == 'm') {
        return value / 100;
    } else if (from == 'm' && to == 'in') {
        return value * 39.3701;
    } else if (from == 'in' && to == 'm') {
        return value / 39.3701;
    } else if (from == 'cm' && to == 'in') {
        return value * 0.393701;
    } else if (from == 'in' && to == 'cm') {
        return value / 0.393701;
    } else {
        printf("Invalid unit conversion!\n");
        return -1;
    }
}

double convert_area(double value, char from, char to) {
    if (from == 'm2' && to == 'cm2') {
        return value * 10000;
    } else if (from == 'cm2' && to == 'm2') {
        return value / 10000;
    } else if (from == 'm2' && to == 'in2') {
        return value * 1550.0031;
    } else if (from == 'in2' && to == 'm2') {
        return value / 1550.0031;
    } else if (from == 'cm2' && to == 'in2') {
        return value * 0.15500031;
    } else if (from == 'in2' && to == 'cm2') {
        return value / 0.15500031;
    } else {
        printf("Invalid unit conversion!\n");
        return -1;
    }
}

double convert_volume(double value, char from, char to) {
    if (from == 'm3' && to == 'cm3') {
        return value * 1000000;
    } else if (from == 'cm3' && to == 'm3') {
        return value / 1000000;
    } else if (from == 'm3' && to == 'in3') {
        return value * 61023.744;
    } else if (from == 'in3' && to == 'm3') {
        return value / 61023.744;
    } else if (from == 'cm3' && to == 'in3') {
        return value * 0.061023744;
    } else if (from == 'in3' && to == 'cm3') {
        return value / 0.061023744;
    } else {
        printf("Invalid unit conversion!\n");
        return -1;
    }
}

double convert_temperature(double value, char from, char to) {
    if (from == 'c' && to == 'f') {
        return value * 1.8 + 32;
    } else if (from == 'f' && to == 'c') {
        return (value - 32) / 1.8;
    } else if (from == 'c' && to == 'k') {
        return value + 273.15;
    } else if (from == 'k' && to == 'c') {
        return value - 273.15;
    } else if (from == 'f' && to == 'k') {
        return (value - 32) / 1.8 + 273.15;
    } else if (from == 'k' && to == 'f') {
        return (value - 273.15) * 1.8 + 32;
    } else {
        printf("Invalid unit conversion!\n");
        return -1;
    }
}

// Print the conversion results
void print_conversion_results(double value, char from, char to, double converted_value) {
    printf("%f %c = %f %c\n", value, from, converted_value, to);
}

// Get the unit conversion input from the user
void get_unit_conversion_input(double *value, char *from, char *to) {
    printf("Enter the value to be converted: ");
    scanf("%lf", value);
    printf("Enter the unit of the value to be converted (e.g., m, cm, in): ");
    scanf(" %c", from);
    printf("Enter the unit to convert to (e.g., m, cm, in): ");
    scanf(" %c", to);
}

// Main function
int main() {
    // Get the unit conversion input from the user
    double value;
    char from, to;
    get_unit_conversion_input(&value, &from, &to);

    // Convert the value using the appropriate function
    double converted_value;
    if (from == 'm' || from == 'cm' || from == 'in') {
        converted_value = convert_length(value, from, to);
    } else if (from == 'm2' || from == 'cm2' || from == 'in2') {
        converted_value = convert_area(value, from, to);
    } else if (from == 'm3' || from == 'cm3' || from == 'in3') {
        converted_value = convert_volume(value, from, to);
    } else if (from == 'c' || from == 'f' || from == 'k') {
        converted_value = convert_temperature(value, from, to);
    } else {
        printf("Invalid unit conversion!\n");
        return 1;
    }

    // Print the conversion results
    print_conversion_results(value, from, to, converted_value);

    return 0;
}