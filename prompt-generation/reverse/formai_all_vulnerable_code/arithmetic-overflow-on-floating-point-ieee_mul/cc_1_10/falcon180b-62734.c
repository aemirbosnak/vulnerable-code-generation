//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char name[20];
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS];
    int num_units = 0;
    char input[100];

    strcpy(units[num_units].name, "meters");
    units[num_units].factor = 1.0;
    num_units++;

    strcpy(units[num_units].name, "kilometers");
    units[num_units].factor = 1000.0;
    num_units++;

    strcpy(units[num_units].name, "miles");
    units[num_units].factor = 1609.34;
    num_units++;

    strcpy(units[num_units].name, "yards");
    units[num_units].factor = 1093.61;
    num_units++;

    strcpy(units[num_units].name, "feet");
    units[num_units].factor = 3280.84;
    num_units++;

    strcpy(units[num_units].name, "inches");
    units[num_units].factor = 39370.1;
    num_units++;

    strcpy(units[num_units].name, "liters");
    units[num_units].factor = 1.0;
    num_units++;

    strcpy(units[num_units].name, "gallons");
    units[num_units].factor = 3.78541;
    num_units++;

    strcpy(units[num_units].name, "pounds");
    units[num_units].factor = 2.20462;
    num_units++;

    strcpy(units[num_units].name, "ounces");
    units[num_units].factor = 35.274;
    num_units++;

    printf("Enter the value to be converted: ");
    scanf("%s", input);

    printf("Enter the unit of the value: ");
    scanf("%s", input);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(input, units[i].name) == 0) {
            printf("%.2f %s = %.2f %s\n", atof(input), units[i].name, atof(input) * units[i].factor, "meters");
            break;
        }
    }

    return 0;
}