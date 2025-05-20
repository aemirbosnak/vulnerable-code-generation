//FormAI DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>

int main() {
    int option;
    float value;
    char unit[10];
    float result;

    printf("Enter the value to be converted: ");
    scanf("%f", &value);
    printf("Enter the unit (m,k,c,f): ");
    scanf("%s", unit);
    printf("Enter the option.\n 1 - Convert to cm, 2 - Convert to km, 3 - Convert to lbs, 4 - Convert to celsius: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            if (unit[0] == 'm') {
                result = value * 100;
            } else if (unit[0] == 'k') {
                result = value * 100000;
            } else if (unit[0] == 'c') {
                result = value;
            } else if (unit[0] == 'f') {
                result = (value - 32) * 5 / 9;
            }
            printf("%.2f %s is equal to %.2f cm.\n", value, unit, result);
            break;
        case 2:
            if (unit[0] == 'm') {
                result = value / 1000;
            } else if (unit[0] == 'k') {
                result = value;
            } else if (unit[0] == 'c') {
                result = value / 100000;
            } else if (unit[0] == 'f') {
                result = (value - 32) * 5 / 9 * 0.001;
            }
            printf("%.2f %s is equal to %.2f km.\n", value, unit, result);
            break;
        case 3:
            if (unit[0] == 'm') {
                result = value * 2.20462;
            } else if (unit[0] == 'k') {
                result = value * 2.20462 * 1000;
            } else if (unit[0] == 'c') {
                result = value * 2.20462 * 100000;
            } else if (unit[0] == 'f') {
                result = value;
            }
            printf("%.2f %s is equal to %.2f lbs.\n", value, unit, result);
            break;
        case 4:
            if (unit[0] == 'm') {
                result = value;
            } else if (unit[0] == 'k') {
                result = value - 273.15;
            } else if (unit[0] == 'c') {
                result = value - 273.15;
            } else if (unit[0] == 'f') {
                result = (value - 32) * 5 / 9 - 273.15;
            }
            printf("%.2f %s is equal to %.2f celsius.\n", value, unit, result);
            break;
        default:
            printf("Invalid option selected.\n");
            break;
    }

    return 0;
}