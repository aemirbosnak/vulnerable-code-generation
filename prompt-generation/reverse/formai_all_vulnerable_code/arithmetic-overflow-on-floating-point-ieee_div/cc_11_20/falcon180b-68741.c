//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    char input[100];
    char *token;
    Unit from_unit, to_unit;
    double value, result;
    int i;

    // Initialize units
    from_unit.name = "meter";
    from_unit.factor = 1.0;

    to_unit.name = "kilometer";
    to_unit.factor = 1000.0;

    printf("Welcome to the Funky Unit Converter!\n");
    printf("Please enter a value to convert: ");
    scanf("%s", input);

    // Parse input
    value = strtod(input, &token);
    if (token == NULL || token[0]!= '\0') {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    // Parse units
    if (strcasecmp(token, "meter") == 0) {
        from_unit.name = "meter";
        from_unit.factor = 1.0;
    } else if (strcasecmp(token, "kilometer") == 0) {
        from_unit.name = "kilometer";
        from_unit.factor = 1000.0;
    } else if (strcasecmp(token, "centimeter") == 0) {
        from_unit.name = "centimeter";
        from_unit.factor = 0.01;
    } else if (strcasecmp(token, "millimeter") == 0) {
        from_unit.name = "millimeter";
        from_unit.factor = 0.001;
    } else {
        printf("Invalid unit. Please enter a valid unit.\n");
        return 1;
    }

    // Convert to target unit
    printf("Convert to: ");
    scanf("%s", input);
    if (strcasecmp(input, "kilometer") == 0) {
        to_unit.name = "kilometer";
        to_unit.factor = 1000.0;
    } else if (strcasecmp(input, "meter") == 0) {
        to_unit.name = "meter";
        to_unit.factor = 1.0;
    } else if (strcasecmp(input, "centimeter") == 0) {
        to_unit.name = "centimeter";
        to_unit.factor = 0.01;
    } else if (strcasecmp(input, "millimeter") == 0) {
        to_unit.name = "millimeter";
        to_unit.factor = 0.001;
    } else {
        printf("Invalid unit. Please enter a valid unit.\n");
        return 1;
    }

    // Convert and print result
    result = value * from_unit.factor / to_unit.factor;
    printf("%.2f %s = %.2f %s\n", value, from_unit.name, result, to_unit.name);

    return 0;
}