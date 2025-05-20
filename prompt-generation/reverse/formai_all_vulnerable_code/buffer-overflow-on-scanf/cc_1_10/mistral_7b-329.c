//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    char unit[3];
    float conversion_factor;
} Unit;

Unit units[] = {{"km", 1000.0}, {"m", 1.0}, {"cm", 0.01}, {"mm", 0.001},
                {"mi", 1609.34}, {"ft", 0.3048}, {"yd", 0.9144}, {"in", 0.0254}};

int get_index(char unit[3]) {
    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (strcmp(units[i].unit, unit) == 0) {
            return i;
        }
    }
    return -1;
}

void convert_unit(char from_unit[3], char to_unit[3], float value) {
    int index_from = get_index(from_unit);
    int index_to = get_index(to_unit);

    if (index_from == -1 || index_to == -1) {
        printf("Error: Invalid units.\n");
        return;
    }

    float result = value * units[index_from].conversion_factor / units[index_to].conversion_factor;
    printf("%.6f %s = %.6f %s\n", value, from_unit, result, to_unit);
}

int main() {
    char from_unit[3], to_unit[3];
    float value;

    printf("Enter value: ");
    scanf("%f", &value);

    printf("Enter the unit of the value (e.g. cm): ");
    scanf("%s", from_unit);

    printf("Enter the unit you want to convert to (e.g. m): ");
    scanf("%s", to_unit);

    convert_unit(from_unit, to_unit, value);

    return 0;
}