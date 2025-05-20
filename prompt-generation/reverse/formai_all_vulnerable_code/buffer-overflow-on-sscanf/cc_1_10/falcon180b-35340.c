//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100

enum temperature_unit {
    CELSIUS,
    FAHRENHEIT
};

struct temperature {
    double value;
    enum temperature_unit unit;
};

void print_temperature(struct temperature temperature) {
    printf("%.2f %s\n", temperature.value, temperature.unit == CELSIUS? "C" : "F");
}

struct temperature convert_temperature(struct temperature temperature, enum temperature_unit to_unit) {
    if (temperature.unit == to_unit) {
        return temperature;
    }

    double converted_value;
    if (temperature.unit == CELSIUS) {
        converted_value = (temperature.value * 1.8) + 32;
    } else {
        converted_value = (temperature.value - 32) / 1.8;
    }

    return (struct temperature) {
       .value = converted_value,
       .unit = to_unit
    };
}

int main() {
    char input[MAX_LENGTH];
    enum temperature_unit input_unit = CELSIUS;
    struct temperature temperature = {0, input_unit};

    printf("Enter a temperature (e.g. 25 C): ");
    fgets(input, MAX_LENGTH, stdin);

    sscanf(input, "%lf %c", &temperature.value, &input_unit);

    if (input_unit == 'C' || input_unit == 'c') {
        temperature.unit = CELSIUS;
    } else if (input_unit == 'F' || input_unit == 'f') {
        temperature.unit = FAHRENHEIT;
    } else {
        printf("Invalid temperature unit.\n");
        return 1;
    }

    printf("You entered: ");
    print_temperature(temperature);

    enum temperature_unit output_unit = FAHRENHEIT;

    temperature = convert_temperature(temperature, output_unit);

    printf("Converted to %s: ", output_unit == CELSIUS? "Fahrenheit" : "Celsius");
    print_temperature(temperature);

    return 0;
}