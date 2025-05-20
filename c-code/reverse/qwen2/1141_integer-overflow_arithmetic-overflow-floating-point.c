#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void convertLength(double value) {
    printf("Meters: %.2f\n", value);
    printf("Feet: %.2f\n", value * 3.28084);
}

void convertTemperature(double value) {
    printf("Celsius: %.2f\n", value);
    printf("Fahrenheit: %.2f\n", (value * 9 / 5) + 32);
    printf("Kelvin: %.2f\n", value + 273.15);
}

void convertMass(double value) {
    printf("Kilograms: %.2f\n", value);
    printf("Ounces: %.2f\n", value * 35.274);
}

int main() {
    int choice;
    double value;

    while (1) {
        printf("\nChoose conversion type:\n");
        printf("1. Length\n");
        printf("2. Temperature\n");
        printf("3. Mass\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        if (choice == 4) break;

        printf("Enter the value to convert: ");
        scanf("%lf", &value);

        switch (choice) {
            case 1:
                convertLength(value);
                break;
            case 2:
                convertTemperature(value);
                break;
            case 3:
                convertMass(value);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
