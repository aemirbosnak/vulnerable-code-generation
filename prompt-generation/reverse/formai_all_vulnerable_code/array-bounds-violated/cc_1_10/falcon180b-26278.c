//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>

#define MAX_UNITS 10

typedef struct {
    char name[20];
    char symbol[10];
    double conversion_factor;
} Unit;

Unit units[MAX_UNITS] = {
    {"meters", "m", 1},
    {"centimeters", "cm", 0.01},
    {"inches", "in", 0.0254},
    {"feet", "ft", 0.3048},
    {"yards", "yd", 0.9144},
    {"miles", "mi", 160934.4},
    {"kilograms", "kg", 1},
    {"grams", "g", 0.001},
    {"pounds", "lb", 0.453592},
    {"ounces", "oz", 0.0283495}
};

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    int choice, num_units;
    double value, result;
    char input[100], unit_name[20];

    printf("Welcome to the Unit Converter!\n");
    printf("Select a unit to convert from:\n");

    for (int i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Select a unit to convert to:\n");

    for (int i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    strcpy(unit_name, units[choice-1].name);

    if (unit_name[0] =='m') {
        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(units[i].name, "meters") == 0) {
                num_units = i;
                break;
            }
        }
    } else {
        num_units = choice - 1;
    }

    result = value * units[num_units].conversion_factor;

    printf("%.2lf %s is equal to %.2lf %s.\n", value, unit_name, result, units[choice-1].name);

    return 0;
}