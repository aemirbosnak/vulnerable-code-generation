//FormAI DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

void convert(char unit[100], double amount, char from[100], char to[100]) {
    double result;
    char output_unit[100];

    // Length conversions
    if (strcmp(unit, "length") == 0) {
        if (strcmp(from, "m") == 0 && strcmp(to, "km") == 0) {
            result = amount / 1000;
            strcpy(output_unit, "km");
        } else if (strcmp(from, "km") == 0 && strcmp(to, "m") == 0) {
            result = amount * 1000;
            strcpy(output_unit, "m");
        } else if (strcmp(from, "cm") == 0 && strcmp(to, "m") == 0) {
            result = amount / 100;
            strcpy(output_unit, "m");
        } else if (strcmp(from, "m") == 0 && strcmp(to, "cm") == 0) {
            result = amount * 100;
            strcpy(output_unit, "cm");
        } else {
            printf("Error: Unknown conversion for length units.");
            return;
        }
    } else {
        printf("Error: Unknown unit type.");
        return;
    }

    printf("%.2lf %s in %s is %.2lf %s", amount, from, to, result, output_unit);
}

int main() {
    char unit[100], from[100], to[100];
    double amount;

    printf("Welcome to the Ken Thompson Unit Converter!\n\n");
    printf("Enter the type of unit (e.g. length): ");
    scanf("%s", unit);

    printf("Enter an amount to convert: ");
    scanf("%lf", &amount);

    printf("Enter the unit to convert from (e.g. m): ");
    scanf("%s", from);

    printf("Enter the unit to convert to (e.g. km): ");
    scanf("%s", to);

    convert(unit, amount, from, to);

    return 0;
}