//FormAI DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
#include <stdio.h>

typedef enum {
    INCHES,
    CENTIMETERS,
    FEET,
    METERS
} unit_t;

double convert(double value, unit_t from, unit_t to) {
    double result = value;

    if (from == INCHES) {
        if (to == CENTIMETERS) {
            result *= 2.54;
        } else if (to == FEET) {
            result /= 12.0;
        } else if (to == METERS) {
            result /= 39.37;
        }
    } else if (from == CENTIMETERS) {
        if (to == INCHES) {
            result /= 2.54;
        } else if (to == FEET) {
            result /= 30.48;
        } else if (to == METERS) {
            result /= 100;
        }
    } else if (from == FEET) {
        if (to == INCHES) {
            result *= 12.0;
        } else if (to == CENTIMETERS) {
            result *= 30.48;
        } else if (to == METERS) {
            result /= 3.281;
        }
    } else if (from == METERS) {
        if (to == INCHES) {
            result *= 39.37;
        } else if (to == CENTIMETERS) {
            result *= 100;
        } else if (to == FEET) {
            result *= 3.281;
        }
    }

    return result;
}

int main() {
    double value;
    unit_t from, to;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (1-inches, 2-centimeters, 3-feet, 4-meters): ");
    scanf("%d", &from);

    printf("Enter the unit to convert to (1-inches, 2-centimeters, 3-feet, 4-meters): ");
    scanf("%d", &to);

    double result = convert(value, from-1, to-1);

    printf("%lf %s equals %lf %s\n", value, from == 1 ? "inches" : from == 2 ? "centimeters" : from == 3 ? "feet" : "meters", result, to == 1 ? "inches" : to == 2 ? "centimeters" : to == 3 ? "feet" : "meters");

    return 0;
}