//FormAI DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include <stdio.h>

/* This program converts between different units of measurement */

int main() {
    float value;
    char current_unit[50], target_unit[50];

    printf("Welcome to the Unit Converter!\n\n");
    printf("Please enter the value you want to convert: ");
    scanf("%f", &value);

    printf("What is the current unit of measurement? ");
    scanf("%s", current_unit);

    printf("What is the target unit of measurement? ");
    scanf("%s", target_unit);

    /* Conversion logic */
    if (strcmp(current_unit, "inches") == 0) {
        if (strcmp(target_unit, "centimeters") == 0) {
            value = value * 2.54;
        } else if (strcmp(target_unit, "feet") == 0) {
            value = value / 12;
        } else if (strcmp(target_unit, "meters") == 0) {
            value = value * 0.0254;
        } else {
            printf("Sorry, that unit of measurement is not recognized.\n");
            return 0;
        }
    } else if (strcmp(current_unit, "centimeters") == 0) {
        if (strcmp(target_unit, "inches") == 0) {
            value = value / 2.54;
        } else if (strcmp(target_unit, "feet") == 0) {
            value = value / 30.48;
        } else if (strcmp(target_unit, "meters") == 0) {
            value = value / 100;
        } else {
            printf("Sorry, that unit of measurement is not recognized.\n");
            return 0;
        }
    } else if (strcmp(current_unit, "feet") == 0) {
        if (strcmp(target_unit, "inches") == 0) {
            value = value * 12;
        } else if (strcmp(target_unit, "centimeters") == 0) {
            value = value * 30.48;
        } else if (strcmp(target_unit, "meters") == 0) {
            value = value * 0.3048;
        } else {
            printf("Sorry, that unit of measurement is not recognized.\n");
            return 0;
        }
    } else if (strcmp(current_unit, "meters") == 0) {
        if (strcmp(target_unit, "inches") == 0) {
            value = value / 0.0254;
        } else if (strcmp(target_unit, "centimeters") == 0) {
            value = value * 100;
        } else if (strcmp(target_unit, "feet") == 0) {
            value = value / 0.3048;
        } else {
            printf("Sorry, that unit of measurement is not recognized.\n");
            return 0;
        }
    } else {
        printf("Sorry, that unit of measurement is not recognized.\n");
        return 0;
    }

    /* Display the converted value */
    printf("%f %s is equal to %f %s\n", value, current_unit, value, target_unit);

    return 0;
}