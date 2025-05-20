//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONVERSIONS 10

typedef struct {
    char *name;
    double (*to_base)(double);
    double (*from_base)(double);
} Conversion;

double to_meters(double value) {
    return value;
}

double from_meters(double value) {
    return value;
}

double to_kilometers(double value) {
    return value / 1000;
}

double from_kilometers(double value) {
    return value * 1000;
}

double to_miles(double value) {
    return value / 1609.34;
}

double from_miles(double value) {
    return value * 1609.34;
}

double to_yards(double value) {
    return value / 0.9144;
}

double from_yards(double value) {
    return value * 0.9144;
}

double to_feet(double value) {
    return value / 0.3048;
}

double from_feet(double value) {
    return value * 0.3048;
}

double to_inches(double value) {
    return value / 0.0254;
}

double from_inches(double value) {
    return value * 0.0254;
}

Conversion conversions[] = {
    {"meters", to_meters, from_meters},
    {"kilometers", to_kilometers, from_kilometers},
    {"miles", to_miles, from_miles},
    {"yards", to_yards, from_yards},
    {"feet", to_feet, from_feet},
    {"inches", to_inches, from_inches}
};

int main() {
    char input[100];
    int conversion_index;
    double value, result;

    printf("Enter a unit of measurement to convert from:\n");
    scanf("%s", input);

    printf("Enter the value to convert:\n");
    scanf("%lf", &value);

    printf("Enter the unit of measurement to convert to:\n");
    scanf("%s", input);

    for (conversion_index = 0; conversion_index < MAX_CONVERSIONS; conversion_index++) {
        if (strcmp(input, conversions[conversion_index].name) == 0) {
            result = conversions[conversion_index].from_base(value);
            printf("%lf %s = %lf %s\n", value, input, result, conversions[conversion_index].name);
            break;
        }
    }

    return 0;
}