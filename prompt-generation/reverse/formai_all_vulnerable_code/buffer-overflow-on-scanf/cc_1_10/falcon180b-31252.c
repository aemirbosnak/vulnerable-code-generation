//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMP_TYPES 3

enum {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
};

int main() {
    char input[10];
    double temperature;
    int temp_type;
    char *temp_types[MAX_TEMP_TYPES] = {"Celsius", "Fahrenheit", "Kelvin"};
    int num_temp_types = 0;

    printf("Welcome to the temperature converter!\n");

    // Prompt the user to enter the temperature and its type
    printf("Enter the temperature: ");
    scanf("%lf", &temperature);
    printf("Enter the temperature type (Celsius, Fahrenheit, or Kelvin): ");
    scanf("%s", input);

    // Check if the input temperature type is valid
    for (int i = 0; i < MAX_TEMP_TYPES; i++) {
        if (strcmp(input, temp_types[i]) == 0) {
            temp_type = i;
            break;
        }
    }

    if (temp_type == -1) {
        printf("Invalid temperature type!\n");
        return 1;
    }

    // Convert the temperature to the desired type
    switch (temp_type) {
        case CELSIUS:
            if (temperature >= -273.15) {
                printf("%.2lf Celsius is equivalent to %.2lf Fahrenheit and %.2lf Kelvin.\n", temperature, (temperature * 9.0 / 5.0) + 32.0, temperature + 273.15);
            } else {
                printf("Invalid temperature!\n");
            }
            break;
        case FAHRENHEIT:
            if (temperature >= -459.67) {
                printf("%.2lf Fahrenheit is equivalent to %.2lf Celsius and %.2lf Kelvin.\n", temperature, (temperature - 32.0) * 5.0 / 9.0, (temperature + 459.67) * 5.0 / 9.0);
            } else {
                printf("Invalid temperature!\n");
            }
            break;
        case KELVIN:
            if (temperature >= 0) {
                printf("%.2lf Kelvin is equivalent to %.2lf Celsius and %.2lf Fahrenheit.\n", temperature, temperature - 273.15, (temperature * 9.0 / 5.0) - 459.67);
            } else {
                printf("Invalid temperature!\n");
            }
            break;
    }

    return 0;
}