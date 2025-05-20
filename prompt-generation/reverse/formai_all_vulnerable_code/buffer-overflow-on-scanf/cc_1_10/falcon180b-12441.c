//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *name;
    double factor;
} unit;

void print_units(unit units[], int num_units) {
    printf("Available units:\n");
    for(int i = 0; i < num_units; i++) {
        printf("%s (%c)\n", units[i].name, i+'a');
    }
}

unit get_unit(char *name) {
    unit units[] = {{"meters", 1}, {"kilometers", 1000}, {"centimeters", 0.01}, {"millimeters", 0.001}, {"inches", 0.0254}, {"feet", 0.3048}, {"yards", 0.9144}, {"miles", 160934.4}};
    for(int i = 0; i < sizeof(units)/sizeof(unit); i++) {
        if(strcmp(units[i].name, name) == 0) {
            return units[i];
        }
    }
    return (unit){NULL, 0};
}

double convert(double value, unit from_unit, unit to_unit) {
    return value * from_unit.factor / to_unit.factor;
}

int main() {
    printf("Enter the value to convert:\n");
    double value = scanf("%lf", &value);

    printf("Enter the unit of the value:\n");
    char unit_name[32];
    scanf("%s", unit_name);

    unit from_unit = get_unit(unit_name);
    if(from_unit.name == NULL) {
        printf("Invalid unit.\n");
        exit(1);
    }

    printf("Enter the unit to convert to:\n");
    scanf("%s", unit_name);

    unit to_unit = get_unit(unit_name);
    if(to_unit.name == NULL) {
        printf("Invalid unit.\n");
        exit(1);
    }

    double result = convert(value, from_unit, to_unit);

    printf("%.2lf %s is equal to %.2lf %s\n", value, from_unit.name, result, to_unit.name);
    return 0;
}