//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    double (*convert)(double);
} TemperatureConverter;

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

TemperatureConverter converters[] = {
    {"Celsius to Fahrenheit", celsius_to_fahrenheit},
    {"Fahrenheit to Celsius", fahrenheit_to_celsius}
};

int main() {
    int num_converters = sizeof(converters) / sizeof(converters[0]);
    int choice;

    printf("Select a temperature converter:\n");
    for (int i = 0; i < num_converters; i++) {
        printf("%d. %s\n", i + 1, converters[i].name);
    }

    scanf("%d", &choice);

    if (choice >= 1 && choice <= num_converters) {
        TemperatureConverter *selected_converter = &converters[choice - 1];
        char input[MAX_LENGTH];

        printf("Enter a temperature in %s:\n", selected_converter->name);
        scanf("%s", input);

        double temperature;
        if (sscanf(input, "%lf", &temperature)!= 1) {
            printf("Invalid input.\n");
            return 1;
        }

        double result = selected_converter->convert(temperature);
        printf("%.2lf %s is %.2lf %s\n", temperature, selected_converter->name, result, selected_converter->name);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}