//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH_UNITS "cm m ft in yd"
#define WEIGHT_UNITS "g kg lb oz"
#define TEMPERATURE_UNITS "°C °F"

int main() {
    float length, weight, temperature;
    char unit[5];

    printf("Enter a length: ");
    scanf("%4s", unit);
    length = atof(unit);

    printf("Enter a weight: ");
    scanf("%4s", unit);
    weight = atof(unit);

    printf("Enter a temperature: ");
    scanf("%4s", unit);
    temperature = atof(unit);

    // Convert length units
    if (strcmp(unit, "cm") == 0) {
        length *= 0.01;
    } else if (strcmp(unit, "m") == 0) {
        length *= 100;
    } else if (strcmp(unit, "ft") == 0) {
        length *= 3.28084;
    } else if (strcmp(unit, "in") == 0) {
        length *= 0.0254;
    } else if (strcmp(unit, "yd") == 0) {
        length *= 0.9144;
    }

    // Convert weight units
    if (strcmp(unit, "g") == 0) {
        weight *= 0.001;
    } else if (strcmp(unit, "kg") == 0) {
        weight *= 1000;
    } else if (strcmp(unit, "lb") == 0) {
        weight *= 0.453592;
    } else if (strcmp(unit, "oz") == 0) {
        weight *= 0.035274;
    }

    // Convert temperature units
    if (strcmp(unit, "°C") == 0) {
        temperature *= 9/5 + 32;
    } else if (strcmp(unit, "°F") == 0) {
        temperature *= 180/5 + 32;
    }

    printf("Length in %s: %4.2f\n", LENGTH_UNITS, length);
    printf("Weight in %s: %4.2f\n", WEIGHT_UNITS, weight);
    printf("Temperature in %s: %4.2f\n", TEMPERATURE_UNITS, temperature);

    return 0;
}