//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>

int main() {

    printf("Welcome to the Temperature Converter\n\n");

    float temperature;
    char unit_from, unit_to;

    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    printf("Enter the unit of temperature from [C]elsius and [F]ahrenheit: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit of temperature to [C]elsius and [F]ahrenheit: ");
    scanf(" %c", &unit_to);

    float result;

    if (unit_from == 'C') {

        if (unit_to == 'C') {
            result = temperature;

        } else if (unit_to == 'F') {
            result = temperature * (9.0 / 5.0) + 32.0;

        } else {
            printf("Invalid unit entered for 'unit_to'\n");
            return 0;
        }

    } else if (unit_from == 'F') {

        if (unit_to == 'F') {
            result = temperature;

        } else if (unit_to == 'C') {
            result = (temperature - 32.0) * (5.0 / 9.0);

        } else {
            printf("Invalid unit entered for 'unit_to'\n");
            return 0;
        }

    } else {
        printf("Invalid unit entered for 'unit_from'\n");
        return 0;
    }

    printf("%.2f %c is equal to %.2f %c\n", temperature, unit_from, result, unit_to);

    return 0;
}