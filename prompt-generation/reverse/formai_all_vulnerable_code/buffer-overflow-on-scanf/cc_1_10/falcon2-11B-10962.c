//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a value from one unit to another
double convertUnit(double value, char fromUnit[], char toUnit[]) {
    double factor;

    // Check if input units are valid
    if (strcmp(fromUnit, "km") == 0)
        factor = 1.0;
    else if (strcmp(fromUnit, "m") == 0)
        factor = 1000.0;
    else if (strcmp(fromUnit, "cm") == 0)
        factor = 100000.0;
    else if (strcmp(fromUnit, "mm") == 0)
        factor = 1000000.0;
    else
        return -1.0;

    // Check if input units are valid
    if (strcmp(toUnit, "km") == 0)
        return value / factor;
    else if (strcmp(toUnit, "m") == 0)
        return value / factor / 1000.0;
    else if (strcmp(toUnit, "cm") == 0)
        return value / factor / 100000.0;
    else if (strcmp(toUnit, "mm") == 0)
        return value / factor / 1000000.0;
    else
        return -1.0;
}

int main() {
    double value, convertedValue;
    char fromUnit[50], toUnit[50];

    // Get user input
    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value (km, m, cm, or mm): ");
    scanf("%s", fromUnit);

    printf("Enter the desired unit of the value (km, m, cm, or mm): ");
    scanf("%s", toUnit);

    convertedValue = convertUnit(value, fromUnit, toUnit);

    // Output the result
    if (convertedValue!= -1.0)
        printf("%.2f %s = %.2f %s\n", value, fromUnit, convertedValue, toUnit);

    return 0;
}