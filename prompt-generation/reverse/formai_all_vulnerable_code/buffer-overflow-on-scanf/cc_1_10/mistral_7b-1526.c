//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct {
    double value;
    char unit[20];
} Unit;

void print_unit(Unit unit) {
    printf("%.2f %s\n", unit.value, unit.unit);
}

Unit convert(Unit from, Unit to, double conversion_factor) {
    from.value *= conversion_factor;
    strcpy(from.unit, to.unit);
    return from;
}

Unit read_input() {
    Unit input;
    printf("Enter value and unit: ");
    scanf("%lf %19s", &input.value, input.unit);
    return input;
}

int main() {
    Unit length_input, mass_input, area_output, volume_output;
    double length_to_mass = 0.0254; // 1 inch to 1 kg
    double length_to_area = 144.0; // 1 square inch to 1 square foot
    double length_to_volume = 45359237.0; // 1 cubic inch to 1 gallon

    length_input = read_input();

    printf("\nLength entered: %.2f %s\n", length_input.value, length_input.unit);

    if (!strcmp(length_input.unit, "inch")) {
        mass_input = (Unit){ 0, "" };
        mass_input.value = length_input.value * length_to_mass;
        print_unit(convert(length_input, mass_input, length_to_mass));

        area_output = (Unit){ 0, "" };
        area_output.value = length_input.value * length_input.value * length_to_area;
        strcpy(area_output.unit, "square foot");
        print_unit(convert(length_input, area_output, length_to_area));

        volume_output = (Unit){ 0, "" };
        volume_output.value = length_input.value * length_input.value * length_input.value * length_to_volume;
        strcpy(volume_output.unit, "gallon");
        print_unit(convert(length_input, volume_output, length_to_volume));
    } else if (!strcmp(length_input.unit, "meter")) {
        // Add conversion for mass, area, and volume in meters here
    } else {
        printf("Invalid length unit.\n");
    }

    return 0;
}