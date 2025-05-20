//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {

    char unit_from[50], unit_to[50];
    double value, result;

    // Prompt user for unit conversion input
    printf("Enter the unit you want to convert from: ");
    scanf("%s", unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit_to);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    // Check for valid unit conversions
    if (strcmp(unit_from, unit_to) == 0) {
        printf("Invalid conversion. Units are the same.\n");
        return 0;
    }

    // Perform unit conversion
    if (strcmp(unit_from, "miles") == 0 && strcmp(unit_to, "kilometers") == 0) {
        result = value * 1.60934;
        printf("%lf miles is equal to %lf kilometers.\n", value, result);
    } else if (strcmp(unit_from, "kilometers") == 0 && strcmp(unit_to, "miles") == 0) {
        result = value / 1.60934;
        printf("%lf kilometers is equal to %lf miles.\n", value, result);
    } else if (strcmp(unit_from, "meters") == 0 && strcmp(unit_to, "feet") == 0) {
        result = value * 3.28084;
        printf("%lf meters is equal to %lf feet.\n", value, result);
    } else if (strcmp(unit_from, "feet") == 0 && strcmp(unit_to, "meters") == 0) {
        result = value / 3.28084;
        printf("%lf feet is equal to %lf meters.\n", value, result);
    } else if (strcmp(unit_from, "pounds") == 0 && strcmp(unit_to, "kilograms") == 0) {
        result = value * 0.453592;
        printf("%lf pounds is equal to %lf kilograms.\n", value, result);
    } else if (strcmp(unit_from, "kilograms") == 0 && strcmp(unit_to, "pounds") == 0) {
        result = value / 0.453592;
        printf("%lf kilograms is equal to %lf pounds.\n", value, result);
    } else {
        printf("Invalid conversion. Units not supported.\n");
    }

    return 0;
}