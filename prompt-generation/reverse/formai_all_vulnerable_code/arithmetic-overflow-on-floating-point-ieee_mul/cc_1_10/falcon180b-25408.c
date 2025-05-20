//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char *name;
    double (*convert)(double);
} Unit;

double length_convert(double value) {
    return value * 0.3048;
}

double weight_convert(double value) {
    return value * 0.453592;
}

double volume_convert(double value) {
    return value * 3.78541;
}

double temperature_convert(double value) {
    return (value - 32) * 5.0 / 9.0;
}

int main() {
    Unit units[] = {
        {"meters", length_convert},
        {"centimeters", length_convert},
        {"kilograms", weight_convert},
        {"grams", weight_convert},
        {"liters", volume_convert},
        {"celsius", temperature_convert},
        {"fahrenheit", temperature_convert}
    };

    int num_units = sizeof(units) / sizeof(units[0]);
    char input[100];
    double value;
    int choice;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of measurement (1. meters\n2. centimeters\n3. kilograms\n4. grams\n5. liters\n6. celsius\n7. fahrenheit): ");
    scanf("%s", input);

    choice = toupper(input[0]) - '0';

    if (choice >= 1 && choice <= num_units) {
        printf("%.2lf %s = ", value, units[choice - 1].name);
        printf("%.2lf %s\n", value * units[choice - 1].convert(value), "meters");
    } else {
        printf("Invalid unit of measurement.\n");
    }

    return 0;
}