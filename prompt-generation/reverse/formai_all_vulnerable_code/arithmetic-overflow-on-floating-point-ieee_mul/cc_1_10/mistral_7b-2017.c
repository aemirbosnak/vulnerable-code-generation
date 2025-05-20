//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

typedef struct {
    double value;
    char unit;
} Unit;

Unit convert(Unit base, Unit target, double conversion_factor) {
    Unit result;

    result.value = base.value * conversion_factor;
    result.unit = target.unit;

    return result;
}

void print_unit(Unit unit) {
    if (unit.unit == 'm') {
        printf("%.2f meters\n", unit.value);
    } else if (unit.unit == 'km') {
        printf("%.2f kilometers\n", unit.value / 1000.0);
    } else if (unit.unit == 'l') {
        printf("%.2f liters\n", unit.value);
    } else if (unit.unit == 'g') {
        printf("%.2f grams\n", unit.value);
    } else if (unit.unit == 'kg') {
        printf("%.2f kilograms\n", unit.value);
    } else if (unit.unit == 'hz') {
        printf("%.2f hertz\n", unit.value);
    } else {
        printf("Invalid unit: %c\n", unit.unit);
    }
}

Unit read_unit() {
    Unit input;
    char temp;

    printf("Enter value and unit (m, km, l, g, kg, hz): ");
    scanf("%lf %c", &input.value, &temp);

    input.unit = temp;

    return input;
}

int main() {
    Unit base, target, result;
    double conversion_factor;

    printf("Welcome to the Grateful Converter!\n");
    printf("I am here to help you convert units with a smile!\n");

    base = read_unit();
    printf("You have entered: ");
    print_unit(base);

    printf("Now, enter the conversion factor and the target unit:\n");
    printf("Conversion factor: ");
    scanf("%lf", &conversion_factor);
    printf("Target unit: ");
    scanf(" %c", &target.unit);

    target.value = 0;

    result = convert(base, target, conversion_factor);

    printf("\nWith a heart full of gratitude, I present to you:\n");
    print_unit(result);

    return 0;
}