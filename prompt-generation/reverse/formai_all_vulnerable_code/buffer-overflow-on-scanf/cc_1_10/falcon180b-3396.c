//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP_UNITS 3

typedef struct {
    char *name;
    double (*to_celsius)(double);
    double (*to_fahrenheit)(double);
    double (*to_kelvin)(double);
} temp_unit;

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

temp_unit temp_units[] = {
    {"Celsius", celsius_to_fahrenheit, celsius_to_kelvin, kelvin_to_celsius},
    {"Fahrenheit", fahrenheit_to_celsius, fahrenheit_to_kelvin, kelvin_to_fahrenheit},
    {"Kelvin", celsius_to_kelvin, kelvin_to_celsius, kelvin_to_fahrenheit}
};

int main() {
    int num_units;
    char input_unit[10];
    char output_unit[10];
    double temp;

    printf("Enter the number of temperature units to convert (1-3): ");
    scanf("%d", &num_units);

    if (num_units < 1 || num_units > MAX_TEMP_UNITS) {
        printf("Invalid number of temperature units.\n");
        return 1;
    }

    printf("Enter the input temperature unit (Celsius, Fahrenheit, or Kelvin): ");
    scanf("%s", input_unit);

    printf("Enter the output temperature unit (Celsius, Fahrenheit, or Kelvin): ");
    scanf("%s", output_unit);

    printf("Enter the temperature value to convert: ");
    scanf("%lf", &temp);

    temp_unit *input_unit_ptr = NULL;
    temp_unit *output_unit_ptr = NULL;

    for (int i = 0; i < num_units; i++) {
        if (strcmp(input_unit, temp_units[i].name) == 0) {
            input_unit_ptr = &temp_units[i];
        } else if (strcmp(output_unit, temp_units[i].name) == 0) {
            output_unit_ptr = &temp_units[i];
        }
    }

    if (input_unit_ptr == NULL || output_unit_ptr == NULL) {
        printf("Invalid temperature unit(s).\n");
        return 1;
    }

    double result = input_unit_ptr->to_celsius(temp);

    for (int i = 0; i < num_units - 1; i++) {
        result = output_unit_ptr->to_celsius(result);
    }

    printf("%.2lf %s = %.2lf %s\n", temp, input_unit, result, output_unit);

    return 0;
}