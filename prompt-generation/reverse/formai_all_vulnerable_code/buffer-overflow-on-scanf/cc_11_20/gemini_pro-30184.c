//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define the conversion factors
    const double INCHES_TO_CM = 2.54;
    const double CM_TO_INCHES = 0.393701;
    const double POUNDS_TO_KG = 0.453592;
    const double KG_TO_POUNDS = 2.20462;
    const double MILES_TO_KM = 1.60934;
    const double KM_TO_MILES = 0.621371;

    // Get the user's input
    char unit_from[32];
    char unit_to[32];
    double value;

    printf("Enter the unit you want to convert from: ");
    scanf("%s", unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit_to);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    // Convert the value
    double result;
    if (strcmp(unit_from, "inches") == 0 && strcmp(unit_to, "cm") == 0) {
        result = value * INCHES_TO_CM;
    } else if (strcmp(unit_from, "cm") == 0 && strcmp(unit_to, "inches") == 0) {
        result = value * CM_TO_INCHES;
    } else if (strcmp(unit_from, "pounds") == 0 && strcmp(unit_to, "kg") == 0) {
        result = value * POUNDS_TO_KG;
    } else if (strcmp(unit_from, "kg") == 0 && strcmp(unit_to, "pounds") == 0) {
        result = value * KG_TO_POUNDS;
    } else if (strcmp(unit_from, "miles") == 0 && strcmp(unit_to, "km") == 0) {
        result = value * MILES_TO_KM;
    } else if (strcmp(unit_from, "km") == 0 && strcmp(unit_to, "miles") == 0) {
        result = value * KM_TO_MILES;
    } else {
        printf("Invalid unit conversion specified.\n");
        return 1;
    }

    // Print the result
    printf("%lf %s is equal to %lf %s.\n", value, unit_from, result, unit_to);

    return 0;
}