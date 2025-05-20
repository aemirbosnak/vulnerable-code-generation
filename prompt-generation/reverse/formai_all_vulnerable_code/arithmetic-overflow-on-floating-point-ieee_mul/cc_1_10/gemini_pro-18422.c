//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: complete
#include <stdlib.h>
#include <stdio.h>

enum Unit {
    FAHRENHEIT,
    CELSIUS
};

struct Temperature {
    double value;
    enum Unit unit;
};

struct Temperature create_temperature(double value, enum Unit unit) {
    struct Temperature temperature = {value, unit};
    return temperature;
}

void print_temperature(struct Temperature temperature) {
    switch (temperature.unit) {
    case FAHRENHEIT:
        printf("%.2f degrees Fahrenheit\n", temperature.value);
        break;
    case CELSIUS:
        printf("%.2f degrees Celsius\n", temperature.value);
        break;
    }
}

double convert_temperature(struct Temperature temperature, enum Unit target_unit) {
    double converted_value;
    switch (temperature.unit) {
    case FAHRENHEIT:
        switch (target_unit) {
        case FAHRENHEIT:
            converted_value = temperature.value;
            break;
        case CELSIUS:
            converted_value = (temperature.value - 32) * 5 / 9;
            break;
        }
        break;
    case CELSIUS:
        switch (target_unit) {
        case CELSIUS:
            converted_value = temperature.value;
            break;
        case FAHRENHEIT:
            converted_value = (temperature.value * 9 / 5) + 32;
            break;
        }
        break;
    }
    return converted_value;
}

int main() {
    char input[100];
    double value;
    char unit;
    enum Unit target_unit;

    printf("Enter a temperature value, unit (F or C), and target unit (F or C): ");
    scanf("%s", input);
    sscanf(input, "%lf %c %c", &value, &unit, &target_unit);

    struct Temperature temperature = create_temperature(value, unit == 'F' ? FAHRENHEIT : CELSIUS);
    double converted_value = convert_temperature(temperature, target_unit == 'F' ? FAHRENHEIT : CELSIUS);

    printf("The converted temperature is: %.2f\n", converted_value);

    return EXIT_SUCCESS;
}