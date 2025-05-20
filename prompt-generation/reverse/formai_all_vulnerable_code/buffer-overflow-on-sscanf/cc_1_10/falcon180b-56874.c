//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DEBUG 0

#ifdef DEBUG
#define debug(x) x
#else
#define debug(x)
#endif

typedef struct {
    char *name;
    double (*convert)(double);
} temperature_unit;

double celsius_to_fahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32.0;
}

double celsius_to_kelvin(double c) {
    return c + 273.15;
}

double fahrenheit_to_celsius(double f) {
    return (f - 32.0) * 5.0 / 9.0;
}

double fahrenheit_to_kelvin(double f) {
    return celsius_to_kelvin(fahrenheit_to_celsius(f));
}

double kelvin_to_celsius(double k) {
    return k - 273.15;
}

double kelvin_to_fahrenheit(double k) {
    return celsius_to_fahrenheit(kelvin_to_celsius(k));
}

int main() {
    temperature_unit units[] = {
        {"Celsius", celsius_to_fahrenheit},
        {"Fahrenheit", fahrenheit_to_celsius},
        {"Kelvin", kelvin_to_celsius}
    };

    int num_units = sizeof(units) / sizeof(units[0]);

    char input_buffer[1024];
    char *token;
    double value, result;
    int i;

    printf("Enter a temperature value: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);

    token = strtok(input_buffer, " ");
    if (token == NULL || sscanf(token, "%lf", &value)!= 1) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter the input temperature unit (Celsius, Fahrenheit, or Kelvin): ");
    fgets(input_buffer, sizeof(input_buffer), stdin);

    token = strtok(input_buffer, " ");
    if (token == NULL) {
        printf("Invalid input\n");
        return 1;
    }

    for (i = 0; i < num_units; i++) {
        if (strcmp(token, units[i].name) == 0) {
            result = units[i].convert(value);
            printf("%.2lf %s = %.2lf %s\n", value, token, result, units[i + 1].name);
            break;
        }
    }

    return 0;
}