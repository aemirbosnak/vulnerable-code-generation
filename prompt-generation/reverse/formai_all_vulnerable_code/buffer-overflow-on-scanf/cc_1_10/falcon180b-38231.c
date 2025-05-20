//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMP 10000

typedef struct {
    char *name;
    double (*convert)(double);
} TemperatureUnit;

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
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

void print_unit(TemperatureUnit unit) {
    printf("%s: ", unit.name);
}

int main() {
    TemperatureUnit units[] = {{"Celsius", celsius_to_fahrenheit},
                             {"Fahrenheit", fahrenheit_to_celsius},
                             {"Kelvin", kelvin_to_celsius}};
    int num_units = sizeof(units) / sizeof(units[0]);
    int choice;
    double temperature;

    srand(time(NULL));
    choice = rand() % num_units;

    printf("Enter a temperature: ");
    scanf("%lf", &temperature);

    printf("Converting %.2lf %s to:\n", temperature, units[choice].name);

    for (int i = 0; i < num_units; i++) {
        if (i == choice)
            continue;
        print_unit(units[i]);
        printf("%.2lf\n", units[i].convert(temperature));
    }

    return 0;
}