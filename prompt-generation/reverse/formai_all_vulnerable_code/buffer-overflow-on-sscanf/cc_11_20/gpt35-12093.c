//FormAI DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main() {
    char input[50], unit1[20], unit2[20];
    float amount, converted;
    printf("Welcome to the puzzling C unit converter!\n");
    printf("Please input the amount and the starting unit (e.g. '10 cm'):\n");
    fgets(input, sizeof(input), stdin);

    // Parse user input
    sscanf(input, "%f %s", &amount, unit1);

    printf("You entered %.2f %s. What unit would you like to convert to?\n", amount, unit1);
    fgets(unit2, sizeof(unit2), stdin);
    strtok(unit2, "\n"); // Remove newline character from user input

    // Perform conversions
    if (strcmp(unit1, "inches") == 0) {
        if (strcmp(unit2, "feet") == 0) {
            converted = amount / 12;
            printf("%.2f inches is %.2f feet.\n", amount, converted);
        }
        else if (strcmp(unit2, "centimeters") == 0) {
            converted = amount * 2.54;
            printf("%.2f inches is %.2f centimeters.\n", amount, converted);
        }
        else {
            printf("Sorry, we cannot convert from inches to %s.\n", unit2);
        }
    }
    else if (strcmp(unit1, "feet") == 0) {
        if (strcmp(unit2, "inches") == 0) {
            converted = amount * 12;
            printf("%.2f feet is %.2f inches.\n", amount, converted);
        }
        else if (strcmp(unit2, "miles") == 0) {
            converted = amount / 5280;
            printf("%.2f feet is %.2f miles.\n", amount, converted);
        }
        else {
            printf("Sorry, we cannot convert from feet to %s.\n", unit2);
        }
    }
    else if (strcmp(unit1, "miles") == 0) {
        if (strcmp(unit2, "feet") == 0) {
            converted = amount * 5280;
            printf("%.2f miles is %.2f feet.\n", amount, converted);
        }
        else if (strcmp(unit2, "kilometers") == 0) {
            converted = amount * 1.609;
            printf("%.2f miles is %.2f kilometers.\n", amount, converted);
        }
        else {
            printf("Sorry, we cannot convert from miles to %s.\n", unit2);
        }
    }
    else if (strcmp(unit1, "kilometers") == 0) {
        if (strcmp(unit2, "miles") == 0) {
            converted = amount / 1.609;
            printf("%.2f kilometers is %.2f miles.\n", amount, converted);
        }
        else if (strcmp(unit2, "centimeters") == 0) {
            converted = amount * 100000;
            printf("%.2f kilometers is %.2f centimeters.\n", amount, converted);
        }
        else {
            printf("Sorry, we cannot convert from kilometers to %s.\n", unit2);
        }
    }
    else if (strcmp(unit1, "centimeters") == 0) {
        if (strcmp(unit2, "inches") == 0) {
            converted = amount / 2.54;
            printf("%.2f centimeters is %.2f inches.\n", amount, converted);
        }
        else if (strcmp(unit2, "kilometers") == 0) {
            converted = amount / 100000;
            printf("%.2f centimeters is %.2f kilometers.\n", amount, converted);
        }
        else {
            printf("Sorry, we cannot convert from centimeters to %s.\n", unit2);
        }
    }
    else {
        printf("Sorry, we don't know how to convert from %s.\n", unit1);
    }

    return 0;
}