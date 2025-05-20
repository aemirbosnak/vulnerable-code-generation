#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char fromUnit[10], toUnit[10];
    double value;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (kg, g, lb, oz, ml, L, km, mi): ");
    scanf("%s", fromUnit);

    printf("Enter the unit to convert to (kg, g, lb, oz, ml, L, km, mi): ");
    scanf("%s", toUnit);

    if (strcmp(fromUnit, "kg") == 0) {
        if (strcmp(toUnit, "g") == 0)
            printf("%.2f\n", value * 1000);
        else if (strcmp(toUnit, "lb") == 0)
            printf("%.2f\n", value * 2.20462);
        else if (strcmp(toUnit, "oz") == 0)
            printf("%.2f\n", value * 35.274);
        else if (strcmp(toUnit, "ml") == 0)
            printf("%.2f\n", value * 1e6);
        else if (strcmp(toUnit, "L") == 0)
            printf("%.2f\n", value);
        else if (strcmp(toUnit, "km") == 0)
            printf("%.2f\n", value / 1000);
        else if (strcmp(toUnit, "mi") == 0)
            printf("%.2f\n", value / 1609.34);
    } else if (strcmp(fromUnit, "g") == 0) {
        // Add similar cases for other units
    }

    return 0;
}
