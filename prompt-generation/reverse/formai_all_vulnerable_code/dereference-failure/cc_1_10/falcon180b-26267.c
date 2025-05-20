//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_TOKEN_SIZE 100

typedef struct {
    char *name;
    double (*convert)(double);
} TemperatureScale;

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

TemperatureScale scales[] = {
    {"Celsius", celsius_to_fahrenheit},
    {"Fahrenheit", fahrenheit_to_celsius},
    {"Kelvin", kelvin_to_celsius}
};

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <temperature> <scale>\n", argv[0]);
        return 1;
    }

    double temperature = strtod(argv[1], NULL);
    char *scale_name = argv[2];

    int i;
    for (i = 0; i < sizeof(scales)/sizeof(scales[0]); i++) {
        if (strcmp(scale_name, scales[i].name) == 0) {
            double result = scales[i].convert(temperature);
            printf("%.2f %s = %.2f %s\n", temperature, scale_name, result, scales[i].name);
            return 0;
        }
    }

    printf("Invalid scale: %s\n", scale_name);
    return 1;
}