#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void convertLength(double value) {
    printf("1 meter = 0.621371 miles\n");
    printf("%f meters = %f miles\n", value, value * 0.621371);
}

void convertMass(double value) {
    printf("1 kilogram = 2.20462 pounds\n");
    printf("%f kilograms = %f pounds\n", value, value * 2.20462);
}

void convertTime(double value) {
    printf("1 second = 1/60 minutes\n");
    printf("%f seconds = %f minutes\n", value, value / 60);
}

int main() {
    int choice;
    double value;

    printf("Futuristic Unit Converter\n");
    printf("1. Convert Length\n");
    printf("2. Convert Mass\n");
    printf("3. Convert Time\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            convertLength(value);
            break;
        case 2:
            convertMass(value);
            break;
        case 3:
            convertTime(value);
            break;
    }

    return 0;
}
