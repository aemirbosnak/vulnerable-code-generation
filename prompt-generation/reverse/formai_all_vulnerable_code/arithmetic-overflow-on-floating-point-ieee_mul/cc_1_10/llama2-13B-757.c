//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH_UNITS "cm,m,km"
#define WEIGHT_UNITS "g,kg,ton"
#define TEMPERATURE_UNITS "celsius,fahrenheit"
#define TIME_UNITS "s,min,hr"

struct unit {
    const char *name;
    double factor;
};

struct unit length_units[] = {
    {"cm", 0.01},
    {"m", 100},
    {"km", 100000}
};

struct unit weight_units[] = {
    {"g", 0.001},
    {"kg", 1000},
    {"ton", 1000000}
};

struct unit temperature_units[] = {
    {"celsius", 100},
    {"fahrenheit", 180 / 5}
};

struct unit time_units[] = {
    {"s", 1},
    {"min", 60},
    {"hr", 3600}
};

void convert(double value, const struct unit *from_unit, const struct unit *to_unit) {
    double factor = from_unit->factor / to_unit->factor;
    printf("%.2f %s = %.2f %s\n", value, from_unit->name, value * factor, to_unit->name);
}

int main() {
    double length, weight, temperature, time;
    char input[100];
    char unit_input[10];

    printf("Enter a length: ");
    fgets(input, 100, stdin);
    length = atof(input);

    printf("Enter a weight: ");
    fgets(input, 100, stdin);
    weight = atof(input);

    printf("Enter a temperature: ");
    fgets(input, 100, stdin);
    temperature = atof(input);

    printf("Enter a time: ");
    fgets(input, 100, stdin);
    time = atof(input);

    printf("Length: %s\n", length_units[0].name);
    convert(length, &length_units[0], &length_units[1]);
    printf("Weight: %s\n", weight_units[0].name);
    convert(weight, &weight_units[0], &weight_units[1]);
    printf("Temperature: %s\n", temperature_units[0].name);
    convert(temperature, &temperature_units[0], &temperature_units[1]);
    printf("Time: %s\n", time_units[0].name);
    convert(time, &time_units[0], &time_units[1]);

    return 0;
}