//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    float factor;
} Unit;

int main() {

    Unit units[MAX_UNITS];
    int num_units = 0;

    units[num_units].name = "meters";
    units[num_units++].factor = 1.0;

    units[num_units].name = "kilometers";
    units[num_units++].factor = 1000.0;

    units[num_units].name = "centimeters";
    units[num_units++].factor = 0.01;

    units[num_units].name = "millimeters";
    units[num_units++].factor = 0.001;

    units[num_units].name = "inches";
    units[num_units++].factor = 0.0254;

    units[num_units].name = "feet";
    units[num_units++].factor = 0.3048;

    units[num_units].name = "yards";
    units[num_units++].factor = 0.9144;

    units[num_units].name = "miles";
    units[num_units++].factor = 160934.4;

    char from_unit[20];
    char to_unit[20];
    float value;

    printf("Enter the unit you want to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", to_unit);

    printf("Enter the value you want to convert: ");
    scanf("%f", &value);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            for (int j = 0; j < num_units; j++) {
                if (strcmp(units[j].name, to_unit) == 0) {
                    printf("%f %s = %f %s\n", value, from_unit, value * units[i].factor / units[j].factor, to_unit);
                    break;
                }
            }
            break;
        }
    }

    return 0;
}