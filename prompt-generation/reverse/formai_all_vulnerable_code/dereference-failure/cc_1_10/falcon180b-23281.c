//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum {
    CELSIUS = 0,
    FAHRENHEIT = 1,
    KELVIN = 2
};

double convert_temperature(double temperature, int from_unit, int to_unit) {
    switch (from_unit) {
        case CELSIUS:
            switch (to_unit) {
                case FAHRENHEIT:
                    return temperature * (9.0 / 5.0) + 32.0;
                case KELVIN:
                    return temperature + 273.15;
                default:
                    return temperature;
            }
        case FAHRENHEIT:
            switch (to_unit) {
                case CELSIUS:
                    return (temperature - 32.0) * (5.0 / 9.0);
                case KELVIN:
                    return (temperature + 459.67) * (5.0 / 9.0);
                default:
                    return temperature;
            }
        case KELVIN:
            switch (to_unit) {
                case CELSIUS:
                    return temperature - 273.15;
                case FAHRENHEIT:
                    return (temperature * (9.0 / 5.0) - 459.67);
                default:
                    return temperature;
            }
        default:
            return temperature;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <temperature> <from_unit> <to_unit>\n", argv[0]);
        return 1;
    }

    double temperature = strtod(argv[1], NULL);
    int from_unit = tolower(argv[2][0]) - 'c';
    int to_unit = tolower(argv[3][0]) - 'c';

    if (from_unit < 0 || from_unit > 2 || to_unit < 0 || to_unit > 2) {
        printf("Invalid unit.\n");
        return 1;
    }

    double result = convert_temperature(temperature, from_unit, to_unit);
    printf("%.2f %c = %.2f %c\n", temperature, argv[2][0], result, argv[3][0]);

    return 0;
}