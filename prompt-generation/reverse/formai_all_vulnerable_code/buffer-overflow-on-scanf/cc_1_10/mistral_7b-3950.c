//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef enum { FAHRENHEIT, CELSIUS } TemperatureUnit;

struct TemperatureConverter {
    TemperatureUnit unit;
    float value;
};

void fahrenheit_to_celsius(struct TemperatureConverter *converter) {
    converter->value = (5.0f / 9.0f) * (converter->value - 32.0f);
    converter->unit = CELSIUS;
}

void celsius_to_fahrenheit(struct TemperatureConverter *converter) {
    converter->value = (converter->value * 9.0f / 5.0f) + 32.0f;
    converter->unit = FAHRENHEIT;
}

void print_temperature(struct TemperatureConverter converter) {
    char *unit_name;

    switch (converter.unit) {
        case FAHRENHEIT:
            unit_name = "Fahrenheit";
            break;
        case CELSIUS:
            unit_name = "Celsius";
            break;
        default:
            unit_name = "Unknown";
            break;
    }

    printf("%.2f %s\n", converter.value, unit_name);
}

int main() {
    struct TemperatureConverter input, output;
    char command[10];

    printf("Welcome to the Temperature Converter,\n"
           "an enchanting journey through the realm of heat and cold!\n");

    while (1) {
        printf("Enter temperature value and conversion command (e.g. '50 F to C'): ");
        scanf("%f %s", &input.value, command);

        if (strcmp(command, "to") != 0) {
            printf("Invalid command. Use 'to' to specify conversion direction.\n");
            continue;
        }

        sscanf(command, "%s %s", command, command+strlen(command)+1);

        if (strcmp(command, "F") == 0) {
            fahrenheit_to_celsius(&input);
        } else if (strcmp(command, "C") == 0) {
            celsius_to_fahrenheit(&input);
        } else {
            printf("Invalid temperature unit. Use 'F' for Fahrenheit or 'C' for Celsius.\n");
            continue;
        }

        output = input;
        print_temperature(output);
    }

    return 0;
}