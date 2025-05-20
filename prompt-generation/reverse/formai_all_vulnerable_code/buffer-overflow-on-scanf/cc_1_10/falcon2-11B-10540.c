//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>
#include <math.h>

typedef struct {
    char unit[10];
    double value;
} Unit;

const Unit units[] = {
    {"Km", 1000.0},
    {"M", 1000.0 / 1000.0},
    {"cm", 100.0},
    {"mm", 100.0 / 1000.0},
    {"um", 1.0 / 1000.0},
    {"m", 1.0},
    {"cm", 1.0 / 100.0},
    {"mm", 1.0 / 1000.0 / 100.0},
    {"um", 1.0 / 1000.0 / 100.0 / 100.0},
    {"nm", 1.0 / 1000.0 / 100.0 / 100.0 / 1000.0},
    {"angstrom", 1.0 / 1000.0 / 100.0 / 100.0 / 1000.0 / 1000.0},
    {"pico", 1.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0},
    {"femto", 1.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0},
    {"atto", 1.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0},
    {"zepto", 1.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0},
    {"yocto", 1.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0 / 1000.0},
};

double convert(double value, const char* unit1, const char* unit2) {
    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (strcmp(unit1, units[i].unit) == 0 && strcmp(unit2, units[i+1].unit) == 0) {
            double factor = 1.0 / units[i+1].value;
            return value * factor;
        }
    }
    return 0;
}

int main() {
    char unit1[10], unit2[10];
    printf("Enter a value and units: ");
    scanf("%s %s", unit1, unit2);

    double value = 0.0;
    printf("Enter a value: ");
    scanf("%lf", &value);

    double result = convert(value, unit1, unit2);
    if (result!= 0) {
        printf("%.2lf %s is equal to %.2lf %s\n", value, unit1, result, unit2);
    } else {
        printf("Invalid units\n");
    }

    return 0;
}