//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float value;
    char unit[10];
} Unit;

void convert(Unit from, Unit to) {
    float conversionFactor;

    // Define conversion factors between various units
    if (strcmp(from.unit, "meter") == 0 && strcmp(to.unit, "feet") == 0) {
        conversionFactor = 3.28084;
    } else if (strcmp(from.unit, "meter") == 0 && strcmp(to.unit, "kilometer") == 0) {
        conversionFactor = 0.001;
    } else if (strcmp(from.unit, "feet") == 0 && strcmp(to.unit, "meter") == 0) {
        conversionFactor = 0.3048;
    } else if (strcmp(from.unit, "feet") == 0 && strcmp(to.unit, "inch") == 0) {
        conversionFactor = 12.0;
    } else if (strcmp(from.unit, "kilometer") == 0 && strcmp(to.unit, "meter") == 0) {
        conversionFactor = 1000.0;
    } else if (strcmp(from.unit, "kilogram") == 0 && strcmp(to.unit, "pound") == 0) {
        conversionFactor = 2.20462;
    } else if (strcmp(from.unit, "pound") == 0 && strcmp(to.unit, "kilogram") == 0) {
        conversionFactor = 0.453592;
    } else {
        printf("Invalid units provided.\n");
        exit(EXIT_FAILURE);
    }

    // Convert the value from the source unit to the target unit
    from.value *= conversionFactor;

    // Set the target unit value
    to.value = from.value;
}

int main() {
    Unit userInput, result;

    printf("\nWelcome to the Magical Unit Converter!\n");
    printf("Please enter the value and the unit you want to convert from (Value [Space] Unit): ");
    scanf("%f %s", &userInput.value, userInput.unit);

    printf("Now, enter the unit you want to convert to: ");
    scanf("%s", result.unit);

    Unit initialInput = userInput; // Save the initial input for later display

    // Perform the conversion
    convert(userInput, result);

    printf("\nYou entered: %0.2f %s\n", initialInput.value, initialInput.unit);
    printf("Your converted value is: %0.2f %s\n", result.value, result.unit);

    return EXIT_SUCCESS;
}