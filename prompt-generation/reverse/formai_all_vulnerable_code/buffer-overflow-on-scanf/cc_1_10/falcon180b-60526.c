//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_UNITS 10
#define UNIT_CONVERSION_FACTOR 5

typedef struct {
    char *name;
    double factor;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"meters", 1},
    {"kilometers", 1000},
    {"grams", 1},
    {"kilograms", 1000},
    {"liters", 1},
    {"gallons", 3.78541},
    {"celsius", 1},
    {"fahrenheit", 1.8},
    {"seconds", 1},
    {"minutes", 60}
};

int main() {
    int choice;
    double value, converted_value;
    char unit_name[20];

    printf("Welcome to the Cyberpunk Unit Converter!\n");
    printf("Please select the unit you want to convert from:\n");

    for (int i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Please enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Please enter the unit you want to convert to:\n");
    scanf("%s", unit_name);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            converted_value = value * units[i].factor;
            printf("%.2lf %s is equal to %.2lf %s.\n", value, unit_name, converted_value, units[i].name);
            break;
        }
    }

    return 0;
}