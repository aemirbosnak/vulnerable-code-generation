//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare the variables
    char unit_from[20], unit_to[20];
    float value, result;
    int choice;

    // Display the menu
    printf("Welcome to the Amazing Unit Converter!\n");
    printf("----------------------------------------\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Quit\n");
    printf("----------------------------------------\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    // Get the units and value
    switch (choice) {
        case 1:
            printf("Enter the unit to convert from: ");
            scanf("%s", unit_from);
            printf("Enter the unit to convert to: ");
            scanf("%s", unit_to);
            printf("Enter the value to convert: ");
            scanf("%f", &value);

            // Convert the length
            if (strcmp(unit_from, "cm") == 0 && strcmp(unit_to, "m") == 0) {
                result = value / 100;
            } else if (strcmp(unit_from, "m") == 0 && strcmp(unit_to, "cm") == 0) {
                result = value * 100;
            } else if (strcmp(unit_from, "in") == 0 && strcmp(unit_to, "cm") == 0) {
                result = value * 2.54;
            } else if (strcmp(unit_from, "cm") == 0 && strcmp(unit_to, "in") == 0) {
                result = value / 2.54;
            } else if (strcmp(unit_from, "ft") == 0 && strcmp(unit_to, "m") == 0) {
                result = value / 3.281;
            } else if (strcmp(unit_from, "m") == 0 && strcmp(unit_to, "ft") == 0) {
                result = value * 3.281;
            } else {
                printf("Invalid units!\n");
                return 1;
            }

            // Display the result
            printf("The converted value is: %.2f %s\n", result, unit_to);
            break;

        case 2:
            printf("Enter the unit to convert from: ");
            scanf("%s", unit_from);
            printf("Enter the unit to convert to: ");
            scanf("%s", unit_to);
            printf("Enter the value to convert: ");
            scanf("%f", &value);

            // Convert the weight
            if (strcmp(unit_from, "g") == 0 && strcmp(unit_to, "kg") == 0) {
                result = value / 1000;
            } else if (strcmp(unit_from, "kg") == 0 && strcmp(unit_to, "g") == 0) {
                result = value * 1000;
            } else if (strcmp(unit_from, "lb") == 0 && strcmp(unit_to, "kg") == 0) {
                result = value / 2.205;
            } else if (strcmp(unit_from, "kg") == 0 && strcmp(unit_to, "lb") == 0) {
                result = value * 2.205;
            } else if (strcmp(unit_from, "oz") == 0 && strcmp(unit_to, "g") == 0) {
                result = value * 28.35;
            } else if (strcmp(unit_from, "g") == 0 && strcmp(unit_to, "oz") == 0) {
                result = value / 28.35;
            } else {
                printf("Invalid units!\n");
                return 1;
            }

            // Display the result
            printf("The converted value is: %.2f %s\n", result, unit_to);
            break;

        case 3:
            printf("Enter the unit to convert from: ");
            scanf("%s", unit_from);
            printf("Enter the unit to convert to: ");
            scanf("%s", unit_to);
            printf("Enter the value to convert: ");
            scanf("%f", &value);

            // Convert the temperature
            if (strcmp(unit_from, "c") == 0 && strcmp(unit_to, "f") == 0) {
                result = value * 9 / 5 + 32;
            } else if (strcmp(unit_from, "f") == 0 && strcmp(unit_to, "c") == 0) {
                result = (value - 32) * 5 / 9;
            } else if (strcmp(unit_from, "k") == 0 && strcmp(unit_to, "c") == 0) {
                result = value - 273.15;
            } else if (strcmp(unit_from, "c") == 0 && strcmp(unit_to, "k") == 0) {
                result = value + 273.15;
            } else {
                printf("Invalid units!\n");
                return 1;
            }

            // Display the result
            printf("The converted value is: %.2f %s\n", result, unit_to);
            break;

        case 4:
            printf("Thank you for using the Amazing Unit Converter!\n");
            return 0;

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    return 0;
}