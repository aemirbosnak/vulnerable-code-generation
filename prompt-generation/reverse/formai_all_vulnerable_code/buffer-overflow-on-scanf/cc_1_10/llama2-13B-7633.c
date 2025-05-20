//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159
#define INF 1e99

// Define a struct for a unit
typedef struct {
    char name[10];
    double factor;
} unit_t;

// Define an array of units
unit_t units[] = {
    {"m", 1},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.34},
    {"yd", 0.9144},
    {"ft", 1},
    {"in", 0.0254},
    {"pt", 0.00070874},
    {"deg", 0.01745329},
    {"rad", 0.02566715},
    {"s", 1},
    {"min", 60},
    {"hr", 3600},
    {"d", 24 * 3600},
    {"A", 1000000},
    {"m^2", 1},
    {"m^3", 1 / 3.0},
    {"kg", 1000},
    {"g", 0.001},
    {"oz", 0.0283495},
    {"lb", 0.45359237},
    {"t", 1000000}
};

// Define a function to convert between units
void convert(double value, unit_t from, unit_t to) {
    double factor = from.factor / to.factor;
    value *= factor;
    printf("%.2f %s -> %.2f %s\n", value, from.name, value, to.name);
}

int main() {
    double value;
    char unit[10];

    // Get the value and unit from the user
    printf("Enter a value and a unit (e.g. 5 cm): ");
    scanf("%lf %s", &value, unit);

    // Find the corresponding unit struct in the array
    int i = 0;
    while (units[i].name[0] != '\0') {
        if (strcmp(unit, units[i].name) == 0) {
            break;
        }
        i++;
    }

    // Convert the value to the target unit
    convert(value, units[i], units[i + 1]);

    return 0;
}