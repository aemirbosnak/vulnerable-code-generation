//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERTERS 10

struct converter {
    char *name;
    double (*convert)(double);
};

double length_convert(double value) {
    return value * 2.54;
}

double weight_convert(double value) {
    return value * 0.453592;
}

double temperature_convert(double value) {
    return (value - 32) * 5.0 / 9.0;
}

int main() {
    char input[100];
    double value;
    int choice;
    struct converter converters[MAX_CONVERTERS] = {
        {"length", length_convert},
        {"weight", weight_convert},
        {"temperature", temperature_convert}
    };

    printf("Welcome to the Unit Converter!\n");
    printf("Please select a unit to convert:\n");

    for (int i = 0; i < MAX_CONVERTERS; i++) {
        printf("%d. %s\n", i+1, converters[i].name);
    }

    scanf("%d", &choice);

    printf("Enter the value to convert:\n");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            printf("%.2lf %s = %.2lf %s\n", value, converters[0].name, length_convert(value), converters[0].name);
            break;
        case 2:
            printf("%.2lf %s = %.2lf %s\n", value, converters[1].name, weight_convert(value), converters[1].name);
            break;
        case 3:
            printf("%.2lf %s = %.2lf %s\n", value, converters[2].name, temperature_convert(value), converters[2].name);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}