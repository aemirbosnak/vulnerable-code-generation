//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 100

typedef struct {
    char *name;
    float factor;
} Unit;

typedef struct {
    char *from_unit;
    char *to_unit;
    float value;
} Conversion;

int main() {
    Unit units[MAX_UNITS] = {{"meters", 1}, {"feet", 0.3048}, {"inches", 0.0254}, {"yards", 0.9144}, {"miles", 160934.4}, {"kilometers", 1000}, {"pounds", 0.453592}, {"ounces", 0.0283495}, {"gallons", 3.78541}, {"liters", 1}};
    Conversion conversions[MAX_CONVERSIONS];
    int num_units = 0, num_conversions = 0;
    char choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter 'u' to add a unit or 'c' to add a conversion:\n");

    while (choice!= 'q') {
        scanf("%c", &choice);

        switch (choice) {
            case 'u':
                printf("Enter the name of the unit (max %d characters): ", MAX_UNITS - num_units - 1);
                scanf("%s", units[num_units].name);
                printf("Enter the conversion factor for %s (e.g. 1 for meters): ", units[num_units].name);
                scanf("%f", &units[num_units].factor);
                num_units++;
                break;
            case 'c':
                printf("Enter the unit to convert from: ");
                scanf("%s", conversions[num_conversions].from_unit);
                printf("Enter the unit to convert to: ");
                scanf("%s", conversions[num_conversions].to_unit);
                printf("Enter the value to convert: ");
                scanf("%f", &conversions[num_conversions].value);
                num_conversions++;
                break;
            case 'q':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    printf("\nUnit Conversions:\n");
    for (int i = 0; i < num_conversions; i++) {
        int from_unit_index = -1, to_unit_index = -1;
        for (int j = 0; j < num_units; j++) {
            if (strcmp(units[j].name, conversions[i].from_unit) == 0) {
                from_unit_index = j;
            }
            if (strcmp(units[j].name, conversions[i].to_unit) == 0) {
                to_unit_index = j;
            }
        }

        if (from_unit_index == -1 || to_unit_index == -1) {
            printf("Invalid units for conversion.\n");
            continue;
        }

        float result = conversions[i].value * units[from_unit_index].factor / units[to_unit_index].factor;
        printf("%s %s = %.2f %s\n", conversions[i].from_unit, conversions[i].to_unit, result, conversions[i].to_unit);
    }

    return 0;
}