//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>
#include <math.h>

#define MAX_LENGTH 100

void convert(double value, char from_unit, char to_unit) {
    if (from_unit =='m' && to_unit == 'ft') {
        value *= 3.2808399;
    } else if (from_unit =='m' && to_unit == 'km') {
        value /= 1.0e-3;
    } else if (from_unit =='m' && to_unit == 'in') {
        value *= 39.3700787;
    } else if (from_unit =='m' && to_unit == 'yd') {
        value *= 1.0936133;
    } else if (from_unit == 'ft' && to_unit =='m') {
        value /= 0.3048;
    } else if (from_unit == 'ft' && to_unit == 'km') {
        value /= 1.0e-3;
    } else if (from_unit == 'ft' && to_unit == 'in') {
        value *= 12.0;
    } else if (from_unit == 'ft' && to_unit == 'yd') {
        value *= 3.0;
    } else if (from_unit == 'km' && to_unit =='m') {
        value *= 1.0;
    } else if (from_unit == 'km' && to_unit == 'ft') {
        value *= 3280.84;
    } else if (from_unit == 'km' && to_unit == 'in') {
        value /= 39370.0787;
    } else if (from_unit == 'km' && to_unit == 'yd') {
        value *= 1093.6133;
    } else if (from_unit == 'yd' && to_unit =='m') {
        value *= 0.9144;
    } else if (from_unit == 'yd' && to_unit == 'ft') {
        value /= 3.0;
    } else if (from_unit == 'yd' && to_unit == 'in') {
        value /= 36.0;
    } else {
        printf("Invalid conversion\n");
        return;
    }
    printf("%s %c is equal to %.2lf %c.\n", value, from_unit, value, to_unit);
}

int main() {
    char from_unit, to_unit;
    double value;

    printf("Enter the value to be converted (enter 0 to exit): ");
    scanf("%lf", &value);

    while (value!= 0.0) {
        printf("Enter the unit to convert from (m, ft, km, yd): ");
        scanf(" %c", &from_unit);

        printf("Enter the unit to convert to (m, ft, km, yd): ");
        scanf(" %c", &to_unit);

        convert(value, from_unit, to_unit);

        printf("Do you want to convert another value? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice!= 'y') {
            break;
        }
    }

    return 0;
}