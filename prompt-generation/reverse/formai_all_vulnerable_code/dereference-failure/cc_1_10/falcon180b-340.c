//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char *name;
    double (*convert)(double);
} TemperatureConverter;

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

TemperatureConverter temperature_converters[] = {
    {"Celsius to Fahrenheit", celsius_to_fahrenheit},
    {"Fahrenheit to Celsius", fahrenheit_to_celsius}
};

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char *token;
    int converter_index;
    double temperature;
    char *output_unit;
    char *target_unit;

    printf("Enter the temperature value: ");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);

    token = strtok(input_buffer, " ");
    if (token == NULL) {
        printf("Invalid input format.\n");
        return 1;
    }

    temperature = strtod(token, NULL);

    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Invalid input format.\n");
        return 1;
    }

    strcpy(output_unit, token);

    printf("Enter the target unit: ");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);

    token = strtok(input_buffer, " ");
    if (token == NULL) {
        printf("Invalid input format.\n");
        return 1;
    }

    strcpy(target_unit, token);

    converter_index = 0;
    while (converter_index < sizeof(temperature_converters) / sizeof(TemperatureConverter)) {
        if (strcmp(temperature_converters[converter_index].name, target_unit) == 0) {
            temperature = temperature_converters[converter_index].convert(temperature);
            printf("%.2f %s = %.2f %s\n", temperature, output_unit, temperature, target_unit);
            break;
        }
        converter_index++;
    }

    if (converter_index == sizeof(temperature_converters) / sizeof(TemperatureConverter)) {
        printf("Invalid target unit.\n");
        return 1;
    }

    return 0;
}