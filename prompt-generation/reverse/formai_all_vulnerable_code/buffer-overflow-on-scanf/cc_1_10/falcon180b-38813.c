//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    double (*convert)(double);
} Conversion;

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
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

Conversion conversions[] = {
    {"Celsius", celsius_to_fahrenheit},
    {"Fahrenheit", fahrenheit_to_celsius},
    {"Kelvin", kelvin_to_celsius},
    {"Celsius", celsius_to_kelvin}
};

int main() {
    int choice;
    double input, output;
    printf("Enter the temperature and the units of measurement: ");
    scanf("%lf %s", &input, conversions[0].name);

    for (int i = 1; i < sizeof(conversions) / sizeof(Conversion); i++) {
        if (!strcmp(conversions[i].name, conversions[0].name)) {
            choice = i;
            break;
        }
    }

    printf("Enter the unit you want to convert to: ");
    scanf("%s", conversions[choice].name);

    output = conversions[choice].convert(input);
    printf("%.2lf %s is equal to %.2lf %s.\n", input, conversions[0].name, output, conversions[choice].name);

    return 0;
}