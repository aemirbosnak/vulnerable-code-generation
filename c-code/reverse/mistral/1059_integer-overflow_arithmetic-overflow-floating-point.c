#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *unit;
    double factor;
} Conversion;

Conversion units[] = {
    {"m", 0.001},
    {"km", 1000},
    {"mi", 1609.34},

    {"kg", 2.20462},
    {"lb", 0.453592},

    {"s", 60},
    {"min", 60},
    {"hr", 3600}
};

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <amount> <from> <to>\n", argv[0]);
        return 1;
    }

    double amount = atof(argv[1]);
    char *fromUnit = argv[2];
    char *toUnit = argv[3];

    int i;
    for (i = 0; i < 14; i++) {
        if (!strcmp(units[i].unit, fromUnit)) {
            if (!strcmp(units[i].unit, toUnit)) {
                printf("%.6f %s = %.6f %s\n", amount, fromUnit, amount * units[i].factor, toUnit);
            } else {
                double factor = 1 / units[i].factor;
                printf("%.6f %s = %.6f %s\n", amount * factor, toUnit, amount, units[i].unit);
            }
            break;
        }
    }

    if (i == 14) {
        printf("Invalid unit: %s or %s\n", fromUnit, toUnit);
        return 1;
    }

    return 0;
}
