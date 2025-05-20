//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_CONVERTIONS 3

typedef struct unit {
    char name[20];
    double factor;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"inch", 0.0254},
    {"foot", 0.3048},
    {"yard", 0.9144}
};

int main() {
    char input_unit[20];
    char output_unit[20];
    double input_value;
    double output_value;

    printf("Welcome to the Unit Converter!\n");

    while (1) {
        printf("Enter a value: ");
        scanf("%lf", &input_value);

        printf("Enter the unit you want to convert from: ");
        fgets(input_unit, 20, stdin);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(input_unit, units[i].name) == 0) {
                output_value = input_value * units[i].factor;
                break;
            }
        }

        if (output_value == 0) {
            printf("Invalid unit or value\n");
            continue;
        }

        printf("The value in %s is %lf\n", output_unit, output_value);

        printf("Do you want to convert again? (y/n): ");
        char answer = getchar();

        if (answer == 'n') {
            break;
        }

        printf("Enter the unit you want to convert to: ");
        fgets(output_unit, 20, stdin);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(output_unit, units[i].name) == 0) {
                output_value = output_value / units[i].factor;
                break;
            }
        }

        printf("The value in %s is %lf\n", output_unit, output_value);
    }

    return 0;
}