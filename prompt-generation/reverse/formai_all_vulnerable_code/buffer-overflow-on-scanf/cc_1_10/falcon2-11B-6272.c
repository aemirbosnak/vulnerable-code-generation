//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char name[20];
    double value;
} Unit;

Unit units[7] = {
    {"meter", 1000},
    {"kilometer", 1000},
    {"centimeter", 0.01},
    {"millimeter", 0.001},
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"yard", 0.9144}
};

double convert(double value, char fromUnit[20], char toUnit[20]) {
    int i;

    for (i = 0; i < 7; i++) {
        if (strcmp(fromUnit, units[i].name) == 0) {
            break;
        }
    }

    if (i == 7) {
        return -1;
    }

    for (i = 0; i < 7; i++) {
        if (strcmp(toUnit, units[i].name) == 0) {
            break;
        }
    }

    if (i == 7) {
        return -1;
    }

    return value * units[i].value;
}

int main() {
    char fromUnit[20], toUnit[20], inputUnit[20], outputUnit[20];
    double value, convertedValue;

    printf("Enter a value to convert:\n");
    scanf("%lf", &value);

    printf("Enter the unit of the value:\n");
    scanf("%s", inputUnit);

    printf("Enter the unit you want to convert to:\n");
    scanf("%s", outputUnit);

    if (convert(value, inputUnit, outputUnit) == -1) {
        printf("Invalid units. Try again.\n");
        return 0;
    }

    printf("The value in %s is %f in %s.\n", inputUnit, convertedValue, outputUnit);

    return 0;
}