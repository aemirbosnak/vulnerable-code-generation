//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function to check if input is a number
int isNumber(char *input) {
    int i = 0;
    while (input[i]!= '\0') {
        if (!isdigit(input[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to convert units
void convert(double value, char from, char to) {
    switch (from) {
        case'm': // meters to feet
            value *= 3.28084;
            break;
        case 'ft': // feet to meters
            value /= 3.28084;
            break;
        case 'kg': // kilograms to pounds
            value *= 2.20462;
            break;
        case 'lb': // pounds to kilograms
            value /= 2.20462;
            break;
        case 'l': // liters to gallons
            value *= 0.264172;
            break;
        case 'gal': // gallons to liters
            value /= 0.264172;
            break;
        default:
            printf("Invalid conversion unit.\n");
            break;
    }
    printf("%.2f %c = %.2f %c\n", value, from, value, to);
}

int main() {
    char input[100];
    char unit1, unit2;
    double value;

    // Prompt user for input
    printf("Enter a value to convert:\n");
    scanf("%s", input);

    // Check if input is a number
    if (!isNumber(input)) {
        printf("Invalid input.\n");
        return 0;
    }

    // Prompt user for units to convert from and to
    printf("Enter the unit to convert from (m, ft, kg, lb, l, gal):\n");
    scanf(" %c", &unit1);
    printf("Enter the unit to convert to (m, ft, kg, lb, l, gal):\n");
    scanf(" %c", &unit2);

    // Convert the value
    value = atof(input);
    convert(value, unit1, unit2);

    return 0;
}