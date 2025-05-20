#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define UNITS 4

int main() {
    double lengths[UNITS] = {1.0, 0.001, 0.621371, 100000};
    char units[UNITS][20] = {"Meters", "Kilometers", "Miles", "Centimeters"};
    int fromUnit, toUnit;
    double value;

    while (1) {
        printf("Choose the unit to convert from:\n");
        for (int i = 0; i < UNITS; i++) {
            printf("%d: %s\n", i + 1, units[i]);
        }
        scanf("%d", &fromUnit);
        if (fromUnit > UNITS || fromUnit <= 0) break;

        printf("Choose the unit to convert to:\n");
        for (int i = 0; i < UNITS; i++) {
            printf("%d: %s\n", i + 1, units[i]);
        }
        scanf("%d", &toUnit);
        if (toUnit > UNITS || toUnit <= 0) break;

        printf("Enter the value to convert: ");
        scanf("%lf", &value);

        double result = value * lengths[fromUnit - 1] / lengths[toUnit - 1];
        printf("%.2f %s is %.2f %s\n", value, units[fromUnit - 1], result, units[toUnit - 1]);

        printf("Do you want to perform another conversion? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') break;
    }

    return 0;
}
