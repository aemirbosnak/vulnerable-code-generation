//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char* from_unit;
    char* to_unit;
    double conversion_factor;
} Unit;

Unit* create_unit(char* from_unit, char* to_unit, double conversion_factor) {
    Unit* unit = (Unit*) malloc(sizeof(Unit));
    unit->from_unit = from_unit;
    unit->to_unit = to_unit;
    unit->conversion_factor = conversion_factor;
    return unit;
}

void print_units() {
    printf("Available units:\n");
    printf("1. Length\n2. Weight\n3. Temperature\n4. Volume\n");
}

int main() {
    int choice;
    char input_unit[50];
    char output_unit[50];
    double input_value, output_value;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter the unit you want to convert from: ");
    scanf("%s", input_unit);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", output_unit);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &input_value);

    Unit* unit = NULL;

    switch(choice) {
        case 1:
            unit = create_unit("meters", "feet", 3.28084);
            break;
        case 2:
            unit = create_unit("kilograms", "pounds", 2.20462);
            break;
        case 3:
            unit = create_unit("celsius", "fahrenheit", 1.8);
            break;
        case 4:
            unit = create_unit("liters", "gallons", 0.264172);
            break;
        default:
            printf("Invalid unit!\n");
            return 1;
    }

    output_value = input_value * unit->conversion_factor;

    printf("%.2lf %s is equal to %.2lf %s.\n", input_value, input_unit, output_value, output_unit);

    return 0;
}