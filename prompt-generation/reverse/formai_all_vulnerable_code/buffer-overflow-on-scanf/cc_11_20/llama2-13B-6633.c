//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

// Global variables
double conversions[MAX_CONVERTIONS][3] = {
    {1, 1, 1}, // None
    {1, 10, 100}, // None
    {1, 100, 1000}, // None
    {10, 10, 100}, // km to m
    {10, 100, 1000}, // m to km
    {100, 10, 100}, // g to kg
    {100, 100, 1000}, // kg to g
    {1000, 10, 100}, // L to ml
    {1000, 100, 1000}, // ml to L
    {1000, 1, 1000}  // s to min
};

int main() {
    int choice;
    double num1, num2, result;
    char unit1, unit2, unit_out;

    do {
        printf("Welcome to the Unit Converter! \n");
        printf("Choose a conversion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the first unit: ");
                scanf(" %c", &unit1);
                printf("Enter the second unit: ");
                scanf(" %c", &unit2);
                break;

            case 2:
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                break;

            case 3:
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second unit: ");
                scanf(" %c", &unit2);
                break;

            default:
                printf("Invalid choice. Try again!\n");
                break;
        }

        // Check for invalid input
        if (unit1 != 'm' && unit1 != 'g' && unit1 != 'L') {
            printf("Invalid unit. Try again!\n");
            break;
        }

        if (unit2 != 'm' && unit2 != 'g' && unit2 != 'L') {
            printf("Invalid unit. Try again!\n");
            break;
        }

        // Perform the conversion
        result = conversions[choice - 1][unit1] * num1 / conversions[choice - 1][unit2];

        // Print the result
        printf("Result: %f %c\n", result, unit_out);

        // Ask the user if they want to convert again
        printf("Do you want to convert again? (y/n): ");
        scanf(" %c", &unit_out);

    } while (unit_out == 'y' || unit_out == 'Y');

    return 0;
}