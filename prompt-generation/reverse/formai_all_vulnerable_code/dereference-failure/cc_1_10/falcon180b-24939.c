//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    double (*convert)(double);
} TemperatureScale;

double celsius_to_fahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

TemperatureScale temperature_scales[] = {
    {"Celsius", celsius_to_fahrenheit},
    {"Fahrenheit", fahrenheit_to_celsius},
    {"Kelvin", kelvin_to_celsius}
};

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <temperature> <scale>\n", argv[0]);
        return 1;
    }

    double temperature = strtod(argv[1], NULL);
    char *scale_name = argv[2];

    TemperatureScale *scale = NULL;
    for (int i = 0; i < sizeof(temperature_scales) / sizeof(temperature_scales[0]); i++) {
        if (strcmp(scale_name, temperature_scales[i].name) == 0) {
            scale = &temperature_scales[i];
            break;
        }
    }

    if (scale == NULL) {
        fprintf(stderr, "Invalid temperature scale: %s\n", scale_name);
        return 1;
    }

    double result = scale->convert(temperature);
    printf("%.2f %s = %.2f %s\n", temperature, scale_name, result, scale->name);

    return 0;
}