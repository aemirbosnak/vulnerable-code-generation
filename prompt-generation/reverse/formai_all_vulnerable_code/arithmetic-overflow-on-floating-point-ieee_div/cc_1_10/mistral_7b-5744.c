//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char unit[3];
    double conversion_factor;
} Unit;

Unit units[] = {{"m", 0.001}, {"km", 1000.0}, {"l", 0.001}, {"L", 1.0}, {"g", 0.001}, {"kg", 1000.0}, {"oz", 0.035274}, {"lb", 0.453592}, {"in", 0.0254}, {"ft", 0.3048}, {"mi", 1609.34}, {"nm", 1000000000.0}, {"A", 1.0E-1}, {"W", 1.0}, {"V", 1.0}, {"Ohm", 1.0}};
int num_units = sizeof(units) / sizeof(Unit);

void print_menu() {
    printf("\nAvailable Units:\n");
    for (int i = 0; i < num_units; ++i) {
        printf("%s -> %s (%lf)\n", units[i].unit, (i % 3 == 0) ? "Convert From" : "Convert To", units[i].conversion_factor);
    }
}

int find_unit_index(char *unit) {
    for (int i = 0; i < num_units; ++i) {
        if (strcmp(units[i].unit, unit) == 0) {
            return i;
        }
    }
    return -1;
}

double convert(char *from_unit, double value, char *to_unit) {
    int from_index = find_unit_index(from_unit);
    int to_index = find_unit_index(to_unit);

    if (from_index == -1 || to_index == -1) {
        printf("Invalid unit!\n");
        return 0;
    }

    double result = value * units[from_index].conversion_factor / units[to_index].conversion_factor;
    return result;
}

int main() {
    char from_unit[3], to_unit[3];
    double value, result;

    print_menu();

    printf("\nEnter unit to convert from: ");
    scanf("%s", from_unit);

    printf("Enter value to convert: ");
    scanf("%lf", &value);

    printf("Enter unit to convert to: ");
    scanf("%s", to_unit);

    result = convert(from_unit, value, to_unit);
    if (result != 0) {
        printf("\nResult: %lf %s\n", result, to_unit);
    }

    return 0;
}