//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 100

typedef struct {
    char name[30];
    double factor;
} unit;

typedef struct {
    char from[30];
    char to[30];
    unit conversion;
} conversion;

conversion conversions[MAX_CONVERSIONS];
int num_conversions;

void add_conversion(conversion c) {
    conversions[num_conversions++] = c;
}

void initialize_conversions() {
    add_conversion((conversion) {"meters", "feet", (unit) {3.28084}});
    add_conversion((conversion) {"feet", "meters", (unit) {0.3048}});
    add_conversion((conversion) {"kilograms", "pounds", (unit) {2.20462}});
    add_conversion((conversion) {"pounds", "kilograms", (unit) {0.453592}});
    add_conversion((conversion) {"liters", "gallons", (unit) {0.264172}});
    add_conversion((conversion) {"gallons", "liters", (unit) {3.78541}});
    add_conversion((conversion) {"celsius", "fahrenheit", (unit) {1.8}});
    add_conversion((conversion) {"fahrenheit", "celsius", (unit) {0.555555}});
}

void print_conversions() {
    printf("Available conversions:\n");
    for (int i = 0; i < num_conversions; i++) {
        printf("%s -> %s\n", conversions[i].from, conversions[i].to);
    }
}

int main() {
    initialize_conversions();
    print_conversions();

    char from_unit[30];
    char to_unit[30];
    double value;

    printf("Enter a value to convert, followed by the units (e.g. 5 meters): ");
    scanf("%lf %s", &value, from_unit);

    printf("Convert to: ");
    scanf("%s", to_unit);

    for (int i = 0; i < num_conversions; i++) {
        if (strcmp(conversions[i].from, from_unit) == 0 && strcmp(conversions[i].to, to_unit) == 0) {
            printf("%lf %s = %lf %s\n", value, from_unit, value * conversions[i].conversion.factor, to_unit);
            return 0;
        }
    }

    printf("Invalid conversion.\n");
    return 1;
}