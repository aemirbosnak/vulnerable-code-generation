//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char *name;
    double (*convert)(double);
} Unit;

double length_convert(double value) {
    double result = value;
    if (result >= 1000) {
        result /= 1000;
        printf("%.2lf %s = %.2lf %s\n", value, "m", result, "km");
    } else if (result < 1) {
        result *= 1000;
        printf("%.2lf %s = %.2lf %s\n", value, "mm", result, "m");
    } else {
        printf("%.2lf %s = %.2lf %s\n", value, "m", result, "m");
    }
    return result;
}

double weight_convert(double value) {
    double result = value;
    if (result >= 1000) {
        result /= 1000;
        printf("%.2lf %s = %.2lf %s\n", value, "kg", result, "g");
    } else if (result < 1) {
        result *= 1000;
        printf("%.2lf %s = %.2lf %s\n", value, "g", result, "kg");
    } else {
        printf("%.2lf %s = %.2lf %s\n", value, "kg", result, "kg");
    }
    return result;
}

double temperature_convert(double value) {
    double result = value;
    if (result >= 1000) {
        result /= 1000;
        printf("%.2lf %sC = %.2lf %sC\n", value, "K", result, "mK");
    } else if (result < 1) {
        result *= 1000;
        printf("%.2lf %sC = %.2lf %sC\n", value, "mK", result, "K");
    } else {
        printf("%.2lf %sC = %.2lf %sC\n", value, "K", result, "K");
    }
    return result;
}

Unit unit_table[] = {
    {"m", length_convert},
    {"kg", weight_convert},
    {"K", temperature_convert},
};

int main() {
    char input[100];
    double value;
    int i;

    printf("Enter the unit you want to convert from:\n");
    scanf("%s", input);

    printf("Enter the value you want to convert:\n");
    scanf("%lf", &value);

    for (i = 0; i < sizeof(unit_table) / sizeof(Unit); i++) {
        if (strcmp(input, unit_table[i].name) == 0) {
            value = unit_table[i].convert(value);
            break;
        }
    }

    printf("The converted value is:\n");
    printf("%.2lf %s\n", value, input);

    return 0;
}