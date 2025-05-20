//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_COUNT 10
#define UNIT_NAMES "m, kg, s, A, K, mol, cd, Hz, N, Pa"
#define UNIT_VALUES "1, 1, 1, 1, 1, 1, 1, 1, 1, 1"
#define UNIT_CONVERSION_RATE "1, 1, 1, 1, 1, 1, 1, 1, 1, 1"
#define UNIT_CONVERSION_RATE_STRING "1, 1, 1, 1, 1, 1, 1, 1, 1, 1"

typedef struct {
    char name[10];
    char value[10];
} Unit;

void print_units() {
    printf("Units:\n");
    for (int i = 0; i < UNIT_COUNT; i++) {
        printf("%s - %s\n", UNIT_NAMES[i * 10], UNIT_NAMES[(i * 10) + 9]);
    }
}

int main() {
    char input_unit[10];
    char output_unit[10];
    double value;
    int unit_index_in, unit_index_out;

    printf("Cyberpunk Unit Converter\n");
    print_units();

    printf("\nEnter input unit: ");
    scanf("%s", input_unit);

    printf("\nEnter output unit: ");
    scanf("%s", output_unit);

    for (int i = 0; i < UNIT_COUNT; i++) {
        if (strcmp(input_unit, UNIT_NAMES[i * 10]) == 0) {
            unit_index_in = i;
            break;
        }
    }

    for (int i = 0; i < UNIT_COUNT; i++) {
        if (strcmp(output_unit, UNIT_NAMES[i * 10]) == 0) {
            unit_index_out = i;
            break;
        }
    }

    value = atof(input_unit) * atof(UNIT_CONVERSION_RATE[unit_index_in]) / atof(UNIT_CONVERSION_RATE[unit_index_out]);

    printf("\n%s %s = %.2f %s\n", input_unit, output_unit, value, output_unit);

    return 0;
}