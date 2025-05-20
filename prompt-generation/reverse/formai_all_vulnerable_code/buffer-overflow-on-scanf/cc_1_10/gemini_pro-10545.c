//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>

typedef struct {
    char *name;
    double (*convert_to_base)(double);
    double (*convert_from_base)(double);
} unit_type;

double convert_to_base_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double convert_from_base_celsius(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double convert_to_base_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double convert_from_base_fahrenheit(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double convert_to_base_inches(double centimeters) {
    return centimeters / 2.54;
}

double convert_from_base_inches(double inches) {
    return inches * 2.54;
}

double convert_to_base_liters(double gallons) {
    return gallons * 3.78541;
}

double convert_from_base_liters(double liters) {
    return liters / 3.78541;
}

double convert_to_base_kilograms(double pounds) {
    return pounds / 2.20462;
}

double convert_from_base_kilograms(double kilograms) {
    return kilograms * 2.20462;
}

unit_type units[] = {
    {"Celsius", convert_to_base_celsius, convert_from_base_celsius},
    {"Fahrenheit", convert_to_base_fahrenheit, convert_from_base_fahrenheit},
    {"Inches", convert_to_base_inches, convert_from_base_inches},
    {"Liters", convert_to_base_liters, convert_from_base_liters},
    {"Kilograms", convert_to_base_kilograms, convert_from_base_kilograms}
};

int main() {
    double value;
    char unit_name[20];
    char target_unit_name[20];
    int i, j;

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value: ");
    scanf("%s", unit_name);

    printf("Enter the target unit: ");
    scanf("%s", target_unit_name);

    for (i = 0; i < sizeof(units) / sizeof(unit_type); i++) {
        if (strcmp(units[i].name, unit_name) == 0) {
            for (j = 0; j < sizeof(units) / sizeof(unit_type); j++) {
                if (strcmp(units[j].name, target_unit_name) == 0) {
                    printf("%lf %s = %lf %s\n", value, units[i].name, units[j].convert_to_base(value), units[j].name);
                    return 0;
                }
            }
        }
    }

    printf("Invalid unit or target unit.\n");
    return 1;
}