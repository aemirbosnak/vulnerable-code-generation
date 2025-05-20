//FormAI DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>

int main() {
    float value;
    char from[10], to[10];

    printf("Enter the value to convert: ");
    scanf("%f", &value);
    printf("Enter the unit to convert FROM (e.g. km, lb, m): ");
    scanf("%s", from);
    printf("Enter the unit to convert TO (e.g. m, kg): ");
    scanf("%s", to);

    if (strcmp(from, "km") == 0) {
        if (strcmp(to, "m") == 0) {
            value *= 1000;
        }
        else if (strcmp(to, "ft") == 0) {
            value *= 3280.84;
        }
        else if (strcmp(to, "mi") == 0) {
            value *= 0.621371;
        }
    }
    else if (strcmp(from, "m") == 0) {
        if (strcmp(to, "km") == 0) {
            value /= 1000;
        }
        else if (strcmp(to, "ft") == 0) {
            value *= 3.28084;
        }
        else if (strcmp(to, "mi") == 0) {
            value *= 0.000621371;
        }
    }
    else if (strcmp(from, "ft") == 0) {
        if (strcmp(to, "km") == 0) {
            value /= 3280.84;
        }
        else if (strcmp(to, "m") == 0) {
            value /= 3.28084;
        }
        else if (strcmp(to, "mi") == 0) {
            value /= 5280;
        }
    }
    else if (strcmp(from, "mi") == 0) {
        if (strcmp(to, "km") == 0) {
            value /= 0.621371;
        }
        else if (strcmp(to, "m") == 0) {
            value /= 0.000621371;
        }
        else if (strcmp(to, "ft") == 0) {
            value *= 5280;
        }
    }
    else {
        printf("Invalid unit entered\n");
        return 1;
    }
    printf("%f %s = %f %s\n", value, from, value, to);

    return 0;
}