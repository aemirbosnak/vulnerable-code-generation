//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979323846

typedef struct {
    float value;
    char unit;
} Unit;

Unit convert(Unit base, Unit to, int is_volume) {
    Unit result;

    switch (to.unit) {
        case 'm':
            result.value = base.value;
            if (is_volume)
                result.value *= 0.001;
            break;
        case 'km':
            result.value = base.value / 1000.0;
            if (is_volume)
                result.value *= PI;
            break;
        case 'l':
            result.value = base.value / 1000.0;
            if (!is_volume)
                result.value *= 0.001;
            break;
        case 'gal':
            result.value = base.value * 3.78541;
            if (!is_volume)
                result.value *= 0.00378541;
            break;
        case 'oz':
            result.value = base.value * 0.068521775;
            if (is_volume)
                result.value *= 0.0000068521775;
            break;
        case 'lb':
            result.value = base.value * 0.0453592;
            if (is_volume)
                result.value *= 0.000453592;
            break;
        default:
            result.value = 0;
            break;
    }

    result.unit = to.unit;
    return result;
}

int main(void) {
    Unit base, to, result;
    char unit_input[10];

    printf("Enter value and unit (space separated): ");
    scanf("%f %s", &base.value, unit_input);
    base.unit = *unit_input;

    printf("Enter unit to convert to: ");
    scanf("%s", unit_input);
    to.unit = *unit_input;

    to.value = 1;

    result = convert(base, to, 0);
    printf("Result: %.8f %c\n", result.value, result.unit);

    result = convert(base, to, 1);
    printf("Volume Result: %.8f %c\n", result.value, result.unit);

    return 0;
}