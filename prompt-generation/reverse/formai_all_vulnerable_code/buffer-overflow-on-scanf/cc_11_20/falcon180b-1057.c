//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double value, result;
    char unit[5];

    printf("Unit Converter\n");
    printf("Enter 1 for length conversion\n");
    printf("Enter 2 for weight conversion\n");
    printf("Enter 3 for temperature conversion\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the value to convert: ");
        scanf("%lf", &value);
        printf("Enter the unit (m, cm, ft, in): ");
        scanf("%s", unit);

        if (strcmp(unit, "m") == 0) {
            result = value * 3.28084;
            printf("%lf meters is equal to %lf feet.\n", value, result);
        } else if (strcmp(unit, "cm") == 0) {
            result = value * 0.0328084;
            printf("%lf centimeters is equal to %lf inches.\n", value, result);
        } else if (strcmp(unit, "ft") == 0) {
            result = value / 3.28084;
            printf("%lf feet is equal to %lf meters.\n", value, result);
        } else if (strcmp(unit, "in") == 0) {
            result = value / 0.0328084;
            printf("%lf inches is equal to %lf centimeters.\n", value, result);
        } else {
            printf("Invalid unit.\n");
        }
    } else if (choice == 2) {
        printf("Enter the value to convert: ");
        scanf("%lf", &value);
        printf("Enter the unit (kg, lb): ");
        scanf("%s", unit);

        if (strcmp(unit, "kg") == 0) {
            result = value * 2.20462;
            printf("%lf kilograms is equal to %lf pounds.\n", value, result);
        } else if (strcmp(unit, "lb") == 0) {
            result = value / 2.20462;
            printf("%lf pounds is equal to %lf kilograms.\n", value, result);
        } else {
            printf("Invalid unit.\n");
        }
    } else if (choice == 3) {
        printf("Enter the value to convert: ");
        scanf("%lf", &value);
        printf("Enter the unit (C, F): ");
        scanf("%s", unit);

        if (strcmp(unit, "C") == 0) {
            result = (value * 9/5) + 32;
            printf("%lf degrees Celsius is equal to %lf degrees Fahrenheit.\n", value, result);
        } else if (strcmp(unit, "F") == 0) {
            result = (value - 32) * 5/9;
            printf("%lf degrees Fahrenheit is equal to %lf degrees Celsius.\n", value, result);
        } else {
            printf("Invalid unit.\n");
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}