//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef enum {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
} TemperatureScale;

char* toString(TemperatureScale scale) {
    switch (scale) {
        case CELSIUS:
            return "Celsius";
        case FAHRENHEIT:
            return "Fahrenheit";
        case KELVIN:
            return "Kelvin";
        default:
            return "Invalid";
    }
}

double convert(double temperature, TemperatureScale from, TemperatureScale to) {
    switch (from) {
        case CELSIUS:
            switch (to) {
                case FAHRENHEIT:
                    return temperature * 9.0 / 5.0 + 32.0;
                case KELVIN:
                    return temperature + 273.15;
                default:
                    return 0;
            }
        case FAHRENHEIT:
            switch (to) {
                case CELSIUS:
                    return (temperature - 32.0) * 5.0 / 9.0;
                case KELVIN:
                    return (temperature + 459.67) * 5.0 / 9.0;
                default:
                    return 0;
            }
        case KELVIN:
            switch (to) {
                case CELSIUS:
                    return temperature - 273.15;
                case FAHRENHEIT:
                    return (temperature - 273.15) * 9.0 / 5.0 + 32.0;
                default:
                    return 0;
            }
        default:
            return 0;
    }
}

int main() {
    char input[MAX_LINE_LENGTH];
    TemperatureScale from, to;
    double temperature;

    printf("Enter a temperature (e.g. 25 C): ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    if (sscanf(input, "%lf %c", &temperature, &from)!= 2) {
        printf("Invalid input\n");
        return 1;
    }

    to = CELSIUS;
    if (isupper(from)) {
        from = tolower(from);
    }

    switch (from) {
        case 'c':
        case 'celsius':
            to = FAHRENHEIT;
            break;
        case 'f':
        case 'fahrenheit':
            to = CELSIUS;
            break;
        case 'k':
        case 'kelvin':
            to = CELSIUS;
            break;
        default:
            printf("Invalid temperature scale: %c\n", from);
            return 1;
    }

    temperature = convert(temperature, from, to);

    printf("%.2lf %c = %.2lf %s\n", temperature, from, temperature, toString(to));

    return 0;
}