//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    char input[100];
    char unit1[10], unit2[10];
    double value, result;
    int choice;

    printf("Enter the value to convert: ");
    fgets(input, 100, stdin);
    value = atof(input);

    printf("Enter the unit to convert from (e.g. kg, m, s): ");
    fgets(unit1, 10, stdin);
    printf("Enter the unit to convert to (e.g. lb, ft, hr): ");
    fgets(unit2, 10, stdin);

    if (strcmp(unit1, "kg") == 0) {
        if (strcmp(unit2, "lb") == 0) {
            result = value * 2.20462;
            printf("%.2f kg is %.2f lb.\n", value, result);
        } else if (strcmp(unit2, "ft") == 0) {
            result = value * 0.3048;
            printf("%.2f kg is %.2f ft.\n", value, result);
        } else if (strcmp(unit2, "hr") == 0) {
            result = value * 0.2777777778;
            printf("%.2f kg is %.2f hr.\n", value, result);
        } else {
            printf("Invalid unit conversion.\n");
        }
    } else if (strcmp(unit1, "m") == 0) {
        if (strcmp(unit2, "ft") == 0) {
            result = value * 3.28084;
            printf("%.2f m is %.2f ft.\n", value, result);
        } else if (strcmp(unit2, "s") == 0) {
            result = value / 0.2777777778;
            printf("%.2f m is %.2f s.\n", value, result);
        } else {
            printf("Invalid unit conversion.\n");
        }
    } else if (strcmp(unit1, "s") == 0) {
        if (strcmp(unit2, "hr") == 0) {
            result = value / 0.2777777778;
            printf("%.2f s is %.2f hr.\n", value, result);
        } else {
            printf("Invalid unit conversion.\n");
        }
    } else {
        printf("Invalid unit conversion.\n");
    }

    return 0;
}