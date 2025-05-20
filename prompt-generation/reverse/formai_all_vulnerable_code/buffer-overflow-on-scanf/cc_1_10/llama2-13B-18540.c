//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

// Structure to hold the unit and its conversion
typedef struct {
    char *name;
    double factor;
} unit_conv_t;

// Array to hold the available units
unit_conv_t units[MAX_UNITS] = {
    {"second", 1.0},
    {"minute", 60.0},
    {"hour", 3600.0},
    {"day", 86400.0},
    {"week", 604800.0},
    {"month", 2592000.0},
    {"year", 31536000.0}
};

// Function to convert a value from one unit to another
double convert(double value, char *from_unit, char *to_unit) {
    int i = 0;
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            break;
        }
    }
    if (i == MAX_UNITS) {
        printf("Invalid unit %s\n", from_unit);
        return 0.0;
    }
    double factor = units[i].factor;
    for (i = 0; i < MAX_CONVERSIONS; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            break;
        }
    }
    if (i == MAX_CONVERSIONS) {
        printf("Invalid unit %s\n", to_unit);
        return 0.0;
    }
    return value * factor / units[i].factor;
}

int main() {
    int choice;
    double value, converted_value;

    do {
        printf("Enter a value in %s: ", "second");
        scanf("%lf", &value);

        printf("Enter the unit to convert to: ");
        char to_unit[50];
        fgets(to_unit, 50, stdin);

        converted_value = convert(value, "second", to_unit);

        printf("Value in %s is %lf\n", to_unit, converted_value);

        printf("Do you want to convert again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}