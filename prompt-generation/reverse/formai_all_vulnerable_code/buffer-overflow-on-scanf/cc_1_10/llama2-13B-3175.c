//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_UNITS 10
#define UNIT_NAMES "cm,m,km,inch,ft,yard,mile,kg,lb,oz"

typedef struct {
    double value;
    char unit[8];
} unit_t;

unit_t units[NUM_UNITS] = {
    {100, "cm"},
    {1000, "m"},
    {10000, "km"},
    {12, "inch"},
    {36, "ft"},
    {3600, "yard"},
    {5280, "mile"},
    {1, "kg"},
    {2.20462, "lb"},
    {35.27407, "oz"}
};

int main() {
    int i, j;
    double value, converted_value;
    char input_unit[8], output_unit[8];

    // Print the list of units
    printf("Available units: ");
    for (i = 0; i < NUM_UNITS; i++) {
        printf("%s ", units[i].unit);
    }
    printf("\n");

    // Get the input value and unit
    printf("Enter a value and unit (e.g. 50 cm): ");
    scanf("%lf %8s", &value, input_unit);

    // Convert the value to all possible units
    for (i = 0; i < NUM_UNITS; i++) {
        converted_value = value * units[i].value / units[0].value;
        printf("Value in unit %s: %lf\n", units[i].unit, converted_value);
    }

    return 0;
}