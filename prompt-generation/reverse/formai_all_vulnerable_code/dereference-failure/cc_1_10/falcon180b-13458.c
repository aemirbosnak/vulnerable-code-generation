//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *unit;
    double factor;
} TemperatureUnit;

TemperatureUnit temperature_units[] = {
    {"C", 1.0},
    {"F", 1.8},
    {"K", 1.0},
    {"R", 1.0},
    {"D", 1.0},
    {"R", 1.0},
    {"N", 1.0},
    {"S", 1.0},
    {"E", 1.0},
    {"B", 1.0},
    {"A", 1.0},
    {"V", 1.0},
    {"W", 1.0},
    {"X", 1.0},
    {"Y", 1.0},
    {"Z", 1.0}
};

int main(int argc, char *argv[]) {
    char input_buffer[MAX_LINE_LENGTH];
    double temperature;
    TemperatureUnit input_unit, output_unit;
    int unit_index;

    printf("Enter a temperature followed by its unit (e.g. 25C):\n");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);

    strtok(input_buffer, " ");
    strcpy(input_unit.unit, strtok(NULL, " "));

    temperature = atof(strtok(NULL, " "));

    unit_index = 0;
    while (unit_index < sizeof(temperature_units) / sizeof(TemperatureUnit)) {
        if (strcmp(input_unit.unit, temperature_units[unit_index].unit) == 0) {
            break;
        }
        unit_index++;
    }

    if (unit_index == sizeof(temperature_units) / sizeof(TemperatureUnit)) {
        printf("Invalid temperature unit.\n");
        return 1;
    }

    strcpy(output_unit.unit, "C");
    temperature = (temperature - 32) / 9 * 5;

    printf("%.2f%s = %.2f%s\n", temperature, input_unit.unit, temperature, output_unit.unit);

    return 0;
}