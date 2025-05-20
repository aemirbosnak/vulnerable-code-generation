//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    double conversion_factor;
} Unit;

// Array of units with their respective names and conversion factors
Unit units[] = {
    {"Meters", 1.0},
    {"Kilometers", 1000.0},
    {"Feet", 0.3048},
    {"Inches", 0.0254},
    {"Miles", 1609.34},
    {"Pounds", 0.453592},
    {"Kilograms", 2.20462},
    {"Stones", 6.35029},
    {"Gallons", 0.00378541},
    {"Liters", 0.001},
    {"Ounces", 0.035274},
    {"Cubic Centimeters", 0.000001},
    {"Cubic Feet", 0.0283168},
    {"Cubic Inches", 0.000016387064},
    {"Cubic Miles", 271577.8},
    {"Cubic Yards", 0.764555},
    {NULL, 0}
};

int find_unit_index(char *unit_name) {
    int i = 0;
    while (units[i].name != NULL) {
        int len1 = strlen(units[i].name);
        int len2 = strlen(unit_name);
        if (len1 >= len2 && strcmp(units[i].name, unit_name) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

double convert(char *from_unit, double quantity, char *to_unit) {
    int from_index = find_unit_index(from_unit);
    int to_index = find_unit_index(to_unit);

    if (from_index < 0 || to_index < 0) {
        printf("Invalid unit(s).\n");
        return -1;
    }

    double result = quantity * (units[to_index].conversion_factor / units[from_index].conversion_factor);
    return result;
}

int main() {
    char from_unit[20], to_unit[20], input[100];
    double quantity;

    printf("Welcome to the Grateful Unit Converter!\n");
    printf("This program will convert various units of length, mass, and volume.\n");
    printf("Please enter the quantity, followed by the unit you want to convert from, and the unit you want to convert to:\n");

    while (1) {
        printf("\nQuantity: ");
        scanf("%lf", &quantity);
        printf("Unit from: ");
        scanf("%s", from_unit);
        from_unit[strcspn(from_unit, "\n")] = '\0'; // Remove newline character
        printf("Unit to: ");
        scanf("%s", to_unit);
        to_unit[strcspn(to_unit, "\n")] = '\0'; // Remove newline character

        double result = convert(from_unit, quantity, to_unit);

        if (result >= 0) {
            printf("\n%lf %s is equal to %lf %s.\n", quantity, from_unit, result, to_unit);
        }

        printf("\nWould you like to convert another unit? (yes/no): ");
        scanf("%s", input);
        if (strcmp(input, "no") == 0) {
            break;
        }
    }

    printf("Thank you for using the Grateful Unit Converter! Have a wonderful day!\n");

    return 0;
}