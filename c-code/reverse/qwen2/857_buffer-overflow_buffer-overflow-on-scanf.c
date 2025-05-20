#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char fromUnit[10], toUnit[10];
    double value;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (kg, g, lb, oz, ml, L, km, mi): ");
    scanf("%s", fromUnit);

    printf("Enter the unit to convert to (kg, g, lb, oz, ml, L, km, mi): ");
    scanf("%s", toUnit);

    if (strcmp(fromUnit, "kg") == 0) {
        if (strcmp(toUnit, "g") == 0)
            printf("%.2f kg = %.2f g\n", value, value * 1000);
        else if (strcmp(toUnit, "lb") == 0)
            printf("%.2f kg = %.2f lb\n", value, value * 2.20462);
        else if (strcmp(toUnit, "oz") == 0)
            printf("%.2f kg = %.2f oz\n", value, value * 35.274);
        // Add other conversions here
    } else if (strcmp(fromUnit, "g") == 0) {
        if (strcmp(toUnit, "kg") == 0)
            printf("%.2f g = %.2f kg\n", value, value / 1000);
        else if (strcmp(toUnit, "lb") == 0)
            printf("%.2f g = %.2f lb\n", value, value * 0.00220462);
        else if (strcmp(toUnit, "oz") == 0)
            printf("%.2f g = %.2f oz\n", value, value * 0.035274);
        // Add other conversions here
    }
    // Add other units and their conversions here

    return 0;
}
