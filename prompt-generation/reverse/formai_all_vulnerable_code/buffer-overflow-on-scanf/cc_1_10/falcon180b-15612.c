//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846

typedef struct {
    char *name;
    double (*convert)(double);
} Conversion;

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double fahrenheit_to_kelvin(double fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvin_to_fahrenheit(double kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

Conversion *get_conversion(char *name) {
    static Conversion conversions[] = {
        {"Celsius", celsius_to_kelvin},
        {"Fahrenheit", fahrenheit_to_kelvin},
        {"Kelvin", kelvin_to_celsius}
    };

    for (int i = 0; i < sizeof(conversions) / sizeof(Conversion); i++) {
        if (strcmp(name, conversions[i].name) == 0) {
            return &conversions[i];
        }
    }

    return NULL;
}

int main() {
    double temperature;
    char input[100];
    Conversion *conversion;

    printf("Enter temperature: ");
    scanf("%lf", &temperature);

    printf("Enter unit (Celsius, Fahrenheit, Kelvin): ");
    scanf("%s", input);

    conversion = get_conversion(input);

    if (conversion == NULL) {
        printf("Invalid unit.\n");
        return 1;
    }

    double result = conversion->convert(temperature);

    printf("%.2lf %s = %.2lf %s\n", temperature, input, result, conversion->name);

    return 0;
}