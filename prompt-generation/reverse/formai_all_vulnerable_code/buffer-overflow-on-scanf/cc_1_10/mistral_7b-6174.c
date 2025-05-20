//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MIN_TEMP  -273.15
#define MAX_TEMP  999.99
#define F_TO_C_OFFSET 32.0
#define C_TO_F_MULTIPLIER 1.8

void convert_temp(double value, int to_celsius) {
    double result;

    if (to_celsius) {
        result = value - F_TO_C_OFFSET;
        result *= C_TO_F_MULTIPLIER;
    } else {
        result = (value * C_TO_F_MULTIPLIER) + F_TO_C_OFFSET;
    }

    printf("%.2f %s = %.2f %s\n", value, to_celsius ? "Celsius" : "Fahrenheit", result, to_celsius ? "Fahrenheit" : "Celsius");
}

int main() {
    int choice;
    double temperature;

    do {
        printf("\n1. Convert Fahrenheit to Celsius\n");
        printf("2. Convert Celsius to Fahrenheit\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        printf("Enter temperature value: ");
        scanf("%lf", &temperature);

        if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
            printf("Invalid temperature value! Temperature should be between %-.2f and %-.2f degrees.\n", MIN_TEMP, MAX_TEMP);
            continue;
        }

        convert_temp(temperature, choice != 1);

    } while (choice != 3);

    return 0;
}