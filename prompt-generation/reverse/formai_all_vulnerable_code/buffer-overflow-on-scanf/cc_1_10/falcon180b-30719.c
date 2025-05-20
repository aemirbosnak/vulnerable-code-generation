//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TEMP_CELSIUS 0
#define TEMP_FAHRENHEIT 1
#define TEMP_KELVIN 2

int main() {
    int choice = 0;
    double temperature = 0;
    char input[100];

    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose a temperature unit:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    scanf("%s", input);

    if (strcmp(input, "1") == 0) {
        choice = TEMP_CELSIUS;
    } else if (strcmp(input, "2") == 0) {
        choice = TEMP_FAHRENHEIT;
    } else if (strcmp(input, "3") == 0) {
        choice = TEMP_KELVIN;
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("Please enter the temperature: ");
    scanf("%lf", &temperature);

    double result = 0;

    switch (choice) {
        case TEMP_CELSIUS:
            result = (temperature * 9 / 5) + 32;
            printf("%.2lf Celsius is %.2lf Fahrenheit.\n", temperature, result);
            break;
        case TEMP_FAHRENHEIT:
            result = (temperature - 32) * 5 / 9;
            printf("%.2lf Fahrenheit is %.2lf Celsius.\n", temperature, result);
            break;
        case TEMP_KELVIN:
            result = temperature + 273.15;
            printf("%.2lf Kelvin is %.2lf Celsius.\n", temperature, result);
            break;
    }

    return 0;
}