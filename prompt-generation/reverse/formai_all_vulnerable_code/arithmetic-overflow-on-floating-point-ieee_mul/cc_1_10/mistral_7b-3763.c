//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float value;
    char unit;
} Unit;

Unit convert(Unit base, float factor, Unit to) {
    Unit result;

    result.value = base.value * factor;

    if (base.unit == to.unit) {
        result.unit = base.unit;
    } else if (base.unit == 'm' && to.unit == 'km') {
        result.unit = 'k';
    } else if (base.unit == 'kg' && to.unit == 'lb') {
        result.unit = 'l';
        result.value *= 2.20462;
    } else if (base.unit == 'lb' && to.unit == 'kg') {
        result.unit = 'k';
        result.value /= 2.20462;
    } else if (base.unit == 'l' && to.unit == 'gal') {
        result.unit = 'g';
        result.value /= 3.78541;
    } else if (base.unit == 'gal' && to.unit == 'l') {
        result.unit = 'l';
        result.value *= 3.78541;
    } else {
        printf("Invalid units conversion.\n");
        result.value = 0.0;
    }

    return result;
}

int main() {
    Unit base, to, result;
    float factor;

    printf("Enter base value: ");
    scanf("%f", &base.value);
    printf("Enter base unit (m/kg/l): ");
    scanf(" %c", &base.unit);

    printf("Enter conversion factor: ");
    scanf("%f", &factor);

    printf("Enter target unit (m/km/kg/lb/l/gal): ");
    scanf(" %c", &to.unit);

    result = convert(base, factor, to);

    if (result.value != 0.0) {
        printf("Result: %.2f %c\n", result.value, result.unit);
    }

    return 0;
}