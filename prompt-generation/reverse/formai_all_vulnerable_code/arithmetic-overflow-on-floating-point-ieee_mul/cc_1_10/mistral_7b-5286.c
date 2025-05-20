//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

typedef struct {
    double value;
    char unit;
} Unit;

void convert_to_inches(Unit *unit) {
    unit->value *= 39.37;
}

void convert_to_feet(Unit *unit) {
    unit->value /= 12.0;
    convert_to_inches(unit);
}

void convert_to_centimeters(Unit *unit) {
    unit->value *= 100.0;
}

void print_unit(Unit unit) {
    if (unit.unit == 'm') {
        printf("%.2f meters = %.2f inches\n", unit.value, unit.value * 39.37);
        convert_to_inches(&unit);
        printf("%.2f meters = %.2f feet\n", unit.value, unit.value / 3.28084);
        convert_to_centimeters(&unit);
        printf("%.2f meters = %.2f centimeters\n", unit.value, unit.value * 100.0);
    } else if (unit.unit == 'i') {
        printf("%.2f inches = %.2f meters\n", unit.value, unit.value / 39.37);
    } else if (unit.unit == 'f') {
        printf("%.2f feet = %.2f meters\n", unit.value, unit.value * 3.28084);
    } else if (unit.unit == 'c') {
        printf("%.2f centimeters = %.2f meters\n", unit.value / 100.0, unit.value / 100.0);
    }
}

int main() {
    Unit meter, inch, foot, centimeter;
    double input;
    char unit_input;

    scanf("%lf %c", &input, &unit_input);
    meter.value = input;
    meter.unit = unit_input;

    print_unit(meter);

    return 0;
}