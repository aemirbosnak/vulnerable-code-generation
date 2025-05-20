//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PRECISION 3

struct unit {
    const char *name;
    double factor;
};

struct unit units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.34},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"yd", 0.9144},
    {"lb", 0.453592},
    {"oz", 0.0283495},
    {"gal", 0.003785},
    {"pt", 0.000625},
    {"fl oz", 0.003785},
    {"cu ft", 28.3168},
    {"cu in", 16.38706},
    {"sq ft", 0.092903},
    {"sq in", 0.0006944},
    {"acre", 4046.85},
    {"ft^2", 0.092903},
    {"in^2", 0.0006944},
    {"yd^2", 0.836127},
    {"mile", 1609.34},
    {"km/h", 3.6},
    {"mph", 2.22462},
    {"kn", 1.94384},
    {"rad", 57.29578},
    {"deg", 0.01745329},
    {" grad", 0.01745329}
};

int main() {
    double value, from_unit, to_unit;
    char from_unit_name[20], to_unit_name[20];

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (e.g. 'm', 'ft', 'in'): ");
    fgets(from_unit_name, 20, stdin);

    printf("Enter the unit to convert to (e.g. 'm', 'ft', 'in'): ");
    fgets(to_unit_name, 20, stdin);

    for (int i = 0; i < sizeof(units) / sizeof(struct unit); i++) {
        if (strcmp(units[i].name, from_unit_name) == 0) {
            from_unit = units[i].factor;
            break;
        }
    }

    for (int i = 0; i < sizeof(units) / sizeof(struct unit); i++) {
        if (strcmp(units[i].name, to_unit_name) == 0) {
            to_unit = units[i].factor;
            break;
        }
    }

    value *= from_unit;
    value /= to_unit;

    printf("Value in %s is %g\n", to_unit_name, value);

    return 0;
}