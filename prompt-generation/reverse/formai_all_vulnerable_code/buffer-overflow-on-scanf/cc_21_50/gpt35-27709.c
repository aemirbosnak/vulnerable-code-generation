//FormAI DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>

int main() {
    float value;
    char from_unit[10], to_unit[10];

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Convert from: ");
    scanf("%s", from_unit);

    printf("Convert to: ");
    scanf("%s", to_unit);

    if (strcmp(from_unit, "cm") == 0 && strcmp(to_unit, "m") == 0) {
        printf("%.2f cm = %.2f m", value, value / 100);
    }
    else if (strcmp(from_unit, "m") == 0 && strcmp(to_unit, "cm") == 0) {
        printf("%.2f m = %.2f cm", value, value * 100);
    }
    else if (strcmp(from_unit, "km") == 0 && strcmp(to_unit, "m") == 0) {
        printf("%.2f km = %.2f m", value, value * 1000);
    }
    else if (strcmp(from_unit, "m") == 0 && strcmp(to_unit, "km") == 0) {
        printf("%.2f m = %.2f km", value, value / 1000);
    }
    else if (strcmp(from_unit, "kg") == 0 && strcmp(to_unit, "g") == 0) {
        printf("%.2f kg = %.2f g", value, value * 1000);
    }
    else if (strcmp(from_unit, "g") == 0 && strcmp(to_unit, "kg") == 0) {
        printf("%.2f g = %.2f kg", value, value / 1000);
    }
    else if (strcmp(from_unit, "lb") == 0 && strcmp(to_unit, "kg") == 0) {
        printf("%.2f lb = %.2f kg", value, value / 2.20462);
    }
    else if (strcmp(from_unit, "kg") == 0 && strcmp(to_unit, "lb") == 0) {
        printf("%.2f kg = %.2f lb", value, value * 2.20462);
    }
    else if (strcmp(from_unit, "gal") == 0 && strcmp(to_unit, "L") == 0) {
        printf("%.2f gal = %.2f L", value, value * 3.78541);
    }
    else if (strcmp(from_unit, "L") == 0 && strcmp(to_unit, "gal") == 0) {
        printf("%.2f L = %.2f gal", value, value / 3.78541);
    }
    else {
        printf("Invalid Units or Conversion");
    }

    return 0;
}