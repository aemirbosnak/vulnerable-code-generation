//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>

typedef struct {
    char *name;
    double (*convert_from_base)(double);
    double (*convert_to_base)(double);
} unit_type;

double convert_from_base_celsius(double temp) {
    return (temp - 32) * 5 / 9;
}

double convert_to_base_celsius(double temp) {
    return (temp * 9 / 5) + 32;
}

double convert_from_base_fahrenheit(double temp) {
    return (temp * 5 / 9) + 32;
}

double convert_to_base_fahrenheit(double temp) {
    return (temp - 32) * 9 / 5;
}

double convert_from_base_miles(double dist) {
    return dist * 1.60934;
}

double convert_to_base_miles(double dist) {
    return dist / 1.60934;
}

double convert_from_base_kilometers(double dist) {
    return dist / 1.60934;
}

double convert_to_base_kilometers(double dist) {
    return dist * 1.60934;
}

unit_type units[] = {
    {"Celsius", convert_from_base_celsius, convert_to_base_celsius},
    {"Fahrenheit", convert_from_base_fahrenheit, convert_to_base_fahrenheit},
    {"Miles", convert_from_base_miles, convert_to_base_miles},
    {"Kilometers", convert_from_base_kilometers, convert_to_base_kilometers}
};

int main() {
    printf("Welcome to the Intergalactic Unit Converter!\n\n");
    printf("Available units:\n");
    for (int i = 0; i < sizeof(units) / sizeof(unit_type); i++) {
        printf("  - %s\n", units[i].name);
    }

    char unit_from[32];
    char unit_to[32];
    double value;

    printf("\nEnter the unit you want to convert from: ");
    scanf("%s", unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit_to);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    int unit_from_index = -1;
    int unit_to_index = -1;

    for (int i = 0; i < sizeof(units) / sizeof(unit_type); i++) {
        if (strcmp(unit_from, units[i].name) == 0) {
            unit_from_index = i;
        } else if (strcmp(unit_to, units[i].name) == 0) {
            unit_to_index = i;
        }
    }

    if (unit_from_index == -1 || unit_to_index == -1) {
        printf("Invalid unit entered.\n");
        return 1;
    }

    double converted_value = units[unit_from_index].convert_to_base(value);
    converted_value = units[unit_to_index].convert_from_base(converted_value);

    printf("%lf %s is equal to %lf %s\n", value, unit_from, converted_value, unit_to);

    return 0;
}