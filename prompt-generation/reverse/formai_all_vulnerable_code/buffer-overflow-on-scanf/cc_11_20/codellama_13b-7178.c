//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: mathematical
// A C Unit Converter Example Program

#include <stdio.h>

// Function to convert from one unit to another
double convert(double value, char from, char to) {
    // Check if the unit is valid
    if (from == 'm' && to == 'cm') {
        return value * 100;
    } else if (from == 'm' && to == 'ft') {
        return value * 3.28084;
    } else if (from == 'm' && to == 'in') {
        return value * 39.3701;
    } else if (from == 'cm' && to == 'm') {
        return value / 100;
    } else if (from == 'cm' && to == 'ft') {
        return value * 0.0328084;
    } else if (from == 'cm' && to == 'in') {
        return value * 1.03937;
    } else if (from == 'ft' && to == 'm') {
        return value / 3.28084;
    } else if (from == 'ft' && to == 'cm') {
        return value * 30.48;
    } else if (from == 'ft' && to == 'in') {
        return value * 12;
    } else if (from == 'in' && to == 'm') {
        return value / 39.3701;
    } else if (from == 'in' && to == 'cm') {
        return value * 2.54;
    } else if (from == 'in' && to == 'ft') {
        return value / 12;
    } else {
        return 0;
    }
}

int main() {
    double value;
    char from, to;

    // Ask for input
    printf("Enter a value: ");
    scanf("%lf", &value);
    printf("Enter the unit (m, cm, ft, in): ");
    scanf(" %c", &from);
    printf("Enter the unit to convert to (m, cm, ft, in): ");
    scanf(" %c", &to);

    // Convert and print output
    double result = convert(value, from, to);
    printf("Result: %f %c\n", result, to);

    return 0;
}