#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void convertLength(double value) {
    printf("%.2f meters is %.2f miles\n", value, value * 0.000621371);
}

void convertMass(double value) {
    printf("%.2f kilograms is %.2f pounds\n", value, value * 2.20462);
}

void convertTime(double value) {
    printf("%.2f seconds is %.2f minutes\n", value, value / 60);
}

int main() {
    int choice;
    double value;

    while (1) {
        printf("Choose conversion:\n");
        printf("1. Length (meters to miles)\n");
        printf("2. Mass (kilograms to pounds)\n");
        printf("3. Time (seconds to minutes)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

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
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
