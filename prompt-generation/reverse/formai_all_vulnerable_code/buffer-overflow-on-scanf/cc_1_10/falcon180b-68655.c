//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert length
double convertLength(double value, char from, char to) {
    double result = 0.0;
    char *unit = "";

    switch (from) {
        case'm':
            unit = "meters";
            result = value * 1.0;
            break;
        case 'cm':
            unit = "centimeters";
            result = value * 0.01;
            break;
        case'mm':
            unit = "millimeters";
            result = value * 0.001;
            break;
        case 'in':
            unit = "inches";
            result = value * 0.0254;
            break;
        case 'ft':
            unit = "feet";
            result = value * 0.3048;
            break;
        case 'yd':
            unit = "yards";
            result = value * 0.9144;
            break;
        default:
            printf("Invalid input unit\n");
            return -1;
    }

    switch (to) {
        case'm':
            printf("%.2f %s = %.2f meters\n", value, unit, result);
            break;
        case 'cm':
            printf("%.2f %s = %.2f centimeters\n", value, unit, result);
            break;
        case'mm':
            printf("%.2f %s = %.2f millimeters\n", value, unit, result);
            break;
        case 'in':
            printf("%.2f %s = %.2f inches\n", value, unit, result);
            break;
        case 'ft':
            printf("%.2f %s = %.2f feet\n", value, unit, result);
            break;
        case 'yd':
            printf("%.2f %s = %.2f yards\n", value, unit, result);
            break;
        default:
            printf("Invalid output unit\n");
            return -1;
    }

    return 0;
}

int main() {
    char inputUnit, outputUnit;
    double value;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the input unit (m/cm/mm/in/ft/yd): ");
    scanf(" %c", &inputUnit);

    printf("Enter the output unit (m/cm/mm/in/ft/yd): ");
    scanf(" %c", &outputUnit);

    convertLength(value, inputUnit, outputUnit);

    return 0;
}