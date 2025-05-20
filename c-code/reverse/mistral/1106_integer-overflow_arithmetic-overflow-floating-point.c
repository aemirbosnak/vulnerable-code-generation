#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    double conversion_factor;
} Unit;

Unit units[] = {
    {"meter", 0.001},
    {"kilometer", 1000},
    {"mile", 1609.34},
};

int main() {
    int choice, from, to;
    double value;

    printf("Length Unit Converter\n");
    printf("1. Convert from:\n");
    for (int i = 0; i < 3; ++i) {
        printf("%d. %s\n", i + 1, units[i].name);
    }

    scanf("%d", &from);
    printf("2. To:\n");
    for (int i = 0; i < 3; ++i) {
        if (i == from - 1) continue;
        printf("%d. %s\n", i + 1, units[i].name);
    }
    scanf("%d", &to);

    printf("Enter value: ");
    scanf("%lf", &value);

    printf("%.2lf %s is equal to %.2lf %s\n", value, units[from - 1].name, value * units[from - 1].conversion_factor * units[to - 1].conversion_factor, units[to - 1].name);

    return 0;
}
