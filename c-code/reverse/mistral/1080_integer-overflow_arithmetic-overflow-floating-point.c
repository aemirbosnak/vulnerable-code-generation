#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    double conversion_factor;
} Unit;

Unit units[] = {
    {"Centimeter", 0.01},
    {"Meter", 1},
    {"Kilometer", 1000},
    {"Inch", 0.0254},
    {"Foot", 0.3048},
    {"Mile", 1609.34}
};

void convert(double value, char* from, char* to) {
    int i;
    for (i = 0; i < 6; i++) {
        if (strcmp(from, units[i].name) == 0) {
            printf("%lf %s to %s: %lf\n", value, from, to, value * units[i].conversion_factor * units[find_index(to)].conversion_factor);
            break;
        }
    }
}

int find_index(char* name) {
    int i;
    for (i = 0; i < 6; i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    double value;
    char from[20], to[20];

    printf("Enter value: ");
    scanf("%lf", &value);
    printf("Enter unit (Centimeter, Meter, Kilometer, Inch, Foot, Mile): ");
    scanf("%s", from);
    printf("Convert to (Centimeter, Meter, Kilometer, Inch, Foot, Mile): ");
    scanf("%s", to);

    convert(value, from, to);

    // Intentional integer overflow vulnerability
    convert(value * 1e18, "Meter", "Meter");

    return 0;
}
