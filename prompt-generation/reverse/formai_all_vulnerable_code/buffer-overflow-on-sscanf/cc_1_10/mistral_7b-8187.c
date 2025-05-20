//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024

typedef struct {
    char unit[10];
    double conversion_factor;
} Unit;

Unit units[] = {
    {"inches", 0.0254},
    {"centimeters", 0.0254},
    {"feet", 0.3048},
    {"meters", 0.3048},
    {"pounds", 0.4536},
    {"kilograms", 0.4536},
    {"ounces", 0.04536},
    {"grams", 0.04536},
    {"degrees_Fahrenheit", 1.8},
    {"degrees_Celsius", 1.8},
    {"gallons", 3.78541},
    {"liters", 3.78541}
};

int main() {
    char input[MAX_INPUT_SIZE];
    char *token, *unit_name;
    double value, result;
    int i;

    printf("Invasive C Unit Converter\n");
    printf("--------------------------\n");

    printf("Enter value and unit (space-separated): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    sscanf(input, "%lf %s", &value, input);

    for (i = 0; i < 13; i++) {
        if (strstr(input, units[i].unit) != NULL) {
            unit_name = units[i].unit;
            break;
        }
    }

    for (i = 0; i < 13; i++) {
        if (strcmp(unit_name, units[i].unit) == 0) {
            result = value * units[i].conversion_factor;
            printf("%.2lf %s is equal to:\n", value, unit_name);
            for (int j = 0; j < 13; j++) {
                printf("%.2lf %s\n", result / units[j].conversion_factor, units[j].unit);
            }
            return 0;
        }
    }

    printf("Invalid unit: %s\n", input);
    return 1;
}