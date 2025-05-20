//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G 6.674e-11
#define C 299792458

typedef struct {
    char *name;
    double (*convert)(double);
} Unit;

double length_convert(double value) {
    return value;
}

double mass_convert(double value) {
    return value;
}

double time_convert(double value) {
    return value;
}

double temperature_convert(double value) {
    return value;
}

Unit units[] = {{"meters", length_convert}, {"kilometers", length_convert}, {"grams", mass_convert}, {"kilograms", mass_convert}, {"seconds", time_convert}, {"minutes", time_convert}, {"hours", time_convert}, {"kelvin", temperature_convert}, {"celsius", temperature_convert}, {"fahrenheit", temperature_convert}};

int main() {
    int choice;
    double value, result;
    char unit[10];

    printf("Enter the unit you want to convert from: ");
    scanf("%s", unit);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit);

    for (int i = 0; i < 10; i++) {
        if (strcmp(units[i].name, unit) == 0) {
            result = units[i].convert(value);
            printf("%.2lf %s = %.2lf %s\n", value, units[i].name, result, units[i].name);
            break;
        }
    }

    return 0;
}