//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double factor;
    int decimals;
} unit;

int main() {
    unit units[] = {
        {"meters", 1.0, 2},
        {"centimeters", 0.01, 2},
        {"millimeters", 0.001, 2},
        {"kilometers", 1000.0, 2},
        {"inches", 0.0254, 2},
        {"feet", 0.3048, 2},
        {"yards", 0.9144, 2},
        {"miles", 160934.4, 2},
        {"pounds", 0.453592, 2},
        {"ounces", 0.0283495, 2},
        {"grams", 1.0, 2},
        {"kilograms", 1000.0, 2},
        {"liters", 1.0, 2},
        {"gallons", 3.78541, 2},
        {"cubic meters", 1.0, 2},
        {"cubic feet", 0.02831685, 2},
        {"cubic inches", 0.000016387, 2},
        {"square meters", 1.0, 2},
        {"square feet", 0.092903, 2},
        {"square yards", 0.836127, 2},
        {"acres", 4046.856, 2},
        {"degrees Celsius", 1.0, 2},
        {"degrees Fahrenheit", 0.555555, 2},
        {"degrees Kelvin", 1.0, 2},
        {"radians", 1.0, 2}
    };

    int i, n = sizeof(units) / sizeof(unit);
    char from_unit[100], to_unit[100];

    printf("Enter the conversion type (e.g. meters to feet): ");
    scanf("%s %s", from_unit, to_unit);

    for (i = 0; i < n; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            break;
        }
    }

    if (i == n) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        if (strcmp(units[i].name, to_unit) == 0) {
            break;
        }
    }

    if (i == n) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    printf("Enter the value to convert: ");
    double value = atof(gets());

    double result = value * units[i].factor;
    printf("%.*f %s = %.*f %s\n", units[i].decimals, value, from_unit, units[i].decimals, result, to_unit);

    return 0;
}