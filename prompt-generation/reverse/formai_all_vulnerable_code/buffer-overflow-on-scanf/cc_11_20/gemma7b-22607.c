//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main() {
    int choice, unit_from, unit_to;
    float value;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert temperature\n");
    printf("2. Convert mass\n");
    printf("3. Convert length\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the value to be converted:");
            scanf("%f", &value);
            unit_from = 0;
            unit_to = 1;
            break;
        case 2:
            printf("Enter the value to be converted:");
            scanf("%f", &value);
            unit_from = 2;
            unit_to = 0;
            break;
        case 3:
            printf("Enter the value to be converted:");
            scanf("%f", &value);
            unit_from = 3;
            unit_to = 2;
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    switch (unit_from) {
        case 0:
            switch (unit_to) {
                case 0:
                    printf("The converted value is: %.2f degrees Celsius.\n", value);
                    break;
                case 1:
                    printf("The converted value is: %.2f degrees Fahrenheit.\n", (value * 1.8) + 32);
                    break;
                case 2:
                    printf("The converted value is: %.2f Kelvin.\n", value + 273.15);
                    break;
                default:
                    printf("Invalid unit conversion.\n");
                    return 1;
            }
            break;
        case 1:
            switch (unit_to) {
                case 0:
                    printf("The converted value is: %.2f degrees Celsius.\n", (value - 32) * 5 / 9);
                    break;
                case 1:
                    printf("The converted value is: %.2f degrees Fahrenheit.\n", value);
                    break;
                case 2:
                    printf("The converted value is: %.2f Kelvin.\n", (value - 32) * 5 / 9 + 273.15);
                    break;
                default:
                    printf("Invalid unit conversion.\n");
                    return 1;
            }
            break;
        case 2:
            switch (unit_to) {
                case 0:
                    printf("The converted value is: %.2f degrees Celsius.\n", (value - 273.15) * 9 / 5 + 32);
                    break;
                case 1:
                    printf("The converted value is: %.2f degrees Fahrenheit.\n", (value - 273.15) * 9 / 5 + 32);
                    break;
                case 2:
                    printf("The converted value is: %.2f Kelvin.\n", value);
                    break;
                default:
                    printf("Invalid unit conversion.\n");
                    return 1;
            }
            break;
        default:
            printf("Invalid unit conversion.\n");
            return 1;
    }

    return 0;
}