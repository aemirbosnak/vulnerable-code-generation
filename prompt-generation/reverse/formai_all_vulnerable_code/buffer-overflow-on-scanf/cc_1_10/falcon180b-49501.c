//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

TemperatureConverter temperature_converters[] = {
    {"Celsius to Fahrenheit", celsius_to_fahrenheit},
    {"Fahrenheit to Celsius", fahrenheit_to_celsius},
    {"Celsius to Kelvin", celsius_to_kelvin},
    {"Kelvin to Celsius", kelvin_to_celsius}
};

int main() {
    int num_converters = sizeof(temperature_converters) / sizeof(TemperatureConverter);
    int choice;

    printf("Select a temperature converter:\n");
    for (int i = 0; i < num_converters; i++) {
        printf("%d. %s\n", i + 1, temperature_converters[i].name);
    }

    scanf("%d", &choice);

    if (choice >= 1 && choice <= num_converters) {
        double input_temp, output_temp;

        printf("Enter the temperature to convert: ");
        scanf("%lf", &input_temp);

        output_temp = temperature_converters[choice - 1].convert(input_temp);

        printf("%.2lf %s = %.2lf %s\n", input_temp, temperature_converters[choice - 1].name, output_temp, temperature_converters[3 - choice].name);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}