//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[] = {
    {"m", 1.0},
    {"km", 1000.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4},
    {"l", 1.0},
    {"ml", 0.001},
    {"fl.oz", 0.029573},
    {"gal", 3.78541},
    {"kg", 1.0},
    {"g", 0.001},
    {"lb", 0.453592},
    {"oz", 0.0283495},
    {"c", 1.0},
    {"f", 1.8 + 32},
    {"k", 1.0},
    {"v", 1.0},
    {"a", 1.0},
    {"h", 1.0},
    {"s", 1.0},
    {"min", 60.0},
    {"hr", 3600.0},
    {"day", 86400.0}
};

int main() {
    int n, i, j;
    char unit1[20], unit2[20];
    double value, result;

    printf("Enter the unit to convert from: ");
    scanf("%s", unit1);

    printf("Enter the unit to convert to: ");
    scanf("%s", unit2);

    for (i = 0; i < sizeof(units)/sizeof(Unit); i++) {
        if (!strcmp(unit1, units[i].name)) {
            value = atof(units[i].name);
            break;
        }
    }

    for (j = 0; j < sizeof(units)/sizeof(Unit); j++) {
        if (!strcmp(unit2, units[j].name)) {
            result = value * units[j].factor;
            printf("%.2f %s = %.2f %s\n", value, unit1, result, unit2);
            return 0;
        }
    }

    printf("Invalid units.\n");
    return 0;
}