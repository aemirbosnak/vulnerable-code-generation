//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if input is a valid number
int isNumber(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert from one unit to another
double convert(double value, char fromUnit[], char toUnit[]) {
    if (strcmp(fromUnit, "m") == 0 && strcmp(toUnit, "ft") == 0) {
        return value * 3.28084;
    } else if (strcmp(fromUnit, "ft") == 0 && strcmp(toUnit, "m") == 0) {
        return value / 3.28084;
    } else if (strcmp(fromUnit, "kg") == 0 && strcmp(toUnit, "lb") == 0) {
        return value * 2.20462;
    } else if (strcmp(fromUnit, "lb") == 0 && strcmp(toUnit, "kg") == 0) {
        return value / 2.20462;
    } else if (strcmp(fromUnit, "l") == 0 && strcmp(toUnit, "gal") == 0) {
        return value * 3.78541;
    } else if (strcmp(fromUnit, "gal") == 0 && strcmp(toUnit, "l") == 0) {
        return value / 3.78541;
    }

    printf("Invalid unit conversion.\n");
    exit(1);
}

int main() {
    char fromUnit[10], toUnit[10];
    double value, result;

    // Get input from user
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit to convert from: ");
    scanf("%s", fromUnit);
    printf("Enter the unit to convert to: ");
    scanf("%s", toUnit);

    // Check if input is valid
    if (!isNumber(fromUnit) ||!isNumber(toUnit)) {
        printf("Invalid unit input.\n");
        exit(1);
    }

    // Convert and display result
    result = convert(value, fromUnit, toUnit);
    printf("%.2lf %s = %.2lf %s\n", value, fromUnit, result, toUnit);

    return 0;
}