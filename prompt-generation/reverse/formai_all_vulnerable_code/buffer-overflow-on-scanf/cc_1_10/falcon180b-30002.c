//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 100

typedef struct {
    char name[20];
    double factor;
} Unit;

int main() {

    // Define the units
    Unit units[MAX_UNITS] = {{"meters", 1.0},
                             {"kilometers", 1000.0},
                             {"inches", 0.0254},
                             {"feet", 0.3048},
                             {"yards", 0.9144},
                             {"miles", 160934.4},
                             {"pounds", 0.453592},
                             {"ounces", 0.0283495},
                             {"gallons", 3.78541},
                             {"liters", 0.264172}};

    int num_units = sizeof(units) / sizeof(units[0]);

    char input[50];
    double value;
    char from_unit[20];
    char to_unit[20];

    // Get user input
    printf("Enter a value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit of the value: ");
    scanf("%s", from_unit);
    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    // Find the indices of the input units
    int from_index = -1;
    int to_index = -1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_index = i;
        } else if (strcmp(to_unit, units[i].name) == 0) {
            to_index = i;
        }
    }

    // Check if the input units are valid
    if (from_index == -1 || to_index == -1) {
        printf("Invalid unit(s).\n");
        return 1;
    }

    // Convert the value
    double result = value * units[from_index].factor / units[to_index].factor;

    // Print the result
    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}