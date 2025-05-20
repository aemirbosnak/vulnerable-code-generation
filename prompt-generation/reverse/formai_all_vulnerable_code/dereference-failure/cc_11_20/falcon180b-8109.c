//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
#define MAX_UNIT_LENGTH 10

enum {
    CELSIUS,
    FAHRENHEIT
} units;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <temperature> <unit>\n", argv[0]);
        return 1;
    }

    double temperature = 0;
    char *unit = argv[2];
    int len = strlen(unit);

    if (len!= 1 && len!= 2) {
        printf("Invalid unit. Use C or F.\n");
        return 1;
    }

    if (unit[0] == 'C' || unit[0] == 'c') {
        units = CELSIUS;
    } else if (unit[0] == 'F' || unit[0] == 'f') {
        units = FAHRENHEIT;
    } else {
        printf("Invalid unit. Use C or F.\n");
        return 1;
    }

    if (sscanf(argv[1], "%lf", &temperature)!= 1) {
        printf("Invalid temperature.\n");
        return 1;
    }

    switch (units) {
        case CELSIUS:
            printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", temperature, (temperature * 9.0 / 5.0) + 32.0);
            break;
        case FAHRENHEIT:
            printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", temperature, (temperature - 32.0) * 5.0 / 9.0);
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    return 0;
}