//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double (*convert)(double);
} Unit;

double length_convert(double value) {
    return value * 2.54;
}

double weight_convert(double value) {
    return value * 0.453592;
}

double temperature_convert(double value) {
    return (value - 32) / 1.8;
}

Unit units[] = {
    {"centimeters", length_convert},
    {"meters", length_convert},
    {"inches", length_convert},
    {"feet", length_convert},
    {"kilograms", weight_convert},
    {"grams", weight_convert},
    {"fahrenheit", temperature_convert},
    {"celsius", temperature_convert}
};

int main() {
    int choice;
    double value, result;
    char unit[100];

    printf("Unit Converter\n");
    printf("1. Length\n2. Weight\n3. Temperature\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the value to convert: ");
            scanf("%lf", &value);
            printf("Enter the unit (centimeters, meters, inches, feet): ");
            scanf("%s", unit);

            result = units[0].convert(value);

            printf("%lf %s = %lf %s\n", value, unit, result, units[0].name);
            break;

        case 2:
            printf("Enter the value to convert: ");
            scanf("%lf", &value);
            printf("Enter the unit (kilograms, grams): ");
            scanf("%s", unit);

            result = units[2].convert(value);

            printf("%lf %s = %lf %s\n", value, unit, result, units[2].name);
            break;

        case 3:
            printf("Enter the value to convert: ");
            scanf("%lf", &value);
            printf("Enter the unit (fahrenheit, celsius): ");
            scanf("%s", unit);

            result = units[6].convert(value);

            printf("%lf %s = %lf %s\n", value, unit, result, units[6].name);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}