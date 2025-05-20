//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000
#define MAX_TOKEN_LENGTH 50

enum {
    CELSIUS = 0,
    FAHRENHEIT
} temperature_scale;

double convert_temperature(double temperature, int from_scale, int to_scale) {
    switch (from_scale) {
        case CELSIUS:
            switch (to_scale) {
                case CELSIUS:
                    return temperature;
                case FAHRENHEIT:
                    return temperature * 1.8 + 32;
                default:
                    return -1;
            }
        case FAHRENHEIT:
            switch (to_scale) {
                case CELSIUS:
                    return (temperature - 32) / 1.8;
                case FAHRENHEIT:
                    return temperature;
                default:
                    return -1;
            }
        default:
            return -1;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <temperature> <from_scale> <to_scale>\n", argv[0]);
        return 1;
    }

    double temperature = atof(argv[1]);
    int from_scale = tolower(argv[2][0]) == 'c'? CELSIUS : FAHRENHEIT;
    int to_scale = tolower(argv[3][0]) == 'c'? CELSIUS : FAHRENHEIT;

    double result = convert_temperature(temperature, from_scale, to_scale);

    if (result == -1) {
        printf("Invalid input\n");
    } else {
        printf("%.2f %c = %.2f %c\n", temperature, argv[2][0], result, argv[3][0]);
    }

    return 0;
}