//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

typedef enum {
    CELSIUS,
    FAHRENHEIT
} TemperatureUnit;

double convert_temperature(double temperature, TemperatureUnit from_unit, TemperatureUnit to_unit);

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char *input_ptr;
    double temperature;
    TemperatureUnit from_unit, to_unit;

    printf("Enter a temperature value: ");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);

    // Remove trailing newline character
    input_ptr = strchr(input_buffer, '\n');
    if (input_ptr!= NULL) {
        *input_ptr = '\0';
    }

    // Determine the input temperature unit
    from_unit = CELSIUS;
    to_unit = FAHRENHEIT;
    if (input_buffer[0] == 'F') {
        from_unit = FAHRENHEIT;
        to_unit = CELSIUS;
    }

    // Convert the temperature
    temperature = strtod(input_buffer, NULL);
    temperature = convert_temperature(temperature, from_unit, to_unit);

    // Print the result
    printf("%.2f %s = %.2f %s\n", temperature, (from_unit == CELSIUS)? "Celsius" : "Fahrenheit", temperature, (to_unit == CELSIUS)? "Celsius" : "Fahrenheit");

    return 0;
}

double convert_temperature(double temperature, TemperatureUnit from_unit, TemperatureUnit to_unit) {
    double result;

    switch (from_unit) {
        case CELSIUS:
            switch (to_unit) {
                case CELSIUS:
                    result = temperature;
                    break;
                case FAHRENHEIT:
                    result = (temperature * 9.0 / 5.0) + 32.0;
                    break;
            }
            break;
        case FAHRENHEIT:
            switch (to_unit) {
                case CELSIUS:
                    result = (temperature - 32.0) * 5.0 / 9.0;
                    break;
                case FAHRENHEIT:
                    result = temperature;
                    break;
            }
            break;
    }

    return result;
}