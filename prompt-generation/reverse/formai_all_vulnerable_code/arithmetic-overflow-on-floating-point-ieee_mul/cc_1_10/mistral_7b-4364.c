//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float value;
    char unit;
} Unit;

void print_unit(Unit unit) {
    switch (unit.unit) {
        case 'm':
            printf("meters\n");
            break;
        case 'km':
            printf("kilometers\n");
            break;
        case 'l':
            printf("liters\n");
            break;
        case 'g':
            printf("grams\n");
            break;
        case 'kg':
            printf("kilograms\n");
            break;
        case 'oz':
            printf("ounces\n");
            break;
        case 'lb':
            printf("pounds\n");
            break;
        case 'ft':
            printf("feet\n");
            break;
        case 'in':
            printf("inches\n");
            break;
        default:
            printf("Unknown unit\n");
    }
}

Unit convert_length(Unit from, float factor) {
    Unit to;

    to.value = from.value * factor;
    to.unit = from.unit;

    if (from.unit == 'm') {
        if (to.value >= 1000) {
            to.unit = 'km';
            to.value /= 1000;
        }
    } else if (from.unit == 'km') {
        to.unit = 'm';
    }

    return to;
}

Unit read_unit() {
    Unit unit;
    char input[10];

    printf("Enter value and unit (e.g. 10m): ");
    scanf("%s%*c %f %c", input, &unit.value, &unit.unit);

    while (getchar() != '\n') {}

    if (unit.unit == '\n') {
        printf("Invalid input. Please try again.\n");
        read_unit();
    }

    return unit;
}

int main() {
    Unit from, to;
    float factor;

    printf("Welcome to the Retro Unit Converter!\n");
    printf("------------------------------------\n");

    from = read_unit();

    printf("Input:\n");
    print_unit(from);
    printf("\n");

    printf("Enter conversion factor: ");
    scanf("%f", &factor);

    to = convert_length(from, factor);

    printf("\nOutput:\n");
    print_unit(to);

    return EXIT_SUCCESS;
}