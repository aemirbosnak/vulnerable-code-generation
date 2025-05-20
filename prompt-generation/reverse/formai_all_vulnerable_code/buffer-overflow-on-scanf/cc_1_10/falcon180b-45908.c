//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    double (*convert)(double);
} Unit;

double length_convert(double value) {
    return value * 0.3048;
}

double weight_convert(double value) {
    return value * 2.20462;
}

double temperature_convert(double value) {
    return (value - 32) * 5.0/9.0;
}

int main() {
    Unit units[] = {
        {"Meters", length_convert},
        {"Kilograms", weight_convert},
        {"Celsius", temperature_convert}
    };

    int num_units = sizeof(units)/sizeof(units[0]);
    char input[MAX_LENGTH];
    double value, result;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of measurement to convert from: ");
    scanf("%s", input);

    printf("Enter the unit of measurement to convert to: ");
    scanf("%s", input);

    for(int i=0; i<num_units; i++) {
        if(strcmp(units[i].name, input) == 0) {
            result = units[i].convert(value);
            printf("%.2lf %s = %.2lf %s\n", value, input, result, input);
            return 0;
        }
    }

    printf("Invalid unit of measurement.\n");
    return 1;
}