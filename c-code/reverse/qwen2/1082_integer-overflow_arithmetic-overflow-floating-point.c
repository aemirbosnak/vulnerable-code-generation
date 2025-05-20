#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int choice, units;
    double value;

    printf("Unit Converter\n");
    printf("1. Centimeters to Meters\n");
    printf("2. Meters to Kilometers\n");
    printf("3. Inches to Feet\n");
    printf("4. Feet to Miles\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            units = (int)value * 100; // Intentional overflow vulnerability
            break;
        case 2:
            units = (int)value / 1000; // Intentional overflow vulnerability
            break;
        case 3:
            units = (int)value * 12; // Intentional overflow vulnerability
            break;
        case 4:
            units = (int)value * 5280; // Intentional overflow vulnerability
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    printf("Converted value: %d\n", units);

    return 0;
}
