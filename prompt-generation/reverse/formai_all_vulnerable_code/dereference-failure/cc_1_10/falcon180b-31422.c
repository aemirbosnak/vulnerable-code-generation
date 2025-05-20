//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char *unit;
    double (*to_celsius)(double);
    double (*to_fahrenheit)(double);
} temperature_unit;

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

temperature_unit celsius = {"Celsius", celsius_to_fahrenheit, fahrenheit_to_celsius};
temperature_unit fahrenheit = {"Fahrenheit", fahrenheit_to_celsius, celsius_to_fahrenheit};

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <temperature> <from_unit> <to_unit>\n", argv[0]);
        return 1;
    }

    double temperature = atof(argv[1]);
    char *from_unit = argv[2];
    char *to_unit = argv[3];

    temperature_unit *from = NULL;
    temperature_unit *to = NULL;

    if (strcmp(from_unit, "Celsius") == 0) {
        from = &celsius;
    } else if (strcmp(from_unit, "Fahrenheit") == 0) {
        from = &fahrenheit;
    } else {
        printf("Invalid from_unit: %s\n", from_unit);
        return 1;
    }

    if (strcmp(to_unit, "Celsius") == 0) {
        to = &celsius;
    } else if (strcmp(to_unit, "Fahrenheit") == 0) {
        to = &fahrenheit;
    } else {
        printf("Invalid to_unit: %s\n", to_unit);
        return 1;
    }

    double result = from->to_celsius(temperature);
    result = to->to_fahrenheit(result);

    printf("%.2f %s is %.2f %s\n", temperature, from->unit, result, to->unit);

    return 0;
}