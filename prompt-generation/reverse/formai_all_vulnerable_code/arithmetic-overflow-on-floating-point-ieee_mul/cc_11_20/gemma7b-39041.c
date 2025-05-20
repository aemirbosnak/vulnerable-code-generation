//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_units, unit_from, unit_to;
    float value;

    printf("Enter the number of units: ");
    scanf("%d", &num_units);

    printf("Enter the unit you are converting from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you are converting to: ");
    scanf("%d", &unit_to);

    printf("Enter the value: ");
    scanf("%f", &value);

    switch (unit_from) {
        case 1:
            switch (unit_to) {
                case 2:
                    value *= 2;
                    break;
                case 3:
                    value *= 3;
                    break;
                case 4:
                    value *= 4;
                    break;
                default:
                    printf("Invalid unit conversion");
                    break;
            }
            break;
        case 2:
            switch (unit_to) {
                case 1:
                    value *= 0.5;
                    break;
                case 3:
                    value *= 1.5;
                    break;
                case 4:
                    value *= 2;
                    break;
                default:
                    printf("Invalid unit conversion");
                    break;
            }
            break;
        case 3:
            switch (unit_to) {
                case 1:
                    value *= 0.333;
                    break;
                case 2:
                    value *= 0.666;
                    break;
                case 4:
                    value *= 2;
                    break;
                default:
                    printf("Invalid unit conversion");
                    break;
            }
            break;
        default:
            printf("Invalid unit conversion");
            break;
    }

    printf("The converted value is: %.2f", value);

    return 0;
}