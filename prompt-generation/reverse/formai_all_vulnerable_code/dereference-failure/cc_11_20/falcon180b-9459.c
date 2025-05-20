//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <temperature> <from_unit> <to_unit>\n", argv[0]);
        return 1;
    }

    char *temperature_str = argv[1];
    char *from_unit = argv[2];
    char *to_unit = argv[3];

    double temperature = strtod(temperature_str, NULL);

    if (strcmp(from_unit, "C") == 0) {
        if (strcmp(to_unit, "F") == 0) {
            temperature = (temperature * 9.0 / 5.0) + 32.0;
        } else if (strcmp(to_unit, "K") == 0) {
            temperature += 273.15;
        } else {
            printf("Invalid conversion unit: %s\n", to_unit);
            return 1;
        }
    } else if (strcmp(from_unit, "F") == 0) {
        if (strcmp(to_unit, "C") == 0) {
            temperature = (temperature - 32.0) * 5.0 / 9.0;
        } else if (strcmp(to_unit, "K") == 0) {
            temperature = (temperature + 459.67) * 5.0 / 9.0;
        } else {
            printf("Invalid conversion unit: %s\n", to_unit);
            return 1;
        }
    } else if (strcmp(from_unit, "K") == 0) {
        if (strcmp(to_unit, "C") == 0) {
            temperature -= 273.15;
        } else if (strcmp(to_unit, "F") == 0) {
            temperature = (temperature * 9.0 / 5.0) - 459.67;
        } else {
            printf("Invalid conversion unit: %s\n", to_unit);
            return 1;
        }
    } else {
        printf("Invalid conversion unit: %s\n", from_unit);
        return 1;
    }

    printf("%.2f %s is %.2f %s\n", temperature, from_unit, temperature, to_unit);

    return 0;
}