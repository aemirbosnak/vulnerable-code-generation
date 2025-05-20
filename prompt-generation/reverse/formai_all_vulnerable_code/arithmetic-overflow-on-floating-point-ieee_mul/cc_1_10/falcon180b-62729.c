//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define UNIT_NAME_LEN 20

typedef struct {
    char name[UNIT_NAME_LEN];
    double factor;
} Unit;

int main() {
    char input[50];
    char output_unit[UNIT_NAME_LEN];
    double value, result;
    int choice;
    Unit units[MAX_UNITS];

    strcpy(units[0].name, "meter");
    units[0].factor = 1;

    strcpy(units[1].name, "kilometer");
    units[1].factor = 1000;

    strcpy(units[2].name, "centimeter");
    units[2].factor = 0.01;

    strcpy(units[3].name, "millimeter");
    units[3].factor = 0.001;

    strcpy(units[4].name, "inch");
    units[4].factor = 0.0254;

    strcpy(units[5].name, "foot");
    units[5].factor = 0.3048;

    strcpy(units[6].name, "yard");
    units[6].factor = 0.9144;

    strcpy(units[7].name, "mile");
    units[7].factor = 160934.4;

    strcpy(units[8].name, "ounce");
    units[8].factor = 0.0283495;

    strcpy(units[9].name, "pound");
    units[9].factor = 0.453592;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the input unit: ");
    scanf("%s", input);

    printf("Enter the output unit: ");
    scanf("%s", output_unit);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (!strcmp(input, units[i].name)) {
            choice = i;
            break;
        }
    }

    if (choice == -1) {
        printf("Invalid input unit.\n");
        return 1;
    }

    result = value * units[choice].factor;

    for (int i = 0; i < MAX_UNITS; i++) {
        if (!strcmp(output_unit, units[i].name)) {
            printf("Result: %.2lf %s\n", result / units[i].factor, output_unit);
            break;
        }
    }

    return 0;
}