//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 100
#define MAX_CONVERSION_TYPES 20

typedef struct {
    char *name;
    double factor;
} Unit;

typedef struct {
    char *name;
    int num_units;
    Unit *units;
} ConversionType;

ConversionType conversion_types[MAX_CONVERSION_TYPES];
int num_conversion_types;

void add_unit(ConversionType *type, char *name, double factor) {
    type->units = realloc(type->units, sizeof(Unit) * ++type->num_units);
    type->units[type->num_units - 1].name = strdup(name);
    type->units[type->num_units - 1].factor = factor;
}

int main() {
    char input[100];
    char *token;
    int i, j;
    double value, result;
    char from_unit[10], to_unit[10];

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the unit you want to convert from: ");
    scanf("%s", from_unit);
    printf("Please enter the unit you want to convert to: ");
    scanf("%s", to_unit);

    for (i = 0; i < num_conversion_types; i++) {
        if (strcmp(from_unit, conversion_types[i].name) == 0 && strcmp(to_unit, conversion_types[i].name)!= 0) {
            printf("Invalid conversion. Cannot convert %s to itself.\n", from_unit);
            return 1;
        }
        for (j = 0; j < conversion_types[i].num_units; j++) {
            if (strcmp(to_unit, conversion_types[i].units[j].name) == 0) {
                printf("Please enter the value you want to convert: ");
                scanf("%lf", &value);
                result = value * conversion_types[i].units[j].factor;
                printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);
                return 0;
            }
        }
    }

    printf("Invalid conversion. Cannot convert %s to %s.\n", from_unit, to_unit);
    return 1;
}