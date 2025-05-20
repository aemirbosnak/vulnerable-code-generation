//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>

int main() {
    // Define the conversion factors
    float miles_to_km = 1.60934;
    float km_to_miles = 0.621371;
    float pounds_to_kg = 0.453592;
    float kg_to_pounds = 2.20462;
    float gallons_to_liters = 3.78541;
    float liters_to_gallons = 0.264172;

    // Get the user's input
    printf("Welcome to the Grateful Unit Converter!\n");
    printf("What unit would you like to convert from?\n");
    printf("Options: miles, km, pounds, kg, gallons, liters\n");
    char from_unit[20];
    scanf("%s", from_unit);

    printf("What unit would you like to convert to?\n");
    printf("Options: miles, km, pounds, kg, gallons, liters\n");
    char to_unit[20];
    scanf("%s", to_unit);

    printf("How much would you like to convert?\n");
    float amount;
    scanf("%f", &amount);

    // Convert the units
    float result;
    if (strcmp(from_unit, "miles") == 0 && strcmp(to_unit, "km") == 0) {
        result = amount * miles_to_km;
    } else if (strcmp(from_unit, "km") == 0 && strcmp(to_unit, "miles") == 0) {
        result = amount * km_to_miles;
    } else if (strcmp(from_unit, "pounds") == 0 && strcmp(to_unit, "kg") == 0) {
        result = amount * pounds_to_kg;
    } else if (strcmp(from_unit, "kg") == 0 && strcmp(to_unit, "pounds") == 0) {
        result = amount * kg_to_pounds;
    } else if (strcmp(from_unit, "gallons") == 0 && strcmp(to_unit, "liters") == 0) {
        result = amount * gallons_to_liters;
    } else if (strcmp(from_unit, "liters") == 0 && strcmp(to_unit, "gallons") == 0) {
        result = amount * liters_to_gallons;
    } else {
        printf("Invalid unit conversion.\n");
        return 1;
    }

    // Print the result
    printf("The result is: %f\n", result);

    // Be grateful!
    printf("Thank you for using the Grateful Unit Converter!\n");
    printf("May your conversions be ever successful.\n");

    return 0;
}